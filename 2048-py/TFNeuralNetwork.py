import os
import sys
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import numpy as np
import random
import tensorflow as tf
from Game import Game
from functions import Gradients
import math
import argparse
import ast

parser = argparse.ArgumentParser()
parser.add_argument("structure", help="Network structure python array")
parser.add_argument("learning-rate", help="Learning rate of model")
parser.add_argument("discount-factor", help="Discount factor of model")
parser.add_argument("epochs", help="Number of games to run")


args = vars(parser.parse_args())
for key, value in args.iteritems():
	args[key] = ast.literal_eval(value)

hidden_layers = args["structure"][1:-1]

tf.reset_default_graph()

# These lines establish the feed-forward part of the network used to choose actions
inputs1 = tf.placeholder(shape=[1, 16], dtype=tf.float32)

last_layer = 16
weights = []
biases = []
activation = [inputs1]

for i, n in enumerate(hidden_layers):
	weights.append(tf.Variable(tf.random_normal([last_layer, n], -0.5, 0.5)))
	biases.append(tf.Variable(tf.constant(0.1, shape=[n])))
	activation.append(tf.nn.relu(tf.add(tf.matmul(activation[i], weights[i]), biases[i])))
	last_layer = n

weights.append(tf.Variable(tf.random_normal([last_layer, 4], -0.5, 0.5)))
biases.append(tf.Variable(tf.constant(0.1, shape=[4])))

Qout = tf.nn.relu(tf.add(tf.matmul(activation[-1], weights[-1]), biases[-1]))


predict = tf.argmax(Qout, 1)

# Below we obtain the loss by taking the sum of squares difference between the target and prediction Q values.
nextQ = tf.placeholder(shape=[1, 4], dtype=tf.float32)
loss = tf.reduce_sum(tf.square(nextQ - Qout))
trainer = tf.train.GradientDescentOptimizer(learning_rate=args["learning-rate"])
updateModel = trainer.minimize(loss)

init = tf.global_variables_initializer()

#  Set learning parameters
y = args["discount-factor"]
e = 0.9

epsilon = Gradients.Exponential(start=0.9,stop=0.1)
num_episodes = args["epochs"]

tf.summary.scalar("loss", loss)
summary_op = tf.summary.merge_all()


def normalize(v):
	mag = np.sqrt(np.sum(np.array(v) ** 2))
	return map(lambda x: math.log(x,2) if x else x, v)
# return map(lambda x: x/mag, v)


def reward(fromstate, tostate):
	if not tostate.valid:
		return -1
	else:
		# return np.log2(tostate.score - fromstate.score)/16
		return 1
	return 0

# create lists to contain total rewards and steps per episode
rList = []
with tf.Session() as sess:
	sess.run(init)

	writer = tf.summary.FileWriter("./log", graph=tf.get_default_graph())
	score=0

	x2 = ""
	for i in range(num_episodes):
		# Reset environment and get first new observation
		game = Game(4)
		s = normalize(game.grid_to_input())
		reward_sum = 0
		halt = False
		steps = 0
		# The Q-Network
		while not halt:
			steps += 1
			currstate = game.currState
			# Choose an action by greedily (with e chance of random action) from the Q-network
			a, allQ = sess.run([predict, Qout], feed_dict={inputs1: [s]})
			if np.random.rand(1) < e:
				a[0] = random.randint(0, 3)

			# Get new state and reward from environment
			nextstate = game.transition(a[0])
			r = reward(currstate, nextstate)
			s1 = normalize(game.grid_to_input())
			halt = nextstate.halt

			# Obtain the Q' values by feeding the new state through our network
			Q1 = sess.run(Qout, feed_dict={inputs1: [s1]})
			# Obtain maxQ' and set our target value for chosen action.
			maxQ1 = np.max(Q1)
			targetQ = allQ
			targetQ[0, a[0]] = r + y*maxQ1

			# Train our network using target and predicted Q values
			_, summary = sess.run([updateModel, summary_op], feed_dict={inputs1: [s], nextQ: targetQ})
			writer.add_summary(summary, i)

			reward_sum += r
			s = s1
			if halt:
				# Reduce chance of random action as we train the model.
				value = float(i+1)/num_episodes
				e = epsilon(value)
				break

		stat = dict()
		stat['maxTile'] = max([max(game.currState.grid[k]) for k in range(len(game.currState.grid))])
		stat['score'] = game.currState.score
		stat['steps'] = steps
		# stat['loss'] = l
		score+=game.currState.score


		print (i+1)/num_episodes, "\t", stat
		rList.append(reward_sum)

	print float(score)/num_episodes;
	sess.close()

# print "Percent of succesful episodes: " + str(sum(rList)/num_episodes) + "%"
