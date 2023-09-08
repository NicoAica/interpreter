//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_NUMEXPR_H
#define INTERPRETER_NUMEXPR_H

class Visitor;

class NumExpr {
public:

    virtual void accept(Visitor *v) = 0;

};


#endif //INTERPRETER_NUMEXPR_H
