//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_NUMEXPR_H
#define INTERPRETER_NUMEXPR_H

class Visitor;

class NumExpr {

    void accept(Visitor *v);

};


#endif //INTERPRETER_NUMEXPR_H
