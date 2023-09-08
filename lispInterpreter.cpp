#include <iostream>
#include <fstream>
#include <filesystem>

#include "Classes/Token/Tokenizer.h"
#include "Classes/Error/Exceptions.h"
#include "Classes/Manager/Manager.h"
#include "Classes/Parser/Parser.h"
#include "Classes/Visitor/Visitor.h"

int main(int argc, char* argv[]) {

    /*+++++++++++++++ Richiesta File **************/

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

    std::uintmax_t fileSize = std::filesystem::file_size(argv[1]);

    if (fileSize == 0) {
        std::cerr << "Il file e' vuoto." << std::endl;
        return EXIT_FAILURE;
    }

    Tokenizer tokenize;
    std::vector<Token> inputTokens;

    try {

        /*+++++++++++++++ Analisi Lessicale **************/

        inputTokens = std::move(tokenize(inputFile));

        for (auto & inputToken : inputTokens) {
            std::cout << inputToken << std::endl;
        }


    } catch (LexicalError& le) {
        std::cerr << "Errore in fase di analisi lessicale" << std::endl;
        std::cerr << le.what() << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception& exc) {
        std::cerr << "Non posso leggere da " << argv[1] << std::endl;
        std::cerr << exc.what() << std::endl;
        return EXIT_FAILURE;
    }



    BlockManager blockManager;
    BoolExprManager boolExprManager;
    NumExprManager numExprManager;
    StatementManager statementManager;
    ProgramManager programManager;

    Parser parse{numExprManager, blockManager, boolExprManager, statementManager, programManager};

    try {

        /*+++++++++++++++ Analisi Sintattica **************/
        Program* _program = parse(inputTokens);

        /*+++++++++++++++ Analisi Semantica **************/
        auto* visitor = new EvaVisitor();
        _program->accept(visitor);

    } catch (LexicalError& le) {
        std::cerr << "Errore in fase di analisi lessicale" << std::endl;
        std::cerr << le.what() << std::endl;
        return EXIT_FAILURE;
    } catch (ParseError& le) {
        std::cerr << "Errore in fase di parser" << std::endl;
        std::cerr << le.what() << std::endl;
        return EXIT_FAILURE;
    } catch (EvaluationError& le) {
        std::cerr << "Errore in fase di valutazione" << std::endl;
        std::cerr << le.what() << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception& exc) {
        std::cerr << "Non posso leggere da " << argv[1] << std::endl;
        std::cerr << exc.what() << std::endl;
        return EXIT_FAILURE;
    }



    return 0;
}
