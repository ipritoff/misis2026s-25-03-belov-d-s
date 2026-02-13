#pragma once
#ifndef RATIONAL_RATIONAL_HPP_27112025
#define RATIONAL_RATIONAL_HPP_27112025

#include <iosfwd>
#include <cstdint>

class Rational {
private:
	std::int32_t num_ = 0;
	std::int32_t den_ = 0;
	void Normalize() noexcept;

public:
	Rational() = default;
	Rational(const Rational&) = default;
	explicit Rational(const std::int32_t num) noexcept : num_(num) {}
	Rational(const std::int32_t num, const std::int32_t den);

	[[nodiscard]] std::int32_t num() const noexcept { return num_; }
	[[nodiscard]] std::int32_t den() const noexcept { return den_; }

	[[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;

	[[nodiscard]] Rational operator-() const noexcept {
		return {
			-num_, den_
		};
	}
	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);

	Rational& operator+=(const std::int32_t rhs) noexcept;
	Rational& operator-=(const std::int32_t rhs) noexcept;
	Rational& operator*=(const std::int32_t rhs) noexcept;
	Rational& operator/=(const std::int32_t rhs);

	std::ostream& writeto(std::ostream& ostrm) const noexcept;
	std::istream& readfrom(std::istream& istrm);
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t rhs);

[[nodiscard]] Rational operator+(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int32_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Rational& rhs);






#endif