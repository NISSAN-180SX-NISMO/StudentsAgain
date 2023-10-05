#include "../../../Headers/UserInterface/Printer.h"

std::string Printer::getLine(int size, char type) {
    std::string line;
    for (int i = 0; i < size; ++i)
        line += type;
    return line;
}

void Printer::printTitle(std::ostream *out) {
    *out << " " << getLine(89, '-') << std::endl;
    *out << "| ФИО студента" << getLine(30, ' ')
         << "| Номер студенческого "
         << "| Группа "
         << "| Средний балл |" << std::endl;
    *out << " " << getLine(89, '-') << std::endl;
}

void Printer::print(Student student, std::ostream *out) {
    *out << "| " << student.getFullName() << getLine(std::abs(int(42 - student.getFullName().size())), ' ')
         << "| " << student.getIdCard() << getLine(20 - 9, ' ')
         << "| " << student.getGroupNumber() << getLine(std::abs(int(7 - student.getGroupNumber().size())), ' ')
         << "| " << student.getAverageMarkStr() << getLine(std::abs(int(13 - student.getAverageMarkStr().size())), ' ')
         << "|" << std::endl;
    *out << " " << getLine(89, '-') << std::endl;
}

void Printer::print(myVector<Student> students, std::ostream *out) {
    printTitle();
    for (int i = 0; i < students.size(); ++i)
        print(students[i]);

}
