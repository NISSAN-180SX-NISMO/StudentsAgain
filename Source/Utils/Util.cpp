#include "../../Headers/Utils/Util.h"


float Util::getJaccardCoef(std::string first, std::string second) {
    size_t size1 = first.size();
    size_t size2 = second.size();

    // ���������� ������� �����������
    size_t intersection = 0;
    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (first[i] == second[j]) {
                intersection++;
                // ��������� ���������
                second[j] = '\0'; // ��������� ������ ������ ������ ��� ������������
                break;
            }
        }
    }

    // ���������� ������������ ��������
    float jaccardCoefficient = static_cast<float>(intersection) / (size1 + size2 - intersection);
    return jaccardCoefficient;
}
