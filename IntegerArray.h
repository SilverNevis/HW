#pragma once
#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H

#include <stdexcept>

class IntegerArray {
public:
    IntegerArray(); 
    IntegerArray(const IntegerArray& other); 
    ~IntegerArray(); 

    int getSize() const; 
    int getElementAt(int index) const; 

    void resize(int newSize); 
    void insert(int index, int value); 
    void remove(int index); 

    IntegerArray& operator=(const IntegerArray& other); 

private:
    int* data; 
    int size; 
    void checkIndex(int index) const; 
};

class bad_range : public std::exception {
public:
    const char* what() const noexcept override {
        return "Index out of range";
    }
};

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid array length";
    }
};

#endif 