#include <iostream>
using namespace std;

class Fraction {
    private:
        int Numerator, Denominator;
    public:
        Fraction (int Fraction_numerator, int Fraction_denominator) {
            setFraction (Fraction_numerator, Fraction_denominator);
        }
        void setFraction (int Fraction_numerator, int Fraction_denominator) {
            Numerator = Fraction_numerator;
            Denominator = Fraction_denominator;
        }
        int getNumerator () {
            return Numerator;
        }
        int getDenominator () {
            return Denominator;
        }
        void getFraction () {
            cout << Numerator << "/" << Denominator << endl;
        }
};

int gcd (int a, int b) {
    if (a > b)
        gcd(a - b, b);
    else if (b > a)
        gcd(b - a, a);
    else
        return a;        
}

int Multiplication_Numerator (Fraction fraction1, Fraction fraction2) {
    int a = fraction1.getNumerator() * fraction2.getNumerator();
    return a;
}

int Multiplication_Denominator (Fraction fraction1, Fraction fraction2) {
    int b = fraction1.getDenominator() * fraction2.getDenominator();
    return b;
}

int Addition_Numerator (Fraction fraction1, Fraction fraction2) {
    int a = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
    return a;
}

int Addition_Denominator (Fraction fraction1, Fraction fraction2) {
    int b = fraction1.getDenominator() * fraction2.getDenominator();
    return b;
}

int Subtraction_Numerator (Fraction fraction1, Fraction fraction2) {
    int a = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    if (a < 0) 
        a = -a;
    else if (a == 0)
        a = 0;
    return a;
}

int Subtraction_Denominator (Fraction fraction1, Fraction fraction2) {
    int b = fraction1.getDenominator() * fraction2.getDenominator();
    return b;
}

int Division_Numerator (Fraction fraction1, Fraction fraction2) {
    int a = fraction1.getNumerator() * fraction2.getDenominator();
    return a;
}

int Division_Denominator (Fraction fraction1, Fraction fraction2) {
    int b = fraction1.getDenominator() * fraction2.getNumerator();
    return b;
}

int main() {
    while (1) {
    int num, denom;
    int c = 1, d = 1;
    cout << "Enter the numerator of the first fraction: " << endl;
    cin >> num;
    cout << "Enter the denominator of the first fraction: " << endl;
    cin >> denom;
    Fraction fraction_1 (num, denom);
    fraction_1.setFraction (fraction_1.getNumerator() / gcd(fraction_1.getNumerator(), fraction_1.getDenominator()), fraction_1.getDenominator() / gcd(fraction_1.getNumerator(), fraction_1.getDenominator()));
    cout << "The first fraction: ";
    fraction_1.getFraction ();
    cout << "Enter the numerator of the second fraction: " << endl;
    cin >> num;
    cout << "Enter the denominator of the second fraction: " << endl;
    cin >> denom;
    Fraction fraction_2 (num, denom);
    fraction_2.setFraction (fraction_2.getNumerator() / gcd(fraction_2.getNumerator(), fraction_2.getDenominator()), fraction_2.getDenominator() / gcd(fraction_2.getNumerator(), fraction_2.getDenominator()));
    cout << "The second fraction: ";
    fraction_2.getFraction ();
    Fraction fraction_3 (c, d);
    c = Multiplication_Numerator (fraction_1, fraction_2);
    d = Multiplication_Denominator (fraction_1, fraction_2);
    fraction_3.setFraction (c / gcd(c, d), d / gcd(c, d));
    cout << "The composition of two fractions: ";
    fraction_3.getFraction ();
    Fraction fraction_4 (c, d);
    c = Addition_Numerator (fraction_1, fraction_2);
    d = Addition_Denominator (fraction_1, fraction_2);
    fraction_4.setFraction (c / gcd(c, d), d / gcd(c, d));
    cout << "The sum of two fractions: ";
    fraction_4.getFraction ();
    Fraction fraction_5 (c, d);
    c = Subtraction_Numerator (fraction_1, fraction_2);
    if (c == 0)
        cout << "The difference between two fractions: 0\n";
    else {
        d = Subtraction_Denominator (fraction_1, fraction_2);
        fraction_5.setFraction (c / gcd(c, d), d / gcd(c, d));
        cout << "The difference between two fractions: ";
        fraction_5.getFraction ();
    }
    Fraction fraction_6 (c, d);
    c = Division_Numerator (fraction_1, fraction_2);
    d = Division_Denominator (fraction_1, fraction_2);
    fraction_6.setFraction (c / gcd(c, d), d / gcd(c, d));
    cout << "The quotient of two fractions: ";
    fraction_6.getFraction ();
    cout << endl;
    }
}