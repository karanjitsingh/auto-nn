#include <iostream>

#include "../OpenNN/opennn/opennn.h"

using namespace std;

namespace NeuralNetwork {
    struct Genotype {
        const int minHiddenLayers;
        const int maxHiddenLayers;
        const int positiveReward;
        const int negativeReward;

        int hiddenLayers;
        float learningRate;         // eta
        float discountFactor;       // gamma
    };

    class NeuralNetwork {

    };
}