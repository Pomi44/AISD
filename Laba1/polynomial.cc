#include <iostream>
#include <stdexcept>
#include <cmath>
#include <random>

template <typename T>
class Polynomial {
private:
    T* coefficients;
    int degree;
    static constexpr double epsilon = 1e-10;

public:
    Polynomial(int degree) : degree(degree) {
        coefficients = new T[degree + 1]();
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = T(1);
        }
    }

    Polynomial(T* values, int degree) : degree(degree) {
        coefficients = new T[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = values[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    T operator[](int power) const {
        if (power < 0 || power > degree) {
            throw std::out_of_range("Index out of range");
        }
        return coefficients[power];
    }

    void set(int power, T value) {
        if (power >= 0) {
            if (power > degree) {
                T* newCoefficients = new T[power + 1]();
                std::copy(coefficients, coefficients + degree + 1, newCoefficients);
                delete[] coefficients;
                coefficients = newCoefficients;
                degree = power;
            }
            coefficients[power] = value;
        }
        else {
            throw std::invalid_argument("Negative power");
        }
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        int maxSize = std::max(degree, other.degree);
        Polynomial<T> result(maxSize);
        for (int i = 0; i <= maxSize; ++i) {
            result.set(i, (*this)[i] + other[i]);
        }
        return result;
    }

    Polynomial<T> operator-(const Polynomial<T>& other) const {
        int maxSize = std::max(degree, other.degree);
        Polynomial<T> result(maxSize);
        for (int i = 0; i <= maxSize; ++i) {
            result.set(i, (*this)[i] - other[i]);
        }
        return result;
    }

    Polynomial<T> operator*(const T& scalar) const {
        Polynomial<T> result(degree);
        for (int i = 0; i <= degree; ++i) {
            result.set(i, coefficients[i] * scalar);
        }
        return result;
    }

    int get_degree() const {
        return degree;
    }

    T* get_coefficients() const {
        T* coefficients_copy = new T[degree + 1];
        std::copy(coefficients, coefficients + degree + 1, coefficients_copy);
        return coefficients_copy;
    }

    T evaluate(T x) const {
        T result = T();
        T powerX = 1;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * powerX;
            powerX *= x;
        }
        return result;
    }

    void shrink_to_fit() {
        while (degree > 0 && coefficients[degree] == T()) {
            --degree;
        }
        T* newCoefficients = new T[degree + 1];
        std::copy(coefficients, coefficients + degree + 1, newCoefficients);
        delete[] coefficients;
        coefficients = newCoefficients;
    }

    void expand(int newDegree) {
        if (newDegree > degree) {
            T* newCoefficients = new T[newDegree + 1]();
            std::copy(coefficients, coefficients + degree + 1, newCoefficients);
            delete[] coefficients;
            coefficients = newCoefficients;
            degree = newDegree;
        }
    }

    bool operator==(const Polynomial<T>& other) const {
        if (degree != other.degree) {
            return false;
        }
        for (int i = 0; i <= degree; ++i) {
            if (std::abs(coefficients[i] - other.coefficients[i]) > epsilon) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Polynomial<T>& other) const {
        return !(*this == other);
    }

    void print() const {
        bool firstTerm = true;
        for (int i = degree; i >= 0; --i) {
            if (coefficients[i] != T()) {
                if (!firstTerm) {
                    std::cout << " + ";
                }
                if (i == 0 || coefficients[i] != T(1)) {
                    std::cout << coefficients[i];
                }
                if (i > 0) {
                    std::cout << "x";
                    if (i > 1) {
                        std::cout << "^" << i;
                    }
                }
                firstTerm = false;
            }
        }
        std::cout << std::endl;
    }
};

template <typename T>
Polynomial<T> integratePolynomial(const Polynomial<T>& poly) {
    int degree = poly.get_degree() + 1;
    Polynomial<T> integral(degree);

    for (int i = degree - 1; i >= 0; --i) {
        integral.set(i + 1, poly[i] / static_cast<T>(i + 1));
    }

    return integral;
}
