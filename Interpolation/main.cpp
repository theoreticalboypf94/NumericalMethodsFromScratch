#include <iostream>
#include "LagrangeInterpolation.h"

typedef  std::vector<std::pair<int,int>> IN;
int main() {
    IN input = {{1,2},{3,4},{5,6}};
    LagrangeInterpolation<int> fun(input);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}