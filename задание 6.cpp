#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

enum SELECT {
    RANDOM = 0,
    MANUALLY = 1
};

void checkN(const int n) {
    if (n <= 0) {
        cout << "Неправильный размер массива" << endl;
        exit(1);
    }
}

size_t getSize() {
    cout << "Введите размер массива: ";
    int n = 0;
    cin >> n;
    if (cin.fail()) {
        cout << "Ошибка ввода" << endl;
        exit(1);
    }
    checkN(n);
    return static_cast<size_t>(n);
}

int getNumber() {
    int number = 0;
    cin >> number;
    if (cin.fail()) {
        cout << "Неправильный ввод данных" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        exit(1);
    }
    return number;
}

void printArray(const int* arr, const int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArrayRandom(int* arr, const int n, const int min, const int max) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max) {
    if (min >= max) {
        cout << "Введен неправильный диапазон" << endl;
        exit(1);
    }
}

int sumOfNegativesDivisibleByTen(const int* arr, const int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0 && arr[i] % 10 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void reverseFirstKElements(int* arr, const int k) {
    int start = 0;
    int end = k - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

bool hasAdjacentProduct(const int* arr, const int n, const int product) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] * arr[i + 1] == product) {
            return true;
        }
    }
    return false;
}

void fillArray(int* arr, const int n, const int min, const int max) {
    for (int i = 0; i < n; i++) {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max) {
            cout << "Значение вне диапазона" << endl;
            exit(1);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    size_t n = getSize();
    int* arr = new int[n];
    int* arr_copy = new int[n]; // Создаем копию массива

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Выберите способ заполнения массива:\n"
         << RANDOM << " - случайное заполнение\n"
         << MANUALLY << " - ручное заполнение\n";
    
    int choice = getNumber();

    switch (choice) {
        case RANDOM:
            fillArrayRandom(arr, n, minValue, maxValue);
            break;
        case MANUALLY:
            fillArray(arr, n, minValue, maxValue);
            break;
        default:
            cout << "Неверный выбор" << endl;
            delete[] arr;
            delete[] arr_copy;
            return -1;
    }

    // Копируем исходный массив
    for (size_t i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    cout << "Сумма отрицательных элементов, кратных 10: " 
         << sumOfNegativesDivisibleByTen(arr, n) << endl;

    cout << "Введите количество элементов для реверса: ";
    int k = getNumber();
    if (k > n) {
        cout << "Ошибка: k превышает размер массива" << endl;
        delete[] arr;
        delete[] arr_copy;
        return -1;
    }
    
    reverseFirstKElements(arr_copy, k);
    cout << "Копия массива после реверса первых " << k << " элементов: ";
    printArray(arr_copy, n);

    cout << "Введите число для проверки произведения соседних элементов: ";
    int product = getNumber();
    if (hasAdjacentProduct(arr, n, product)) {
        cout << "Есть пара соседних элементов с произведением " << product << endl;
    } else {
        cout << "Нет пары соседних элементов с произведением " << product << endl;
    }

    delete[] arr;
    delete[] arr_copy;
    return 0;
}
    return -1/ (k + 1) / (k + 2);
}