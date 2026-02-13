#include "arrayd.hpp"

#include <cstring>
#include <stdexcept>

ArrayD::ArrayD(const ArrayD& other)
    : capacity_(other.size_)
    , size_(other.size_)
    , data_(nullptr) {
    if (size_ > 0) {
        data_ = new double[size_];
        std::memcpy(data_, other.data_, size_ * sizeof(double));
    }
}

ArrayD::ArrayD(std::ptrdiff_t size)
    : capacity_(size)
    , size_(size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    data_ = new double[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        data_[i] = 0.0;
    }
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD& ArrayD::operator=(const ArrayD& other) {
    if (this == &other) {
        return *this;
    }

    resize(other.size_);

    if (size_ > 0) {
        std::memcpy(data_, other.data_, size_ * sizeof(double));
    }

    return *this;
}

void ArrayD::resize(std::ptrdiff_t new_size) {
    if (new_size < 0) {
        throw std::invalid_argument("New size must be non-negative");
    }

    if (new_size <= capacity_) {
        if (new_size > size_) {
            for (std::ptrdiff_t i = size_; i < new_size; ++i) {
                data_[i] = 0.0;
            }
        }
        size_ = new_size;
        return;
    }

    double* new_data = new double[new_size];

    if (data_ != nullptr) {
        const std::ptrdiff_t copy_size = (size_ < new_size) ? size_ : new_size;
        std::memcpy(new_data, data_, copy_size * sizeof(double));

        for (std::ptrdiff_t i = copy_size; i < new_size; ++i) {
            new_data[i] = 0.0;
        }

        delete[] data_;
    }
    else {
        for (std::ptrdiff_t i = 0; i < new_size; ++i) {
            new_data[i] = 0.0;
        }
    }

    data_ = new_data;
    capacity_ = new_size;
    size_ = new_size;
}

double& ArrayD::operator[](std::ptrdiff_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Array index out of bounds");
    }
    return data_[index];
}

double ArrayD::operator[](std::ptrdiff_t index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Array index out of bounds");
    }
    return data_[index];
}

void ArrayD::insert(std::ptrdiff_t index, double value) {
    if (index < 0 || index > size_) {
        throw std::out_of_range("Insert index out of bounds");
    }

    const std::ptrdiff_t old_size = size_;
    resize(size_ + 1);

    if (index < old_size) {
        for (std::ptrdiff_t i = size_ - 1; i > index; --i) {
            data_[i] = data_[i - 1];
        }
    }

    data_[index] = value;
}

void ArrayD::remove(std::ptrdiff_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Remove index out of bounds");
    }

    for (std::ptrdiff_t i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    resize(size_ - 1);
}