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
	sign->max_hidden_layers = 2;
	sign->min_neurons = 16;
	sign->max_neurons = 32;
	sign->positive_reward = 1;
	sign->negative_reward = 1;
	sign->input_size = 16;
	sign->output_size = 4;
	sign->layer_structure = Random;

	srand(time(NULL));

	GeneticAlgorithm * ga = new GeneticAlgorithm(10, 3, 2, sign);


	for(int i=0; i<5; i++) {
		cout << "Year: " << i+1 << endl << endl;
		ga->iterate(3);
		cout << endl << endl;
	}


//	auto results = new vector<TrainingResult *>;




	return 0;
}
