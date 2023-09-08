//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_VARIABLE_H
#define INTERPRETER_VARIABLE_H


#include <string>
#include <utility>
#include "NumExpr.h"

class Visitor;

class Variable: public NumExpr {

public:

    Variable(std::string _name): name{std::move(_name)} {};


    std::string get_name() const {
        return name;
    }

    void accept(Visitor* v) override;

private:
    std::string name;
};


#endif //INTERPRETER_VARIABLE_H
