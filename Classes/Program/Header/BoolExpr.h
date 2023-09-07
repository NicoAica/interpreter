//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BOOLEXPR_H
#define INTERPRETER_BOOLEXPR_H


#include "NumExpr.h"

class BoolExpr {
public:

     BoolExpr(bool value) : value{value} {};
     BoolExpr() = default;

private:
    bool value;

};


#endif //INTERPRETER_BOOLEXPR_H
