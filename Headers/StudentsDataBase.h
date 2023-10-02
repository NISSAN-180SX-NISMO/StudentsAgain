#ifndef STUDENTMANAGER_STUDENTSDATABASE_H
#define STUDENTMANAGER_STUDENTSDATABASE_H
#pragma once
#include <fstream>
#include "DataBaseAdapter.h"
#include "Student.h"

namespace mydb {
    class StudentsDataBase : public DataBaseAdapter<Student> {
    private:
        std::string filename = "save.txt";
        myVector<Student> insideDataBase;
    public:
        StudentsDataBase();
        void add(Student student) override;
        void del(int index) override;
        void edit(int index, Student student) override;
        Student get(int index) override;

        void saveToFile();
        void loadToFile();
        myVector<Student> getAll(bool filter = true) override;
        void sort(bool filter) override;
    };
}


#endif //STUDENTMANAGER_STUDENTSDATABASE_H
