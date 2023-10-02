//
// Created by user on 02.10.2023.
//

#ifndef STUDENTMANAGER_MENUCASE_H
#define STUDENTMANAGER_MENUCASE_H


#include <iostream>

namespace MenuCase {
    void printCases(){
        std::cout << "1 Добавить студента в список" << std::endl;
        std::cout << "2 Удалить студента из списка" << std::endl;
        std::cout << "3 Изменить данные о студенте" << std::endl;
        std::cout << "4 Поиск студента..." << std::endl;
        std::cout << "5 Вывести список студентов..." << std::endl;
        std::cout << "6 Загрузить данные из файла" << std::endl;
        std::cout << "0 Сохранение и выход" << std::endl;
    }
};


#endif //STUDENTMANAGER_MENUCASE_H
