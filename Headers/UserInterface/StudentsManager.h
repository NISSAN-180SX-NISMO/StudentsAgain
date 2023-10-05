#pragma once
#include <iostream>
#include <conio.h>
#include "Printer.h"
#include "Validator.h"
#include "../Controllers/StudentsDataBaseController.h"


class StudentsManager {
private:
    static StudentsDataBaseController controller;
    static std::string input(const std::string& title, FORMAT);
    static void pause();
public:
    enum class SORT {
        NONE,
        ID_CARD,
        GROUP_NUMBER,
        FULLNAME,
        AVERAGE_MARK
    };
    static void addStudent();
    static void deleteStudent();
    static void editStudent();
    static void findStudentByFullname(float similarityCoef);
    static void findStudentByGroupNumber();
    static void findStudentByIdCard_Match();
    static void findStudentByIdCard_Between();
    static void printStudents(SORT = SORT::NONE);
    static void putMark();
    static void saveAndExit();
};
