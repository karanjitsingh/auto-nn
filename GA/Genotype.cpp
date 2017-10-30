#include "iostream"
#include "Genotype.h"

namespace GA {

	void Genotype::print_architecture(bool newline) const{
		auto layers = architecture.size();

		cout << "[";
		for(int j=0;j<layers;j++) {
			cout << architecture[j] << ",";
		}
		cout << "]";

		if(newline) cout << endl;
	}

	void Genotype::generate_architecture() {

		this->architecture.clear();

		int layers = rand()%(signature->max_hidden_layers - signature->min_hidden_layers + 1) + signature->min_hidden_layers;
		int nodes = rand()%(signature->max_neurons - signature->min_neurons + 1) + signature->min_neurons;

		architecture.push_back(signature->input_size);

		switch(signature->layer_structure) {
			case Uniform:
				for(int i=0;i<layers;i++)
					architecture.push_back(nodes);
				break;
			case Decreasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes > signature->min_neurons)
						nodes--;
				}
				break;
			case Increasing:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					if (nodes < signature->max_neurons)
						nodes++;
				}
				break;
			case Random:
				for(int i=0;i<layers;i++) {
					architecture.push_back(nodes);
					nodes = rand() % (signature->max_neurons - signature->min_neurons) + signature->min_neurons;
				}
				break;
		}

		architecture.push_back(signature->output_size);
	}

	Genotype::Genotype(int id, const Signature *_signature) {

		this->id = id;
		this->parent_id = NULL;

		// Generate genotype
		this->signature = _signature;
		generate_architecture();

		learning_rate = ((float) (rand() % 100)/ 100);
		discount_factor = ((float) (rand() % 100)/ 100);
	}

	Genotype::Genotype(int id, const Genotype * A, bool cloneWithMutation) {

		this->id = id;
		this->parent_id = new pair<int,int>(A->id, A->id);

		// Clone genotype
		this->signature = A->signature;
		architecture = A->architecture;	// copies the vector
		learning_rate = A->learning_rate;
		discount_factor = A->discount_factor;

		if(cloneWithMutation) {		// Add random mutation
			int c = rand();
			switch(c%3) {
				case 0:
					learning_rate = (rand() % 100) / 100.0f;
					break;
				case 1:
					discount_factor = (rand() % 100) / 100.0f;
					break;
				case 2:
					generate_architecture();
 					break;
			}
		}
	}

	Genotype::Genotype(int id, const Genotype * parentA, const Genotype * parentB) {

		this->id = id;
		this->parent_id = new pair<int, int>(parentA->id, parentB->id);

		// Perform uniform crossover A -> C <- B
		// parentA->signature is same as parentB->signature
		this->signature = parentA->signature;

		// Arrange A and B such that layers_A <= layers_B
		const Genotype * A = parentA->architecture.size() <= parentB->architecture.size() ? parentA : parentB;
		const Genotype * B = A == parentA ? parentB : parentA;

		int layers_A = (int)A->architecture.size() - 2;		// count for hidden layers only
		int layers_B = (int)B->architecture.size() - 2;		// count for hidden layers only


		// Add (layers_A + layers_B)%2 term to add ceil to integer division
		int layers_C = (layers_A + layers_B)/2 + (layers_A + layers_B)%2;

		architecture.push_back(signature->input_size);

		for(int i=0;i<layers_C;i++) {

			int avg_neurons=0;

			// layers_A <= layers_C since C is an average of A and B
			// each layer of C will map to at most one layer in A
			int layerAIndex = i*layers_A/layers_C;

			avg_neurons += A->architecture.at(layerAIndex + 1);

			// layers_B >= layers_C
			// each layer of C may map to one or more layers in B
			int start = i*layers_B/layers_C;
			int end = (i+1)*layers_B/layers_C;

			for(int j=start; j<end; j++) {
				avg_neurons += B->architecture.at(j + 1);
			}

			avg_neurons /= (end - start + 1);	// number of layers mapped in B + 1 layer mapped in A
			avg_neurons += (end - start + 1)%2;	// ceil

			this->architecture.push_back(avg_neurons);
		}

		// take average of float parameters
		learning_rate = (A->learning_rate + B->learning_rate)/2;
		discount_factor = (A->discount_factor + B->discount_factor)/2;

		architecture.push_back(signature->output_size);

	}
}