// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: Nathan Spriegel
// Section: 002L
// Assignment: Lab Proj 4
//

#include "Frac.h"

Fraction::Fraction(int n, int d)
{
    numerator = (d < 0 ? -n : n);
    denominator = (d < 0 ? -d : d);
    reduce();
}

Fraction Fraction::add(const Fraction &a)
{
    Fraction t;

    t.numerator = a.numerator * denominator + a.denominator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduce();

    return t;
}

Fraction Fraction::subtract(const Fraction &a)
{
    Fraction t;

    t.numerator = numerator * a.denominator - a.numerator * denominator;
    t.denominator = a.denominator * denominator;
    t.reduce();

    return t;
}

Fraction Fraction::multiply(const Fraction &a)
{
    Fraction t;

    t.numerator = a.numerator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduce();

    return t;
}

Fraction Fraction::divide(const Fraction &a)
{
    Fraction t;

    t.numerator = numerator * a.denominator;
    t.denominator = denominator * a.numerator;
    t.reduce();

    return t;
}

void Fraction::printFraction()
{
    cout << numerator << "/" << denominator;
}

void Fraction::printFractionAsFloat()
{
    if (denominator == 0)
    {
        cout << endl
             << "DIVIDE BY ZERO ERROR!!!" << endl;
    }
    else
    {
        cout << float(numerator) / float(denominator);
    }
}

void Fraction::reduce()
{
    int n = numerator < 0 ? -numerator : numerator;
    int d = denominator;
    int largest = n > d ? n : d;

    int gcd = 0;

    for (int loop = largest; loop >= 2; loop--)
    {
        if (numerator % loop == 0 && denominator % loop == 0)
        {
            gcd = loop;
            break;
        }
    }

    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }
}

/*
 */