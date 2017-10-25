#include <iostream>
#include "../OpenNN/opennn/opennn.h"
#include "../2048/Two048.h"
#include "../GA/GA.h"

using namespace std;

namespace NeuralNetwork {

    class NeuralNetwork {
    private:

        int minHiddenLayers;
        int maxHiddenLayers;
        int positiveReward;
        int negativeReward;
        int inputSize;
        int outPutSize;

        OpenNN::NeuralNetwork * nn;
        GA::Genotype * genotype;

        Two048::Game * game;

    public:

        // Generate new entity from genotype
        NeuralNetwork(const int &Genotype) {


            this->game = new Two048::Game(4);
//            this->genotype.minHiddenLayers = genotype.minHiddenLayers;
//            this->genotype.maxHiddenLayers = genotype.maxHiddenLayers;
//



//            vector<unsigned> architecture = {1,2,3,4};
//            nn = new OpenNN::NeuralNetwork(&architecture);

        }

    };
}