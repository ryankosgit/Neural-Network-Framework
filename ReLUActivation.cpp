
#include <iostream>
#include <iomanip>
#include "ReLUActivation.h"

ReLUActivation::ReLUActivation(double p_s, double n_s) {
    Module::weights[0] = p_s;
    Module::weights[1] = n_s;
};

vector<double> ReLUActivation::forward(const vector<double>& inputs) const{
    vector<double> result(inputs.size(), 0);

    for(int i = 0; i < inputs.size(); i++){ //if positive, multiply by positive var, negative same thing
        if(inputs[i]>=0)
            result[i] = Module::weights[0]*inputs[i];
        else
            result[i] = Module::weights[1]*inputs[i];
    }
    return result;
};

void ReLUActivation::display() const{
    cout << fixed << setprecision(1);
    cout << "\nReLUActivation: slope = " << Module::weights[0] << ", negative slope = " << Module::weights[1];
};

void ReLUActivation::setWeights(const vector<double>& newWeights){ //set new weights
    Module::weights[0] = newWeights[0];
    Module::weights[1] = newWeights[1];
};


