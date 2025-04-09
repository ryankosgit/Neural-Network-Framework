
#include <iostream>
#include "Block.h"

Block::Block(int in_size, int out_size) : linear(in_size, out_size), relu() {};


vector<double> Block::forward(const vector<double>& input) const{
    vector<double> result;
    result = linear.forward(input);
    result = relu.forward(result);

    return result;
};

void Block::display() const{

    linear.display();
    relu.display();
    cout << "\n------------------------------";

};

void Block::size() const{

    linear.size();
    cout << endl;

};

void Block::setWeights(const vector<double>& flatWeights){
        linear.setFlatWeights(flatWeights);
};

void Block::setActivationWeights(const vector<double>& setActivationWeights){
    relu.setWeights(setActivationWeights);
};