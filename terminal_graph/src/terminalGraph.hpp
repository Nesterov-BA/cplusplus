#include <bits/types/FILE.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

void graph(std::vector<double> x_const, std::vector<double> y_const);
void printVector(std::vector<double> x);
double vecMin(std::vector<double> x);
double vecMax(std::vector<double> x);

std::vector<double> scale_vector(std::vector<double> x_const, double min,
                                 double max);
void plot_function(double func(double), double min, double max);
