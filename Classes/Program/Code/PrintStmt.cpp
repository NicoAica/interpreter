//
// Created by Nicolò Aicardi on 09/08/2023.
//

#include "../Header/PrintStmt.h"

#include "../../Visitor/Visitor.h"

void PrintStmt::accept(Visitor *v) {
    v->visitPrint(this);
}
