#include <iostream>
#include "GA/GA.h"

using namespace std;


void print_population(GeneticAlgorithm * ga) {
	for(int i=0;i<ga->population_size;i++) {
		ga->population[i]->genotype->print_architecture();
	}
}

int main() {

	Signature * sign = new Signature;
	sign->min_hidden_layers = 1;
	sign->max_hidden_layers = 3;
	sign->min_neurons = 16;
	sign->max_neurons = 32;
	sign->positive_reward = 1;
	sign->negative_reward = 1;
	sign->input_size = 16;
	sign->output_size = 4;
	sign->layer_structure = Random;

	srand(time(NULL));

	GeneticAlgorithm * ga = new GeneticAlgorithm(20, 5, 5, sign);

	print_population(ga);

	ga->iterate(300);
	cout << endl;

	print_population(ga);


//	auto results = new vector<TrainingResult *>;




	return 0;
}
