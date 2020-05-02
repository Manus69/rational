#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

//f = a / b;
class Rational
{
    private:
        long a;
        long b;
    public:
        Rational();
        Rational(long a, long b);
        ~Rational();
        long get_b() const {return b;};
        long get_a() const {return a;};
        double to_double();
        friend Rational operator *(Rational r, Rational f);
        friend Rational operator +(Rational r, Rational f);
        friend Rational operator -(Rational r, Rational f);
        friend Rational operator /(Rational r, Rational f);
};

//overloads
std::ostream& operator <<(std::ostream& stream, Rational& rational);

//helpers
void swap(long& a, long& b);
long gcd(long a, long b);
void error(std::string message);

#endif