#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Задание 1
class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    virtual ~Vehicle() = default;
    Vehicle(string make, string model, const int year)
        : make(std::move(make)), model(std::move(model)), year(year) {}

    virtual void move() {
        cout << "Транспортное средство " << make << " " << model << " " << year << " года движется" << endl;
    }

    virtual void stop() {
        cout << "Транспортное средство " << make << " " << model << " " << year << " года останавливается" << endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car(const string& make, const string& model, const int year)
        : Vehicle(make, model, year) {}

    void move() override {
        cout << "Автомобиль " << make << " " << model << " " << year << " года едет" << endl;
    }

    void stop() override {
        cout << "Автомобиль " << make << " " << model << " " << year << " года останавливается" << endl;
    }
};

class Boat : virtual public Vehicle {
public:
    Boat(const string& make, const string& model, const int year)
        : Vehicle(make, model, year) {}

    void move() override {
        cout << "Лодка " << make << " " << model << " " << year << " года плывет" << endl;
    }

    void stop() override {
        cout << "Лодка " << make << " " << model << " " << year << " года останавливается" << endl;
    }
};

class AmphibiousCar : public Car, public Boat {
public:
    AmphibiousCar(const string& make, const string& model, const int year)
    : Vehicle(make, model, year), Car(make, model, year), Boat(make, model, year) {}

    void move() override {
        cout << "Амфибийный автомобиль " << make << " " << model << " " << year << " года движется по суше и воде" << endl;
    }

    void stop() override {
        cout << "Амфибийный автомобиль " << make << " " << model << " " << year << " года останавливается" << endl;
    }
};

// Задание 2
class Person {
protected:
    string name;
    int age;

public:
    virtual ~Person() = default;

    Person(string name, const int age) : name(std::move(name)), age(age) {}

    virtual void work() {
        cout << name << ", возраст " << age << ", работает" << endl;
    }
};

class Employee : virtual public Person {
public:
    Employee(const string& name, const int age) : Person(name, age) {}

    void work() override {
        cout << name << ", возраст " << age << ", работает на предприятии" << endl;
    }
};

class Student : virtual public Person {
public:
    Student(const string& name, const int age) : Person(name, age) {}

    void work() override {
        cout << name << ", возраст " << age << ", учится в университете" << endl;
    }
};

class Intern final : public Employee, public Student {
public:
    Intern(const string& name, const int age) : Person(name, age), Employee(name, age), Student(name, age) {}

    void work() override {
        cout << name << ", возраст " << age << ", работает и учится одновременно" << endl;
    }
};


// Задание 3
class MusicInstrument {
protected:
    string name;
    string type;

public:
    virtual ~MusicInstrument() = default;

    MusicInstrument(string  name, string  type) : name(std::move(name)), type(std::move(type)) {}

    virtual void play() {
        cout << "Музыкальный инструмент " << name << " (" << type << ") издает звуки" << endl;
    }
};

class StringInstrument : public MusicInstrument {
public:
    explicit StringInstrument(const string& name) : MusicInstrument(name, "струнный") {}

    void play() override {
        cout << "Струнный инструмент " << name << " издает звуки" << endl;
    }
};

class PercussionInstrument : public MusicInstrument {
public:
    explicit PercussionInstrument(const string& name) : MusicInstrument(name, "ударный") {}

    void play() override {
        cout << "Ударный инструмент " << name << " издает звуки" << endl;
    }
};

class Guitar final : public StringInstrument {
public:
    Guitar() : StringInstrument("Гитара") {}

    void play() override {
        cout << "Гитара издает звуки" << endl;
    }
};

class Drum final : public PercussionInstrument {
public:
    Drum() : PercussionInstrument("Барабан") {}

    void play() override {
        cout << "Барабан издает звуки" << endl;
    }
};

class MultiInstrumentalist final : public StringInstrument, public PercussionInstrument {
public:
    MultiInstrumentalist() : StringInstrument("Гитара"), PercussionInstrument("Барабан") {}

    void play() override {
        StringInstrument::play();
        PercussionInstrument::play();
        cout << "Мультиинструменталист играет на нескольких инструментах" << endl;
    }
};

// Задание 4
class Phone {
public:
    virtual ~Phone() = default;

    virtual void makeCall(const string& number) {
        cout << "Телефон совершает звонок на номер " << number << endl;
    }
};

class Computer {
public:
    virtual ~Computer() = default;

    virtual void processData(const string& data) {
        cout << "Компьютер обрабатывает данные: " << data << endl;
    }
};

class Smartphone : public Phone, public Computer {
public:
    void makeCall(const string& number) override {
        cout << "Смартфон совершает звонок на номер " << number << endl;
    }

    void processData(const string& data) override {
        cout << "Смартфон обрабатывает данные: " << data << endl;
    }
};

// Задание 5
class Bird {
protected:
    string species;

public:
    virtual ~Bird() = default;

    explicit Bird(string  species) : species(std::move(species)) {}

    virtual void move() {
        cout << "Птица вида " << species << " перемещается" << endl;
    }
};

class FlyingBird : public Bird {
public:
    explicit FlyingBird(const string& species) : Bird(species) {}

    void move() override {
        cout << "Птица вида " << species << " летит" << endl;
    }
};

class NonFlyingBird : public Bird {
public:
    explicit NonFlyingBird(const string& species) : Bird(species) {}

    void move() override {
        cout << "Птица вида " << species << " ходит" << endl;
    }
};

class Penguin final : public NonFlyingBird {
public:
    Penguin() : NonFlyingBird("Пингвин") {}

    void move() override {
        cout << "Пингвин ходит" << endl;
    }
};

class Eagle final : public FlyingBird {
public:
    Eagle() : FlyingBird("Орел") {}

    void move() override {
        cout << "Орел летит" << endl;
    }
};


int main() {
    // Задание 1
    cout << "Задание 1:" << endl;
    Vehicle* v1 = new Car("Toyota", "Camry", 2020);
    Vehicle* v2 = new Boat("Yamaha", "Jetboat", 2018);
    Vehicle* v3 = new AmphibiousCar("Gibbs", "Quadski", 2015);

    v1->move(); v1->stop();
    v2->move(); v2->stop();
    v3->move(); v3->stop();

    delete v1;
    delete v2;
    delete v3;

    // Задание 2
    cout << "\nЗадание 2:" << endl;
    Person* p1 = new Employee("Иван Иванов", 35);
    Person* p2 = new Student("Мария Петрова", 20);
    Person* p3 = new Intern("Алексей Сидоров", 22);

    p1->work();
    p2->work();
    p3->work();

    delete p1;
    delete p2;
    delete p3;

    // Задание 3
    cout << "\nЗадание 3:" << endl;
    MusicInstrument* i = new Guitar();
    MusicInstrument* i2 = new Drum();
    auto* i3 = new MultiInstrumentalist();

    i->play();
    i2->play();
    i3->play();

    delete i;
    delete i2;
    delete i3;

    // Задание 4
    cout << "\nЗадание 4:" << endl;
    Phone* phone = new Smartphone();
    Computer* comp = new Smartphone();

    phone->makeCall("12345678");
    comp->processData("Данные для обработки");

    delete phone;
    delete comp;

    // Задание 5
    cout << "\nЗадание 5:" << endl;
    vector<Bird*> birds = {
        new Penguin(),
        new Eagle()
    };

    for (const auto bird : birds) {
        bird->move();
    }

    for (const auto bird : birds) {
        delete bird;
    }

    return 0;
}
