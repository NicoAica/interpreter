//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_VARIABLE_H
#define INTERPRETER_VARIABLE_H


#include <string>
#include <utility>

class Variable {

public:

    Variable(std::string _name): name{std::move(_name)} {};

private:
    std::string name;
};


#endif //INTERPRETER_VARIABLE_H
