//
// Created by nicol on 25/08/2023.
//

#ifndef INTERPRETER_MANAGER_H
#define INTERPRETER_MANAGER_H

#include <vector>

#include "../Program/Header/NumExpr.h"
#include "../Program/Header/Operator.h"
#include "../Program/Header/Number.h"

class Manager {
public:

    Manager() = default;
    ~Manager() = default;

    Manager(const Manager& other) = delete;
    Manager& operator=(const Manager& other) = delete;

    template<typename T> static void clearMemory(std::vector<T>& vector) {
        auto i = vector.begin();
        for (; i != vector.end(); ++i) {
            delete(*i);
        }
        vector.resize(0);
    };


};


class NumExprManager : public Manager {

public:
    NumExpr* makeOperator(Operator::OpCode op, NumExpr* l, NumExpr* r) {
        auto* o = reinterpret_cast<NumExpr *>(new Operator(op, l, r));
        numExprAllocated.push_back(o);
        return o;
    }

    NumExpr* makeNumber(int value) {
        auto* n = reinterpret_cast<NumExpr *>(new Number(value));
        numExprAllocated.push_back(n);
        return n;
    }

    ~NumExprManager() {
        clearMemory(numExprAllocated);
    };

private:
    std::vector<NumExpr*> numExprAllocated;
};


#endif //INTERPRETER_MANAGER_H
