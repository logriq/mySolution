#include <iostream>
#include "Matrix.h"
#include "Fraction.h"
#include "Complex.h"

void PrintMatrix(Matrix& M)
{
    std::cout << "l value reference\n";
    M.Print();
}

void PrintMatrix(Matrix&& M)
{
    std::cout << "r value reference\n";
    M.Print();
}

int main()
{
    Complex c1(3, 4);
    Complex c2(1, 2);
    std::cout << "Complex c1: ";
    c1.TrigonometricForm();
    std::cout << "Complex c2: ";
    c2.TrigonometricForm();
    Complex sum = c1 + c2;
    std::cout << "c1 + c2: ";
    sum.TrigonometricForm();

    Fraction f1(9, 16);
    Fraction f2(15, 24);
    std::cout << "Fraction f1: " << f1 << "\n";
    std::cout << "Fraction f2: " << f2 << "\n";
    std::cout << "f1 + f2: " << f1 + f2 << "\n";
    std::cout << "f1 * f2: " << f1 * f2 << "\n";

    Matrix A(4, 5, 1);
    Matrix B(4, 5, 2);
    std::cout << "Matrix A:\n";
    PrintMatrix(A);
    std::cout << "Matrix B:\n";
    PrintMatrix(B);
    std::cout << "A + B:\n";
    PrintMatrix(A + B);
    Matrix C = Matrix::createMatrix();
    std::cout << "Matrix C:\n";
    C.Print();
    C(1, 1) = 10;
    std::cout << "Modified C:\n";
    C.Print();

    return 0;
}