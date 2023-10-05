//
// Created by user on 03.10.2023.
//

#include "../../Headers/Controllers/StudentsDataBaseController.h"

bool StudentsDataBaseController::addStudent(const std::string& fullName, const std::string& groupNumber,
                                            const std::string& idCard,  const std::string& averageMark) {
    if (studentsDataBase.get([idCard](const Student& student) {
        return student.getIdCard() == idCard;
        }) == nullptr) 
    {
        this->studentsDataBase.add(Student{ idCard, groupNumber, fullName, std::stof(averageMark.c_str()) });
        return true;
    }
    else return false;
}

bool StudentsDataBaseController::deleteStudent(const std::string &idCard) {
    auto student = studentsDataBase.get([idCard](Student student){
        return student.getIdCard() == idCard;
    });
    if (student == nullptr) return false;
    else studentsDataBase.del(student[0].second);
    return true;
}

std::pair<Student, int> *StudentsDataBaseController::findStdent(std::string idCard) {
    return studentsDataBase.get([idCard](Student student){
        return student.getIdCard() == idCard;
    });;
}

void StudentsDataBaseController::editStudent(int index,
                                             const std::string &newFullName,
                                             const std::string &newGroupNumber,
                                             const std::string &newIdCard)
                                             {
    if (!newFullName.empty()) studentsDataBase.get(index).setFullName(newFullName);
    if (!newGroupNumber.empty()) studentsDataBase.get(index).setGroupNumber(newGroupNumber);
    if (!newIdCard.empty()) studentsDataBase.get(index).setIdCard(newIdCard);
}

myVector<Student> StudentsDataBaseController::getStudents(std::function<bool(Student)> filter) {
    myVector<Student> output;
    auto students = studentsDataBase.getAll(filter);
    for (int i = 0; i < students.size(); i++)
        output.push_back(students[i].first);
    return output;
}

myVector<Student> StudentsDataBaseController::sort(std::function<bool(Student, Student)> filter)
{
    return mydb::StudentsDataBase::sort(studentsDataBase.getAllRaw(), filter);
}

void StudentsDataBaseController::saveToFile()
{
    this->studentsDataBase.saveToFile();
}
