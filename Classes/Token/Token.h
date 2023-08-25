//
// Created by Nicolò Aicardi on 24/08/2023.
//

#ifndef INTERPRETER_TOKEN_H
#define INTERPRETER_TOKEN_H

#include <string>

struct Token {

    static constexpr int LP = 0;
    static constexpr int RP = 1;
    static constexpr int SET = 2;
    static constexpr int PRINT = 3;
    static constexpr int INPUT = 4;
    static constexpr int IF = 5;
    static constexpr int WHILE = 6;
    static constexpr int ADD = 7;
    static constexpr int SUB = 8;
    static constexpr int MUL = 9;
    static constexpr int DIV = 10;
    static constexpr int GT = 11;
    static constexpr int LT = 12;
    static constexpr int EQ = 13;
    static constexpr int AND = 14;
    static constexpr int OR = 15;
    static constexpr int NOT = 16;
    static constexpr int TRUE = 17;
    static constexpr int FALSE = 18;
    static constexpr int NUM = 19;
    static constexpr int VARIABLE = 20;
    static constexpr int BLOCK = 21;

    static constexpr const char* id2word[]{
            "(", ")", "SET", "PRINT", "INPUT", "IF", "WHILE", "ADD", "SUB", "MUL",
            "DIV", "GT", "LT", "EQ", "AND", "OR", "NOT", "TRUE", "FALSE",
            "NUM", "VARIABLE", "BLOCK"
    };

    Token(int t, const char* w) : tag{ t }, word{ w } { }

    Token(int t, std::string w) : tag{ t }, word{ w } { }

    int tag;
    std::string word;

};


std::ostream& operator<<(std::ostream& os, const Token& t);

#endif //INTERPRETER_TOKEN_H
