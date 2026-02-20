#pragma once
#ifndef STACKA_STACKA_HPP_20022026
#define STACKA_STACKA_HPP_20022026


#include <cstdint>

class StackA 
{
public:
	StackA() {};
	StackA(const StackA& other);
	~StackA();

	StackA& operator=(const StackA& other);

	void pop() noexcept;
	void push(const int64_t value);
	[[nodiscard]] bool is_empty() const noexcept;

	void clear() noexcept;

	[[nodiscrad]] int64_t& top();
	[[nodiscard]] int64_t top() const;
private:

	int64_t* data_ = nullptr;
	size_t size_ = 0;

};












#endif