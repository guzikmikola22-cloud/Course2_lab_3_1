#pragma once                  
#include "Triad.h"         

class Time : public Triad     
{
public:                       

    // --- Конструктори та деструктор ---
    Time(const int h = 0, const int m = 0, const int s = 0); // Конструктор ініціалізації (та без аргументів)
    Time(const Time& r);                                     // Конструктор копіювання
    ~Time();                                                 // Деструктор

    // --- Перевизначені сеттери (з перевіркою коректності часу) ---
    void setFirst(const int h);   // Встановлення годин (допустимо 0..23)
    void setSecond(const int m);  // Встановлення хвилин (допустимо 0..59)
    void setThird(const int s);   // Встановлення секунд (допустимо 0..59)

    // --- Перевизначені методи збільшення полів на 1 (із переходом розрядів) ---
    void incFirst();              // Збільшити час на 1 годину
    void incSecond();             // Збільшити час на 1 хвилину
    void incThird();              // Збільшити час на 1 секунду

    // --- Власні методи класу Time (за умовою варіанту 15) ---
    void addSeconds(const int n); // Збільшити час на n секунд
    void addMinutes(const int n); // Збільшити час на n хвилин

    // --- Операція приведення типу ---
    operator string() const;      // Перетворення об'єкта Time у рядок формату ГГ:ХХ:СС

    // --- Дружні функції вводу / виводу ---
    friend ostream& operator<<(ostream& out, const Time& r); // Перевантаження виводу (cout << obj)
    friend istream& operator>>(istream& in, Time& r);        // Перевантаження вводу (cin >> obj)
};