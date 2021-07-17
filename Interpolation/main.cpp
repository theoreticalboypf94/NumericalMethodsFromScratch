#include <iostream>
#include "LagrangeInterpolation.h"

typedef  std::vector<std::pair<double,double>> IN;
int main() {
    IN input = {{1,2},{3,4},{5,6}};
    LagrangeInterpolation<double> fun(input);
    std::cout << fun.evaluate(3.5);
    return 0;
}