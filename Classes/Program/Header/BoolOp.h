//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BOOLOP_H
#define INTERPRETER_BOOLOP_H


#include "BoolExpr.h"


class Visitor;

class BoolOp: public BoolExpr {
public:
     enum BoolOpCode {AND, OR, NOT};

     BoolOp(BoolOpCode o, BoolExpr* l, BoolExpr* r) : op{ o }, left{ l }, right{ r } { };
     BoolOp(BoolOpCode o, BoolExpr* l) : op{ o }, left{ l }, right{nullptr} { };

     void accept(Visitor* v) override;

    BoolExpr* getLeft() {
        return left;
    }

    BoolExpr* getRight() {
        return right;
    }

    BoolOpCode getCode() {
        return op;
    }

private:
     BoolOpCode op;
     BoolExpr* left;
     BoolExpr* right;
};


#endif //INTERPRETER_BOOLOP_H
