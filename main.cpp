#include <iostream>
#include <string>
#include "header.h"

int main() {
  std::string fraction_1;
  std::cout << "Enter the first fraction: ";
  std::cin >> fraction_1;
  Fraction first_fraction(fraction_1);

  std::string fraction_2;
  std::cout << "Enter the second fraction: ";
  std::cin >> fraction_2;
  Fraction second_fraction(fraction_2);

  std::cout << "Their sum: " << FractiontoString(first_fraction + second_fraction) << std::endl;
  std::cout << "Their difference: " << FractiontoString(first_fraction - second_fraction) << std::endl;
  std::cout << "Their product: " << FractiontoString(first_fraction * second_fraction) << std::endl;
  std::cout << "Their quotient: " << FractiontoString(first_fraction / second_fraction) << std::endl;
  return 0;
}