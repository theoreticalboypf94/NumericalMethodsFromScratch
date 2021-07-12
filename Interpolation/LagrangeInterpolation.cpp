//
// Created by alpharius on 13.07.2021.
//
#include "LagrangeInterpolation.h"

template <class C>
LagrangeInterpolation<C>::LagrangeInterpolation(std::vector<std::pair<C, C>> &input) {
    std::copy(input.begin(), input.end(), std::back_inserter(interal));
}

