#include "../../../Headers/Validator.h"

Validator::Validator(std::string source) {
    this->value = source;
}

bool Validator::operator()(FORMAT index) {
    return (std::regex_match(this->value, std::regex(formats[index])));
}

