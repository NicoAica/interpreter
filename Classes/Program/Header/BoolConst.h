//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BOOLCONST_H
#define INTERPRETER_BOOLCONST_H


#include "BoolExpr.h"

class Visitor;

class BoolConst: public BoolExpr {

public:
    BoolConst(bool _value) : value{_value} {}

    void accept(Visitor *v) override;

    bool get_value(){
        return value;
    }

private:
    bool value;
};


#endif //INTERPRETER_BOOLCONST_H
