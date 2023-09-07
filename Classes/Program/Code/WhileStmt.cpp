//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/WhileStmt.h"
#include "../../Visitor/Visitor.h"

void WhileStmt::accept(Visitor *v) {
    v->visitWhile(this);
}
