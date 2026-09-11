#include "CppUnitTest.h"
#include "../StackLibrary/Stack.h"
#include <utility>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
    TEST_CLASS(StackTests)
    {
    public:

        // Тест конструктора по умолчанию
        TEST_METHOD(DefaultConstructorTest)
        {
            Stack stack;

            Assert::IsTrue(stack.empty());
            Assert::AreEqual(0, stack.getSize());
        }

        // Тест конструктора со списком инициализации
        TEST_METHOD(InitializerListConstructorTest)
        {
            Stack stack{ 1, 2, 3 };

            Assert::AreEqual(3, stack.getSize());
            Assert::AreEqual(3, stack.peek());
        }

        // Тест конструктора копирования
        TEST_METHOD(CopyConstructorTest)
        {
            Stack stack{ 1, 2, 3 };

            Stack copy(stack);

            Assert::AreEqual(
                stack.toString(),
                copy.toString()
            );

            Assert::AreEqual(
                stack.getSize(),
                copy.getSize()
            );
        }

        // Тест конструктора перемещения
        TEST_METHOD(MoveConstructorTest)
        {
            Stack stack{ 1, 2, 3 };

            Stack moved(std::move(stack));

            Assert::AreEqual(3, moved.getSize());
            Assert::AreEqual(3, moved.peek());
        }

        // Тест метода push()
        TEST_METHOD(PushTest)
        {
            Stack stack;

            stack.push(10);
            stack.push(20);

            Assert::AreEqual(2, stack.getSize());
        }

        // Тест метода peek()
        TEST_METHOD(PeekTest)
        {
            Stack stack{ 1, 2, 3 };

            Assert::AreEqual(3, stack.peek());
        }

        // Тест метода pop()
        TEST_METHOD(PopTest)
        {
            Stack stack{ 10, 20, 30 };

            int value = stack.pop();

            Assert::AreEqual(30, value);
            Assert::AreEqual(2, stack.getSize());
        }

        // Тест метода empty()
        TEST_METHOD(EmptyTest)
        {
            Stack stack;

            Assert::IsTrue(stack.empty());
        }
    };
}
