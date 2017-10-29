//
// Created by kj on 10/26/17.
//

#include "GA.h"

namespace GA {

	Agent::Agent * x;

	GeneticAlgorithm::GeneticAlgorithm(int population_size, int retain_size, int mutate_size, const Signature * genotype_signature)
	{
		Genotype * genotype;
		Agent::Agent * agent;

		year = 0;
		this->population_size = population_size;
		this->retain_size = retain_size;
		this->mutate_size = mutate_size;

		for(int i=0;i<population_size;i++) {
			genotype = new Genotype(genotype_signature);
			agent = new Agent::Agent(genotype);

			if(i==0) {
				x = agent;
			}

			genotype->generation = 1;

			this->population.push_back(agent);
		}
	}

	vector<TrainingResult *> * GeneticAlgorithm::iterate(int epochs) {

		this->year++;

		int k = 0;


		Agent::Agent * agent;
		map<float, int> ranking;
		vector<Agent::Agent *> next_generation;

		auto * results =  new vector<TrainingResult *>;

		for(int i=0;i<population_size;i++) {
			agent = this->population[i];

			Agent::TrainingResult  * result = agent->train(epochs);
			results->push_back(result);

			ranking.insert(pair<float, int>(result->avg_score, i));
		}

		// Remember map is already sorted, just have to use an iterator

		int i=0;
		for (auto it=ranking.begin(); it!=ranking.end(); ++it, i++) {

			agent = population[it->second];

			if(i<retain_size) {
				next_generation.push_back(agent);
			}
			else if(i <retain_size + mutate_size) {
				Genotype * mutated_genotype = new Genotype(agent->genotype,true);

				mutated_genotype->generation = this->year + 1;

				Agent::Agent * mutated_agent = new Agent::Agent(mutated_genotype);

				delete agent;

				next_generation.push_back(mutated_agent);
			}
			else {
				delete agent;
			}
		}

		population.clear();

		int offspring_length = this->population_size - retain_size - mutate_size;
		int parent_A_index, parent_B_index;
		int alive = retain_size + mutate_size;

		Genotype * offspring_genotype;

		for(int i=0;i<offspring_length;i++) {
			parent_A_index = rand()%alive;
			while((parent_B_index = rand()%alive) == parent_A_index);

			offspring_genotype = new Genotype(next_generation[parent_A_index]->genotype, next_generation[parent_B_index]->genotype);
			offspring_genotype->generation = this->year + 1;

			next_generation.push_back(new Agent::Agent(offspring_genotype));
		}

		this->population = next_generation;

		return results;


	}

}


