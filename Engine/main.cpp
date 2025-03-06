#include <windows.h>
#include <iostream>
using namespace std;

class Engine {
    bool isOnn;

public:
    Engine() : isOnn(false) {cout << "Двигатель создан\n";}
    ~Engine() {cout << "Двигатель уничтожен\n";}

    void turnOn() {
        isOnn = true;
        cout << "Двигатель включен\n";
    }

    void turnOff() {
        isOnn = false;
        cout << "Двигатель выключен\n";
    }

    bool isOn() const {return isOnn;}
};


class Car {
public:
    class GPS {
        bool m_isActive;

    public:
        GPS() : m_isActive(false) {cout << "Навигационная система создана\n";}
        ~GPS() {cout << "Навигационная система уничтожена\n";}

        void activate() {
            m_isActive = true;
            cout << "GPS активирована\n";
        }

        void deactivate() {
            m_isActive = false;
            cout << "GPS деактивирована\n";
        }
        bool isActive() const {return m_isActive;}
    };

private:
    string model;
    Engine engine;
    GPS gps;

public:
    Car(const string& _model) : model(_model) {cout << "Создан автомобиль: " << model << "\n";}
    ~Car() {cout << "Автомобиль " << model << " уничтожен\n";}

    void start() {
        cout << "Запуск автомобиля " << model << endl;
        engine.turnOn();
        gps.activate();
    }

    void stop() {
        cout << "Остановка автомобиля " << model << endl;
        engine.turnOff();
        gps.deactivate();
    }

    bool isRunning() const {return engine.isOn();}
    string getModel() const {return model;}
};


class Garage {
    Car** cars;
    int capacity;
    int count;

public:
    Garage(const int _capacity) : capacity(_capacity), count(0) {
        cout << "Создан гараж на " << capacity << " мест\n";
        cars = new Car*[capacity];
        for (int i = 0; i < capacity; ++i) {
            cars[i] = nullptr;
        }
    }

    ~Garage() {
        delete[] cars;
        cout << "Гараж уничтожен\n";
    }

    bool addCar(Car* car) {
        if (count < capacity) {
            cars[count++] = car;
            cout << "Автомобиль " << car->getModel() << " помещён в гараж\n";
            return true;
        } else {
            cout << "В гараже нет свободных мест \n";
            return false;
        }
    }

    void listCars() const {
        cout << "Список автомобилей в гараже:\n";
        for (int i = 0; i < count; ++i) {
            if (cars[i]) {
                cout << "  - " << cars[i]->getModel() << (cars[i]->isRunning() ? " (запущен)\n" : " (выключен)\n");
            }
        }
    }
};


// int main() {
//     SetConsoleOutputCP(CP_UTF8);
//     Car car1("Ford Focus");
//     Car car2("Toyota Corolla");
//
//     car1.start();
//
//     Garage garage(2);
//
//     garage.addCar(&car1);
//     garage.addCar(&car2);
//
//     garage.listCars();
//
//     car1.stop();
//     cout << "\n";
//
//     garage.listCars();
// }
