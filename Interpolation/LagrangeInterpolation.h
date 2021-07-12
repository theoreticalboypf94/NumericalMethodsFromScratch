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
    std::vector<std::pair<T, T>> interal;                       // возможно неэфективно по памяти - нужно прояснить, устойчивы ли входные данные в памяти или они стираются...
                                                                // что точно - так это безопасность и потеряустойчивость.

    T* P_i_j = NULL;                                            // массив под одномерное рекурентное вычисление
    T error;                                                    // накопленная ошибка
    T MAX_error;                                                // выставленная пользователем ошибка
public:
    //template<class T1> LagrangeInterpolation(std::vector<std::pair<T1, T1>>& input);
    LagrangeInterpolation(std::vector<std::pair<T, T>>& input);
    //template<class T1> LagrangeInterpolation<T1>(const char* csv_file_location);

    T evaluate(T x);
    void set_accessible_error(const T& YOUR_error);             // установка ошибки
    void check_error_good(void);                                // укладываются ли вычисление в установленную ошибку
    T return_error(void);
};


#endif //INTERPOLATION_LAGRANGEINTERPOLATION_H
