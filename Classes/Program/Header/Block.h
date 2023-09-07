//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BLOCK_H
#define INTERPRETER_BLOCK_H

#include <vector>

class Visitor;

#include "Statement.h"

class Block {

public:
    void accept(Visitor* v);
/*
    void push(Statement* _s) {
        statement.push_back(_s);
    }
*/
private:
    //std::vector<Statement *> statement;
};


#endif //INTERPRETER_BLOCK_H
