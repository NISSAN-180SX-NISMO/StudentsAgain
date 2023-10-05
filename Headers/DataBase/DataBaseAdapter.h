#pragma once
#include <functional>
#include "myVector.h"
#include "../Entities/Student.h"

namespace mydb {
    template<class something>
    class DataBaseAdapter {
    public:
        virtual void add(something) = 0;
        virtual void del(int index) = 0;
        virtual void edit(int index, something) = 0;
        virtual something get(int index) = 0;
        virtual std::pair<something, int>* get(std::function<bool(Student)>) = 0;
        virtual myVector<std::pair<something, int>> getAll(std::function<bool(Student)>) = 0;
        virtual myVector<something> getAllRaw() = 0;
        virtual void saveToFile() = 0;
        virtual void loadFromFile() = 0;
        
    };
}