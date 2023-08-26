//
// Created by nicol on 26/08/2023.
//

#ifndef INTERPRETER_PROGRAM_H
#define INTERPRETER_PROGRAM_H


#include "Block.h"

class Program {

public:
    explicit Program(Block* b) : block{b} {}

private:
    Block* block;
};


#endif //INTERPRETER_PROGRAM_H
