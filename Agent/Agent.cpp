#include "Agent.h"

namespace Agent {
	Agent::Agent(const GA::Genotype * genotype) {


		this->genotype = genotype;

		// skip the rest for now till we're testing ga
		return;


		this->game = new Two048::Game(4);

		OpenNN::Vector<size_t> nn_architecture;

		auto layers = (int)genotype->architecture.size();
		for(int i=0;i<layers;i++) {
			nn_architecture.push_back((size_t)genotype->architecture[i]);
		}


		this->network = new OpenNN::NeuralNetwork(nn_architecture);
		/*
		 * set other nn settings
		 */
	}

	TrainingResult * Agent::train(int epochs) {

		TrainingResult * results = new TrainingResult;

		/* remember to set static settings for agent in main
		 *
		 *	python code
		 *
		 *	nn.train(
		 *		verbose=False,
		 *		progress=True,
		 *		save=True,
		 *		maxepochs=20000,
		 *		batch=30,
		 *		replay_size=100000,
		 *		filename=name,
		 *		autosave=100,
		 *		savestats=True,
		 *	)
		 *
		 *	the following is stub code for now
		 */

		results->avg_score = rand()%5000 + 5000;

		return results;

	}


}