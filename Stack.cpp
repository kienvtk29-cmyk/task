#include "Stack.h"

#include <sstream>
#include <stdexcept>

//
// Конструктор по умолчанию
//
Stack::Stack()
{
    size = 0;
}

//
// Конструктор со списком инициализации
//
Stack::Stack(std::initializer_list<int> list)
{
    size = 0;

    for (int value : list)
    {
        if (size < 4)
        {
            data[size++] = value;
        }
    }
}

//
// Конструктор копирования
//
Stack::Stack(const Stack& other)
{
    size = other.size;

    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

//
// Конструктор перемещения
//
Stack::Stack(Stack&& other) noexcept
{
    size = other.size;

    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    other.size = 0;
}

//
// Деструктор
//
Stack::~Stack()
{
}

//
// Оператор копирующего присваивания
//
Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        size = other.size;

        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    return *this;
}

//
// Оператор перемещающего присваивания
//
Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        size = other.size;

        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        other.size = 0;
    }

    return *this;
}

//
// Добавление элемента в стек
//
void Stack::push(int value)
{
    if (size >= 4)
    {
        throw std::out_of_range("Stack is full");
    }

    data[size++] = value;
}

//
// Удаление верхнего элемента
//
int Stack::pop()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return data[--size];
}

//
// Получение верхнего элемента
//
int Stack::peek() const
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return data[size - 1];
}

//
// Проверка на пустоту
//
bool Stack::empty() const
{
    return size == 0;
}

//
// Получение количества элементов
//
int Stack::getSize() const
{
    return size;
}

//
// Преобразование содержимого стека в строку
//
std::string Stack::toString() const
{
    std::stringstream ss;

    ss << "[";

    for (size_t i = 0; i < size; i++)
    {
        ss << data[i];

        if (i < size - 1)
        {
            ss << ", ";
        }
    }

    ss << "]";

    return ss.str();
}

//
// Перегрузка оператора <<
// Добавление элемента
//
Stack& operator<<(Stack& stack, int value)
{
    stack.push(value);
    return stack;
}

//
// Перегрузка оператора >>
// Извлечение элемента
//
Stack& operator>>(Stack& stack, int& value)
{
    value = stack.pop();
    return stack;
}
