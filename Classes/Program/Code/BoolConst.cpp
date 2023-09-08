//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/BoolConst.h"

#include "../../Visitor/Visitor.h"

void BoolConst::accept(Visitor *v) {
    v->visitBoolConst(this);
}
