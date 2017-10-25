//
// Created by kj on 10/25/17.
//

#ifndef AUTO_NN_GA_H
#define AUTO_NN_GA_H

#include <iostream>
#include "../OpenNN/opennn/opennn.h"

using namespace std;

namespace GA {
    enum LayerStructure {Uniform, Decreasing, Increasing} ;
    struct Signature {
        int minHiddenLayers;
        int maxHiddenLayers;
        int minNeurons;
        int maxNeurons;
        int positiveReward;
        int negativeReward;
        int inputSize;
        int outputSize;
        LayerStructure layerStructure;
    };

    class Genotype {

public:
    Signature signature;
    vector<int> architecture;
    float learningRate;         // eta
    float discountFactor;       // gamma
    int generation;

    // genotype from signature
    Genotype(Signature *_signature);

    // clone, set cloneWithMutation if you require performing random mutation
    Genotype(Genotype * A, bool cloneWithMutation = false);

    // crossover
    Genotype(Genotype * A, Genotype * B);
};
}


#endif //AUTO_NN_GA_H
