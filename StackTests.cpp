#include "CppUnitTest.h"
#include "../StackLibrary/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
    TEST_CLASS(StackTests)
    {
    public:

        TEST_METHOD(PushTest)
        {
            Stack stack;

            stack.push(10);
            stack.push(20);

            Assert::AreEqual((size_t)2, stack.getSize());
        }

        TEST_METHOD(PeekTest)
        {
            Stack stack{ 1,2,3 };

            Assert::AreEqual(3, stack.peek());
        }

        TEST_METHOD(PopTest)
        {
            Stack stack{ 10,20,30 };

            int value = stack.pop();

            Assert::AreEqual(30, value);
            Assert::AreEqual((size_t)2, stack.getSize());
        }

        TEST_METHOD(EmptyTest)
        {
            Stack stack;

            Assert::IsTrue(stack.empty());
        }

        TEST_METHOD(CopyConstructorTest)
        {
            Stack stack{ 1,2,3 };

            Stack copy(stack);

            Assert::AreEqual(
                stack.toString(),
                copy.toString()
            );
        }
    };
}