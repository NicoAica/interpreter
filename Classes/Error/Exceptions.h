//
// Created by Nicolò Aicardi on 25/08/2023.
//

#ifndef INTERPRETER_EXCEPTIONS_H
#define INTERPRETER_EXCEPTIONS_H

#include <stdexcept>
#include <string>

struct LexicalError : std::runtime_error {
    explicit LexicalError(const char* msg) : std::runtime_error(msg) { }
    explicit LexicalError(std::string msg) : std::runtime_error(msg.c_str()) { }
};

struct ParseError : std::runtime_error {
    explicit ParseError(const char* msg) : std::runtime_error(msg) { }
    explicit ParseError(std::string msg) : std::runtime_error(msg.c_str()) { }
};

struct EvaluationError : std::runtime_error {
    explicit EvaluationError(const char* msg) : std::runtime_error(msg) { }
    explicit EvaluationError(std::string msg) : std::runtime_error(msg.c_str()) { }
};


#endif //INTERPRETER_EXCEPTIONS_H
