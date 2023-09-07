//
// Created by nicol on 07/09/2023.
//

#include "Visitor.h"

void EvaVisitor::visitIf(IfStmt *_tmp) {

}

void EvaVisitor::visitProgram(Program *_tmp) {
    _tmp->getBlock()->accept(this);
}

void EvaVisitor::visitBlock(Block *_tmp) {

}

void EvaVisitor::visitPrint(PrintStmt *_tmp) {

}

void EvaVisitor::visitSet(SetStmt *_tmp) {

}

void EvaVisitor::visitInput(InputStmt *_tmp) {
}

void EvaVisitor::visitWhile(WhileStmt *_tmp) {

}

void EvaVisitor::visitOperator(Operator *_tmp) {

}

void EvaVisitor::visitBoolOp(BoolOp *_tmp) {
}

void EvaVisitor::visitNumber(Number *_tmp) {

}

void EvaVisitor::visitVariable(Variable *_tmp) {

}

void EvaVisitor::visitRelOp(RelOp *_tmp) {

}

void EvaVisitor::visitBoolConst(BoolConst *_tmp) {

}
