//
// Created by Nicolò Aicardi on 25/08/2023.
//


/*************
 *                                                   Manager
 * Il Manager sarà l'elemento del programma a cui verrà affidata la gestione della memorizzazione della struttura ad
 * albero.
 *
 *************/


#ifndef INTERPRETER_MANAGER_H
#define INTERPRETER_MANAGER_H

#include <utility>
#include <vector>
#include <string>
#include <sstream>

#include "../Program/Header/NumExpr.h"
#include "../Program/Header/Operator.h"
#include "../Program/Header/Number.h"
#include "../Program/Header/Block.h"
#include "../Program/Header/BoolExpr.h"
#include "../Program/Header/RelOp.h"
#include "../Program/Header/BoolOp.h"
#include "../Program/Header/Statement.h"
#include "../Program/Header/IfStmt.h"
#include "../Program/Header/WhileStmt.h"
#include "../Program/Header/Variable.h"
#include "../Program/Header/InputStmt.h"
#include "../Program/Header/PrintStmt.h"
#include "../Program/Header/SetStmt.h"
#include "../Program/Header/Program.h"

#include "../Error/Exceptions.h"
#include "../Program/Header/BoolConst.h"

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

class ProgramManager : public Manager {
public:
    Program* makeProgram(Block* _b) {
        auto* b = new Program(_b);
        programAllocated.push_back(b);
        return b;
    }

    ~ProgramManager() {
        clearMemory(programAllocated);
    };

private:
    std::vector<Program*> programAllocated;
};


class BlockManager : public Manager {
public:
    Block* makeBlock() {
        auto* b = new Block();
        blockAllocated.push_back(b);
        return b;
    }

    ~BlockManager() {
        clearMemory(blockAllocated);
    };

private:
    std::vector<Block*> blockAllocated;
};

class BoolExprManager : public Manager {
public:
    BoolExpr* makeBoolConst(bool value) {
        auto* b = reinterpret_cast<BoolExpr *>(new BoolConst(value));
        boolExprAllocated.push_back(b);
        return b;
    }

    BoolExpr* makeRelOp(RelOp::RelOpCode o, NumExpr* l, NumExpr* r) {
        auto* b = reinterpret_cast<BoolExpr *>(new RelOp(o, l, r));
        boolExprAllocated.push_back(b);
        return b;
    }

    BoolExpr* makeBoolOp(BoolOp::BoolOpCode o, BoolExpr* l, BoolExpr* r) {
        auto* b = reinterpret_cast<BoolExpr *>(new BoolOp(o, l, r));
        boolExprAllocated.push_back(b);
        return b;
    }

    BoolExpr* makeBoolOp(BoolOp::BoolOpCode o, BoolExpr* l) {
        auto* b = reinterpret_cast<BoolExpr *>(new BoolOp(o, l));
        boolExprAllocated.push_back(b);
        return b;
    }

    ~BoolExprManager() {
        clearMemory(boolExprAllocated);
    };

private:
    std::vector<BoolExpr*> boolExprAllocated;
};

class StatementManager : public Manager {
public:
    Statement* makeIfStmt(BoolExpr* c, Block* _true, Block* _false) {
        auto* b = reinterpret_cast<Statement *>(new IfStmt(c, _true, _false));
        statementAllocated.push_back(b);
        return b;
    }

    Statement* makeWhileStmt(BoolExpr* c, Block* _b) {
        auto* b = reinterpret_cast<Statement *>(new WhileStmt(c, _b));
        statementAllocated.push_back(b);
        return b;
    }

    Statement* makeInputStmt(Variable* v) {
        auto* b = reinterpret_cast<Statement *>(new InputStmt(v));
        statementAllocated.push_back(b);
        return b;
    }

    Statement* makePrintStmt(NumExpr* n) {
        auto* b = reinterpret_cast<Statement *>(new PrintStmt(n));
        statementAllocated.push_back(b);
        return b;
    }

    Statement* makeSetStmt(NumExpr* n, Variable* v) {
        auto* b = reinterpret_cast<Statement *>(new SetStmt(n, v));
        statementAllocated.push_back(b);
        return b;
    }

    ~StatementManager() {
        clearMemory(statementAllocated);
    };

private:
    std::vector<Statement*> statementAllocated;
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

    NumExpr* makeVariable(std::string name) {
        auto* n = reinterpret_cast<NumExpr *>(new Variable(std::move(name)));
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
