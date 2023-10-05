#include "../../Headers/Utils/Util.h"


float Util::getJaccardCoef(std::string first, std::string second) {
    size_t size1 = first.size();
    size_t size2 = second.size();

    // Вычисление размера пересечения
    size_t intersection = 0;
    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (first[i] == second[j]) {
                intersection++;
                // Исключаем дубликаты
                second[j] = '\0'; // Маркируем символ второй строки как обработанный
                break;
            }
        }
    }

    // Вычисление коэффициента Жаккарда
    float jaccardCoefficient = static_cast<float>(intersection) / (size1 + size2 - intersection);
    return jaccardCoefficient;
}
