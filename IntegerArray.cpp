#include "IntegerArray.h"

IntegerArray::IntegerArray() : data(nullptr), size(0) {}

IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

IntegerArray::~IntegerArray() {
    delete[] data;
}

int IntegerArray::getSize() const {
    return size;
}

int IntegerArray::getElementAt(int index) const {
    if (index < 0 || index >= size) {
        throw bad_range();
    }
    return data[index];
}

void IntegerArray::resize(int newSize) {
    if (newSize < 0) {
        throw bad_length();
    }

    int* newData = new int[newSize];
    for (int i = 0; i < std::min(size, newSize); ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

void IntegerArray::insert(int index, int value) {
    checkIndex(index);

    int* newData = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newData[i] = data[i];
    }

    newData[index] = value;

    for (int i = index; i < size; ++i) {
        newData[i + 1] = data[i];
    }

    delete[] data;
    data = newData;
    size++;
}

void IntegerArray::remove(int index) {
    checkIndex(index);

    int* newData = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newData[i] = data[i];
    }

    for (int i = index + 1; i < size; ++i) {
        newData[i - 1] = data[i];
    }

    delete[] data;
    data = newData;
    size--;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

void IntegerArray::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw bad_range();
    }
}