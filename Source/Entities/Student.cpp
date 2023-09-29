#include "..\..\Headers\Student.h"


const std::string &Student::getIdCard() const {
    return idCard;
}
void Student::setIdCard(const std::string &idCard) {
    Student::idCard = idCard;
}
const std::string &Student::getGroupNumber() const {
    return groupNumber;
}
void Student::setGroupNumber(const std::string &groupNumber) {
    Student::groupNumber = groupNumber;
}
const std::string &Student::getFullName() const {
    return fullName;
}
void Student::setFullName(const std::string &fullName) {
    Student::fullName = fullName;
}

void Student::setMark(int mark) {
    this->marks.push_back(mark);
}
