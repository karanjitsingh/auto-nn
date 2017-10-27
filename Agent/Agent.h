#ifndef AUTO_NN_AGENT_H_H
#define AUTO_NN_AGENT_H_H

#include <iostream>
#include "../OpenNN/opennn/opennn.h"
#include "../2048/Two048.h"
#include "../GA/Genotype.h"

namespace Agent {

	class Agent {
	private:

		OpenNN::NeuralNetwork * nn;
		GA::Genotype * genotype;
		Two048::Game * game;

	public:

		// Generate new entity from genotype
		Agent(const GA::Genotype &genotype);

	};
}

#endif //AUTO_NN_AGENT_H_H