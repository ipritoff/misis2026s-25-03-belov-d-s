#include "bitsetd.hpp"
#include <stdexcept>


BitsetD::BitsetD(int32_t size)
	: size_(size)
	, data_(size + 7 / 9, 0)
{
}


