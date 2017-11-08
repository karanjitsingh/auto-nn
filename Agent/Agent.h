#ifndef AUTO_NN_AGENT_H_H
#define AUTO_NN_AGENT_H_H

#include <iostream>
#include <map>
#include <memory>

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

		std::string exec(const char* cmd) {
			std::array<char, 128> buffer;
			std::string result;
			std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
			if (!pipe) throw std::runtime_error("popen() failed!");
			while (!feof(pipe.get())) {
				if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
				result += buffer.data();
			}
			return result;
		}

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