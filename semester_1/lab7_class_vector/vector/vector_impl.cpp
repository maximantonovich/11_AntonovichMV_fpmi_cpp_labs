#include "vector_impl.h"
#include <algorithm>
#include <iostream>
#include <exception>

Vector::Vector() {
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

Vector::Vector(size_t size) {
    if (size <= 0) {
        throw "size has to be greater than 0";
    }
    arr_ = new int[size];
    size_ = size;
    capacity_ = size;
    for (size_t i = 0; i < size_; i++) {
        arr_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list) {
    arr_ = new int[list.size()];
    size_ = list.size();
    capacity_ = size_;
    for (size_t i = 0; i < size_; ++i) {
        arr_[i] = list.begin()[i];
    }
}

Vector::Vector(const Vector& other) {
    if (other.capacity_ == 0) {
        arr_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    } else {
        arr_ = new int[other.capacity_];
        size_ = other.size_;
        capacity_ = other.capacity_;
        for (size_t i = 0; i < size_; i++) {
            arr_[i] = other.arr_[i];
        }
    }
}

Vector::~Vector() {
    if (arr_ != nullptr) {
        delete[] arr_;
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (arr_ == other.arr_) {
        return *this;
    } else {
        Vector temp(other);
        Swap(temp);
    }
    return *this;
}

size_t Vector::get_size() const {
    return size_;
}

size_t Vector::get_capacity() const {
    return capacity_;
}

void Vector::Swap(Vector& other) {
    std::swap(this->size_, other.size_);
    std::swap(this->capacity_, other.capacity_);
    std::swap(this->arr_, other.arr_);
}

int& Vector::operator[](size_t i) const {
    return this->arr_[i];
}

int& Vector::operator[](size_t i) {
    return this->arr_[i];
}

int& Vector::At(size_t i) const {
    if (i >= size_) {
        throw std::out_of_range("");
    }
    return this->arr_[i];
}

int& Vector::At(size_t i) {
    if (i >= size_) {
        throw std::out_of_range("");
    }
    return this->arr_[i];
}

size_t Vector::Size() const {
    return this->size_;
}

size_t Vector::Capacity() const {
    return this->capacity_;
}

void Vector::PushBack(int n) {
    if (size_ == capacity_) {
        reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    arr_[size_] = n;
    size_++;
}

void Vector::reallocate(size_t n) {
    int* temp = new int[n];
    for (size_t i = 0; i < size_; i++) {
        temp[i] = arr_[i];
    }
    delete[] arr_;
    capacity_ = n;
    arr_ = temp;
}

void Vector::PopBack() {
    size_--;
    reallocate(capacity_);
}

void Vector::Clear() {
    size_ = 0;
    int* temp = new int[capacity_];
    delete[] arr_;
    arr_ = temp;
}

void Vector::Reserve(size_t n) {
    if (n > capacity_) {
        reallocate(n);
    }
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << "[";
    if (v.Size() > 0) {
        out << v[0];
        for (size_t i = 1; i < v.Size(); i++) {
            out << ", " << v[i];
        }
    }
    out << "]";
    return out;
}
