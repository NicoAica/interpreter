//
// Created by Nicolò Aicardi on 25/08/2023.
//

#ifndef INTERPRETER_STRINGHELPER_H
#define INTERPRETER_STRINGHELPER_H

#include <string>

#include <sstream>
#include <cctype>

class StringHelper {

public:

    static bool isNumber(const std::string& str) {
        if (str.empty() || (!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
            return false;
        }

        for (size_t i = 1; i < str.length(); ++i) {
            if (!std::isdigit(str[i])) {
                return false;
            }
        }

        if (str.length() > 1 && str[0] == '0') {
            return false;
        }

        return true;
    }
};


#endif //INTERPRETER_STRINGHELPER_H
