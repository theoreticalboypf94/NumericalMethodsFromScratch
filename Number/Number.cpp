//
// Created by alpharius on 12.07.2021.
//
#include "Number.h"

Number::Number(const Number &original) {
    if (iptr != NULL)
        delete[] iptr;
    iptr = new int[original.precision];
    sign = original.sign;
    power = original.power;
    precision = original.precision;
    for(size_t i=0; i<precision; ++i)
        iptr[i] = original.iptr[i];
}


/* friend */
std::ostream& operator<<(std::ostream& os, const Number& num){
    os << num.sign ;
    for(size_t i=0; i<num.precision; ++i){
        os << num.iptr[i];
        if(i == 0)
            os << '.';
    }
    os << "e" << num.power;
}