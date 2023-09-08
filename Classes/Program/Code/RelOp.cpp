//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/RelOp.h"

#include "../../Visitor/Visitor.h"

void RelOp::accept(Visitor *v) {
    v->visitRelOp(this);
}
