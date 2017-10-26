//
// Created by kj on 10/26/17.
//

#ifndef AUTO_NN_GA_H
#define AUTO_NN_GA_H

#include "Genotype.h"
#include "../OpenNN/opennn/vector.h"
#include "../NeuralNetwork/NeuralNetwork.h"

using namespace std;
using namespace GA;
using namespace NeuralNetwork;

namespace GA {
	class GA {

	public:

		int year;
		vector<NeuralNetwork::NeuralNetwork *> population;

		GA(int n, Signature &signature);
		void train();
	};
}


#endif //AUTO_NN_GA_H
