#include <iostream>
#include <iomanip>
#include "LinearLayer.h"

LinearLayer::LinearLayer(int in_size, int out_size) : input_size(in_size), output_size(out_size) { //inits and resizes
    bias.resize(out_size, 1.0);
    weights.resize(input_size * output_size, 1.0);
};

vector<double> LinearLayer::forward(const vector<double>& input) const{ //Wx + b function
    vector<double> result(output_size, 0);

    for(int i = 0; i < output_size; i++){
        result[i] = bias[i];
        for(int j = 0; j < input_size; j++){
            result[i] += weights[i * input_size + j] * input[j];
        }
    }
    return result;
};

void LinearLayer::display() const { //linear layer cout
    cout << "LinearLayer expected weight dimensions: " << input_size << " (input) x " << output_size << " (output)" << endl;

    cout << "Bias: ";
    for(int i = 0; i < bias.size(); i++)
        cout << bias[i] << " ";

    cout << "\nFlat weight vector: ";
    for(int i = 0; i < weights.size(); i++)
        cout << weights[i] << " ";
    cout << endl;
};

void LinearLayer::size() const{
    cout << fixed << setprecision(1);
    cout << "LinearLayer – Input size: " << input_size << ", " << "Output size: " << output_size;
};


void LinearLayer::setFlatWeights(const vector<double>& newWeights){ //set module::flatweights
    Module::weights.resize(newWeights.size());

    for(int i = 0; i < newWeights.size(); i++){
        Module::weights[i] = newWeights[i];
    }
};