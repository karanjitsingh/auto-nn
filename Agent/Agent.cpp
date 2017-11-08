#include "Agent.h"

namespace Agent {
	Agent::Agent(const GA::Genotype * genotype) {


		this->genotype = genotype;

	}

	TrainingResult * Agent::train(int epochs) {

		TrainingResult * results = new TrainingResult;

		string architecture = "";

		architecture += "[";

		for(int i=0;i<this->genotype->architecture.size();i++) {
			if(i)
				architecture+=",";
			architecture += to_string(this->genotype->architecture[i]);
		}

		architecture += "]";

		string l =to_string(this->genotype->learning_rate);
		string d =to_string(this->genotype->discount_factor);
		string e = to_string(epochs);

		cout << this->genotype->generation << "\t";
		this->genotype->print_architecture(false);
		cout << "\t" << this->genotype->discount_factor << "\t" << this->genotype->learning_rate << "\tFitness: ";

		string command = "python ./py2048/TFNeuralNetwork.py " + architecture + " " + l + " " + d + " " + e;
		string val = this->exec(command.c_str());
		cout << val;

		results->avg_score = atof(val.c_str());



		return results;

	}


}