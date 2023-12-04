#include <iostream>
#include <random>
#include "polynomial.cc" // Подключаем заголовочный файл с классом Polynomial

int main() {
    // Создание полиномов и проверка основных функций

    // Создание полинома через конструктор
    Polynomial<int> poly1(5);
    poly1.set(5, 3);
    poly1.set(4, 0);
    poly1.set(3, -2);
    poly1.set(2, 0);
    poly1.set(1, 5);
    poly1.set(0, 1);

    std::cout << "Polynomial 1: ";
    poly1.print();

    // Получение значения полинома при заданном x
    int x = 2;
    std::cout << "Value of Polynomial 1 at x = " << x << ": " << poly1.evaluate(x) << std::endl;

    // Создание второго полинома через конструктор
    int values2[] = { 2, 0, -1, 0, 4, 1 };
    Polynomial<int> poly2(values2, 5);

    std::cout << "\nPolynomial 2: ";
    poly2.print();

    // Проверка оператора []
    std::cout << "Coefficient of power 3 in Polynomial 2: " << poly2[3] << std::endl;

    // Сложение полиномов
    Polynomial<int> sum = poly1 + poly2;
    std::cout << "\nSum of Polynomial 1 and Polynomial 2: ";
    sum.print();

    // Вычитание полиномов
    Polynomial<int> diff = poly1 - poly2;
    std::cout << "\nDifference of Polynomial 1 and Polynomial 2: ";
    diff.print();

    // Умножение полинома на скаляр
    Polynomial<int> scalarProduct = poly1 * 3;
    std::cout << "\nScalar Product of Polynomial 1 and 3: ";
    scalarProduct.print();

    // Сравнение полиномов
    std::cout << "\nChecking equality of Polynomial 1 and Polynomial 2: ";
    if (poly1 == poly2) {
        std::cout << "Polynomials are equal." << std::endl;
    }
    else {
        std::cout << "Polynomials are not equal." << std::endl;
    }

    return 0;
}
