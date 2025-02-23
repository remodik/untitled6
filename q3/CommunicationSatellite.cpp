//
// Created by slend on 23.02.2025.
//

#include "CommunicationSatellite.h"

void CommunicationSatellite::transmitData() const {
    cout << format("Передача данных: Скорость {0} Мбит/с в диапазоне {1} МГц\n", dataRate, frequencyRange);
}

void CommunicationSatellite::getStatus() const {
    Satellite::getStatus();
    cout << format("Диапазон частот: {0} МГц\nСкорость передачи данных: {1} МБит/с\n", frequencyRange, dataRate);
}
