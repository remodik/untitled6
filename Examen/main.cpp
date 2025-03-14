#include <iostream>
#include <utility>
#include <vector>
#include <cassert>
#include <chrono>

#define TEST_MEM 0
#define TEST_FUNC 1

using namespace std;
using namespace chrono;

// Реализуйте текущий интерфейс (Все необходимые классы по ТЗ и методы)
class Dish {
protected:
    string name;
    double price;
    int cookingTime;

public:
    Dish(string n, const double p, const int t) : name(std::move(n)), price(p), cookingTime(t) {}
    virtual double getPrice() const = 0;
    virtual int getCookingTime() const = 0;
    virtual ~Dish() = default; // Виртуальный деструктор
};


class MainCourse final : public Dish {
public:
    MainCourse(const string &n, const double p, const int t) : Dish(n, p, t) {}

    double getPrice() const override {
        return price;
    }

    int getCookingTime() const override {
        return cookingTime;
    }
};

// Десерт
class Dessert final : public Dish {
public:
    Dessert(const string &n, const double p, const int t) : Dish(n, p, t) {}

    double getPrice() const override {
        return price;
    }

    int getCookingTime() const override {
        return cookingTime;
    }
};

// Напиток
class Drink final : public Dish {
public:
    Drink(const string &n, const double p, const int t) : Dish(n, p, t) {}

    double getPrice() const override {
        return price;
    }

    int getCookingTime() const override {
        return cookingTime;
    }
};


// Реализуйте текущие методы для работы программы (Вам даны декларации)
// Подсчет общей стоимости заказа
double calculateTotalPrice(const vector<Dish*> order) {
    double total = 0;
    for (const auto& dish : order) {
        total += dish->getPrice();
    }
    return total;
}

// Подсчет максимального времени приготовления
int calculateMaxTime(const vector<Dish*> order) {
    int maxTime = 0;
    for (const auto& dish : order) {
        if (dish->getCookingTime() > maxTime) {
            maxTime = dish->getCookingTime();
        }
    }
    return maxTime;
}

#if TEST_MEM
// Тест скорости и потребления памяти
void testPerformanceAndMemory() {
    constexpr int MAX_DISHES = 1000;
    vector<Dish*> largeOrder;

    // Время старта
    const auto start = high_resolution_clock::now();

    // Создание 1000 блюд
    for (int i = 0; i < MAX_DISHES; i++) {
        largeOrder.push_back(new MainCourse("Тест", 500, 20));
    }

    // Вычисляем цену и время приготовления
    const double totalPrice = calculateTotalPrice(largeOrder);
    const int maxTime = calculateMaxTime(largeOrder);

    // Засекаем время окончания
    const auto end = high_resolution_clock::now();
    const duration<double, milli> elapsed = end - start;

    // Проверка корректности данных
    assert(totalPrice == 500 * MAX_DISHES);
    assert(maxTime == 20);

    // Проверка скорости выполнения. Программа должна уложиться в 500мс.
    assert(elapsed.count() < 500);

    // Очистка памяти
    for (const auto dish : largeOrder) delete dish;

    cout << "Тест производительности и памяти успешно пройден. Время: " << elapsed.count() << " мс." << endl;
}

// Основная тестовая функция
void testRestaurantSystem() {
    cout << "Запуск тестов...\n";

    vector<Dish*> order;
    order.push_back(new MainCourse("Стейк", 1200, 30));
    order.push_back(new Dessert("Тирамису", 500, 15));
    order.push_back(new Drink("Кофе", 300, 5));

    // Проверка общей стоимости заказа
    assert(calculateTotalPrice(order) == 2000);

    // Проверка времени ожидания
    assert(calculateMaxTime(order) == 30);

    for (const auto dish : order) delete dish;

    cout << "Все тесты пройдены успешно!\n";

    // Проверка памяти и скорости
    testPerformanceAndMemory();
}
#endif

/*
int main() {
    vector<Dish*> order;
    order.push_back(new MainCourse("Стейк", 1200, 30));
    order.push_back(new Dessert("Тирамису", 500, 15));
    order.push_back(new Drink("Кофе", 300, 5));
    return 0;
}
*/
