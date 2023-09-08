//
// Created by Nicolò Aicardi on 24/08/2023.
//

/*************
 *                                                   Tokenizer
 * Il Tokenizer, leggendo carattere per carattere, verifica per prima cosa quei token di grandezza unitaria (1 char),
 * e in caso negativo, salva in una stringa i caratteri letti fino a che la parola non sia finita, per poi controllare
 * quest'ultima
 *
 *************/

#ifndef INTERPRETER_TOKENIZER_H
#define INTERPRETER_TOKENIZER_H

#include <vector>
#include <fstream>
#include "Token.h"

class Tokenizer {

public:
    std::vector<Token> operator()(std::ifstream& inputFile) {
        std::vector<Token> inputTokens;
        tokenizeInputFile(inputFile, inputTokens);
        return inputTokens;
    }

private:
    static void tokenizeInputFile(std::ifstream& inputFile, std::vector<Token>& inputTokens);

};


#endif //INTERPRETER_TOKENIZER_H
