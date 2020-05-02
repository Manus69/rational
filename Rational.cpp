#include "Rational.h"

Rational::Rational()
{
    this->a = 1;
    this->b = 1;
}

Rational::Rational(long a, long b)
{
    if (!b) error("Zero denominator\n");
    if (a < 0 && b < 0) 
    {
        a = -a; 
        b = -b;
    }
    else if (b < 0)
    {
        b = -b;
        a = -a;
    }
    long divisor = gcd(a, b);
    this->a = a / divisor;
    this->b = b / divisor;
}

Rational::~Rational(){};

std::ostream& operator <<(std::ostream& stream, Rational& rational)
{
    if (rational.get_b() == 1)
        return stream << rational.get_a();
    return stream << rational.get_a() << "/" << rational.get_b();
}

Rational operator *(Rational r, Rational f)
{
    return Rational(r.a * f.a, r.b * f.b);
}

Rational operator +(Rational r, Rational f)
{
    if (r.a == f.b)
        return Rational(r.a + f.a, f.b);
    long denom = r.b * f.b;
    long num = r.a * f.b + r.b * f.a;
    return Rational(num, denom);
}

Rational operator -(Rational r, Rational f)
{
    f.a = -f.a;
    return r + f;
}

Rational operator /(Rational r, Rational f)
{
    Rational reciprocal = Rational(f.b, f.a);
    return r * reciprocal;
}

double Rational::to_double()
{
    double number = (double)this->a / (double)this->b;
    return number;
}

void error(std::string message)
{
    std::cout << message.c_str();
    exit(1);
}

void swap(long& a, long& b)
{
    long t = a;
    a = b;
    b = t;
}

long gcd(long a, long b) //a = nb + r;
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) swap(a, b);
    if (!a || !b) return !a ? b : a;
    if (a == b) return b;
    long r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}