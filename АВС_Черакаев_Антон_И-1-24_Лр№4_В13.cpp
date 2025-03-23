#include <iostream>
#include <cmath>
using namespace std;

// Функция для вывода результата первой задачи
void task1()
{
    float a = 35.5, b = 27.725;
    float result = a + b;

    // Выводим исходные данные и результат
    cout << "Task 1: " << a << " + " << b << " = " << result << "\n";
    cout << "\n\n";
}

// Функция для вывода результата второй задачи
void task2()
{
    float a = 9.15, b = 5.25, c = 7.525;
    float result = a * b - c;

    // Выводим исходные данные и результат
    cout << "Task 2: " << a << " * " << b << " - " << c << " = " << result << "\n";
    cout << "\n\n";
}

// Функция для вывода результата третьей задачи
void task3()
{
    float a = 90.15, b = 10.25, c = 25.0;
    float result = a - b + c;

    // Выводим исходные данные и результат
    cout << "Task 3: " << a << " - " << b << " + " << c << " = " << result << "\n";
    cout << "\n\n";
}

// Функция для перевода шестнадцатеричного числа в десятичное
float hexToDecimal(string hex)
{
    float result = 0;
    int pointPos = hex.find('.');
    if (pointPos == string::npos) pointPos = hex.length();

    // Обрабатываем целую часть
    for (int i = 0; i < pointPos; i++)
    {
        char c = hex[i];
        int digit = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        result += digit * pow(16, pointPos - 1 - i);
    }

    // Обрабатываем дробную часть
    if (pointPos != hex.length())
    {
        for (int i = pointPos + 1; i < hex.length(); i++)
        {
            char c = hex[i];
            int digit = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
            result += digit * pow(16, -(i - pointPos));
        }
    }
    return result;
}

// Функция для вывода результата четвертой задачи (шестнадцатеричные числа)
void task4()
{
    string a = "DA9C.4", b = "B2", c = "EE.9";
    float decA = hexToDecimal(a);
    float decB = hexToDecimal(b);
    float decC = hexToDecimal(c);
    float result = decA - decB * decC;

    // Выводим исходные данные и результат
    cout << "Task 4: " << a << " - " << b << " * " << c << " = " << result << " (decimal)\n";
    cout << "\n\n";
}

// Функция для вывода результата пятой задачи (шестнадцатеричные числа)
void task5()
{
    string a = "ED78", b = "D4A", c = "12", d = "8E.F";
    float decA = hexToDecimal(a);
    float decB = hexToDecimal(b);
    float decC = hexToDecimal(c);
    float decD = hexToDecimal(d);
    float result = decA + decB * decC - decD;

    // Выводим исходные данные и результат
    cout << "Task 5: " << a << " + " << b << " * " << c << " - " << d << " = " << result << " (decimal)\n";
    cout << "\n\n";
}

int main()
{
    int choice;

    // Бесконечный цикл с меню
    while (true)
    {
        cout << "Select a task to solve:\n";
        cout << "1. 35.5 + 27.725\n";
        cout << "2. 9.15 * 5.25 - 7.525\n";
        cout << "3. 90.15 - 10.25 + 25\n";
        cout << "4. DA9C.4 - B2 * EE.9 (hex)\n";
        cout << "5. ED78 + D4A * 12 - 8E.F (hex)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            task1();
        }
        else if (choice == 2)
        {
            task2();
        }
        else if (choice == 3)
        {
            task3();
        }
        else if (choice == 4)
        {
            task4();
        }
        else if (choice == 5)
        {
            task5();
        }
        else if (choice == 0)
        {
            break; // Выход из цикла
        }
        else
        {
            cout << "Invalid choice, try again.\n";
        }
    }

    // Ожидание ввода перед завершением
    cin.get();
    cin.get(); // Добавляем второй cin.get(), так как после cin >> choice остается символ новой строки
    return 0;
}