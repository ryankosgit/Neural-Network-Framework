//Name: Ryan Baiano
//Class: COP 3330 Session 14
//Due Date: Apr 3


#include "Module.h"
using namespace std;

Module::Module() : weights(1, 1) {};

vector<double> Module::forward(const vector<double>& input) const{ //multiplier

    vector<double> result(input.size(), 0);

    for(int i = 0; i < input.size(); i++)
        result[i] = input[i] * weights[i];

    return result;
};


