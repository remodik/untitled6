#include <iostream>
#include <utility>

using namespace std;

class Animal {
protected:
    string name;
    double weight;

public:
    Animal(string  name, const double weight) : name(std::move(name)), weight(weight) {}

    virtual void makeSound() const = 0;

    virtual void print() const {
        cout << "Имя: " << name << ", Вес: " << weight << " кг" << endl;
    }

    virtual ~Animal() = default;
};

class Cat final : public Animal {
public:
    Cat(const string& name, const double weight) : Animal(name, weight) {}

    void makeSound() const override {
        cout << name << " мяукает" << endl;
    }
};

class Dog final : public Animal {
public:
    Dog(const string& name, const double weight): Animal(name, weight) {}

    void makeSound() const override {
        cout << name << " лает" << endl;
    }
};

int main() {
    const Animal* myCat = new Cat("Мурка", 3.5);
    const Animal* myDog = new Dog("Бобик", 7.8);

    myCat->print();
    myCat->makeSound();

    myDog->print();
    myDog->makeSound();

    delete myCat;
    delete myDog;
}