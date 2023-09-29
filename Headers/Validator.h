#include <string>
#include <regex>

enum FORMAT {
    ID_CARD,
    GROUP_NUMBER,
    FULLNAME,
    MARK,
    INTEGER
};

class Validator {
private:
    std::string value;
    std::vector<std::string> formats {
            "",
            "",
            "",
            "",
            "",
    };
public:
    explicit Validator(std::string source);
    bool operator()(FORMAT);
};


