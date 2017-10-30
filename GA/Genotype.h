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
		int min_hidden_layers;
		int max_hidden_layers;
		int min_neurons;
		int max_neurons;
		int positive_reward;
		int negative_reward;
		int input_size;
		int output_size;
		LayerStructure layer_structure;
	};

	class Genotype {

	private:
		void generate_architecture();

	public:
		const Signature * signature;

		vector<int> architecture;
		float learning_rate;         // eta
		float discount_factor;       // gamma
		int generation;
		int id;
		std::pair<int,int> * parent_id;

		void print_architecture(bool newline = true) const;

		// genotype from signature
		Genotype(int id, const Signature *_signature);

		// clone, set cloneWithMutation if you require performing random mutation
		Genotype(int id, const Genotype * A, bool cloneWithMutation = false);

		// crossover
		Genotype(int id, const Genotype * A, const Genotype * B);

		~Genotype() {
			delete parent_id;
		}
	};
}


#endif //AUTO_NN_GENOTYPE_H
