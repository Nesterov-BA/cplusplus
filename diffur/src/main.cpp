#include "rungeKutta.hpp"
#include <math.h>

double alpha;
double dx(double x, double y);
inline double dy(double x, double y);

double dx(double x, double y) {
  x = x;
  return y;
}
inline double dy(double x, double y) {
  return /*alpha*/ alpha * (1 - x * x) * y - x;
}

int main(int argc, char **argv) {
  double xStart = 2;
  double yStart = 0;
  double xEnd, yEnd;
  double cycleL, cycleR;
  alpha = 0.1;
  if (argc > 1)
    alpha = atof(argv[1]);
  solutionUpToTime(xStart, yStart, dx, dy, 10, &cycleL, &cycleR, &xEnd, &yEnd);
  findCycle(xStart, yStart, dx, dy, &xEnd, &yEnd);

  return 0;
}
