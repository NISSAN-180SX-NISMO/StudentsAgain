cmake_minimum_required(VERSION 3.26)
project(StudentManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(StudentManager Source/main.cpp
        Headers/Entities/Student.h
        Source/Entities/Student.cpp
        Headers/DataBase/DataBaseAdapter.h
        Source/DataBase/StudentsDataBase.cpp
        Headers/DataBase/StudentsDataBase.h
        Source/UserInterface/Validators/Validator.cpp
        Headers/UserInterface/Validator.h
        Source/DataBase/DataStruct/myVector.cpp
        Headers/DataBase/myVector.h
        Source/UserInterface/Printer/Printer.cpp
        Headers/UserInterface/Printer.h
        Source/UserInterface/StudentsManager.cpp
        Headers/UserInterface/StudentsManager.h
        Source/UserInterface/ConsoleMenu/ConsoleMenu.cpp
        Headers/ConsoleMenu/ConsoleMenu.h
        Headers/ConsoleMenu/ConsoleMenuFailures.h
        Source/Controllers/StudentsDataBaseController.cpp
        Headers/Controllers/StudentsDataBaseController.h
)
