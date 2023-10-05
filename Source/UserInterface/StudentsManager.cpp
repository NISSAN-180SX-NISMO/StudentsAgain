#include "../../Headers/UserInterface/StudentsManager.h"
#include "../../Headers/Utils/Util.h"

StudentsDataBaseController StudentsManager::controller = StudentsDataBaseController();

void StudentsManager::addStudent() {
    std::string surname =       input("Введите фамилию студента: ", FORMAT::SURNAME),
                name =          input("Введите имя студента: ", FORMAT::NAME),
                patronymic =    input("Введите отчество студента: ", FORMAT::PATRONYMIC),
                groupNumber =   input("Введите номер группы: ", FORMAT::GROUP_NUMBER),
                idCard =        input("Введите номер студенческого билета: ", FORMAT::ID_CARD),
                AverageMark =   input("Введите средний балл (или введите \"0\" если оценок не было): ", FORMAT::AVERAGE_MARK);
    if (controller.addStudent(surname + " " + name + " " + patronymic, groupNumber, idCard, AverageMark))
        std::cout << "Студент успешно добавлен!" << std::endl;
    else std::cout << "Ошибка! Такой студент уже есть!" << std::endl;
    pause();
}

void StudentsManager::deleteStudent() {
    std::string idCard = input("Введите номер студенческого билета удаляемого студента: ", FORMAT::ID_CARD);
    if (controller.deleteStudent(idCard)) std::cout << "Студент успешно удален!" << std::endl;
    else std::cout << "Ошибка! Такого студента не существует!" << std::endl;
    pause();
}

void StudentsManager::editStudent() {
    std::string idCard = input("Введите номер студенческого билета удаляемого студента: ", FORMAT::ID_CARD);
    auto student = controller.findStdent(idCard);
    if (!student) {
        std::cout << "Ошибка! Студент не найден!" << std::endl;
        return;
    }

    Printer::print(myVector<Student> { student->first});
    std::cout << "Введите новые значения для одного или нескольких полей:" << std::endl;
    std::string newSurname =       input("Введите фамилию студента: ", FORMAT::SURNAME),
            newName =          input("Введите имя студента: ", FORMAT::NAME),
            newPatronymic =    input("Введите отчество студента: ", FORMAT::PATRONYMIC),
            newGroupNumber =   input("Введите номер группы: ", FORMAT::GROUP_NUMBER),
            newIdCard =        input("Введите номер студенческого билета: ", FORMAT::ID_CARD);
    controller.editStudent(student->second,  + " " + newName + " " + newPatronymic, newGroupNumber, newIdCard);
    pause();
}

void StudentsManager::findStudentByFullname(float similarityCoef) {
    std::string fullName = input("Введите фамилию студента: ", FORMAT::NONE);
    auto students = controller.getStudents([fullName, similarityCoef](Student student) {
        return Util::getJaccardCoef(student.getFullName(),fullName) > similarityCoef;
        });
    if (students.size() == 0)
        std::cout << "Студенты с таким ФИО н найдены" << std::endl;
    else {
        std::cout << "Найденные студенты:" << std::endl;
        Printer::print(students);
    }
    pause();
}

void StudentsManager::findStudentByGroupNumber() {
    std::string groupNumber = input("Введите номер группы: ", FORMAT::NONE);
    auto students = controller.getStudents([groupNumber](Student student) {
        return student.getGroupNumber() == groupNumber;
    });
    if (students.size() == 0)
        std::cout << "Студенты из этой группы не найдены" << std::endl;
    else {
        std::cout << "Найденные студенты:" << std::endl;
        Printer::print(students);
    }
    pause();
}

void StudentsManager::findStudentByIdCard_Match() {
    std::string mark = input("Введите оценку (целое или десятичное число от 2 до 5): ", FORMAT::NONE);
    if (mark.size() > 1) if (mark[1] == '.') mark[1] = ',';
    auto students = controller.getStudents([mark](Student student) {
        return student.getAverageMarkStr() == mark;
    });
    if (students.size() == 0)
        std::cout << "Студенты с таким средним баллом не найдены" << std::endl;
    else {
        std::cout << "Найденные студенты:" << std::endl;
        Printer::print(students);
    }
    pause();
}

void StudentsManager::findStudentByIdCard_Between() {
    std::string first_mark = input("Введите нижнюю границу (целое или десятичное число от 2 до 5): ", FORMAT::NONE);
    std::string second_mark = input("Введите верхнюю границу (целое или десятичное число от 2 до 5): ", FORMAT::NONE);
    if (first_mark.size() > 1) if (first_mark[1] == '.') first_mark[1] = ',';
    if (second_mark.size() > 1) if (second_mark[1] == '.') second_mark[1] = ',';
    auto students = controller.getStudents([first_mark, second_mark](Student student) {
        return student.getAverageMarkStr() >= first_mark && student.getAverageMarkStr() <= second_mark;
    });
    if (students.size() == 0)
        std::cout << "Студенты с таким средним баллом не найдены" << std::endl;
    else {
        std::cout << "Найденные студенты:" << std::endl;
        Printer::print(students);
    }
    pause();
}

void StudentsManager::printStudents(SORT flag) {
    switch (flag) {
        case SORT::NONE:Printer::print(controller.getStudents()); break;
        case SORT::FULLNAME:Printer::print(controller.sort([](Student first, Student second) {
                return first.getFullName() > second.getFullName(); })); break;
        case SORT::GROUP_NUMBER:Printer::print(controller.sort([](Student first, Student second) {
                return first.getGroupNumber() > second.getGroupNumber(); })); break;
        case SORT::ID_CARD:Printer::print(controller.sort([](Student first, Student second) {
                return first.getIdCard() > second.getIdCard(); })); break;
        case SORT::AVERAGE_MARK:Printer::print(controller.sort([](Student first, Student second) {
                return first.getAverageMarkStr() > second.getAverageMarkStr(); })); break;
    }
    pause();
}

void StudentsManager::saveAndExit() {
    controller.saveToFile();
    std::cout << "Данные сохранены" << std::endl;
    exit(0);
}

std::string StudentsManager::input(const std::string& title, FORMAT format) {
    while (true) {
        std::string input;
        std::cout << title;
        getline(std::cin, input);
        Validator inputValidator(input);
        if (inputValidator(format)) return input;
        std::cout << "Format Error! Repeat the input please!" << std::endl;
    }
}

void StudentsManager::pause()
{
    std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
    _getch();
}

void StudentsManager::putMark() {
    std::string idCard = input("Введите номер студенческого билета студента: ", FORMAT::ID_CARD);
    auto student = controller.findStdent(idCard);
    if (!student) {
        std::cout << "Ошибка! Студент не найден!" << std::endl;
        return;
    }
    std::string mark = input("Введите оценку (целое число от 2 до 5): ", FORMAT::MARK);

    pause();
}



