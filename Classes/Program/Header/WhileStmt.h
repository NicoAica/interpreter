//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_WHILESTMT_H
#define INTERPRETER_WHILESTMT_H


#include "BoolExpr.h"
#include "Block.h"

class WhileStmt {

public:
    WhileStmt(BoolExpr* c, Block* b): condition{c}, block{b} {}

private:
    BoolExpr* condition;
    Block* block;
};


#endif //INTERPRETER_WHILESTMT_H
