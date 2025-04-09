
#include <vector>
#include "Module.h"


class LinearLayer : public Module {
    public:
        LinearLayer(int in_size, int out_size);
        vector<double> forward(const vector<double>& input) const;
        void display() const;
        void size() const;
        void setFlatWeights(const vector<double>& newWeights);
    
    protected:
        int input_size;
        int output_size;
        vector<double> bias;
};