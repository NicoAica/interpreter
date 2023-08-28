//
// Created by nicol on 28/08/2023.
//

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
};