#include <iostream>
#include <windows.h>
#include "Time.h"

using namespace std;

// Функція, що одержує і повертає об'єкт базового класу (для демонстрації принципу підстановки)
Triad incrementTriad(Triad t)
{
    t.incFirst();
    t.incSecond();
    t.incThird();
    return t;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 1. Робота з базовим класом Triad ===" << endl;
    Triad tr1;                  // Конструктор без аргументів
    Triad tr2(10, 20, 30);      // Конструктор ініціалізації
    Triad tr3(tr2);             // Конструктор копіювання

    cout << "tr1: " << tr1 << endl;
    cout << "tr2: " << tr2 << endl;
    cout << "tr3 (копія tr2): " << tr3 << endl;

    tr2.incFirst();
    tr2.incSecond();
    tr2.incThird();
    cout << "tr2 після збільшення всіх полів на 1: " << tr2 << endl;

    cout << "\n=== 2. Робота з похідним класом Time ===" << endl;
    Time t1;                    // 00:00:00
    Time t2(23, 59, 58);        // Конструктор ініціалізації
    Time t3(t2);                // Конструктор копіювання

    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t3 (копія t2): " << t3 << endl;

    t2.incThird();
    cout << "t2 (+1 сек): " << t2 << endl;
    t2.incThird();
    cout << "t2 (+1 сек, перехід через добу): " << t2 << endl;

    t2.incSecond();
    cout << "t2 (+1 хв): " << t2 << endl;
    t2.incFirst();
    cout << "t2 (+1 год): " << t2 << endl;

    t2.addSeconds(125);
    cout << "t2 (+125 сек): " << t2 << endl;
    t2.addMinutes(70);
    cout << "t2 (+70 хв): " << t2 << endl;

    cout << "\n=== 3. Введення з клавіатури ===" << endl;
    Time tInput;
    cin >> tInput;
    cout << "Введений час: " << tInput << endl;

    cout << "\n=== 4. Демонстрація принципу підстановки ===" << endl;
    Time tSub(12, 30, 45);
    // Передаємо об'єкт похідного класу Time туди, де очікується базовий клас Triad
    Triad res = incrementTriad(tSub);
    cout << "Початковий Time: " << tSub << endl;
    cout << "Результат incrementTriad(tSub) як Triad: " << res << endl;

    cout << "\n=== 5. Масиви об'єктів та динамічне створення ===" << endl;
    Time arr[2] = { Time(8, 15, 0), Time(14, 45, 30) };
    for (int i = 0; i < 2; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    Time* dynTime = new Time(18, 0, 59);
    cout << "Динамічний об'єкт: " << *dynTime << endl;
    dynTime->incThird();
    cout << "Після incThird(): " << *dynTime << endl;
    delete dynTime;

    return 0;
}