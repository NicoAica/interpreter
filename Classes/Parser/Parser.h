//
// Created by Nicolò Aicardi on 27/08/2023.
//

#ifndef INTERPRETER_PARSER_H
#define INTERPRETER_PARSER_H


#include "../Manager/Manager.h"
#include "../Token/Token.h"
#include "../Error/Exceptions.h"

class Parser {

public:

    Parser(
            NumExprManager& _numExprManager,
            BlockManager& _blockManager,
            BoolExprManager& _boolExprManager,
            StatementManager& _statementManager,
            ProgramManager& _programManager
    ) :
    numExprManager{_numExprManager},
    blockManager{_blockManager},
    boolExprManager{_boolExprManager},
    statementManager{_statementManager},
    programManager{_programManager} {}

    Program *operator()(const std::vector<Token> &tokenStream) {
        auto tokenItr = tokenStream.begin();
        streamEnd = tokenStream.end();
        streamStart = tokenStream.begin();
        Program *expr = recursiveParse(tokenItr);

        if (tokenItr != (streamEnd - 1)){
            throw ParseError("Troppi token");
        }

        return expr;
    }

private:
    std::vector<Token>::const_iterator streamEnd;
    std::vector<Token>::const_iterator streamStart;

    NumExprManager& numExprManager;
    BlockManager& blockManager;
    BoolExprManager& boolExprManager;
    StatementManager& statementManager;
    ProgramManager& programManager;

    Program *recursiveParse(std::vector<Token>::const_iterator &tokenItr);
    Block *recursiveParseBlock(std::vector<Token>::const_iterator &tokenItr);
    Statement *recursiveParseStatement(std::vector<Token>::const_iterator &tokenItr);
    NumExpr* recursiveParseNumExpr(std::vector<Token>::const_iterator &tokenItr);
    BoolExpr* recursiveParseBoolExpr(std::vector<Token>::const_iterator &tokenItr);

    void safe_next(std::vector<Token>::const_iterator &itr) {
        if (itr == streamEnd) {
            throw ParseError("Inaspettata fine del programma");
        }
        ++itr;
    }

    void safe_back(std::vector<Token>::const_iterator &itr) {
        --itr;
    }

};


#endif //INTERPRETER_PARSER_H
