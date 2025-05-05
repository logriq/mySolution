#pragma once
#include <ostream>

class Complex
{
public:
    Complex();
    Complex(double re, double im);
    double Abs() const;
    Complex operator-();
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator*(const double&);
    Complex operator/(const Complex&);
    void TrigonometricForm();

private:
    double m_abs;
    double m_phi;
    double m_real;
    double m_imag;
};