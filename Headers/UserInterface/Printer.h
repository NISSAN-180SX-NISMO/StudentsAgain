#pragma once
#include <iostream>
#include "../Entities/Student.h"

class Printer {
private:
    static std::string getLine(int size, char type);
public:
    static void printTitle(std::ostream* out = &std::cout);
    static void print (Student, std::ostream* out = &std::cout);
    static void print (myVector<Student>, std::ostream* out = &std::cout);
};
