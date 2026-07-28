#include "terminalGraph.hpp"
#include <cstdio>
#include <string>
#include <vector>

double vecMin(std::vector<double> x) {
  int lenX = x.size();
  double res = x[0];
  for (int i = 1; i < lenX; i++) {
    if (x[i] < res)
      res = x[i];
  }
  return res;
}
double vecMax(std::vector<double> x) {
  int lenX = x.size();
  double res = x[0];
  for (int i = 1; i < lenX; i++) {
    if (x[i] > res)
      res = x[i];
  }
  return res;
}

std::vector<double> scale_vector(std::vector<double> x_const, double min,
                                 double max) {
  std::vector<double> x(x_const);
  int lenX = x.size();
  double xMin = vecMin(x);
  double xMax = vecMax(x);
  if (xMax - xMin < 1.e-9) {
    for (int i = 0; i < lenX; i++) {
      x[i] = min;
    }
  } else {

    for (int i = 0; i < lenX; i++) {
      x[i] = (x[i] - xMin) / (xMax - xMin);
      x[i] = x[i] * (max - min) + min;
    }
  }
  return x;
}

void printVector(std::vector<double> x) {

  std::cout << "< ";
  for (double element : x) {
    std::cout << element << " ";
  }
  std::cout << ">\n";
}
void graph(std::vector<double> x_const, std::vector<double> y_const) {

  int width = 80;
  int height = 30;
  std::vector<double> x = scale_vector(x_const, 0, width - 1);
  std::vector<double> y = scale_vector(y_const, 0, height - 1);
  int lenX = x.size();
  std::vector<std::string> graph_str;

  std::cout << "^\n";
  for (int i = 0; i < height; i++) {
    std::string temp = std::string(width + 1, ' ');
    temp[0] = '|';
    graph_str.push_back(temp);
  }
  for (int i = 0; i < lenX; i++) {

    int tempX = static_cast<int>(x[i]);
    int tempY = height - 1 - static_cast<int>(y[i]);
    // printf("%f, %f \n", x[i], y[i]);
    // printf("%d, %d \n", tempX, tempY);
    if (graph_str[tempY][tempX + 1] == '.') {
      graph_str[tempY][tempX + 1] = '*';
    } else {
      graph_str[tempY][tempX + 1] = '.';
    }
  }
  for (int i = 2; i < width - 1; i++) {
    for (int j = 2; j < height - 1; j++) {
      if (graph_str[j][i] != ' ') {
        if (graph_str[j + 1][i] != ' ' && graph_str[j - 1][i] != ' ') {
          graph_str[j][i] = '|';

        } else if (graph_str[j][i - 1] != ' ' && graph_str[j][i + 1] != ' ') {
          graph_str[j][i] = '_';
        } else if (graph_str[j - 1][i] != ' ' && graph_str[j][i + 1] != ' ') {
          graph_str[j][i] = 'L';
        } else if (graph_str[j + 1][i] != ' ' &&
                   graph_str[j - 1][i + 1] != ' ') {
          graph_str[j][i] = '/';
        } else if (graph_str[j + 1][i] != ' ' &&
                   graph_str[j - 1][i - 1] != ' ') {
          graph_str[j][i] = '\\';
        }
      }
    }
  }
  for (std::string str : graph_str) {
    std::cout << str << "\n";
  }
  char A = '-';
  std::string str(width, A);
  std::cout << str << ">\n";
}

void plot_function(double func(double), double min, double max) {
  std::vector<double> x;
  std::vector<double> y;
  for (int i = 0; i < 1000; i++) {
    double t = min + i * (max - min) / 999;
    x.push_back(t);
    y.push_back(func(t));
  }
  graph(x, y);
}
