//
// Created by kj on 10/26/17.
//

#include "GA.h"

namespace GA {

	GA::GA(int population_size, const Signature &signature) {
		Genotype * genotype;
		Agent::Agent * agent;

		year = 0;
		this->population_size = population_size;

		for(int i=0;i<population_size;i++) {
			genotype = new Genotype(&signature);
			agent = new Agent::Agent(genotype);

			genotype->generation = 1;

			this->population.push_back(agent);
		}
	}

	void GA::iterate() {
		// ga algorithm here

		Agent::Agent * agent;

		/*
		 *	map<int,float> ranking;
		 */

		for(int i=0;i<population_size;i++) {
			agent = this->population[i];

			/* remember to set static settings for agent in main
			 *
			 *	python code
			 *
			 *	nn.train(
			 *		verbose=False,
			 *		progress=True,
			 *		save=True,
			 *		maxepochs=20000,
			 *		batch=30,
			 *		replay_size=100000,
			 *		filename=name,
			 *		autosave=100,
			 *		savestats=True,
			 *	)
			 *
			 *	Agent::Agent::TrainingResult * result = agent.train(number of epochs)
			 *
			 *	ranking.push_back(i,result.fitness_score);
			 *
			 */
		}

		/*
		 * sort ranking by fitness
		 *
		 * retain first 25%
		 * mutate next 15%
		 * delete rest 60%
		 * randomly select 8 pairs and perform crossover
		 *
		 */
	}

}


