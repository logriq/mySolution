#include "Complex.h"
#include <iostream>
#include <math.h>

Complex::Complex(double re, double im) : m_real(re), m_imag(im)
{
    m_abs = sqrt(m_real * m_real + m_imag * m_imag);
    if (abs(m_real - 0.0) > 1e-6)
        m_phi = atan(m_imag / m_real);
    else
        m_phi = 0;
}

Complex::Complex() : Complex(0, 0)
{
}

double Complex::Abs() const
{
    return m_abs;
}

Complex Complex::operator-()
{
    return (*this) * (-1);
}

Complex Complex::operator+(const Complex& other)
{
    double re = m_real + other.m_real;
    double im = m_imag + other.m_imag;
    Complex res(re, im);
    return res;
}

Complex Complex::operator-(const Complex& other)
{
    double re = m_real - other.m_real;
    double im = m_imag - other.m_imag;
    Complex res(re, im);
    return res;
}

Complex Complex::operator*(const Complex& other)
{
    double re = m_real * other.m_real - m_imag * other.m_imag;
    double im = m_real * other.m_imag + m_imag * other.m_real;
    Complex res(re, im);
    return res;
}

Complex Complex::operator*(const double& other)
{
    double re = m_real * other;
    double im = m_imag * other;
    Complex res(re, im);
    return res;
}

Complex Complex::operator/(const Complex& other)
{
    if (other.m_real == 0 && other.m_imag == 0)
    {
        std::cout << "division by zero\n";
        return Complex(0, 0);
    }
    else
    {
        double abs = other.m_real * other.m_real + other.m_imag * other.m_imag;
        double re = (m_real * other.m_real + m_imag * other.m_imag) / abs;
        double im = (m_imag * other.m_real - m_real * other.m_imag) / abs;
        Complex res(re, im);
        return res;
    }
}

void Complex::TrigonometricForm()
{
    std::cout << m_abs << " * (cos " << m_phi << " + i * sin " << m_phi << ")\n";
}