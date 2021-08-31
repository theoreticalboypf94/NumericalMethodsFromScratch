#include <iostream>
#include "LagrangeInterpolation.h"
#include <math.h>

typedef  std::vector<std::pair<double,double>> IN;
int main() {
//    IN input = {{1,2},{3,4},{5,6}};
//    LagrangeInterpolation<double> fun(input);
    LagrangeInterpolation<double> fun("/home/alpharius/Git/NumericalMethodsFromScratch/Interpolation/sin.txt");
    double x = 0;
    for(double dx = 0.01; x < 2; x+=dx)
        std::cout << x << " " << fun.evaluate(x) << " " << sin(x) << std::endl;
    return 0;
}