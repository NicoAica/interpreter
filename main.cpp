#include <iostream>
#include <fstream>

#include "Classes/Program/Header/Block.h"
#include "Classes/Token/Tokenizer.h"
#include "Classes/Helpers/StringHelper.h"
#include "Classes/Error/Exceptions.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "File non specificato!" << std::endl;
        std::cerr << "Utilizzo: " << argv[0] << " <nome_file>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream inputFile;

    try {
        inputFile.open(argv[1]);
    } catch (std::exception& exc) {
        std::cerr << "Non posso aprire " << argv[1] << std::endl;
        std::cerr << exc.what() << std::endl;
        return EXIT_FAILURE;
    }

    Tokenizer tokenize;
    std::vector<Token> inputTokens;

    try {
        inputTokens = std::move(tokenize(inputFile));

        for (auto & inputToken : inputTokens) {
            std::cout << inputToken << std::endl;
        }

        inputFile.close();
    } catch (LexicalError& le) {
        std::cerr << "Errore in fase di analisi lessicale" << std::endl;
        std::cerr << le.what() << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception& exc) {
        std::cerr << "Non posso leggere da " << argv[1] << std::endl;
        std::cerr << exc.what() << std::endl;
        return EXIT_FAILURE;
    }




    return 0;
}
