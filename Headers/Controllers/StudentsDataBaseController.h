#pragma once
#include "../DataBase/StudentsDataBase.h"
#include "../Entities/Student.h"

class StudentsDataBaseController {
private:
    mydb::StudentsDataBase studentsDataBase;
public:
    StudentsDataBaseController() = default;
    bool addStudent(const std::string& fullName, const std::string& groupName, const std::string& idCard, const std::string& averageMark);
    bool deleteStudent(const std::string& idCard);
    std::pair<Student, int>* findStdent(std::string idCard);
    void editStudent(int index, const std::string& newFullName, const std::string& newGroupName, const std::string& newIdCard);
    void putMark(Student, int mark);
    myVector<Student> getStudents(std::function<bool(Student)> filter = [](Student){return true;});
    myVector<Student> sort(std::function<bool(Student, Student)> filter = [](Student, Student){return true;});

    void saveToFile();
};