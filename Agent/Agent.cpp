#include "Agent.h"

namespace Agent {
	Agent::Agent(const GA::Genotype &genotype) {

		this->game = new Two048::Game(4);
//        this->genotype.minHiddenLayers = genotype.minHiddenLayers;
//        this->genotype.maxHiddenLayers = genotype.maxHiddenLayers;
//        vector<unsigned> architecture = {1,2,3,4};
//        nn = new OpenNN::NeuralNetwork(&architecture);
	}
}