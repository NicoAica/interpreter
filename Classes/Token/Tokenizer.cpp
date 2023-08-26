//
// Created by Nicolò Aicardi on 24/08/2023.
//

#include "Tokenizer.h"

#include <string>
#include <iostream>
#include <algorithm>

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
                inputTokens.emplace_back(Token::NUM, tmp);
            } else {
                auto it = std::find(std::begin(Token::id2word), std::end(Token::id2word), tmp);
                if (it != std::end(Token::id2word)) {
                    std::size_t position = std::distance(std::begin(Token::id2word), it);
                    inputTokens.emplace_back(position, Token::id2word[position]);
                } else {
                    for (char & c : tmp){
                        if (!std::isalpha(c)){
                            std::stringstream _tmp{};
                            _tmp << "Errore lessicale in: " << tmp;
                            throw LexicalError(_tmp.str());
                        }
                    }
                    inputTokens.emplace_back(Token::VARIABLE, tmp);
                }
            }
            tmp = "";
        }
    }
}