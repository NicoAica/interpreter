//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_SETSTMT_H
#define INTERPRETER_SETSTMT_H


#include "Variable.h"
#include "NumExpr.h"

class SetStmt {
public:

    SetStmt(NumExpr* n, Variable* v) : number{n}, variable{v} {}

private:
    NumExpr* number;
    Variable* variable;

};


#endif //INTERPRETER_SETSTMT_H
