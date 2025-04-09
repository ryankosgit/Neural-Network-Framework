
using namespace std;
#include <vector>
#include "Module.h"
#include "ReLUActivation.h"
#include "LinearLayer.h"

class Block{
public:
    Block(int in_size, int out_size);
    vector<double> forward(const vector<double>& input) const;
    void display() const;
    void size() const;
    void setWeights(const vector<double>& flatWeights);
    void setActivationWeights(const vector<double>& actWeights);
protected:
    LinearLayer linear;
    ReLUActivation relu;
};