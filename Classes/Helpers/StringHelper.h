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
        std::istringstream ss(str);
        double num;
        return (ss >> num) && (ss.eof() || ss.peek() == '\n');
    }
};


#endif //INTERPRETER_STRINGHELPER_H
