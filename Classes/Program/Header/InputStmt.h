//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_INPUTSTMT_H
#define INTERPRETER_INPUTSTMT_H


#include "Variable.h"
#include "Statement.h"

class Visitor;

class InputStmt : public Statement{
public:

    explicit InputStmt(Variable* v) : variable{v} {}

    void accept(Visitor* v) override;

private:
    Variable* variable;
};


#endif //INTERPRETER_INPUTSTMT_H
