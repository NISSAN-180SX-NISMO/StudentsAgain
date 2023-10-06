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
    MARK
};

class Validator {
private:
    std::string value;
    std::vector<std::string> formats {
            "[\\d\\D]*", // none
            "[À-ß][à-ÿ¸]+(-[À-ß][à-ÿ¸]+)?", // surname
            "[À-ß][à-ÿ¸]+", // name
            "[À-ß][à-ÿ¸]+", // patronymic
            "[0-9]{4}",     // groupNumber
            "20(([0-1][0-9])|(2[0-3]))/([0-9]{4})", // idCard
            "0|(([2-4](,[0-9])?)|(5)(,0)?)", // averageMark
            "[2-5]", // mark
    };
public:
    explicit Validator(std::string source);
    bool operator()(FORMAT);
};


