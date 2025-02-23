//
// Created by slend on 23.02.2025.
//

#include "AutonomousResearchSatellite.h"

void AutonomousResearchSatellite::selfRepair() const {
    if (selfRepairCapability) {
        cout << format("Запущено автоматическое исправление неисправностей с помощью ИИ версии {}", aiVersion) << endl;
    }
    else {
        cout << "Для этого спутника автоисправление не доступно" << endl;
    }
}

void AutonomousResearchSatellite::getStatus() const {
    ScientificSatellite::getStatus();
    cout << format("Версия ИИ (Исскуственный Интеллект): {0}\n"
                   "Возможность самовосстановления: {1}", aiVersion, (selfRepairCapability ? "Есть" : "Нету")) << endl;
}
