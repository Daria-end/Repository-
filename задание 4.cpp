#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введённое значение
 * @throw Завершает программу при ошибке ввода
 */
double getValue();

/**
 * @brief Функция для вычисления значения y = 3x - 4*ln(x) - 5
 * @param x Аргумент функции (x > 0)
 * @return Значение функции
 * @throw Завершает программу при x <= 0
 */
double calculateFunction(double x);

/**
 * @brief Получает положительный шаг
 * @return Положительное значение шага
 * @throw Завершает программу при некорректном вводе или неположительном шаге
 */
double getPositiveStep();

int main()
{
    setlocale(LC_ALL, "Russian");

    try {
        cout << "Введите начальное значение x: ";
        double startX = getValue();

        cout << "Введите конечное значение x: ";
        double endX = getValue();

        if (startX >= endX) {
            cout << "Ошибка: начальное значение x должно быть меньше конечного" << endl;
            return 1;
        }

        double step = getPositiveStep();

        cout << "x\t|\ty" << endl;
        cout << "----------------" << endl;

        // Используем точное сравнение с учетом погрешности
        for (double x = startX; x <= endX + numeric_limits<double>::epsilon(); x += step)
        {
            if (x <= 0) {
                cout << "Ошибка: логарифм не определен для x = " << x << endl;
                return 1;
            }

            double y = calculateFunction(x);
            cout << fixed << setprecision(6) << x << "\t|\t" << y << endl;
        }
    }
    catch (...) {
        return 1;
    }

    return 0;
}

double getValue()
{
    double value=0;
    if (!(cin >> value)) {
        cout << "Ошибка ввода: требуется числовое значение" << endl;
        exit(1);
    }
    return value;
}

double calculateFunction(double x)
{
    if (x <= 0) {
        cout << "Ошибка: аргумент логарифма должен быть положительным" << endl;
        exit(1);
    }
    return 3 * x - 4 * log(x) - 5;
}

double getPositiveStep()
{
    cout << "Введите шаг: ";
    double step = getValue();
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным" << endl;
        exit(1);
    }
    return step;
}