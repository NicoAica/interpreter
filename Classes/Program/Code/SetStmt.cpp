//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/SetStmt.h"

#include "../../Visitor/Visitor.h"

void SetStmt::accept(Visitor *v) {
    v->visitSet(this);
}
