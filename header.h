#ifndef FRACTIONS_H
#define FRACTIONS_H
#include <iostream>

long int gcd(long int a, long int b);
long int lcm(long int a, long int b);

class Fraction {
  private:
    long int my_numerator;
    long int my_denominator;
  public:
    // constructors
    Fraction();
    Fraction(long int numerator, long int denominator);
    Fraction(std::string &string);
    // destructor
    ~Fraction();
    // getters
    long int getNumerator() const;
    long int getDenominator() const;
    // setters
    void setNumerator(long int numerator);
    void setDenominator(long int denominator);
};

// auxiliary functions, designed for work with fractions
Fraction operator+(const Fraction &fraction_1, const Fraction &fraction_2);
Fraction operator-(const Fraction &fraction_1, const Fraction &fraction_2);
Fraction operator*(const Fraction &fraction_1, const Fraction &fraction_2);
Fraction operator/(const Fraction &fraction_1, const Fraction &fraction_2);
Fraction reduction (Fraction unreduced_fraction);
std::string FractiontoString(const Fraction &fraction);

#endif