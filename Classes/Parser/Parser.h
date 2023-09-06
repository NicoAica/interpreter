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
        // Utilizzo auto per evitare di scrivere per esteso il tipo dell'iteratore
        auto tokenItr = tokenStream.begin();
        streamEnd = tokenStream.end();
        Program *expr = recursiveParse(tokenItr);
        // TODO: controllare se sono arrivato in fondo al token stream
        return expr;
    }

private:
    std::vector<Token>::const_iterator streamEnd;

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

    // Avanzamento "sicuro" di un iteratore
    void safe_next(std::vector<Token>::const_iterator &itr) {
        if (itr == streamEnd) {
            throw ParseError("Unexpected end of input");
        }
        ++itr;
    }

};


#endif //INTERPRETER_PARSER_H
