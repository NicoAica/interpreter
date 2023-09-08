//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_NUMBER_H
#define INTERPRETER_NUMBER_H


#include "NumExpr.h"
class Visitor;

class Number: public NumExpr {
public:

    // Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Number(int v) : value{ v } { }
    ~Number() = default;

    Number(const Number& other) = default;
    Number& operator=(const Number& other) = default;

    void accept(Visitor *v) override;

    int get_value() const {
        return value;
    }

private:
    int value;
};


#endif //INTERPRETER_NUMBER_H
