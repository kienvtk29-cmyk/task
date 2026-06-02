#include "Stack.h"
#include <sstream>
#include <stdexcept>


void Stack::resize(size_t newCapacity)
{
    int* newData = new int[newCapacity];

    for (size_t i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

Stack::Stack()
{
    capacity = 4;
    size = 0;
    data = new int[capacity];
}

Stack::Stack(std::initializer_list<int> list)
{
    capacity = list.size() > 4 ? list.size() : 4;
    size = list.size();

    data = new int[capacity];

    size_t index = 0;

    for (int value : list)
    {
        data[index++] = value;
    }
}

Stack::Stack(const Stack& other)
{
    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];

    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Stack::Stack(Stack&& other) noexcept
{
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Stack::~Stack()
{
    delete[] data;
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] data;

        size = other.size;
        capacity = other.capacity;

        data = new int[capacity];

        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

void Stack::push(int value)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    data[size++] = value;
}

int Stack::pop()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return data[--size];
}

int Stack::peek() const
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return data[size - 1];
}

bool Stack::empty() const
{
    return size == 0;
}

size_t Stack::getSize() const
{
    return size;
}

std::string Stack::toString() const
{
    std::stringstream ss;

    ss << "[";

    for (size_t i = 0; i < size; i++)
    {
        ss << data[i];

        if (i + 1 < size)
        {
            ss << ", ";
        }
    }

    ss << "]";

    return ss.str();
}

Stack& operator<<(Stack& stack, int value)
{
    stack.push(value);
    return stack;
}

Stack& operator>>(Stack& stack, int& value)
{
    value = stack.pop();
    return stack;
}