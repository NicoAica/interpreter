//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_PRINTSTMT_H
#define INTERPRETER_PRINTSTMT_H


#include "NumExpr.h"

class PrintStmt {
public:

    explicit PrintStmt(NumExpr* n) : number{n} {}

private:
    NumExpr* number;

};


#endif //INTERPRETER_PRINTSTMT_H
