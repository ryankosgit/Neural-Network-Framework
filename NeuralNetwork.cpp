
#include <iostream>
#include <iomanip>
#include "NeuralNetwork.h"


NeuralNetwork::NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size) { // set blocks
    if(num_blocks < 2){
        blocks.push_back(Block(in_size, out_size));
    }
    else{
        blocks.push_back(Block(in_size, hidden_size));
        for(int i = 1; i < num_blocks - 1; i++){
            blocks.push_back(Block(hidden_size,hidden_size));
        }
        blocks.push_back(Block(hidden_size, out_size));
    }
};


vector<double> NeuralNetwork::forward(const vector<double>& input) const{ // forward for all blocks
    vector<double> result = input;

    for(int i = 0; i < blocks.size(); i++){
        result = blocks[i].forward(result);
    }

    return result;
};


void NeuralNetwork::printModel() const{ 
    for(int i = 0 ; i < blocks.size(); i++){
        cout << "\nBlock " << i + 1 << ": " << endl;
        blocks[i].display();
    }
};

void NeuralNetwork::printBlockSizes() const{
    cout << "\n";
    cout << fixed << setprecision(1);
    for(int i = 0; i < blocks.size(); i++){
            cout << "Block " << i + 1 << " size: ";
            blocks[i].size();
            cout << endl;
    }
};


void NeuralNetwork::setBlockWeights(int block_index, const vector<double>& flatWeights){                  
    blocks[block_index].setWeights(flatWeights);

};


void NeuralNetwork::setBlockActivationWeights(int block_index, const vector<double>& actWeights){
    blocks[block_index].setActivationWeights(actWeights);

};

