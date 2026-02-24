#include "complex.hpp"
#include <sstream>
#include <iostream>

Complex::Complex() = default;

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

bool Complex::operator==(const Complex& rhs) const {
    return (re == rhs.re) && (im == rhs.im);
}

bool Complex::operator!=(const Complex& rhs) const {
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    if (rhs == 0.0) {
        throw std::invalid_argument("division by zero");
    }
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex operator/(const Complex& lhs, const double rhs) {
    Complex result(lhs);
    result /= rhs;
    return result;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    return rhs.readFrom(istrm);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);

    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;

    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) &&
            (Complex::separator == comma) &&
            (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaginary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

bool testParse(const std::string& str) {
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}