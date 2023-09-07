//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_WHILESTMT_H
#define INTERPRETER_WHILESTMT_H


#include "BoolExpr.h"
#include "Block.h"
#include "Statement.h"

class Visitor;


class WhileStmt: public Statement {

public:
    WhileStmt(BoolExpr* c, Block* b): condition{c}, block{b} {}

    void accept(Visitor* v) override;

private:
    BoolExpr* condition;
    Block* block;
};


#endif //INTERPRETER_WHILESTMT_H
