#include <iostream>
using namespace std;

// Задание 1: Транспортные средства
class Vehicle {
public:
    virtual void move() {
        cout << "Транспортное средство движется" << endl;
    }
};

class Car : public Vehicle {
public:
    void move() override {
        cout << "Машина едет по дороге" << endl;
    }
};

class Boat : public Vehicle {
public:
    void move() override {
        cout << "Лодка плывет по воде" << endl;
    }
};

class AmphibiousCar : public Car, public Boat {
public:
    void move() {
        cout << "Амфибия может ехать по дороге и плыть по воде" << endl;
    }
};

// Задание 2: Люди и сотрудники
class Person {
public:
    virtual void introduce() {
        cout << "Я человек" << endl;
    }
};

class Employee : public Person {
public:
    void introduce() override {
        cout << "Я работаю" << endl;
    }
    void work() {
        cout << "Работаю в офисе" << endl;
    }
};

class Student : public Person {
public:
    void introduce() override {
        cout << "Я учусь" << endl;
    }
    void study() {
        cout << "Готовлюсь к экзамену" << endl;
    }
};

class Intern : public Employee, public Student {
public:
    void introduce() override {
        cout << "Я стажер" << endl;
    }
    void doInternship() {
        cout << "Получаю опыт на стажировке" << endl;
    }
};

// Задание 3: Музыкальные инструменты
class MusicInstrument {
public:
    virtual void play() {
        cout << "Игра на музыкальном инструменте" << endl;
    }
};

class StringInstrument : public MusicInstrument {};
class PercussionInstrument : public MusicInstrument {};

class Guitar : public StringInstrument {
public:
    void play() override {
        cout << "Бренчание на гитаре" << endl;
    }
};

class Drum : public PercussionInstrument {
public:
    void play() override {
        cout << "Барабанный бой" << endl;
    }
};

class MultiInstrumentalist : public Guitar, public Drum {
public:
    void playBoth() {
        cout << "Играю и на гитаре, и на барабанах" << endl;
    }
};

// Задание 4: Смартфон
class Phone {
public:
    void call() {
        cout << "Совершение звонка" << endl;
    }
};

class Computer {
public:
    void processData() {
        cout << "Обработка данных" << endl;
    }
};

class Smartphone : public Phone, public Computer {
public:
    void useApp() {
        cout << "Открытие приложения" << endl;
    }
    void browseInternet() {
        cout << "Просмотр веб-страниц" << endl;
    }
};

// Задание 5: Птицы
class Bird {
public:
    virtual void makeSound() {
        cout << "Чириканье птицы" << endl;
    }
};

class FlyingBird : public Bird {
public:
    void fly() {
        cout << "Птица взлетает в небо" << endl;
    }
};

class NonFlyingBird : public Bird {
public:
    void walk() {
        cout << "Птица гуляет по земле" << endl;
    }
};

class Penguin : public NonFlyingBird {
public:
    void swim() {
        cout << "Пингвин плавает в холодной воде" << endl;
    }
};

class Eagle : public FlyingBird {
public:
    void hunt() {
        cout << "Орел высматривает добычу" << endl;
    }
};

int main() {
    AmphibiousCar ac;
    ac.move();

    Intern intern;
    intern.introduce();
    intern.work();
    intern.study();
    intern.doInternship();

    MultiInstrumentalist musician;
    musician.Guitar::play();
    musician.Drum::play();
    musician.playBoth();

    Smartphone phone;
    phone.call();
    phone.processData();
    phone.useApp();
    phone.browseInternet();

    Eagle eagle;
    eagle.fly();
    eagle.hunt();

    Penguin penguin;
    penguin.walk();
    penguin.swim();

}
