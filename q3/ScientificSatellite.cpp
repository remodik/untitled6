//
// Created by slend on 23.02.2025.
//

#include "ScientificSatellite.h"

void ScientificSatellite::getStatus() const{
    cout << format("Тип датчика: {0}, Область исследований: {1}", sensorType, researchField) << endl;
}

void ScientificSatellite::collectData() const {
    cout << format("Сбор научных данных с использованием датчика типа {0} в области {1}.", sensorType, researchField) << endl;
}
