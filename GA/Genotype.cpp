#include "Genotype.h"

namespace GA {

	void Genotype::generateArchitecture() {

		this->architecture.clear();

		int layers = rand()%(signature->maxHiddenLayers - signature->minHiddenLayers) + signature->minHiddenLayers;
		int nodes = rand()%(signature->maxNeurons - signature->minNeurons) + signature->minHiddenLayers;

		architecture.push_back(signature->inputSize);

		switch(signature->layerStructure) {
			case Uniform:
				for(int i=0;i<layers;i++)
					architecture.push_back(nodes);
				break;
			case Decreasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes > signature->minNeurons)
						nodes--;
				}
				break;
			case Increasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes < signature->maxNeurons)
						nodes++;
				}
				break;
			case Random:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					nodes = rand() % (signature->maxNeurons - signature->minNeurons) + signature->minHiddenLayers;
				}
				break;
		}

		architecture.push_back(signature->outputSize);
	}

	Genotype::Genotype(const Signature *_signature) {

		// Generate genotype
		this->signature = _signature;
		generateArchitecture();

		learningRate = ((float) (rand() % 100)/ 100);
		discountFactor = ((float) (rand() % 100)/ 100);
	}

	Genotype::Genotype(const Genotype * A, bool cloneWithMutation) {

		// Clone genotype
		this->signature = A->signature;
		architecture = A->architecture;	// copies the vector
		learningRate = A->learningRate;
		discountFactor = A->discountFactor;

		if(cloneWithMutation) {		// Add random mutation
			switch(rand()%3) {
				case 0:
					learningRate = float((rand() * 100) / 1000);
					break;
				case 1:
					discountFactor = float((rand() * 100) / 1000);
					break;
				case 2:
					generateArchitecture();
					break;
			}
		}
	}

	Genotype::Genotype(const Genotype * parentA, const Genotype * parentB) {

		// Perform uniform crossover A -> C <- B

		// Arrange A and B such that layers_A <= layers_B
		const Genotype * A = parentA->architecture.size() <= parentB->architecture.size() ? parentA : parentB;
		const Genotype * B = A == parentA ? parentB : parentA;

		int layers_A = (int)A->architecture.size() - 2;		// count for hidden layers only
		int layers_B = (int)B->architecture.size() - 2;		// count for hidden layers only


		// Add (layers_A + layers_B)%2 term to add ceil to integer division
		int layers_C = (layers_A + layers_B)/2 + (layers_A + layers_B)%2;

		architecture.push_back(signature->inputSize);

		for(int i=0;i<layers_C;i++) {

			int avg_neurons=0;

			// layers_A <= layers_C since C is an average of A and B
			// each layer of C will map to at most one layer in A
			int layerAIndex = i*layers_A/layers_C;

			avg_neurons += A->architecture.at(layerAIndex);

			// layers_B >= layers_C
			// each layer of C may map to one or more layers in B
			int start = i*layers_B/layers_C;
			int end = (i+1)*layers_B/layers_C;

			for(int j=start; j<end; j++) {
				avg_neurons += B->architecture.at(j);
			}

			avg_neurons /= (end - start + 1);	// number of layers mapped in B + 1 layer mapped in A
			avg_neurons += (end - start + 1)%2;	// ceil

			this->architecture.push_back(avg_neurons);
		}

		// take average of float parameters
		learningRate = (A->learningRate + B->learningRate)/2;
		discountFactor = (A->discountFactor + B->discountFactor)/2;

		architecture.push_back(signature->outputSize);
	}
}