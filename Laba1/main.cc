#include <iostream>
#include "polynomial.cc"

int main() {
    Polynomial<int> poly1(5);
    poly1.set(5, 3);
    poly1.set(4, 0);
    poly1.set(3, -2);
    poly1.set(2, 0);
    poly1.set(1, 5);
    poly1.set(0, 1);

    std::cout << "Polynomial 1: ";
    poly1.print();

    int x = 2;
    std::cout << "Value of Polynomial 1 at x = " << x << ": " << poly1.evaluate(x) << std::endl;

    int values2[] = { 2, 0, -1, 0, 4, 1 };
    Polynomial<int> poly2(values2, 5);

    std::cout << "\nPolynomial 2: ";
    poly2.print();

    std::cout << "Coefficient of power 0 in Polynomial 2: " << poly2[0] << std::endl;

    Polynomial<int> sum = poly1 + poly2;
    std::cout << "\nSum of Polynomial 1 and Polynomial 2: ";
    sum.print();

    Polynomial<int> diff = poly1 - poly2;
    std::cout << "\nDifference of Polynomial 1 and Polynomial 2: ";
    diff.print();

    Polynomial<int> scalarProduct = poly1 * 3;
    std::cout << "\nScalar Product of Polynomial 1 and 3: ";
    scalarProduct.print();

    std::cout << "\nChecking equality of Polynomial 1 and Polynomial 2: ";
    if (poly1 == poly2) {
        std::cout << "Polynomials are equal." << std::endl;
    }
    else {
        std::cout << "Polynomials are not equal." << std::endl;
    }

    Polynomial<double> poly(3);
    poly.set(3, 2.0);
    poly.set(2, -1.0);
    poly.set(1, 3.0);
    poly.set(0, 4.0);

    std::cout << "Original Polynomial: ";
    poly.print();

    Polynomial<double> integral = integratePolynomial(poly);

    std::cout << "\nIntegral of Polynomial: ";
    integral.print();

    return 0;
}
