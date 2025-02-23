#include <windows.h>
#include <iostream>
#include <format>
#include <utility>
using namespace std;

class Animal {
protected:
    string name;
    double weight;

public:
    Animal(string name, const double weight) : name(move(name)), weight(weight) {}

    virtual void makeSound() const = 0;

    void print() const {
        cout << format("Имя: {0}, Вес: {1} кг", name, weight) << endl;
    }

    virtual ~Animal() = default;
};

class Cat final : public Animal {
public:
    Cat(const string& name, const double weight) : Animal(name, weight) {}

    void makeSound() const override {
        cout << name << " мяукает\n" << endl;
    }
};

class Dog final : public Animal {
public:
    Dog(const string& name, const double weight) : Animal(name, weight) {}

    void makeSound() const override {
        cout << name << " гавкает\n" << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const Cat cat("Барсик", 4.5);
    const Dog dog("Шарик", 10.2);

    cat.print();
    cat.makeSound();

    dog.print();
    dog.makeSound();
}
