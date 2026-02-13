#pragma once
#ifndef ARRAYD_ARRAYD_HPP
#define ARRAYD_ARRAYD_HPP

#include <cstddef>

class ArrayD {
public:
    ArrayD() = default;
    ArrayD(const ArrayD& other);
    explicit ArrayD(std::ptrdiff_t size);
    ~ArrayD();

    ArrayD& operator=(const ArrayD& other);

    [[nodiscard]] std::ptrdiff_t size() const noexcept { return size_; }

    void resize(std::ptrdiff_t new_size);

    [[nodiscard]] double& operator[](std::ptrdiff_t index);
    [[nodiscard]] double operator[](std::ptrdiff_t index) const;

    void insert(std::ptrdiff_t index, double value);
    void remove(std::ptrdiff_t index);

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    double* data_ = nullptr;
};

#endif