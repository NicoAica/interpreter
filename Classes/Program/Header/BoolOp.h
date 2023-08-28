//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BOOLOP_H
#define INTERPRETER_BOOLOP_H


#include "BoolExpr.h"

class BoolOp {
public:
     enum BoolOpCode {};

     BoolOp(BoolOpCode o, BoolExpr* l, BoolExpr* r) : op{ o }, left{ l }, right{ r } { };
     BoolOp(BoolOpCode o, BoolExpr* l) : op{ o }, left{ l }, right{nullptr} { };

private:
     BoolOpCode op;
     BoolExpr* left;
     BoolExpr* right;
};


#endif //INTERPRETER_BOOLOP_H
