#pragma once
#ifndef DIO_DIOSTRB_HPP_20022026
#define DIOSTRB_DIOSTRB_HPP_20022026


#include <string>
#include <iosfwd>
#include <ostream>

class DioStrB
{
public:
	DioStrB();
	DioStrB(const std::string& str)
		: value(str)
	{}

	std::string& val()
		const std::string& val() const

	friend std::ostream& operator<<(std::ostream& output_s, const DioStrB& str);
	
	void read(std::istream& input_s) 
	void write(std::ostream& output_s) const
	


	~DioStrB();

private:
	std::string value;
};












#endif
