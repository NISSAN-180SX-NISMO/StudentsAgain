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
    marksSum += mark;
    marksCount++;
    averageMark = float(marksSum) / marksCount;
}

Student::Student(const std::string &idCard,
                 const std::string &groupNumber,
                 const std::string &fullName,
                 float averageMark, float marksSum,
                 int marksCount) :
                 idCard(idCard),
                 groupNumber(groupNumber),
                 fullName(fullName),
                 averageMark(averageMark),
                 marksSum(marksSum),
                 marksCount(marksCount){}

Student::Student(const Student &other) {
    this->averageMark = other.averageMark;
    this->marksCount = other.marksCount;
    this->marksSum = other.marksSum;
    this->fullName = other.fullName;
    this->groupNumber = other.groupNumber;
    this->idCard = other.idCard;
}

void Student::operator=(const Student& other)
{
    this->averageMark = other.averageMark;
    this->marksCount = other.marksCount;
    this->marksSum = other.marksSum;
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
        << getAverageMarkStr() << "|"
        << marksSum << "|"
        << marksCount << "\n";
}

Student Student::load(std::string line) {
    Student student;
    std::string averageMark, marksSum, marksCount;
    myVector<std::string*> fields {&student.fullName, & student.groupNumber, &student.idCard, &averageMark, &marksSum, &marksCount};
    std::string buff;
    int i = 0;
    for(auto ch : line){
        if(ch == '|'){
            *fields[i++] = buff;
            buff.clear();
        } else buff.push_back(ch);
    }
    marksCount = buff;

    student.averageMark = std::stof(averageMark.c_str());
    student.marksSum = std::stof(marksSum.c_str());
    student.marksCount = std::atoi(marksCount.c_str());
    return student;
}

const std::string Student::getAverageMarkStr() const {
    std::string markStr = std::to_string(this->averageMark);
    if(markStr[3] > '4') markStr[2]++;
    markStr.erase(3, markStr.size());
    markStr[1] = '.';
    return markStr;
}
