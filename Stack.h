#pragma once

#include <string>
#include <initializer_list>

/*
    Класс Stack реализует структуру данных "Стек".
    (Last In, First Out) - последний вошёл, первый вышел.

    Максимальное количество элементов: 4.
*/
class Stack
{
private:

    // Массив для хранения элементов стека
    int data[4];

    // Текущее количество элементов в стеке
    int size;

public:

    // Конструктор по умолчанию
    Stack();

    // Конструктор со списком инициализации
    Stack(const std::initializer_list<int> list);

    // Конструктор копирования
    Stack(const Stack& other);

    // Конструктор перемещения
    Stack(Stack&& other) noexcept;

    // Деструктор
    ~Stack();

    // Оператор копирующего присваивания
    Stack& operator=(const Stack& other);

    // Оператор перемещающего присваивания
    Stack& operator=(Stack&& other) noexcept;

    // Добавление элемента в вершину стека
    void push(const int value);

    // Удаление и возврат верхнего элемента
    int pop();

    // Получение верхнего элемента без удаления
    int peek() const;

    // Проверка на пустоту стека
    bool empty() const;

    // Получение количества элементов
    int getSize() const;

    // Преобразование содержимого стека в строку
    std::string toString() const;

    /*
        Перегрузка оператора <<
        Добавляет элемент в стек.

        Пример:
        stack << 10;
    */
    friend Stack& operator<<(Stack& stack,const int value);

    /*
        Перегрузка оператора >>
        Извлекает элемент из стека.

        Пример:
        int x;
        stack >> x;
    */
    friend Stack& operator>>(Stack& stack, int& value);
};
