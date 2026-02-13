#include "rational.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>


std::int32_t nod_solve(std::int32_t a, std::int32_t b) noexcept {      // реализация нахождения нода перебором
	a = std::abs(a);
	b = std::abs(b);   // берем модули а и б

	std::int32_t min_v = (a < b) ? a : b;   // находим из а и б минимальное тк нод не может быть больше минимального чилителя или знаменателя
	std::int32_t result = 1;  // определение с инициализауцией. минимально возможный нод = 1

	for (std::int32_t i = 1; i <= min_v; i += 1) {   // перебором идем от 1го до минимального числа
		if ((a % i == 0) && (b % i == 0)) {     // если и то и то делится на i то result = i
			result = i;
		}
	}
	return result;
}




void Rational::Normalize() noexcept {
	if (den_ < 0) {      // если знаменатель <1 то приводим дробь к виду -num/den
		num_ = -num_;
		den_ = -den_;
	}
	if (num_ == 0) {  // если числитель = 0 то дробь = 0/1
		den_ = 1;
		return;
	}
	int nod = nod_solve(num_, den_); // дробвь тут сокращается на нод
	num_ /= nod;
	den_ /= nod;
}






Rational::Rational(const std::int32_t num, const std::int32_t den) // реализация основго конструктора
	: num_(num), den_(den)
{
	if (den_ == 0) {												// если знам равен 0 то кидаем искоючение и сообщение об ошибке 
		throw std::invalid_argument("denominator cant be zero");
	}
	Normalize(); // делаем дробь в норм виде
}

bool Rational::operator==(const Rational& rhs) const noexcept {    // реал-я перегрузки оператора сравнения ==. 
	return (num_ * rhs.den_) == (rhs.num_ * den_);					// если числ первой дроби * знам правой дроби равен наоборот то дроби равны
}

bool Rational::operator!=(const Rational& rhs) const noexcept {	   // реал-ция перегрузки оператора !=

	return !(*this == rhs);										// чтобы не было дублирования кода - this. если текущий обьект не равен правому операнду возвращаем тру или фолс
}
bool Rational::operator<(const Rational& rhs) const noexcept {   //реализации остальных операторов сравнения ...

	return (num_ * rhs.den_) < (rhs.num_ * den_);

}
bool Rational::operator<=(const Rational& rhs) const noexcept {
	return (*this < rhs) || (*this == rhs);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
	return !(*this <= rhs);
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
	return !(*this < rhs);
}


Rational& Rational::operator+=(const Rational& rhs) noexcept {
	num_ = num_ * rhs.den_ + rhs.num_ * den_;
	den_ = den_ * rhs.den_;
	Normalize();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
	num_ = num_ * rhs.den_ - rhs.num_ * den_;
	den_ = den_ * rhs.den_;
	Normalize();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
	num_ = num_ * rhs.num_;
	den_ = den_ * rhs.den_;
	Normalize();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.num_ == 0) {
		throw std::invalid_argument("division by zero");
	}
	num_ = num_ * rhs.den_;
	den_ = den_ * rhs.num_;
	Normalize();
	return *this;
}


Rational& Rational::operator+=(const std::int32_t rhs) noexcept {
	return operator+=(Rational(rhs));
}
Rational& Rational::operator-=(const std::int32_t rhs) noexcept {
	return operator-=(Rational(rhs));
}
Rational& Rational::operator*=(const std::int32_t rhs) noexcept {
	return operator*=(Rational(rhs));
}
Rational& Rational::operator/=(const std::int32_t rhs) {
	return operator/=(Rational(rhs));
}

std::ostream& Rational::writeto(std::ostream& ostrm) const noexcept {
	ostrm << num_;
	if (den_ != 1) {
		ostrm << '/' << den_;
	}
	return ostrm;
}

std::istream& Rational::readfrom(std::istream& istrm) {
	std::int32_t num(0);
	std::int32_t den(1);
	char slash(0);

	istrm >> num;
	if (istrm.peek() == '/') {
		istrm >> slash;
		if (slash == '/') {
			istrm >> den;
			if (den == 0) {
				istrm.setstate(std::ios_base::failbit);
				return istrm;
			}
		}
		else {
			istrm.setstate(std::ios_base::failbit);
			return istrm;
		}
	}

	if (istrm.good()) {
		num_ = num;
		den_ = den;
		Normalize();
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
	return rhs.writeto(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.readfrom(istrm);
}




Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
	Rational result(lhs);
	result += rhs;
	return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
	Rational result(lhs);
	result -= rhs;
	return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
	Rational result(lhs);
	result *= rhs;
	return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational result(lhs);
	result /= rhs;
	return result;
}


Rational operator+(const Rational& lhs, const std::int32_t rhs) noexcept {
	return lhs + Rational(rhs);
}

Rational operator-(const Rational& lhs, const std::int32_t rhs) noexcept {
	return lhs - Rational(rhs);
}

Rational operator*(const Rational& lhs, const std::int32_t rhs) noexcept {
	return lhs * Rational(rhs);
}

Rational operator/(const Rational& lhs, const std::int32_t rhs) {
	return lhs / Rational(rhs);
}


Rational operator+(const std::int32_t lhs, const Rational& rhs) noexcept {
	return Rational(lhs) + rhs;
}

Rational operator-(const std::int32_t lhs, const Rational& rhs) noexcept {
	return Rational(lhs) - rhs;
}

Rational operator*(const std::int32_t lhs, const Rational& rhs) noexcept {
	return Rational(lhs) * rhs;
}

Rational operator/(const std::int32_t lhs, const Rational& rhs) {
	return Rational(lhs) / rhs;
}