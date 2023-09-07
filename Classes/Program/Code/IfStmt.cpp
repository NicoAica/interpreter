//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/IfStmt.h"
#include "../../Visitor/Visitor.h"

void IfStmt::accept(Visitor *v) {
    v->visitIf(this);
}
