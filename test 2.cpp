#include <iostream>
#include <vector>
#include <memory>

#include "Oval.h"

using namespace std;

int main()
{
    // Фиксированное разрешение экрана
    constexpr unsigned int SCREEN_RESOLUTION = 1920;

    try
    {
        // Вектор умных указателей на фигуры
        vector<shared_ptr<PlaneFigure>> figures;
        // Создание первого овала с использованием конструктора Point
        figures.push_back(
            make_shared<Oval>(
                Point(100, 200),
                50,
                30,
                SCREEN_RESOLUTION));
        // Создание второго овала с использованием координат x, y
        figures.push_back(
            make_shared<Oval>(
                400,
                300,
                80,
                60,
                SCREEN_RESOLUTION));
        // Вывод списка фигур
        cout << "=== DANH SACH HINH ===" << endl;

        for (const auto& figure : figures)
        {
            figure->Draw();
        }

        cout << endl;

        cout << "=== NHAP THEM OVAL ===" << endl;
        cout << "Nhap: x y radiusX radiusY" << endl;

        Oval oval =
            Oval::ReadOval(
                cin,
                SCREEN_RESOLUTION);

        cout << endl;
        cout << "Oval vua nhap:" << endl;
        cout << oval << endl;
    }
    catch (const exception& exception)
    {
        cout
            << "Error: "
            << exception.what()
            << endl;
    }

    return 0;
}