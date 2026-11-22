#include "Triad.h"     
#include <sstream>     

// --- Конструктор ініціалізації (та за умовчанням) ---
Triad::Triad(const int f, const int s, const int t)
{
    setFirst(f);       // Встановлюємо перше число через сеттер
    setSecond(s);      // Встановлюємо друге число через сеттер
    setThird(t);       // Встановлюємо третє число через сеттер
}

// --- Конструктор копіювання ---
Triad::Triad(const Triad& r)
    : first(r.first), second(r.second), third(r.third)   // Копіюємо всі три поля з об'єкта r
{}

// --- Деструктор ---
Triad::~Triad()
{}                     // Динамічної пам'яті немає, очищати нічого

// --- Збільшення першого поля на 1 ---
void Triad::incFirst()
{
    first++;           // Додаємо 1 до first
}

// --- Збільшення другого поля на 1 ---
void Triad::incSecond()
{
    second++;          // Додаємо 1 до second
}

// --- Збільшення третього поля на 1 ---
void Triad::incThird()
{
    third++;           // Додаємо 1 до third
}

// --- Операція приведення типу до string ---
Triad::operator string() const
{
    stringstream ss;                                           // Створюємо рядковий потік
    ss << "(" << first << ", " << second << ", " << third << ")"; // Форматуємо у вигляд (a, b, c)
    return ss.str();                                           // Повертаємо готовий рядок
}

// --- Дружня функція виводу в потік (cout << obj) ---
ostream& operator<<(ostream& out, const Triad& r)
{
    return out << string(r);   // Перетворюємо об'єкт у string і передаємо в потік виводу
}

// --- Дружня функція вводу з потоку (cin >> obj) ---
istream& operator>>(istream& in, Triad& r)
{
    int f, s, t;                       // Тимчасові змінні для зчитування значень
    cout << "first = "; in >> f;       // Запит і ввід першого числа
    cout << "second = "; in >> s;      // Запит і ввід другого числа
    cout << "third = "; in >> t;       // Запит і ввід третього числа
    r.setFirst(f);                     // Записуємо перше число в об'єкт
    r.setSecond(s);                    // Записуємо друге число в об'єкт
    r.setThird(t);                     // Записуємо третє число в об'єкт
    return in;                         // Повертаємо потік для ланцюжкового вводу
}