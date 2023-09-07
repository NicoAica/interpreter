//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/InputStmt.h"

#include "../../Visitor/Visitor.h"

void InputStmt::accept(Visitor *v) {
    v->visitInput(this);
}
