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

    BoolExpr* get_condition(){
        return condition;
    }

    Block* get_block() {
        return block;
    }

    void accept(Visitor* v) override;

private:
    BoolExpr* condition;
    Block* block;
};


#endif //INTERPRETER_WHILESTMT_H
