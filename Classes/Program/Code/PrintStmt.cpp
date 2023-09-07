//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/PrintStmt.h"

#include "../../Visitor/Visitor.h"

void PrintStmt::accept(Visitor *v) {
    v->visitPrint(this);
}
