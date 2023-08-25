//
// Created by Nicolò Aicardi on 24/08/2023.
//

#include "Tokenizer.h"

#include <string>
#include <iostream>

#include "../Error/Exceptions.h"
#include "../Helpers/StringHelper.h"

void Tokenizer::tokenizeInputFile(std::ifstream& inputFile, std::vector<Token>& inputTokens) {

    char ch;
    std::string tmp;
    ch = inputFile.get();

    while (!inputFile.eof()) {
        if (std::isspace(ch)){
            ch = inputFile.get();
            continue;
        }

        if (ch == '(') {
            inputTokens.emplace_back( Token::LP, Token::id2word[Token::LP] );
            ch = inputFile.get();
        } else if (ch == ')') {
            inputTokens.emplace_back( Token::RP, Token::id2word[Token::RP] );
            ch = inputFile.get();
        } else {

            tmp.push_back(ch);
            ch = inputFile.get();

            while (!inputFile.eof() && !std::isspace(ch) && ch != '(' && ch != ')'){
                tmp.push_back(ch);
                ch = inputFile.get();
            }

            if (StringHelper::isNumber(tmp)){
                inputTokens.emplace_back(Token::NUM, Token::id2word[Token::NUM]);
            } else if (tmp == "SET") {
                inputTokens.emplace_back(Token::SET, Token::id2word[Token::SET]);
            } else if (tmp == "PRINT") {
                inputTokens.emplace_back(Token::PRINT, Token::id2word[Token::PRINT]);
            } else if (tmp == "INPUT") {
                inputTokens.emplace_back(Token::INPUT, Token::id2word[Token::INPUT]);
            } else if (tmp == "IF") {
                inputTokens.emplace_back(Token::IF, Token::id2word[Token::IF]);
            } else if (tmp == "WHILE") {
                inputTokens.emplace_back(Token::WHILE, Token::id2word[Token::WHILE]);
            } else if (tmp == "ADD") {
                inputTokens.emplace_back(Token::ADD, Token::id2word[Token::ADD]);
            } else if (tmp == "SUB") {
                inputTokens.emplace_back(Token::SUB, Token::id2word[Token::SUB]);
            } else if (tmp == "MUL") {
                inputTokens.emplace_back(Token::MUL, Token::id2word[Token::MUL]);
            } else if (tmp == "DIV") {
                inputTokens.emplace_back(Token::DIV, Token::id2word[Token::DIV]);
            } else if (tmp == "GT") {
                inputTokens.emplace_back(Token::GT, Token::id2word[Token::GT]);
            } else if (tmp == "LT") {
                inputTokens.emplace_back(Token::LT, Token::id2word[Token::LT]);
            } else if (tmp == "EQ") {
                inputTokens.emplace_back(Token::EQ, Token::id2word[Token::EQ]);
            } else if (tmp == "AND") {
                inputTokens.emplace_back(Token::AND, Token::id2word[Token::AND]);
            } else if (tmp == "OR") {
                inputTokens.emplace_back(Token::OR, Token::id2word[Token::OR]);
            } else if (tmp == "NOT") {
                inputTokens.emplace_back(Token::NOT, Token::id2word[Token::NOT]);
            } else if (tmp == "TRUE") {
                inputTokens.emplace_back(Token::TRUE, Token::id2word[Token::TRUE]);
            } else if (tmp == "FALSE") {
                inputTokens.emplace_back(Token::FALSE, Token::id2word[Token::FALSE]);
            } else if (tmp == "BLOCK") {
                inputTokens.emplace_back(Token::BLOCK, Token::id2word[Token::BLOCK]);
            } else {
                for (char & c : tmp){
                    if (!std::isalpha(c)){
                        std::stringstream _tmp{};
                        _tmp << "Errore lessicale sul simbolo: " << c;
                        throw LexicalError(_tmp.str());
                    }
                }
                inputTokens.emplace_back(Token::VARIABLE, Token::id2word[Token::VARIABLE]);
            }

            tmp = "";
        }
    }
}