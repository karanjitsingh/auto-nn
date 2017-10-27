#include "Agent.h"

namespace Agent {
	Agent::Agent(const GA::Genotype * genotype) {

		this->game = new Two048::Game(4);
		this->genotype = genotype;

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

	TrainingResult * train(int epochs) {

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
		 */

		return results;

	}


}