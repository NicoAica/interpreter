//
// Created by Nicolò Aicardi on 27/08/2023.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "Parser.h"
#include "../Helpers/TokenHelper.h"

Program* Parser::recursiveParse(std::vector<Token>::const_iterator &tokenItr) {
    return programManager.makeProgram(recursiveParseBlock(tokenItr));
}

Block* Parser::recursiveParseBlock(std::vector<Token>::const_iterator &tokenItr){

    if (tokenItr->tag != Token::LP) {

        // TODO verificare direttamente statement

        std::stringstream _tmp{};
        _tmp << "Mancanza di LP in Block";
        throw ParseError(_tmp.str());
    } else {
        safe_next(tokenItr);
        Block* _block = blockManager.makeBlock();
        Statement* _statement = nullptr;
        if (TokenHelper::verifyStatementNotBlock(tokenItr->tag)){
            safe_back(tokenItr);
            _statement = recursiveParseStatement(tokenItr);
            //_block->pushback(_statement);
        } else if (tokenItr->tag == Token::BLOCK){
            safe_next(tokenItr);
            do {
                _statement = recursiveParseStatement(tokenItr);
                safe_next(tokenItr);
                //_block->pushback(_statement);
            } while (tokenItr->tag != Token::RP);
        } else {
            std::stringstream _tmp{};
            _tmp << "Errore in block";
            throw ParseError(_tmp.str());
        }
        return _block;
    }
}

Statement* Parser::recursiveParseStatement(std::vector<Token>::const_iterator &tokenItr){
    if (tokenItr->tag != Token::LP) {
        std::stringstream _tmp{};
        _tmp << "Mancanza di LP in Statement";
        throw ParseError(_tmp.str());
    } else {
        safe_next(tokenItr);
        Statement* _statement = nullptr;

        std::cout << "Statement " << tokenItr->word << std::endl;

        switch (tokenItr->tag) {
            case Token::IF: {
                safe_next(tokenItr);
                BoolExpr* _boolExpr = recursiveParseBoolExpr(tokenItr);
                Block* _trueBlock = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                Block* _falseBlock = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                _statement = statementManager.makeIfStmt(_boolExpr, _trueBlock, _falseBlock);
                break;
            }
            case Token::INPUT: {
                safe_next(tokenItr);
                Variable* _variable = nullptr; //recursiveParseVariable(tokenItr);
                // TODO: introdurre le variabili
                _statement = statementManager.makeInputStmt(_variable);
                break;
            }
            case Token::PRINT: {
                safe_next(tokenItr);
                NumExpr* _numExpr = recursiveParseNumExpr(tokenItr);
                _statement = statementManager.makePrintStmt(_numExpr);
                break;
            }
            case Token::SET: {
                safe_next(tokenItr);
                NumExpr *var = recursiveParseNumExpr(tokenItr);
                NumExpr* _numExpr = recursiveParseNumExpr(tokenItr);
                _statement = statementManager.makeSetStmt(_numExpr, reinterpret_cast<Variable *>(var));
                break;
            }
            case Token::WHILE: {
                safe_next(tokenItr);
                BoolExpr* _boolExpr = recursiveParseBoolExpr(tokenItr);
                Block* _block = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                _statement = statementManager.makeWhileStmt(_boolExpr, _block);
                break;
            }
            default: {
                std::stringstream _tmp{};
                _tmp << "Errore definizione in block";
                throw LexicalError(_tmp.str());
            }
        }

        std::cout << "Fine stat " << tokenItr->word << std::endl;

        if (tokenItr->tag != Token::RP) {
            std::stringstream _tmp{};
            _tmp << "Mancanza di RP in Statement";
            throw ParseError(_tmp.str());
        }

        return _statement;
    }
}

NumExpr* Parser::recursiveParseNumExpr(std::vector<Token>::const_iterator &tokenItr){
    if (tokenItr->tag != Token::LP) {

        if (tokenItr->tag == Token::NUM){
            int _number = std::stoi(tokenItr->word);
            safe_next(tokenItr);
            return numExprManager.makeNumber(_number);
        } else if (tokenItr->tag == Token::VARIABLE){
            NumExpr* _variable = numExprManager.makeVariable(tokenItr->word);
            safe_next(tokenItr);
            return _variable;
        }

        std::stringstream _tmp{};
        _tmp << "Token inaspettato";
        throw ParseError(_tmp.str());
    } else {
        safe_next(tokenItr);

        Operator::OpCode _opCode = TokenHelper::tokenToOpCode(tokenItr->tag);

        std::cout << "DIV passa" << std::endl;

        safe_next(tokenItr);

        NumExpr* _left = recursiveParseNumExpr(tokenItr);
        NumExpr* _right = recursiveParseNumExpr(tokenItr);

        if (tokenItr->tag != Token::RP) {
            std::stringstream _tmp{};
            _tmp << "Mancanza di RP in NumExpr";
            throw ParseError(_tmp.str());
        }

        safe_next(tokenItr);

        return numExprManager.makeOperator(_opCode, _left, _right);
    }
}


BoolExpr* Parser::recursiveParseBoolExpr(std::vector<Token>::const_iterator &tokenItr) {
    if (tokenItr->tag != Token::LP) {

        if (tokenItr->tag == Token::TRUE || tokenItr->tag == Token::FALSE){
            BoolExpr* _boolExpr = boolExprManager.makeBoolConst((tokenItr->tag == Token::TRUE));
            safe_next(tokenItr);
            return _boolExpr;
        }

        std::stringstream _tmp{};
        _tmp << "Token inaspettato";
        throw ParseError(_tmp.str());
    } else {
        safe_next(tokenItr);

        BoolExpr* _boolExpr = nullptr;

        if (tokenItr->tag == Token::GT || tokenItr->tag == Token::LT || tokenItr->tag == Token::EQ){

            RelOp::RelOpCode _op = TokenHelper::tokenToRelCode(tokenItr->tag);

            safe_next(tokenItr);

            NumExpr* _left = recursiveParseNumExpr(tokenItr);

            std::cout << "in GT " << tokenItr->word << std::endl;

            NumExpr* _right = recursiveParseNumExpr(tokenItr);
            std::cout << "in GT dopo 1 " << tokenItr->word << std::endl;
            _boolExpr = boolExprManager.makeRelOp(_op, _left, _right);

        } else if (tokenItr->tag == Token::OR || tokenItr->tag == Token::AND) {

            BoolOp::BoolOpCode _op = TokenHelper::tokenToBoolCode(tokenItr->tag);

            safe_next(tokenItr);

            BoolExpr* _left = recursiveParseBoolExpr(tokenItr);
            BoolExpr* _right = recursiveParseBoolExpr(tokenItr);
            _boolExpr = boolExprManager.makeBoolOp(_op, _left, _right);
        } else if (tokenItr->tag == Token::NOT) {

            safe_next(tokenItr);
            BoolExpr* _left = recursiveParseBoolExpr(tokenItr);

            _boolExpr = boolExprManager.makeBoolOp(BoolOp::NOT, _left);

        } else {
            std::stringstream _tmp{};
            _tmp << "Errore definizione operatore Bool Expr";
            throw ParseError(_tmp.str());
        }

        if (tokenItr->tag != Token::RP) {
            std::stringstream _tmp{};
            _tmp << "Mancanza di RP in Bool Expr";
            throw ParseError(_tmp.str());
        }

        safe_next(tokenItr);

        return _boolExpr;
    }
}