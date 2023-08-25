//
// Created by Nicolò Aicardi on 24/08/2023.
//

#include <sstream>
#include "Token.h"

std::ostream& operator<<(std::ostream& os, const Token& t) {
    std::stringstream tmp;
    tmp << t.tag << " : " << t.word;
    os << tmp.str();
    return os;
}