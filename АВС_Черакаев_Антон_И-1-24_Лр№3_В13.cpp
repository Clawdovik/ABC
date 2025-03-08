#include <iostream>
#include <bitset>
#include <windows.h>
using namespace std;

// Установка кодировки для поддержки русского языка
void SetConsoleRussian()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Функция для задачи 1
void task1()
{
    cout << "Назначение обратного и дополнительного кодов:\n";
    cout << "Обратный и дополнительный коды используются в вычислительной технике для представления отрицательных чисел в двоичной системе.\n";
    cout << "Обратный код получается путём инверсии всех битов положительного числа (кроме знакового бита), а дополнительный код — это обратный код с прибавлением 1.\n";
    cout << "Эти коды позволяют упрощать арифметические операции, такие как сложение и вычитание.\n";
    cout << "Дополнительный код стал стандартом в современных процессорах, так как устраняет необходимость в дополнительных корректировках при сложении чисел с разными знаками.\n\n";
}

// Функция для задачи 2
void task2()
{
    cout << "Назначение модифицированных обратного и дополнительного кодов:\n";
    cout << "Модифицированные обратный и дополнительный коды — это адаптированные версии стандартных кодов, используемые в специфических архитектурах или для повышения точности вычислений.\n";
    cout << "Например, модифицированный обратный код может учитывать отдельное представление знака, а модифицированный дополнительный код может включать дополнительные биты для коррекции ошибок или работы с переполнением.\n";
    cout << "Их назначение — оптимизация вычислений в условиях ограничений оборудования или для специализированных задач.\n\n";
}

// Функция для перевода числа в прямой код
string toDirectCode(long long num, int bits)
{
    if (num >= 0)
    {
        return bitset<32>(num).to_string();
    }
    else
    {
        long long absNum = abs(num);
        string binary = bitset<32>(absNum).to_string();
        binary[0] = '1'; // Устанавливаем знаковый бит в 1 для отрицательного числа
        return binary;
    }
}

// Функция для перевода числа в обратный код
string toInverseCode(long long num, int bits)
{
    if (num >= 0)
    {
        return bitset<32>(num).to_string();
    }
    else
    {
        long long absNum = abs(num);
        string binary = bitset<32>(absNum).to_string();
        for (int i = 0; i < bits; i++)
        {
            binary[i] = (binary[i] == '0') ? '1' : '0';
        }
        return binary;
    }
}

// Функция для перевода числа в дополнительный код
string toComplementCode(long long num, int bits)
{
    if (num >= 0)
    {
        return bitset<32>(num).to_string();
    }
    else
    {
        long long absNum = abs(num);
        string binary = bitset<32>(absNum).to_string();
        for (int i = 0; i < bits; i++)
        {
            binary[i] = (binary[i] == '0') ? '1' : '0';
        }
        int carry = 1;
        for (int i = bits - 1; i >= 0; i--)
        {
            if (carry == 0) break;
            if (binary[i] == '0')
            {
                binary[i] = '1';
                carry = 0;
            }
            else
            {
                binary[i] = '0';
            }
        }
        return binary;
    }
}

// Функция для задачи 3
void task3()
{
    long long result1 = 75687 - 9884;       // 65803
    long long result2 = 46746 + 3853;       // 50599
    long long result3 = 204 - 3235;         // -3031
    long long result4 = 372 - 346;          // 26
    long long result5 = 99 / 9;             // 11

    cout << "Result of 75687 - 9884 = " << result1 << "\n";
    cout << "  Direct code: " << toDirectCode(result1, 32) << "\n";
    cout << "  Inverse code: " << toInverseCode(result1, 32) << "\n";
    cout << "  Complement code: " << toComplementCode(result1, 32) << "\n";

    cout << "Result of 46746 + 3853 = " << result2 << "\n";
    cout << "  Direct code: " << toDirectCode(result2, 32) << "\n";
    cout << "  Inverse code: " << toInverseCode(result2, 32) << "\n";
    cout << "  Complement code: " << toComplementCode(result2, 32) << "\n";

    cout << "Result of CC1_2 - CA3_16 = " << result3 << "\n";
    cout << "  Direct code: " << toDirectCode(result3, 32) << "\n";
    cout << "  Inverse code: " << toInverseCode(result3, 32) << "\n";
    cout << "  Complement code: " << toComplementCode(result3, 32) << "\n";

    cout << "Result of 2442_5 - 2341_5 = " << result4 << "\n";
    cout << "  Direct code: " << toDirectCode(result4, 32) << "\n";
    cout << "  Inverse code: " << toInverseCode(result4, 32) << "\n";
    cout << "  Complement code: " << toComplementCode(result4, 32) << "\n";

    cout << "Result of 99 / 9 = " << result5 << "\n";
    cout << "  Direct code: " << toDirectCode(result5, 32) << "\n";
    cout << "  Inverse code: " << toInverseCode(result5, 32) << "\n";
    cout << "  Complement code: " << toComplementCode(result5, 32) << "\n\n";
}

int main()
{
    SetConsoleRussian();

    int choice = -1;

    while (choice != 0)
    {
        cout << "Выберите задачу для выполнения:\n";
        cout << "1. Задача 1: Назначение обратного и дополнительного кодов\n";
        cout << "2. Задача 2: Назначение модифицированных обратного и дополнительного кодов\n";
        cout << "3. Задача 3: Преобразование чисел в двоичную систему с кодами\n";
        cout << "0. Выход\n";
        cout << "Введите ваш выбор: ";
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
        else if (choice == 0)
        {
            cout << "Выход из программы.\n";
        }
        else
        {
            cout << "Неверный выбор. Попробуйте снова.\n\n";
        }
    }

    cin.get();
    return 0;
}