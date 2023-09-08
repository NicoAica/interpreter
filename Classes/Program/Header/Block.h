//
// Created by Nicolò Aicardi on 09/08/23.
//

#ifndef INTERPRETER_BLOCK_H
#define INTERPRETER_BLOCK_H


#include <vector>

class Visitor;
class Statement;

class Block {

public:
    void accept(Visitor* v);

    void emplace_back(Statement* _tmp){
        statement.emplace_back(_tmp);
    }

    std::vector<Statement *> get_vector() {
        return statement;
    }

private:
    std::vector<Statement *> statement;
};


#endif //INTERPRETER_BLOCK_H
