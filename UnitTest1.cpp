#include "pch.h"
#include "CppUnitTest.h"

#include "../test 2/point.h"
#include "../test 2/oval.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(ConstructorTest)
        {
            Point point(10, 20);

            Assert::AreEqual(10, point.GetX());
            Assert::AreEqual(20, point.GetY());
        }

        TEST_METHOD(EqualOperatorTest)
        {
            Point p1(10, 20);
            Point p2(10, 20);

            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(NotEqualOperatorTest)
        {
            Point p1(10, 20);
            Point p2(30, 40);

            Assert::IsTrue(p1 != p2);
        }

        TEST_METHOD(AddOperatorTest)
        {
            Point p(10, 20);

            Point result = p + 5;

            Assert::AreEqual(15, result.GetX());
            Assert::AreEqual(25, result.GetY());
        }

        TEST_METHOD(SubtractOperatorTest)
        {
            Point p(20, 30);

            Point result = p - 10;

            Assert::AreEqual(10, result.GetX());
            Assert::AreEqual(20, result.GetY());
        }
    };

    TEST_CLASS(OvalTests)
    {
    public:

        TEST_METHOD(ConstructorTest)
        {
            Oval oval(
                Point(100, 200),
                50,
                30,
                1920);

            std::string text =
                oval.ToString();

            Assert::IsTrue(
                text.find("radiusX = 50")
                != std::string::npos);
        }

        TEST_METHOD(InvalidRadiusXTest)
        {
            auto action = []()
                {
                    Oval oval(
                        Point(100, 100),
                        0,
                        20,
                        1920);
                };

            Assert::ExpectException<
                std::invalid_argument>(
                    action);
        }

        TEST_METHOD(InvalidRadiusYTest)
        {
            auto action = []()
                {
                    Oval oval(
                        Point(100, 100),
                        20,
                        -5,
                        1920);
                };

            Assert::ExpectException<
                std::invalid_argument>(
                    action);
        }

        TEST_METHOD(InvalidCoordinateTest)
        {
            auto action = []()
                {
                    Oval oval(
                        Point(-1, 100),
                        20,
                        20,
                        1920);
                };

            Assert::ExpectException<
                std::invalid_argument>(
                    action);
        }
    };
}