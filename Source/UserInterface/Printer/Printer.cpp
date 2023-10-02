//
// Created by user on 02.10.2023.
//

#include "../../../Headers/Printer.h"

void Printer::print(Student student, std::ostream *out) {
    *out << student.getFullName() << std::endl;
    *out << student.getGroupNumber() << std::endl;
    *out << student.getIdCard() << std::endl;
    *out << student.getAverageMark() << std::endl;
}

void Printer::print(myVector<Student> students, std::ostream *out) {
    for (int i = 0; i < students.size(); ++i)
        print(students[i]);

}
