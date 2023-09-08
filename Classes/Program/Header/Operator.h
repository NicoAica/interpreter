//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_OPERATOR_H
#define INTERPRETER_OPERATOR_H


#include "NumExpr.h"

class Visitor;

class Operator : public NumExpr {

public:

    enum OpCode {ADD, SUB, MUL, DIV};

    Operator(OpCode o, NumExpr* lop, NumExpr* rop) :
            op{ o }, left{ lop }, right{ rop } { };

    NumExpr* getLeft(){ return left; }
    NumExpr* getRight(){ return right; }
    OpCode getCode(){ return op; }

    void accept(Visitor *v) override;

private:
    OpCode      op;
    NumExpr* left;
    NumExpr* right;

};


#endif //INTERPRETER_OPERATOR_H
