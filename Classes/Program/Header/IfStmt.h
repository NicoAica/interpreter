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

private:
    Block* trueBlock;
    Block* falseBlock;
    BoolExpr* condition;
};


#endif //INTERPRETER_IFSTMT_H
