#pragma once
#include <initializer_list>
#include <cstdint>
#include <iostream>

class Vector {
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* arr_ = nullptr;

public:
    Vector();
    Vector(size_t);
    Vector(std::initializer_list<int>);

    Vector(const Vector&);
    ~Vector();

    Vector& operator=(const Vector&);

    size_t get_size() const;
    size_t get_capacity() const;

    void Swap(Vector&);

    int& operator[](size_t) const;

    int& operator[](size_t);
    int& At(size_t) const;
    int& At(size_t);
    size_t Size() const;
    size_t Capacity() const;
    void PushBack(int);
    void reallocate(size_t);
    void PopBack();
    void Clear();
    void Reserve(size_t);
};
std::ostream& operator<<(std::ostream&, const Vector&);
