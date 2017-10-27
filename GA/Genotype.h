#ifndef AUTO_NN_GENOTYPE_H
#define AUTO_NN_GENOTYPE_H

#include <iostream>
#include "../OpenNN/opennn/opennn.h"

using namespace std;

namespace GA {
	enum LayerStructure {
		Uniform,
		Decreasing,
		Increasing,
		Random
	};

	struct Signature {
		int minHiddenLayers;
		int maxHiddenLayers;
		int minNeurons;
		int maxNeurons;
		int positiveReward;
		int negativeReward;
		int inputSize;
		int outputSize;
		LayerStructure layerStructure;
	};

	class Genotype {

	private:
		void generateArchitecture();

	public:
		const Signature * signature;

		vector<int> architecture;
		float learningRate;         // eta
		float discountFactor;       // gamma
		int generation;

		// genotype from signature
		Genotype(const Signature *_signature);

		// clone, set cloneWithMutation if you require performing random mutation
		Genotype(const Genotype * A, bool cloneWithMutation = false);

		// crossover
		Genotype(const Genotype * A, const Genotype * B);
	};
}


#endif //AUTO_NN_GENOTYPE_H
