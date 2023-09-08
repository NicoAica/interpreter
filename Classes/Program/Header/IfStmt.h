//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_IFSTMT_H
#define INTERPRETER_IFSTMT_H


#include "Block.h"
#include "BoolExpr.h"
#include "Statement.h"

class Visitor;

class IfStmt: public Statement{

public:
    IfStmt(BoolExpr* c, Block* _true, Block* _false) :
            trueBlock{ _true }, falseBlock{_false}, condition{c} {};

    void accept(Visitor* v) override;

    Block* get_true_block() {
        return trueBlock;
    }

    Block* get_false_block() {
        return falseBlock;
    }

    BoolExpr* get_condition() {
        return condition;
    }

private:
    Block* trueBlock;
    Block* falseBlock;
    BoolExpr* condition;
};


#endif //INTERPRETER_IFSTMT_H
