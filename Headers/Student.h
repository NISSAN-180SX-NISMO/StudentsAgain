#ifndef STUDENTMANAGER_STUDENT_H
#define STUDENTMANAGER_STUDENT_H
#pragma once
#include <string>
#include "myVector.h"
#include <fstream>

class Student {
private:
    std::string idCard;     // primary key
    std::string groupNumber;
    std::string fullName;
    float averageMark = 0;
public:
    Student();
    Student(const std::string &idCard, const std::string &groupNumber, const std::string &fullName, float averageMark);
    Student(const Student& other);
    ~Student();
    const std::string getIdCard() const;
    void setIdCard(const std::string &idCard);
    const std::string getGroupNumber() const;
    void setGroupNumber(const std::string &groupNumber);
    const std::string getFullName() const;
    void setFullName(const std::string &fullName);
    const float getAverageMark() const;
    void addMark(int mark);

    void save(std::ofstream& out);
    static Student load(std::string line);
};

#endif //STUDENTMANAGER_STUDENT_H
