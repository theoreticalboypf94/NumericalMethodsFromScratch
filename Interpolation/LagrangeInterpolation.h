//
// Created by alpharius on 13.07.2021.
//

#ifndef INTERPOLATION_LAGRANGEINTERPOLATION_H
#define INTERPOLATION_LAGRANGEINTERPOLATION_H
#include <utility>
#include <vector>
#include <fstream>
#include <assert.h>

#ifndef ABS
#define ABS(X) X>0 ? (X) : -(X)
#endif
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
public:
    std::vector<std::pair<T, T>> xyPair;                       // возможно неэфективно по памяти - нужно прояснить, устойчивы ли входные данные в памяти или они стираются...
                                                                // что точно - так это безопасность и потеряустойчивость.

    T* P_i_j = NULL;                                            // массив под одномерное рекурентное вычисление
    T error;                                                    // накопленная ошибка
    T MAX_error;                                                // выставленная пользователем ошибка
public:
    LagrangeInterpolation(std::vector<std::pair<T, T>>& input);
    LagrangeInterpolation(const char* csv_file_location);      // TODO
    ~LagrangeInterpolation() {delete[] P_i_j;}

    T evaluate(T x);
    void set_accessible_error(const T& YOUR_error);             // установка ошибки
    bool check_error_good(void);                                // укладываются ли вычисление в установленную ошибку
    T return_error(void);
};


/*
 *  implementation section
 */


template <class C>
LagrangeInterpolation<C>::LagrangeInterpolation(std::vector<std::pair<C, C>> &input) {
    std::copy(input.begin(), input.end(), std::back_inserter(xyPair));
    P_i_j = new C[xyPair.size()];
}

template <class C>
LagrangeInterpolation<C>::LagrangeInterpolation(const char *csv_file_location) {
    std::ifstream infile(csv_file_location);
    if (!infile.is_open())
        assert("lol" == NULL);
    C first, second;
    while(infile >> first >> second){
        xyPair.push_back({first, second});
    }
    P_i_j = new C[xyPair.size()];
}

template <class C>
C LagrangeInterpolation<C>::evaluate(C x) {
    /* firs initialisation */
    auto n = xyPair.size();
    int k = 2;                              // k - second index - and external counter
    C error_first_term;
    for(int i=0; i< n ; ++i)
        P_i_j[i] = xyPair[i].second;      // y_i

    for(int right = n-1; right > 1; right--){
        int kk = k;
        for(int i=0; i+1<n; i++){
            C left = P_i_j[i] * (xyPair[kk].first - x);
            C right = P_i_j[i+1] * (x - xyPair[i].first);
            C bot = (xyPair[kk].first - xyPair[i].first);
            P_i_j[i] = (left + right) / bot;
            kk++;
        }
        k++;
    }

    error = ABS(error_first_term - P_i_j[0]);

    return P_i_j[0];
}

template <class C>
void LagrangeInterpolation<C>::set_accessible_error(const C &YOUR_error) {
    MAX_error = YOUR_error;
}

template <class C>
bool LagrangeInterpolation<C>::check_error_good() {
    return MAX_error > error;
}

template <class C>
C LagrangeInterpolation<C>::return_error() {
    return error;
}

#undef ABS
#endif //INTERPOLATION_LAGRANGEINTERPOLATION_H
