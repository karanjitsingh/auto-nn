#ifndef AUTO_NN_NN_H_H
#define AUTO_NN_NN_H_H

#include <iostream>
#include "../OpenNN/opennn/opennn.h"
#include "../2048/Two048.h"
#include "../GA/GA.h"

using namespace std;

namespace NeuralNetwork {

	class NeuralNetwork {
	private:

		int minHiddenLayers;
		int maxHiddenLayers;
		int positiveReward;
		int negativeReward;
		int inputSize;
		int outPutSize;

		OpenNN::NeuralNetwork * nn;
		GA::Genotype * genotype;

		Two048::Game * game;

	public:

		// Generate new entity from genotype
		NeuralNetwork(const int &Genotype);

	};
}

#endif //AUTO_NN_NN_H_H