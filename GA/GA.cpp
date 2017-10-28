//
// Created by kj on 10/26/17.
//

#include "GA.h"

namespace GA {

	GA::GA(int population_size, int mutate_size, int retain_size, const Signature &genotype_signature)
	{
		Genotype * genotype;
		Agent::Agent * agent;

		year = 0;
		this->population_size = population_size;
		this->retain_size = retain_size;
		this->mutate_size = mutate_size;

		for(int i=0;i<population_size;i++) {
			genotype = new Genotype(&genotype_signature);
			agent = new Agent::Agent(genotype);

			genotype->generation = 1;

			this->population.push_back(agent);
		}
	}

	vector<TrainingResult *> * GA::iterate(int epochs) {

		this->year++;

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

		sort(ranking.begin(), ranking.end());

		for(int i=0;i<this->retain_size;i++) {
			agent = population[0];
			population.erase(population.begin());
			next_generation.push_back(agent);
		}

		for(int i=0;i<this->mutate_size;i++) {
			agent = population[0];
			population.erase(population.begin());

			Genotype * mutated_genotype = new Genotype(agent->genotype,true);
			mutated_genotype->generation = this->year + 1;

			Agent::Agent * mutated_agent = new Agent::Agent(mutated_genotype);
			delete agent;

			next_generation.push_back(mutated_agent);
		}

		while(population.size()) {
			agent = population[0];
			delete agent;
		}

		int offspring_length = this->population_size - retain_size - mutate_size;
		int parent_A_index, parent_B_index;
		int alive = retain_size + mutate_size;

		Genotype * offspring_genotype;

		for(int i=0;i<offspring_length;i++) {
			parent_A_index = rand()%alive;
			while((parent_B_index = rand()%alive) != parent_A_index);

			offspring_genotype = new Genotype(next_generation[parent_A_index]->genotype, next_generation[parent_B_index]->genotype);
			offspring_genotype->generation = this->year + 1;

			next_generation.push_back(new Agent::Agent(offspring_genotype));
		}

		this->population = next_generation;

		return results;

	}

}


