//
// Created by alpharius on 13.07.2021.
//

#ifndef INTERPOLATION_LAGRANGEINTERPOLATION_H
#define INTERPOLATION_LAGRANGEINTERPOLATION_H
#include <utility>
#include <vector>

/*
 *  все численные методы должны быть основанны только на ШАБЛОННЫХ КЛАССАХ
 *  во избежение невыносимой дублежки кода.
 *
 *  Обратите внимание я штампую новые проекты на своей локальной машине, по этому везде main.срр
 *  это временное - потом отрефакторим и сделаем все по нормальному
 */

// полиномиальная интерполяция на базе формулы Лагранжа
template<typename T>
class LagrangeInterpolation {
private:
    std::vector<std::pair<T, T>> internal;                       // возможно неэфективно по памяти - нужно прояснить, устойчивы ли входные данные в памяти или они стираются...
                                                                // что точно - так это безопасность и потеряустойчивость.

    T* P_i_j = NULL;                                            // массив под одномерное рекурентное вычисление
    T error;                                                    // накопленная ошибка
    T MAX_error;                                                // выставленная пользователем ошибка
public:
    LagrangeInterpolation(std::vector<std::pair<T, T>>& input);
    //template<class T1> LagrangeInterpolation<T1>(const char* csv_file_location);      // TODO
    ~LagrangeInterpolation() {delete[] P_i_j;}

    T evaluate(T x);
    void set_accessible_error(const T& YOUR_error);             // установка ошибки
    void check_error_good(void);                                // укладываются ли вычисление в установленную ошибку
    T return_error(void);
};


/*
 *  implementation section
 */


template <class C>
LagrangeInterpolation<C>::LagrangeInterpolation(std::vector<std::pair<C, C>> &input) {
    std::copy(input.begin(), input.end(), std::back_inserter(internal));
    P_i_j = new C[internal.size()];
}

template <class C>
C LagrangeInterpolation<C>::evaluate(C x) {
    /* firs initialisation */
    auto n = internal.size();
    for(int i=0; i< n ; ++i)
        P_i_j[i] = internal[i].second;      // y_i

    for(int right_limit = n - 1; right_limit > 0; right_limit--){
        for(int index = 0; index < right_limit; index++){
            P_i_j[index] = P_i_j[index] * (internal[index+1].first - x);
            P_i_j[index] += P_i_j[index+1]*(x - internal[index].first);
            P_i_j[index] /= (internal[index+1].first - internal[index].first);
        }
    }
    return P_i_j[0];
}

#endif //INTERPOLATION_LAGRANGEINTERPOLATION_H
