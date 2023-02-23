#include "main.h"

double frand()
{
    return (2.0*(double)rand()/RAND_MAX)-1.0;
}

Perceptron::Perceptron(int inputs, double bias)
{
    this->bias = bias;
    weights.resize(inputs+1);
    generate(weights.begin(), weights.end(), frand);
}

double Perceptron::run(std::vector<double> x)
{
    x.push_back(bias);
    double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
    return sigmoid(sum);
}

void Perceptron::set_weights(std::vector<double> w_init)
{
    weights = w_init;
}

double Perceptron::sigmoid(double x)
{
    return 1.0/(1.0+exp(-x));
}

int main()
{
    srand(time(NULL));
    rand();

    std::cout << "-----------------" << std::endl;
    std::cout << "AND Gate Example" << std::endl;
    std::cout << "-----------------" << std::endl;

    Perceptron *p = new Perceptron(2);

    p->set_weights({10, 10, -15});

    std::cout << "AND Gate:" << std::endl;
    std::cout <<p->run({0, 0}) << std::endl;
    std::cout <<p->run({0, 1}) << std::endl;
    std::cout <<p->run({1, 0}) << std::endl;
    std::cout <<p->run({1, 1}) << std::endl;

    std::cout << "-----------------" << std::endl;
    std::cout << "OR Gate Example" << std::endl;
    std::cout << "-----------------" << std::endl;

    p->set_weights({15, 15, -10});

    std::cout << "OR Gate:" << std::endl;
    std::cout <<p->run({0, 0}) << std::endl;
    std::cout <<p->run({0, 1}) << std::endl;
    std::cout <<p->run({1, 0}) << std::endl;
    std::cout <<p->run({1, 1}) << std::endl;

    std::cout << "-----------------" << std::endl;
}