#pragma once
#include <fstream>
#include "DataBaseAdapter.h"
#include "../Entities/Student.h"

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

        std::pair<Student, int>* get(std::function<bool(Student)> filter = [](Student){return true;}) override;
        myVector<std::pair<Student, int>> getAll(std::function<bool(Student)> filter = [](Student){return true;}) override;
        myVector<Student> getAllRaw() override;
        void saveToFile() override;
        void loadFromFile() override;
        static myVector<Student> sort(myVector<Student> students, std::function<bool(Student, Student)> filter = [](Student, Student){return true;});
    };
}