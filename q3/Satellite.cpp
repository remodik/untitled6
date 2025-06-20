#include "Satellite.h"
#include <format>

void Satellite::getStatus() const {
    cout << format("--- Статус спутника ---\nВысота орбиты {0} км, масса {1} кг, потребление энергии {2} Вт\n",
        orbitHeight, weight, powerConsumption);
}
