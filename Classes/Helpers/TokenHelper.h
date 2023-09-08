//
// Created by Nicolò Aicardi on 28/08/2023.
//

/*************
 *                                                   String Helper
 * In questo Helper vengono inseriti tutti quei metodi utili per la manipolazione dei token
 *
 *************/

#include "../Token/Token.h"

#ifndef INTERPRETER_TOKENHELPER_H
#define INTERPRETER_TOKENHELPER_H

#endif //INTERPRETER_TOKENHELPER_H

class TokenHelper {
public:

    static bool verifyStatementNotBlock(const int _statement){
        switch (_statement) {
            case Token::IF:
            case Token::WHILE:
            case Token::PRINT:
            case Token::SET:
            case Token::INPUT:
                return true;
            default:
                return false;
        }
    }

    static RelOp::RelOpCode tokenToRelCode(int tag){
        RelOp::RelOpCode _op;
        switch (tag) {
            case Token::GT: _op = RelOp::GT; break;
            case Token::LT: _op = RelOp::LT; break;
            case Token::EQ: _op = RelOp::EQ; break;
            default:
                std::stringstream _tmp{};
                _tmp << "Errore inaspettato";
                throw ParseError(_tmp.str());
        }
        return _op;
    }

    static BoolOp::BoolOpCode tokenToBoolCode(int tag){
        BoolOp::BoolOpCode _op;
        switch (tag) {
            case Token::OR: _op = BoolOp::OR; break;
            case Token::NOT: _op = BoolOp::NOT; break;
            case Token::AND: _op = BoolOp::AND; break;
            default:
                std::stringstream _tmp{};
                _tmp << "Errore inaspettato";
                throw ParseError(_tmp.str());
        }
        return _op;
    }

    static Operator::OpCode tokenToOpCode(int tag){
        Operator::OpCode _opCode;
        switch (tag) {
            case Token::ADD:
                _opCode = Operator::ADD;
                break;
            case Token::SUB:
                _opCode = Operator::SUB;
                break;
            case Token::MUL:
                _opCode = Operator::MUL;
                break;
            case Token::DIV:
                _opCode = Operator::DIV;
                break;
            default: {
                std::stringstream _tmp{};
                _tmp << "Errore definizione operatore Num Expr";
                throw ParseError(_tmp.str());
            }
        }
        return _opCode;
    }

};