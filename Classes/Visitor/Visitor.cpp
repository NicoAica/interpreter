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

#include <sstream>
#include <iostream>
#include "Visitor.h"
#include "../Error/Exceptions.h"
#include "../Helpers/StringHelper.h"

void EvaVisitor::visitIf(IfStmt *_tmp) {
    _tmp->get_condition()->accept(this);
    if (get_boolean()){
        _tmp->get_true_block()->accept(this);
    } else {
        _tmp->get_false_block()->accept(this);
    }
}

void EvaVisitor::visitProgram(Program *_tmp) {
    _tmp->getBlock()->accept(this);
}

void EvaVisitor::visitBlock(Block *_tmp) {
    for (auto _statement: _tmp->get_vector()) {
        _statement->accept(this);
    }
}

void EvaVisitor::visitPrint(PrintStmt *_tmp) {
    _tmp->get_value()->accept(this);
    std::cout << get_number() << std::endl;
}

void EvaVisitor::visitSet(SetStmt *_tmp) {
    std::string _str = _tmp->get_variable()->get_name();
    _tmp->get_value()->accept(this);
    variableManager.set_value(_str, get_number());
}

void EvaVisitor::visitInput(InputStmt *_tmp) {
    std::string _str;
    std::cin >> _str;

    if (!StringHelper::isNumber(_str)) {
        std::stringstream _out{};
        _out << "L'input: " << _str << " non e' stato riconosciuto come numero";
        throw EvaluationError(_out.str());
    }

    variableManager.set_value(_tmp->get_value()->get_name(), std::stoi(_str));
}

void EvaVisitor::visitWhile(WhileStmt *_tmp) {
    _tmp->get_condition()->accept(this);
    bool condition = get_boolean();

    while (condition){
        _tmp->get_block()->accept(this);
        _tmp->get_condition()->accept(this);
        condition = get_boolean();
    }
}

void EvaVisitor::visitOperator(Operator *_tmp) {
    _tmp->getLeft()->accept(this);
    _tmp->getRight()->accept(this);

    int right_val = get_number();
    int left_val = get_number();
    switch (_tmp->getCode()) {
        case Operator::ADD:
            push_number(left_val + right_val); return;
        case Operator::SUB:
            push_number(left_val - right_val); return;
        case Operator::MUL:
            push_number(left_val * right_val); return;
        case Operator::DIV:
            if (right_val == 0) {
                std::stringstream _str{};
                _str << "Impossibile dividere per 0";
                throw EvaluationError(_str.str());
            }
            push_number(left_val / right_val); return;
        default:
            std::stringstream _str{};
            _str << "Operatore non riconosciuto";
            throw EvaluationError(_str.str());
    }

}

void EvaVisitor::visitBoolOp(BoolOp *_tmp) {

    if (_tmp->getCode() == BoolOp::NOT){
        _tmp->getLeft()->accept(this);
        push_boolean(!get_boolean());
    } else {
        _tmp->getLeft()->accept(this);
        int left_val = get_boolean();

        switch (_tmp->getCode()) {
            case BoolOp::OR:
                if (left_val) { push_boolean(left_val); return; }
                _tmp->getRight()->accept(this);
                push_boolean(get_boolean()); return;
            case BoolOp::AND:
                if (!left_val){ push_boolean(left_val); return; }
                _tmp->getRight()->accept(this);
                push_boolean(get_boolean()); return;
            default:
                std::stringstream _str{};
                _str << "Operatore non riconosciuto";
                throw EvaluationError(_str.str());
        }
    }

}

void EvaVisitor::visitNumber(Number *_tmp) {
    push_number(_tmp->get_value());
}

void EvaVisitor::visitVariable(Variable *_tmp) {
    push_number(variableManager.get_value(_tmp->get_name()));
}

void EvaVisitor::visitRelOp(RelOp *_tmp) {
    _tmp->getLeft()->accept(this);
    _tmp->getRight()->accept(this);

    int right_val = get_number();
    int left_val = get_number();
    switch (_tmp->getCode()) {
        case RelOp::EQ:
            push_boolean(left_val == right_val); return;
        case RelOp::LT:
            push_boolean(left_val < right_val); return;
        case RelOp::GT:
            push_boolean(left_val > right_val); return;
        default:
            std::stringstream _str{};
            _str << "Operatore non riconosciuto";
            throw EvaluationError(_str.str());
    }
}

void EvaVisitor::visitBoolConst(BoolConst *_tmp) {
    push_boolean(_tmp->get_value());
}
