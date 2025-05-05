#pragma once
#include <ostream>

class Fraction
{
public:
    Fraction();
    Fraction(int a, int b);
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator*(int);
    bool operator==(const Fraction&) const;
    void Simplify();
    friend Fraction operator*(int, const Fraction&);
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

private:
    int GCD(int a, int b);
    int m_numerator;
    int m_denominator;
    bool is_valid;
};