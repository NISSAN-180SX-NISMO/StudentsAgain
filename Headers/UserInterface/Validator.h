#pragma once
#include <string>
#include <regex>
enum FORMAT {
    NONE,
    SURNAME,
    NAME,
    PATRONYMIC,
    GROUP_NUMBER,
    ID_CARD,
    AVERAGE_MARK,
    MARK,
    UNSIGNED_INTEGER
};

class Validator {
private:
    std::string value;
    std::vector<std::string> formats {
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*",
            "[\\d\\D]*"
    };
public:
    explicit Validator(std::string source);
    bool operator()(FORMAT);
};


