
/*
#include <windows.h>
#include "ElectricBus.h"
#include "Transport.h"
#include "LandTransport.h"
#include "PublicTransport.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ElectricBus bus(50, 60, 6, 12, 30.0, 300, 2);
    bus.getInfo();
    cout << format("Доход от 40 пассажиров: {}", bus.calculateRevenue(40)) << endl;
    cout << format("Расход энергии на 100 км: {} кВт·ч", bus.calculateEnergyConsumption(100)) << endl;
}
*/

/*
#include <windows.h>
#include <iostream>
#include "Warrior.h"
#include "Archer.h"
#include "EliteKnight.h"
#include "Weapon.h"
#include <format>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Weapon sw(20, 5);

    Warrior w1("Warrior", 100, 15, 5);
    Archer a1("Archer", 80, 7, 70);
    EliteKnight ek1("Elite Knight", 200, 20, 15, 30);

    w1.attack(a1, sw);
    cout << format("У {0} {1} здоровья", a1.getName(), a1.getHealth()) << endl;

    a1.shoot(ek1);
    cout << format("У {0} {1} здоровья", ek1.getName(), ek1.getHealth()) << endl;

    ek1.useSpecialAttack(w1);
    cout << format("У {0} {1} здоровья", w1.getName(), w1.getHealth()) << endl;

    ek1.useSpecialAttack(a1);
    cout << format("У {0} {1} здоровья", a1.getName(), a1.getHealth()) << endl;

}
*/

/*
#include <windows.h>
#include "AutonomousResearchSatellite.h"
#include "CommunicationSatellite.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const CommunicationSatellite sp1(20000, 1500, 500, 300, 100);
    cout << "sp1:" << endl;
    sp1.getStatus();
    sp1.transmitData();
    cout << endl;

    const ScientificSatellite sp2(18000, 1200, 400, "Оптический", "Астрономия");
    cout << "sp2:" << endl;
    sp2.getStatus();
    sp2.collectData();
    cout << endl;

    const AutonomousResearchSatellite sp3(22000, 2000, 600, "Рентгеновский", "Космическая физика", "v1.0", true);
    cout << "sp3:" << endl;
    sp3.getStatus();
    sp3.collectData();
    sp3.selfRepair();

    return 0;
}
*/
