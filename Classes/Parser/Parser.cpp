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
    return programManager->makeProgram(recursiveParseBlock(tokenItr));
}

Block* Parser::recursiveParseBlock(std::vector<Token>::const_iterator &tokenItr){
    if (tokenItr->tag != Token::LP) {
        std::stringstream _tmp{};
        _tmp << "Mancanza di LP";
        throw LexicalError(_tmp.str());
    } else {
        safe_next(tokenItr);

        Block* _block = blockManager->makeBlock();
        Statement* _statement = nullptr;

        if (TokenHelper::verifyStatementNotBlock(tokenItr->tag)){
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
            throw LexicalError(_tmp.str());
        }
        return _block;
    }
}

Statement* Parser::recursiveParseStatement(std::vector<Token>::const_iterator &tokenItr){
    if (tokenItr->tag != Token::LP) {
        std::stringstream _tmp{};
        _tmp << "Mancanza di LP";
        throw LexicalError(_tmp.str());
    } else {
        safe_next(tokenItr);
        Statement* _statement = nullptr;

        switch (tokenItr->tag) {
            case Token::IF: {
                safe_next(tokenItr);
                BoolExpr* _boolExpr = nullptr;//recursiveParseBoolExpr(tokenItr);
                Block* _trueBlock = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                Block* _falseBlock = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                _statement = statementManager->makeIfStmt(_boolExpr, _trueBlock, _falseBlock);
                break;
            }
            case Token::INPUT: {
                safe_next(tokenItr);
                Variable* _variable = nullptr; //recursiveParseVariable(tokenItr);
                // TODO: introdurre le variabili
                _statement = statementManager->makeInputStmt(_variable);
                break;
            }
            case Token::PRINT: {
                safe_next(tokenItr);
                NumExpr* _numExpr = nullptr; //recursiveParseNumExpr(tokenItr);
                _statement = statementManager->makePrintStmt(_numExpr);
                break;
            }
            case Token::SET: {
                safe_next(tokenItr);
                Variable* _variable = nullptr; //recursiveParseVariable(tokenItr);
                // TODO: introdurre le variabili
                NumExpr* _numExpr = nullptr; //recursiveParseNumExpr(tokenItr);
                _statement = statementManager->makeSetStmt(_numExpr, _variable);
                break;
            }
            case Token::WHILE: {
                safe_next(tokenItr);
                BoolExpr* _boolExpr = nullptr;//recursiveParseBoolExpr(tokenItr);
                Block* _block = recursiveParseBlock(tokenItr);
                safe_next(tokenItr);
                _statement = statementManager->makeWhileStmt(_boolExpr, _block);
                break;
            }

        }

        return _statement;
    }
}
