//
// Created by nicol on 26/08/2023.
//

#include "../Header/Program.h"
#include "../../Visitor/Visitor.h"

void Program::accept(Visitor *v) {
    v->visitProgram(this);
}
