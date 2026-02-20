#pragma once
#ifndef BITSETD_BITSETD_13022026
#define BITSETD_BITSETD_13022026


#include <vector>


class BitsetD
{
private:
	std::size_t size_ = 0;
	std::vector<uint32_t> data_;

public:
	BitsetD() = default;

	BitsetD(const BitsetD& other);

	excplicit BitsetD(std::int32_t size);

	~BitsetD();

	BitsetD& operator=(const BitsetD& other);

	std::size_t size() const noexcept { return size_; }

	void set(int32_t index, bool value);

	bool get(int32_t index) const noexcept;

	bool empty() const noexcept { return size_ == 0; }

	void resize(std::int32_t new_size);


};















#endif
