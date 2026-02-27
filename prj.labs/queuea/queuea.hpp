#ifndef QUEUEA_QUEUEA_HPP_27022026
#define QUEUEA_QUEUEA_HPP_27022026

#include <cstdint>


class QueueA
{
public:
	QueueA() = default;
	QueueA(const QueueA& other);
	~QueueA() = default;
	
	QueueA& operator=(const Queue& other);

	void pop() noexcept;
	void push(const int64_t value);
	[[nodiscard]] bool is_empty() const noecept;

	void clear() noexcept;

	[[nodiscard]] int64_t& top();
	[[nodiscard]] int64_t top() const;






private:
	int64_t* data = nullptr;
	size_t size_ = 0;
	size_t head_ = 0;
	size_t tail_ = 0;
	size_t capacity_ = 0;
};







#endif