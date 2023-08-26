//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_INPUTSTMT_H
#define INTERPRETER_INPUTSTMT_H


#include "Variable.h"

class InputStmt {
public:

    explicit InputStmt(Variable* v) : variable{v} {}

private:
    Variable* variable;
};


#endif //INTERPRETER_INPUTSTMT_H
