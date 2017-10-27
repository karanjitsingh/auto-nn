//
// Created by kj on 10/26/17.
//

#ifndef AUTO_NN_GA_H
#define AUTO_NN_GA_H

#include "Genotype.h"
#include "../OpenNN/opennn/vector.h"
#include "../Agent/Agent.h"

using namespace std;
using namespace GA;
using namespace Agent;

namespace GA {
	class GA {

	public:

		vector<Agent::Agent *> population;
		int population_size;
		int year;

		GA(int population_size, const Signature &signature);

		void iterate();
	};
}


#endif //AUTO_NN_GA_H
