#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP


#include <iostream>
#include <string>


struct Complex {
    Complex();
    explicit Complex(const double real);    // действительная часть
    Complex(const double real, const double imaginary); // действ + мнимая


    bool operator==(const Complex& rhs) const;  //равенство
    bool operator!=(const Complex& rhs) const;  // перегрузка оператора нервенства


    Complex& operator+=(const Complex& rhs);    //сложение с комплексным числом
    Complex& operator+=(const double rhs);      //сложение с действительным числом
    Complex& operator*=(const double rhs);      // умножение на действительное число
    Complex& operator/=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;  // запись в поток
    std::istream& readFrom(std::istream& istrm);       // чтение из потока


    double re{ 0.0 };  // действ часть
    double im{ 0.0 };  // мнимая часть

    // стат. конст. для форматирования
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};


Complex operator+(const Complex& lhs, const Complex& rhs);  // сложение
Complex operator-(const Complex& lhs, const Complex& rhs);  // вычитание

Complex operator/(const Complex& lhs, const double rhs);


std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);  //вывод
std::istream& operator>>(std::istream& istrm, Complex& rhs);        // ввод

// функция для тестирования парсинга
bool testParse(const std::string& str);




#endif
