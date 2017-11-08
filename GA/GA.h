//
// Created by kj on 10/26/17.
//

#ifndef AUTO_NN_GA_H
#define AUTO_NN_GA_H

#include "Genotype.h"
#include <vector>
#include "../Agent/Agent.h"

using namespace std;
using namespace GA;
using namespace Agent;

namespace GA {

	class GeneticAlgorithm {

	public:

		vector<Agent::Agent *> population;

		// Evolution parameters
		int population_size;
		int mutate_size;
		int retain_size;

		int year;

		GeneticAlgorithm(
				int population_size,
				int retain_size,
				int mutate_size,
				const Signature * genotype_signature
		);

		vector<TrainingResult *> * iterate(int epochs);

		~GeneticAlgorithm() {
			for(int i=0;i<population_size;i++) {
				delete population[i];
			}
		}
	};
}


#endif //AUTO_NN_GA_H
