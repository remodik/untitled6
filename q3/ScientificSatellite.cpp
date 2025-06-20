#include <iostream>
#include <string>

class ScientificSatellite {
    std::string sensorType;
    std::string researchField;

public:
    void initializeSatellite(const std::string& sensor, const std::string& field) {
        sensorType = sensor;
        researchField = field;
        std::cout << "Спутник инициализирован с датчиком типа " << sensorType
                  << " для области исследований " << researchField << ".\n";
    }

    static void shutdownSatellite() {
        std::cout << "Спутник завершает работу. Освобождение ресурсов...\n";
    }

    static void transmitData(const std::string& data) {
        std::cout << "Передача данных: " << data << " на наземную станцию.\n";
    }

    void updateSensor(const std::string& newSensorType) {
        sensorType = newSensorType;
        std::cout << "Тип датчика обновлен на: " << sensorType << ".\n";
    }

    static void diagnoseIssues() {
        std::cout << "Диагностика спутника: все системы работают корректно.\n";
    }
};