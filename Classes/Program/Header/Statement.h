//
// Created by nicol on 26/08/2023.
//

#ifndef INTERPRETER_STATEMENT_H
#define INTERPRETER_STATEMENT_H

#include "Block.h"

class Visitor;

class Statement {

public:
    Statement() = default;

    virtual void accept(Visitor* v) = 0;

};


#endif //INTERPRETER_STATEMENT_H
