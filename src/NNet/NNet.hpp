#include<vector>
#include<cmath>
using namespace std;
class NNetwork
{
    private:
        int epoches;
        double learning_rate;
        
        double b1,b2,b3;
    public:
        NNetwork(int es,double lr);
        double sigmoid(double x);
        double deriv_sigmoid(double x);
        double forward(vector<double> data);
        void train(vector<vector<double>> data,vector<double> label);
        void predict(vector<vector<double>> test_data,vector<double> test_label);
};
