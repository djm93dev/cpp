#include "main.h"

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}


// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(int inputs, double bias){
	this->bias = bias;
	weights.resize(inputs+1);
	generate(weights.begin(),weights.end(),frand);
}

// Run the perceptron. x is a std::vector with the input values.
double Perceptron::run(std::vector<double> x){
	x.push_back(bias);
	double sum = inner_product(x.begin(),x.end(),weights.begin(),(double)0.0);
	return sigmoid(sum);
}

// Set the weights. w_init is a std::vector with the weights.
void Perceptron::set_weights(std::vector<double> w_init){
	weights = w_init;
}

// Evaluate the sigmoid function for the floating point input x.
double Perceptron::sigmoid(double x){
	return 1.0/(1.0 + exp(-x));
}


// Return a new MultiLayerPerceptron object with the specified parameters.
MultiLayerPerceptron::MultiLayerPerceptron(std::vector<int> layers, double bias, double eta) {
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;

    for (int i = 0; i < layers.size(); i++){
        values.push_back(std::vector<double>(layers[i],0.0));
        network.push_back(std::vector<Perceptron>());
        if (i > 0)   //network[0] is the input layer,so it has no neurons
            for (int j = 0; j < layers[i]; j++)
                network[i].push_back(Perceptron(layers[i-1], bias));
    }
}


// Set the weights. w_init is a std::vector of std::vectors of std::vectors with the weights for all but the input layer.
void MultiLayerPerceptron::set_weights(std::vector<std::vector<std::vector<double> > > w_init) {
    for (int i = 0; i< w_init.size(); i++)
        for (int j = 0; j < w_init[i].size(); j++)
            network[i+1][j].set_weights(w_init[i][j]);
}

void MultiLayerPerceptron::print_weights() {
    std::cout << std::endl;
    for (int i = 1; i < network.size(); i++){
        for (int j = 0; j < layers[i]; j++) {
            std::cout << "Layer " << i+1 << " Neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                std::cout << it <<"   ";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Feed a sample x into the MultiLayer Perceptron.
std::vector<double> MultiLayerPerceptron::run(std::vector<double> x) {
    values[0] = x;
    for (int i = 1; i < network.size(); i++)
        for (int j = 0; j < layers[i]; j++)
            values[i][j] = network[i][j].run(values[i-1]);
    return values.back();
}

int main() {
    srand(time(NULL));
    rand();


    std::cout << "\n\n--------Logic Gate Example----------------\n\n";
    Perceptron *p = new Perceptron(2);

    //{10,10,-15} #AND
    //{15,15,-10}  #OR
    //{-15,-15,10}  #NOR
    //{-10,-10,15} #NAND

    p->set_weights({15,15,-10});

    std::cout << "Gate: "<<std::endl;
    std::cout<<p->run({0,0})<<std::endl;
    std::cout<<p->run({0,1})<<std::endl;
    std::cout<<p->run({1,0})<<std::endl;
    std::cout<<p->run({1,1})<<std::endl;

    std::cout<<"\n\n--------Hardcoded XOR Example----------------\n\n";
    MultiLayerPerceptron mlp = MultiLayerPerceptron({2,2,1});  //mlp
    mlp.set_weights({{{-10,-10,15},{15,15,-10}}, {{10,10,-15}}});
    std::cout << "Hard-coded weights:\n";
    mlp.print_weights();

    std::cout<<"XOR:"<<std::endl;
    std::cout<<"0 0 = "<<mlp.run({0,0})[0]<<std::endl;
    std::cout<<"0 1 = "<<mlp.run({0,1})[0]<<std::endl;
    std::cout<<"1 0 = "<<mlp.run({1,0})[0]<<std::endl;
    std::cout<<"1 1 = "<<mlp.run({1,1})[0]<<std::endl;


}


