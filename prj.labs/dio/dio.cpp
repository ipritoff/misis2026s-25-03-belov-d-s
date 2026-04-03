#include "DioStrB.hpp"
#include <iostream>


DioStrB::DioStrB() = default;

DioStrB::DioStrB(const std::string& str)
	: value(str)
{}

std::string& DioStrB::val()
{
	return value;
}

const std::string& DioStrB::val() const
{
	return value;
}

void DioStrB::write(std::ostream& output_s) const
{
	size_t size = value.size();
	output_s.write(reinterpret_cast<const char*>(&size), sizeof(size));
	output_s.write(value.data(), size);
}

void DioStrB::read(std::istream& input_s)
{
	size_t size = 0;
	input_s.read(reinterpret_cast<char*>(&size), sizeof(size));
	value.resize(size);
	input_s.read(&value[0], size);
}
