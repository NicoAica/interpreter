//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_VARIABLE_H
#define INTERPRETER_VARIABLE_H


#include <string>
#include <utility>
#include "NumExpr.h"

class Variable: public NumExpr {

public:

    Variable(std::string _name): name{std::move(_name)} {};

private:
    std::string name;
};


#endif //INTERPRETER_VARIABLE_H
