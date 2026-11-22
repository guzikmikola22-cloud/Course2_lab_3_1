#pragma once               
#include <iostream>        
#include <string>          

using namespace std;      

class Triad                // Оголошення базового класу Triad
{
private:                   // Закрита секція (інкапсуляція — доступ лише всередині класу)
    int first;             // Перше число трійки
    int second;            // Друге число трійки
    int third;             // Третє число трійки

public:                    // Відкрита секція (інтерфейс класу, доступний ззовні)

    // --- Конструктори та деструктор ---
    Triad(const int f = 0, const int s = 0, const int t = 0); // Конструктор ініціалізації (та без аргументів)
    Triad(const Triad& r);                                    // Конструктор копіювання
    ~Triad();                                                 // Деструктор

    // --- Методи доступу (геттери — тільки для читання полів) ---
    int getFirst() const { return first; }                    // Повертає значення first
    int getSecond() const { return second; }                  // Повертає значення second
    int getThird() const { return third; }                    // Повертає значення third

    // --- Методи встановлення значень (сеттери — для запису полів) ---
    void setFirst(const int value) { first = value; }         // Записує нове значення в first
    void setSecond(const int value) { second = value; }       // Записує нове значення в second
    void setThird(const int value) { third = value; }         // Записує нове значення в third

    // --- Методи збільшення полів на 1 (за умовою варіанту) ---
    void incFirst();                                          // Збільшити first на 1
    void incSecond();                                         // Збільшити second на 1
    void incThird();                                          // Збільшити third на 1

    // --- Операція приведення типу ---
    operator string() const;                                  // Перетворення об'єкта Triad у рядок

    // --- Дружні функції вводу / виводу ---
    friend ostream& operator<<(ostream& out, const Triad& r); // Перевантаження виводу (cout << obj)
    friend istream& operator>>(istream& in, Triad& r);        // Перевантаження вводу (cin >> obj)
};