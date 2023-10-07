#include "../../Headers/Utils/Util.h"


float Util::getJaccardCoef(std::string first, std::string second) {
    int size1 = first.size();
    int size2 = second.size();

    // Вычисление размера пересечения
    int intersection = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (first[i] == second[j]) {
                intersection++;
                // Исключаем дубликаты
                second[j] = '\0'; // Маркируем символ второй строки как обработанный
                break;
            }
        }
    }

    // Вычисление коэффициента Жаккарда
    return float(intersection) / (size1 + size2 - intersection);
}
