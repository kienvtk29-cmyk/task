#include <iostream> 
#include "Stack.h"
int main()
{
    // Создание стека с начальными элементами 10, 20 и 30
    Stack stack{ 10, 20, 30 };

    // Вывод содержимого стека
    std::cout << "Initial stack: "
        << stack.toString()
        << std::endl;

    // Добавление элемента 40 на вершину стека
    stack.push(40);

    std::cout << "After push(40): "
        << stack.toString()
        << std::endl;

    // Просмотр элемента на вершине стека без его удаления
    std::cout << "Peek: "
        << stack.peek()
        << std::endl;

    int value;

    // Извлечение элемента с вершины стека
    stack >> value;

    std::cout << "Popped value: "
        << value
        << std::endl;

    // Вывод состояния стека после извлечения элемента
    std::cout << "Stack after pop: "
        << stack.toString()
        << std::endl;

    // Добавление элементов 100 и 200 с помощью перегруженного оператора <<
    stack << 100 << 200;

    std::cout << "After operator<< : "
        << stack.toString()
        << std::endl;

    // Создание копии стека с помощью конструктора копирования
    Stack copy = stack;

    std::cout << "Copied stack: "
        << copy.toString()
        << std::endl;

    return 0;
}