//
// Created by alpharius on 12.07.2021.
//

#ifndef NUMBER_NUMBER_H
#define NUMBER_NUMBER_H

#include <cstdint>
#include <cstdio>
#include <string>
#include <iostream>

/*
 *      в общем начинаю набрасывать - просьба везде делать все виды конструкторов
 *      копирования и move конструкторы
 *      malloc & free - не используйте (если не оговорено обратного)
 *
 *      пишу так, чтобы утечек не было, но потом нужен ответственный, кто будет настраивать санитайзер мемори лиак
 */

class Number{
private:
    int* iptr = NULL ;
    uint16_t precision = 0;
    int64_t power = 0;

    // service functions
    bool check_cells(void);                           // проверка перегрузки ячеек
    void overload_cells(void);                        // перенос перегруженного разряда на более высокий
public:
    char sign = '+';

    /* constructors */
    Number(uint16_t _precision) {precision = _precision; iptr = new int[precision];}
    Number(const Number& original);          //+
    Number(const Number&& moved_rval);      // TODO
    // реализуем позже
    Number(int int_to_Number);              // TODO
    Number(double double_to_Number);        // TODO
    Number(std::string string_to_Number);   // реализую конечным автоматом - прототип есть
    ~Number() {delete[] iptr;}

    /* operatorst */
    Number operator+ (const Number& other);
    Number operator- (const Number& other);
    Number operator* (const Number& other);
    Number operator/ (const Number& other);

    Number operator^ (const double power);
    int operator[] (size_t index);              // доступ к элементу

    friend std::ostream& operator<<(std::ostream& os, const Number& num);


    /* friend functions */
    friend Number sqrt(const Number& root);
    friend void DebugInfo(const Number& num);
};

#endif //NUMBER_NUMBER_H
