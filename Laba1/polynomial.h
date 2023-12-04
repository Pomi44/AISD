#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

template<typename T>
class Polynomial {
private:
    T* coefficients;
    int degree;

public:
    Polynomial(int degree);
    Polynomial(T* values, int degree);
    ~Polynomial();

    T operator[](int power) const;
    void set(int power, T value);

    Polynomial<T> operator+(const Polynomial<T>& other) const;
    Polynomial<T> operator-(const Polynomial<T>& other) const;
    Polynomial<T> operator*(const T& scalar) const;

    T evaluate(T x) const;

    void shrink_to_fit();
    void expand(int newDegree);
};
#endif 
