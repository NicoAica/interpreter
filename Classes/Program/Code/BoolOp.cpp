//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/BoolOp.h"
#include "../../Visitor/Visitor.h"

void BoolOp::accept(Visitor *v) {
    v->visitBoolOp(this);
}
