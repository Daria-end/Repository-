#include <iostream>
#include <cmath>
#include <limits> // Для numeric_limits
#define _USE_MATH_DEFINES // for C++
#include <cmath>
using namespace std;

// Определение константы PI
const double PI = 3.14159265358979323846;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введённое значение
 */
double getValue();

/**
 * @brief Проверяет, расположены ли три точки на одной прямой
 * @param x1, y1 - координаты точки A
 * @param x2, y2 - координаты точки B
 * @param x3, y3 - координаты точки C
 * @return true, если точки на одной прямой, иначе false
 */
bool areCollinear(const double x1,const double y1,const double x2,const double y2,const double x3,const double y3);

/**
 * @brief Вычисляет угол B в градусах между AB и BC
 * @param x1, y1 - координаты точки A
 * @param x2, y2 - координаты точки B
 * @param x3, y3 - координаты точки C
 * @return Угол B в градусах
 */
double calculateAngleB(const double x1,const double y1,const double x2,const double y2,const double x3,const double y3);

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Введите координаты точки A (x1, y1): " << endl;
    double x1 = getValue();
    double y1 = getValue();

    cout << "Введите координаты точки B (x2, y2): " << endl;
    double x2 = getValue();
    double y2 = getValue();

    cout << "Введите координаты точки C (x3, y3): " << endl;
    double x3 = getValue();
    double y3 = getValue();

    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        cout << "Точки A, B и C расположены на одной прямой." << endl;
    }
    else {
        double angleB = calculateAngleB(x1, y1, x2, y2, x3, y3);
        cout << "Точки A, B и C не расположены на одной прямой." << endl;
        cout << "Угол B: " << angleB << " градусов." << endl;
    }

    return 0;
}

double getValue() {
    double value=0;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Ошибка: введено некорректное значение. Пожалуйста, введите число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

bool areCollinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Проверка на коллинеарность через площадь треугольника (должна быть нулевой)
    double area = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    return abs(area) < 1e-10; // Сравнение с учётом погрешности вычислений
}

double calculateAngleB(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Вектор BA
    double BAx = x1 - x2;
    double BAy = y1 - y2;
    
    // Вектор BC
    double BCx = x3 - x2;
    double BCy = y3 - y2;

    // Скалярное произведение векторов
    double dotProduct = BAx * BCx + BAy * BCy;
    
    // Длины векторов
    double magnitudeBA = sqrt(BAx * BAx + BAy * BAy);
    double magnitudeBC = sqrt(BCx * BCx + BCy * BCy);

    // Защита от деления на ноль и арккосинуса значений вне [-1, 1]
    double cosAngle = dotProduct / (magnitudeBA * magnitudeBC);
    cosAngle = max(-1.0, min(1.0, cosAngle)); // Ограничиваем значение

    // Угол в радианах и перевод в градусы
    double angleRadian = acos(cosAngle);
    return angleRadian * (180.0 / PI);
}
