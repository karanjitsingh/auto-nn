#include "GA.h"

namespace GA {

	Genotype::Genotype(Signature *_signature) {

		this->signature.minHiddenLayers = _signature->minHiddenLayers;
		this->signature.maxHiddenLayers = _signature->maxHiddenLayers;
		this->signature.minNeurons = _signature->minNeurons;
		this->signature.maxNeurons = _signature->maxNeurons;
		this->signature.positiveReward = _signature->positiveReward;
		this->signature.negativeReward = _signature->negativeReward;
		this->signature.inputSize = _signature->inputSize;
		this->signature.outputSize = _signature->outputSize;
		this->signature.layerStructure = _signature->layerStructure;

		int layers = rand()%(this->signature.maxHiddenLayers - this->signature.minHiddenLayers + 1) + 1;
		int nodes = rand()%(this->signature.maxNeurons - this->signature.minNeurons + 1) + 1;

		this->generation = 0;

		vector<int> architecture;

		for(int i=0;i<layers;i++) {
			architecture.push_back(nodes);
			switch(signature.layerStructure) {
				case Uniform:
					break;
				case Decreasing:
					if(nodes > signature.minNeurons)
						nodes--;
					break;
				case Increasing:
					if(nodes < signature.maxNeurons)
						nodes++;
					break;
			}
		}

		learningRate = ((float) (rand() % 100)/ 100);
		discountFactor = ((float) (rand() % 100)/ 100);
	}

	// clone, set cloneWithMutation if you require performing random mutation
	Genotype::Genotype(Genotype * A, bool cloneWithMutation) {
		this->signature.minHiddenLayers = A->signature.minHiddenLayers;
		this->signature.maxHiddenLayers = A->signature.maxHiddenLayers;
		this->signature.minNeurons = A->signature.minNeurons;
		this->signature.maxNeurons = A->signature.maxNeurons;
		this->signature.positiveReward = A->signature.positiveReward;
		this->signature.negativeReward = A->signature.negativeReward;
		this->signature.inputSize = A->signature.inputSize;
		this->signature.outputSize = A->signature.outputSize;
		this->signature.layerStructure = A->signature.layerStructure;

		this->architecture = A->architecture;
		learningRate = A->learningRate;
		discountFactor = A->discountFactor;

		this->generation++;


		if(cloneWithMutation) {
			// clone with mutation
		}
	}

	// crossover
	Genotype::Genotype(Genotype * A, Genotype * B) {
		this->generation ++;

		//
	}
}