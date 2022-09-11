#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <assert.h>
#include "header.h"

// function for calculation of the greatest common divisor
long int gcd(long int a, long int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

// function for calculation of the least common multiple
long int lcm(long int a, long int b) {
  return a * b * gcd(a, b);
}

Fraction::Fraction() {}  // constructor by default
Fraction::~Fraction () {}  // destructor by default

// numerator and denominator constructor
Fraction::Fraction (long int numerator, long int denominator)
  : my_numerator(numerator), my_denominator(denominator) {}

// constructor that takes a string as an argument
Fraction::Fraction (std::string &string) {
  // we search for a slash that separates numerator from denominator
  unsigned long int pos = string.find("/");
  // if it hasn't been found, we consider the whole entered number as a numerator only
  if (pos == std::string::npos) {
    my_numerator = std::stol(string);
    my_denominator = 1L;
  }
  else {
    my_numerator = std::stol(string.substr(0, pos));
    my_denominator = std::stol(string.substr(pos + 1));
    assert (my_denominator != 0L && "You have entered a fraction with a zero denominator!");
  }
}

// getters
long int Fraction::getNumerator() const {
  return my_numerator;
}

long int Fraction::getDenominator() const {
  return my_denominator;
}

// setters
void Fraction::setNumerator(long int numerator) {
  my_numerator = numerator;
  return;
}

void Fraction::setDenominator(long int denominator) {
  my_denominator = denominator;
  return;
}

// a function that reduces a fraction
Fraction reduction (Fraction unreduced_fraction) {
  // if a fraction is zero, we don't reduce it
  if (unreduced_fraction.getNumerator() == 0)
    return unreduced_fraction;
  long int GCD = gcd(std::abs(unreduced_fraction.getNumerator()),
                     std::abs(unreduced_fraction.getDenominator()));
  Fraction reduced_fraction(unreduced_fraction.getNumerator() / GCD,
                            unreduced_fraction.getDenominator() / GCD);
  return reduced_fraction;
}

// an overloaded summation operator
Fraction operator+(const Fraction &fraction_1, const Fraction &fraction_2) {
  Fraction sum(fraction_1.getNumerator() * fraction_2.getDenominator() + fraction_1.getDenominator() * fraction_2.getNumerator(),
               fraction_1.getDenominator() * fraction_2.getDenominator());
  // if denominator is negative, we move up "minus"
  if (sum.getDenominator() < 0L) {
    sum.setNumerator(-sum.getNumerator());
    sum.setDenominator(-sum.getDenominator());
  }
  return reduction(sum);
}

// an overloaded subtraction operator
Fraction operator-(const Fraction &fraction_1, const Fraction &fraction_2) {
  Fraction difference(fraction_1.getNumerator() * fraction_2.getDenominator() - fraction_1.getDenominator() * fraction_2.getNumerator(),
                      fraction_1.getDenominator() * fraction_2.getDenominator());
  // if denominator is negative, we move up "minus"
  if (difference.getDenominator() < 0L) {
    difference.setNumerator(-difference.getNumerator());
    difference.setDenominator(-difference.getDenominator());
  }
  return reduction(difference);
}

// an overloaded multiplication operator
Fraction operator*(const Fraction &fraction_1, const Fraction &fraction_2) {
  Fraction product(fraction_1.getNumerator() * fraction_2.getNumerator(),
                   fraction_1.getDenominator() * fraction_2.getDenominator());
  // if denominator is negative, we move up "minus"
  if (product.getDenominator() < 0L) {
    product.setNumerator(-product.getNumerator());
    product.setDenominator(-product.getDenominator());
  }
  return reduction(product);
}

// an overloaded division operator
Fraction operator/(const Fraction &fraction_1, const Fraction &fraction_2) {
  assert (fraction_2.getNumerator() != 0 && "It's prohibited to divide by zero!");
  Fraction quotient(fraction_1.getNumerator() * fraction_2.getDenominator(),
                    fraction_1.getDenominator() * fraction_2.getNumerator());
  // if denominator is negative, we move up "minus"
  if (quotient.getDenominator() < 0L) {
    quotient.setNumerator(-quotient.getNumerator());
    quotient.setDenominator(-quotient.getDenominator());
  }
  return reduction(quotient);
}

// a function that converts an instance of class 'Fraction' into the string that is convenient for user's perception
std::string FractiontoString(const Fraction &fraction) {
  // a zero fraction
  if (fraction.getNumerator() == 0L)
    return "0";
  std::string string_fraction = "";
  // an improper fraction whose denominator is equal to 1
  if (fraction.getDenominator() == 1L) {
    string_fraction.append(std::to_string(fraction.getNumerator()));
    return string_fraction;
  }
  // at this point of program, we are sure that either: 1) numerator is negative and denominator is positive; or: 2) numerator and denominator are both positive
  // moreover, the fraction is either: 1) proper; or: 2) improper, and its denominator is not equal to 1
  if (std::abs(fraction.getNumerator()) > fraction.getDenominator()) {  // we aim to print improper fractions correctly
    string_fraction.append(std::to_string(fraction.getNumerator() / fraction.getDenominator()));
    string_fraction.append(" ");
    string_fraction.append(std::to_string(std::abs(fraction.getNumerator()) % fraction.getDenominator()));
    string_fraction.append("/");
    string_fraction.append(std::to_string(fraction.getDenominator()));
    return string_fraction;
  }
  else {  // this is the way we print proper fractions
    string_fraction.append(std::to_string(fraction.getNumerator()));
    string_fraction.append("/");
    string_fraction.append(std::to_string(fraction.getDenominator()));
    return string_fraction;
  }
}