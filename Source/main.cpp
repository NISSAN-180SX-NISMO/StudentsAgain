#include <iostream>
#include <vector>
#include "../Headers/myVector.h"
#include "../Headers/Student.h"
#include "../Headers/Printer.h"
#include "../Headers/Serializer.h"



#include "fstream"
#include "../Headers/StudentsDataBase.h"

int main() {

    mydb::StudentsDataBase students;


    students.add(Student{  "111","01","semen", 4 });
    students.add(Student{  "222","02","ivan", 5 });
    students.add(Student{  "333","03","anton", 3 });


    students.saveToFile();
    mydb::StudentsDataBase test;
    test.loadToFile();
    Printer::print(test.getAll());


}
