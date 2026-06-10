#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    cout << "===== STACK DEMO =====" << endl;

    // Создание стека через список инициализации
    Stack stack{ 10, 20, 30 };

    cout << "Начальный стек: "
        << stack.toString()
        << endl;

    // Добавление элемента
    stack.push(40);

    cout << "После push(40): "
        << stack.toString()
        << endl;

    // Получение верхнего элемента
    cout << "Верхний элемент: "
        << stack.peek()
        << endl;

    // Извлечение элемента
    int value;

    stack >> value;

    cout << "Извлечённый элемент: "
        << value
        << endl;

    cout << "Стек после pop(): "
        << stack.toString()
        << endl;

    // Использование оператора <<
    stack << 100;

    cout << "После operator<< : "
        << stack.toString()
        << endl;

    // Проверка конструктора копирования
    Stack copy(stack);

    cout << "Копия стека: "
        << copy.toString()
        << endl;

    // Проверка оператора присваивания
    Stack another;

    another = stack;

    cout << "После присваивания: "
        << another.toString()
        << endl;

    cout << "Количество элементов: "
        << stack.getSize()
        << endl;

    cout << "Стек пуст? "
        << (stack.empty() ? "Да" : "Нет")
        << endl;

    return 0;
}
