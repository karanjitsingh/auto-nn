#ifndef AUTO_NN_AGENT_H_H
#define AUTO_NN_AGENT_H_H

#include <iostream>
#include "../OpenNN/opennn/opennn.h"
#include "../2048/Two048.h"
#include "../GA/Genotype.h"

using namespace std;

namespace Agent {

	struct TrainingResult {
		int total_games;
		map<int, int> maxTileCount;	// <tile, count>
		float avg_score;
		int min_score;
		int max_score;
		float avg_invalid;
		float avg_steps;
		string datetime;
	};

	class Agent {
	private:

		OpenNN::NeuralNetwork * network;
		Two048::Game * game;

	public:

		const GA::Genotype * genotype;

		// Generate new entity from genotype
		explicit Agent(const GA::Genotype * genotype);

		~Agent() {
//			delete network;
			delete genotype;
//			delete game;
		}

		TrainingResult * train(int epochs);


	};
}

#endif //AUTO_NN_AGENT_H_H