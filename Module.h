//Name: Ryan Baiano
//Class: COP 3330 Session 14
//Due Date: Apr 3

#include <vector>
using namespace std;
#ifndef _Module_h_
#define _Module_h_

class Module {
public:
    Module();
    vector<double> forward(const vector<double>& input) const;
protected:
    vector<double> weights;  // flat weight vector  
};

#endif