#include "Agent.h"

namespace Agent {
	Agent::Agent(const GA::Genotype * genotype) {

		this->game = new Two048::Game(4);
		this->genotype = genotype;

		OpenNN::Vector nn_architecture;

		auto layers = (int)genotype->architecture.size();
		for(int i=0;i<layers;i++) {
			nn_architecture.push_back(genotype->architecture[i]);
		}

		this->network = new OpenNN::NeuralNetwork(nn_architecture);
		/*
		 * set other nn settings
		 */
	}

	TrainingResults * train(int epochs) {

		TrainingResults * results = new TrainingResults;

		// train the nn'

		return results;

	}


}