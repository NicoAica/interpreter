//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BOOLEXPR_H
#define INTERPRETER_BOOLEXPR_H


#include "NumExpr.h"
class Visitor;

class BoolExpr {
public:
     BoolExpr() = default;

     virtual void accept(Visitor *v) = 0;

};


#endif //INTERPRETER_BOOLEXPR_H
