#include "terminalGraph.hpp"
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>

double square(double x);
double square(double x) { return x * x; }
double standart_dev(double x) { return pow(std::exp(1), -(x * x)); }

int main() {
  std::vector<double> x = {1, 2, 3, 4};
  std::vector<double> y = {4, 3, 2, 1};
  std::vector<double> scaled_x = scale_vector(x, 0, 1);
  printVector(scaled_x);

  std::ifstream file("data.csv"); // Open the file
  std::vector<std::vector<double>> data;
  std::string line;
  std::getline(file, line);
  // Read file line-by-line
  while (std::getline(file, line)) {
    std::vector<double> row;
    std::stringstream ss(line);
    std::string cell;

    // Split line by commas
    while (std::getline(ss, cell, ',')) {
      row.push_back(std::stod(cell));
    }

    data.push_back(row);
  }
  file.close();
  std::vector<double> x_1;
  std::vector<double> y_1;
  std::vector<double> t;
  // Print out the data to verify
  for (const auto &row : data) {
    x_1.push_back(row[0]);
    y_1.push_back(row[1]);
    t.push_back(row[2]);
  }
  // Read line by line until the end of the file
  // graph(x_1, y_1);
  // graph(t, x_1);
  // graph(t, y_1);
  plot_function(sin, -6, 6);
  plot_function(std::sqrt, 0, 8);
  plot_function(standart_dev, -2, 2);
}
