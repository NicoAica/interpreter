//
// Created by nicol on 07/09/2023.
//


/*************
 *                                                   Visitor
 * Il visitor avrà il compito di visitare l'albero sintattico creato dal parser. In questo caso l'unico visito
 * "utilizzabile" è quello che ha il compito di valutare e "eseguire" il codice LISP-like.
 *
 * Nel Evaluation Visitor sono stati inseriti dei metodi per la gestione degli accumulatori (sia di tipo numerico che
 * booleano)
 *
 *************/


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
#include "../Manager/Manager.h"
#include "../Manager/VariableManager.h"

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

    EvaVisitor() = default;

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
    std::vector<int> _accumulatorNumber;
    std::vector<bool> _accumulatorBoolean;
    VariableManager variableManager;

    int get_number() {
        int val = _accumulatorNumber.back();
        _accumulatorNumber.pop_back();
        return val;
    }

    bool get_boolean() {
        bool val = _accumulatorBoolean.back();
        _accumulatorBoolean.pop_back();
        return val;
    }

    void push_number(int val) {
        _accumulatorNumber.push_back(val);
    }

    void push_boolean(bool val) {
        _accumulatorBoolean.push_back(val);
    }
};


#endif //INTERPRETER_VISITOR_H
