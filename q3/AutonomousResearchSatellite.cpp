#include "AutonomousResearchSatellite.h"
#include <sstream>

void AutonomousResearchSatellite::selfRepair() const {
    if (selfRepairCapability) {
        cout << format("Запущено автоматическое исправление неисправностей с помощью ИИ версии {}\n", aiVersion);
    }
    else {
        cout << "Для этого спутника автоисправление не доступно\n";
    }
}

void AutonomousResearchSatellite::getStatus() const {
    ostringstream oss;
    ScientificSatellite::getStatus();
    oss << "Версия ИИ (Искусственный Интеллект): " << aiVersion << '\n'
        << "Возможность самовосстановления: " << (selfRepairCapability ? "Есть" : "Нету") << '\n';
    cout << oss.str();
}

void AutonomousResearchSatellite::monitorHealth() const {
    cout << format("Мониторинг состояния спутника...\n");
    cout << format("Версия ИИ: {0}\n", aiVersion);
    cout << format("Возможность самовосстановления: {0}\n", selfRepairCapability ? "Да" : "Нет");
    cout << format("Все системы работают корректно.\n");
}
