#include "queuea.hpp"

#include <memory>
#include <stdexcept>

QueueA::QueueA(const QueueA& other)
	: data_(nullptr)
	, size_(other.size_)
	, head_(0)
	, tail_(other.size_)
	, capacity_(other.size_)
	 
{
	if (!other.is_empty())
	{
		data_ = new int64_t[capacity_];
		for (size_t i = 0; i < size_; i++)
		{
			data_[i] = other.data_[(other.head_ + i) % other.capacity_];
		}
	}
}

QueueA::~QueueA()
{
	delete[] data_;
	data_ = nullptr;
}


QueueA& QueueA::operator=(const QueueA& other)
{
	if (this != &other)
	{
		delete[] data_;
		size_ = other.size_;
		head_ = 0;
		tail_ = other.size_;
		capacity_ = other.capacity_;

		if (capacity_ > 0)
		{
			data = new int64_t[capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				data_[i] = other.data[(other.head_ + 1) % other.capacity_];
			}
		else
		{
			data_ = nullptr;
		}
	}
	return *this;
}

void QueueA::pop() noexcept
{
	if (is_empty())
	{
		throw std::logical_error("Очередь пуста")
	}
	else
	{
		head_ = (head_ + 1) % capacity_;
		size_--;
	}
}
bool QueueA::is_empty() const noexcept
{
	return size_ == 0;
}

void QueueA::clear() noexcept
{
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
}


/*void Queue::push(const int64_t value)
{
	tail_ = (tail_ + 1) % capacity_;
	
}*/



