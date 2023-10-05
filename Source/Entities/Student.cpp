#include "../../Headers/Entities/Student.h"


const std::string Student::getIdCard() const {
    return idCard;
}
void Student::setIdCard(const std::string &idCard) {
    this->idCard = idCard;
}
const std::string Student::getGroupNumber() const {
    return groupNumber;
}
void Student::setGroupNumber(const std::string &groupNumber) {
    this->groupNumber = groupNumber;
}
const std::string Student::getFullName() const {
    return fullName;
}
void Student::setFullName(const std::string &fullName) {
    this->fullName = fullName;
}

void Student::addMark(int mark) {
    averageMark = (averageMark == float(0))?
            float(mark) :
            (averageMark + float(mark))/2;
}

Student::Student(const std::string &idCard,
                 const std::string &groupNumber,
                 const std::string &fullName,
                 float averageMark) :
                 idCard(idCard),
                 groupNumber(groupNumber),
                 fullName(fullName),
                 averageMark(averageMark){}

Student::Student(const Student &other) :
                fullName(other.fullName),
                groupNumber(other.groupNumber),
                idCard(other.idCard),
                averageMark(other.averageMark){}

void Student::operator=(const Student& other)
{
    this->averageMark = other.averageMark;
    this->fullName = other.fullName;
    this->groupNumber = other.groupNumber;
    this->idCard = other.idCard;
}

Student::Student() {}

const float Student::getAverageMark() const {
    return this->averageMark;
}

Student::~Student() {
    this->idCard.clear();
    this->fullName.clear();
    this->groupNumber.clear();
}

void Student::save(std::ofstream& out) {
    out << this->fullName << "|"
        << this->groupNumber << "|"
        << this->idCard << "|"
        << averageMark << "\n";
}

Student Student::load(std::string line) {
    Student student;
    myVector<std::string*> fields {&student.fullName, & student.groupNumber, &student.idCard};
    std::string buff;
    int i = 0;
    for(auto ch : line){
        if(ch == '|'){
            *fields[i++] = buff;
            buff.clear();
        } else buff.push_back(ch);
    }

    student.averageMark = std::stof(buff.c_str());
    return student;
}

const std::string Student::getAverageMarkStr() const {
    std::string markStr = std::to_string(this->averageMark);
    if(markStr[3] > '4') markStr[2]++;
    markStr.erase(3, markStr.size());
    return markStr;
}
