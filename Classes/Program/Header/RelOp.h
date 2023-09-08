//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_RELOP_H
#define INTERPRETER_RELOP_H

#include "BoolExpr.h"

class Visitor;

class RelOp: public BoolExpr {
public:

    enum RelOpCode { LT, GT, EQ };

    RelOp(RelOpCode o, NumExpr* l, NumExpr* r) :
    op{ o }, left{ l }, right{ r } { }

    void accept(Visitor *v) override;

    NumExpr* getLeft() {
        return left;
    }

    NumExpr* getRight() {
        return right;
    }

    RelOpCode getCode() {
        return op;
    }

private:
    RelOpCode  op;
    NumExpr* left;
    NumExpr* right;
};



#endif //INTERPRETER_RELOP_H
