#include "Genotype.h"

namespace GA {

	void Genotype::generateArchitecture() {

		int layers = rand()%(signature.maxHiddenLayers - signature.minHiddenLayers) + signature.minHiddenLayers;
		int nodes = rand()%(signature.maxNeurons - signature.minNeurons) + signature.minHiddenLayers;

		switch(signature.layerStructure) {
			case Uniform:
				for(int i=0;i<layers;i++)
					architecture.push_back(nodes);
				break;
			case Decreasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes > signature.minNeurons)
						nodes--;
				}
				break;
			case Increasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes < signature.maxNeurons)
						nodes++;
				}
				break;
			case Random:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					nodes = rand() % (signature.maxNeurons - signature.minNeurons) + signature.minHiddenLayers;
				}
				break;
		}
	}

	Genotype::Genotype(Signature *_signature) {

		signature.minHiddenLayers = _signature->minHiddenLayers;
		signature.maxHiddenLayers = _signature->maxHiddenLayers;
		signature.minNeurons = _signature->minNeurons;
		signature.maxNeurons = _signature->maxNeurons;
		signature.positiveReward = _signature->positiveReward;
		signature.negativeReward = _signature->negativeReward;
		signature.inputSize = _signature->inputSize;
		signature.outputSize = _signature->outputSize;
		signature.layerStructure = _signature->layerStructure;

		generateArchitecture();

		learningRate = ((float) (rand() % 100)/ 100);
		discountFactor = ((float) (rand() % 100)/ 100);
	}

	Genotype::Genotype(Genotype * A, bool cloneWithMutation) {

		// Clone genotype
		signature.minHiddenLayers = A->signature.minHiddenLayers;
		signature.maxHiddenLayers = A->signature.maxHiddenLayers;
		signature.minNeurons = A->signature.minNeurons;
		signature.maxNeurons = A->signature.maxNeurons;
		signature.positiveReward = A->signature.positiveReward;
		signature.negativeReward = A->signature.negativeReward;
		signature.inputSize = A->signature.inputSize;
		signature.outputSize = A->signature.outputSize;
		signature.layerStructure = A->signature.layerStructure;

		architecture = A->architecture;	// copies the vector
		learningRate = A->learningRate;
		discountFactor = A->discountFactor;

		if(cloneWithMutation) {		// Add random mutation
			// clone with mutation
		}
	}

	Genotype::Genotype(Genotype * A, Genotype * B) {

		// Perform uniform crossover

		Genotype * parent;



	}
}