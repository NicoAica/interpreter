//
// Created by nicol on 26/08/2023.
//

#ifndef INTERPRETER_PROGRAM_H
#define INTERPRETER_PROGRAM_H


#include "Block.h"

class Visitor;

class Program {

public:
    Program(Block* b) : block{b} {}

    Block* getBlock() { return block; }

    void accept(Visitor *v);


private:
    Block* block;
};


#endif //INTERPRETER_PROGRAM_H
