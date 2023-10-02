//
// Created by user on 30.09.2023.
//

#ifndef STUDENTMANAGER_MYVECTOR_H
#define STUDENTMANAGER_MYVECTOR_H


#include <initializer_list>

template<class value>
class myVector {
private:
    value* dataArray = nullptr;
    int currentSize = 0;
public:
    myVector();
    myVector(std::initializer_list<value> initList);
    void push_back(value);
    void erase(const int index);
    void insert(const int index, value);
    int size();
    value& operator[](int index);

};

template<class value>
myVector<value>::myVector() {

}

template<class value>
myVector<value>::myVector(std::initializer_list<value> initList) {
    currentSize = initList.size();
    dataArray = new value[currentSize];
    int i = 0;
    for (const value& val : initList) {
        dataArray[i++] = val;
    }
}

template<class value>
void myVector<value>::push_back(value newValue) {
    value* temp = new value[currentSize + 1];
    for (int i = 0; i < currentSize; ++i)
        temp[i] = dataArray[i];
    temp[currentSize] = newValue;
    delete[] dataArray;
    dataArray = temp;
    currentSize++;
}

template<class value>
void myVector<value>::erase(const int index) {
    if (index < 0 || index >= currentSize) return;
    value* temp = new value[currentSize - 1];
    for (int i = 0, j = 0; i < currentSize; ++i, ++j) {
        if (i == index) --j;
        else temp[j] = dataArray[i];
    }
    delete[] dataArray;
    dataArray = temp;
    currentSize--;
}

template<class value>
void myVector<value>::insert(const int index, value newValue) {
    if (index < 0 || index >= currentSize) return;
    value* temp = new value[currentSize + 1];
    for (int i = 0, j = 0; i < currentSize; ++i, ++j) {
        if (i == index) {
            temp[i] = newValue;
            --j;
        } else temp[i] = dataArray[j];
    }
    delete[] dataArray;
    dataArray = temp;
    currentSize++;
}

template<class value>
int myVector<value>::size() {
    return currentSize;
}

template<class value>
value &myVector<value>::operator[](int index) {
    return dataArray[index];
}


#endif //STUDENTMANAGER_MYVECTOR_H
