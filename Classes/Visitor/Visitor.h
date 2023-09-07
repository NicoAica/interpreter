//
// Created by nicol on 07/09/2023.
//

#ifndef INTERPRETER_VISITOR_H
#define INTERPRETER_VISITOR_H


#include <vector>
#include "../Program/Header/Program.h"
#include "../Program/Header/PrintStmt.h"
#include "../Program/Header/SetStmt.h"
#include "../Program/Header/InputStmt.h"
#include "../Program/Header/WhileStmt.h"
#include "../Program/Header/IfStmt.h"
#include "../Program/Header/Operator.h"
#include "../Program/Header/Number.h"
#include "../Program/Header/RelOp.h"
#include "../Program/Header/BoolConst.h"
#include "../Program/Header/BoolOp.h"

class Visitor {
public:

    virtual void  visitProgram(Program* _tmp) = 0;
    virtual void  visitBlock(Block* _tmp) = 0;

    virtual void  visitPrint(PrintStmt* _tmp) = 0;
    virtual void  visitSet(SetStmt* _tmp) = 0;
    virtual void  visitInput(InputStmt* _tmp) = 0;
    virtual void  visitWhile(WhileStmt* _tmp) = 0;

    virtual void  visitIf(IfStmt* _tmp) = 0;

    virtual void  visitOperator(Operator* _tmp) = 0;
    virtual void  visitNumber(Number* _tmp) = 0;
    virtual void  visitVariable(Variable* _tmp) = 0;
    virtual void  visitRelOp(RelOp* _tmp) = 0;
    virtual void  visitBoolConst(BoolConst* _tmp) = 0;
    virtual void  visitBoolOp(BoolOp* _tmp) = 0;

};

class EvaVisitor: public Visitor {
public:
    void visitProgram(Program* _tmp) override;
    void visitBlock(Block* _tmp) override;

    void visitPrint(PrintStmt* _tmp) override;
    void visitSet(SetStmt* _tmp) override;
    void visitInput(InputStmt* _tmp) override;
    void visitWhile(WhileStmt* _tmp) override;
    void visitIf(IfStmt* _tmp) override;
    void visitOperator(Operator* _tmp) override;
    void visitNumber(Number* _tmp) override;
    void visitVariable(Variable* _tmp) override;
    void visitRelOp(RelOp* _tmp) override;
    void visitBoolConst(BoolConst* _tmp) override;
    void visitBoolOp(BoolOp* _tmp) override;

private:
    std::vector<int> accumulator;
};


#endif //INTERPRETER_VISITOR_H
