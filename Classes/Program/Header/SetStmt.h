//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_SETSTMT_H
#define INTERPRETER_SETSTMT_H


#include "Variable.h"
#include "NumExpr.h"
#include "Statement.h"

class SetStmt: public Statement {
public:

    SetStmt(NumExpr* n, Variable* v) : number{n}, variable{v} {}

    void accept(Visitor* v) override;

    Variable* get_variable() const {
        return variable;
    }

    NumExpr* get_value() const {
        return number;
    }

private:
    NumExpr* number;
    Variable* variable;

};


#endif //INTERPRETER_SETSTMT_H
