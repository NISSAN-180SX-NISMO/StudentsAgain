#ifndef STUDENTMANAGER_STUDENTSDATABASE_H
#define STUDENTMANAGER_STUDENTSDATABASE_H

#include "DataBaseAdapter.h"
#include "Student.h"

namespace mydb {
    template<class value>
    class StudentsDataBase : public DataBaseAdapter<Student> {
    private:
        std::vector<Student> insideDataBase;
    public:
        void add(Student student) override;
        void del(int index) override;
        void edit(int index, Student student) override;
        Student get(int index) override;
        std::vector<Student> getAll(int index, bool filter) override;
        void sort(bool filter) override;
    };
}


#endif //STUDENTMANAGER_STUDENTSDATABASE_H
