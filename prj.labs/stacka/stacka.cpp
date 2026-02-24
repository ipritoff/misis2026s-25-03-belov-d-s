#include "stacka.hpp"

#include <memory>
#include <stdexcept>


StackA::StackA(const StackA& other) 
	: data_(nullptr)
	, size_(other.size_)
{
	if (!other.is_empty())
	{
		data_ = new int64_t[size_];
		for (size_t i = 0; i < size_; i++)
		{
			data_[i] = other.data_[i];
		}
	}
}


StackA::~StackA()
{
	delete[] data_;
	data_ = nullptr;

}

StackA& StackA::operator=(const StackA& other)
{
	if (this != &other)
	{
		try
		{
			delete[] data_;
			size_ = other.size_;
			data_ = new int64_t[other.size_];
			for (size_t i = 0; i < (size_); i++)
			{
				data_[i] = other.data_[i];
			}
		}
		catch (...)
		{
			data_ = nullptr;
			size_ = 0;
			throw;
		}
	}
	return *this;
}

void StackA::pop() noexcept
{
	if (size_ > 0)
	{
		size_--;
	}
}

void StackA::clear() noexcept
{
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
}

void StackA::push(const int64_t value)
{
	int64_t* new_data = new int64_t[size_ + 1];
	for (size_t i = 0; i < size_; i++)
	{
		new_data[i] = data_[i];
	}
	new_data[size_] = value;
	delete[] data_; 
	data_ = new_data;
	size_++;
}

int64_t& StackA::top()
{
	if (is_empty())
	{
		throw std::logic_error("стек пуст");
	}
	return data_[size_ - 1];
}
int64_t StackA::top() const
{
	if (is_empty())
	{ 
		throw std::logic_error("стек пуст");
	}
	return data_[size_ - 1];
}

bool StackA::is_empty() const noexcept
{
	return (size_ == 0);
}