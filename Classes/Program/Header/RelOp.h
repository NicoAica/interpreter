//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_RELOP_H
#define INTERPRETER_RELOP_H

#include "BoolExpr.h"

class RelOp: public BoolExpr {
public:

    enum RelOpCode { LT, GT, EQ };

    RelOp(RelOpCode o, NumExpr* l, NumExpr* r) :
    op{ o }, left{ l }, right{ r } { }

private:
    RelOpCode  op;
    NumExpr* left;
    NumExpr* right;
};



#endif //INTERPRETER_RELOP_H
