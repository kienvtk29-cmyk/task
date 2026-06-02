#pragma once

#include <string>
#include <initializer_list>

class Stack
{
private:
    int* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    // Constructors
    Stack();
    Stack(std::initializer_list<int> list);

    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;

    // Destructor
    ~Stack();

    // Assignment operators
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    // Stack operations
    void push(int value);
    int pop();
    int peek() const;

    bool empty() const;
    size_t getSize() const;

    std::string toString() const;

    // Operators
    friend Stack& operator<<(Stack& stack, int value);
    friend Stack& operator>>(Stack& stack, int& value);
};