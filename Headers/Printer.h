//
// Created by user on 02.10.2023.
//

#ifndef STUDENTMANAGER_PRINTER_H
#define STUDENTMANAGER_PRINTER_H

#include <iostream>
#include "Student.h"

class Printer {
public:
    static void print (Student, std::ostream* out = &std::cout);
    static void print (myVector<Student>, std::ostream* out = &std::cout);
};


#endif //STUDENTMANAGER_PRINTER_H
