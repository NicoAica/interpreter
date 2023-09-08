//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_PRINTSTMT_H
#define INTERPRETER_PRINTSTMT_H


#include "NumExpr.h"
#include "Statement.h"

class Visitor;

class PrintStmt: public Statement {
public:

    PrintStmt(NumExpr* n) : number{n} {}

    void accept(Visitor* v) override;

    NumExpr* get_value(){
        return number;
    }

private:
    NumExpr* number;

};


#endif //INTERPRETER_PRINTSTMT_H
