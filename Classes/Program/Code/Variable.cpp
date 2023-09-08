//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/Variable.h"

#include "../../Visitor/Visitor.h"

void Variable::accept(Visitor *v) {
    v->visitVariable(this);
}
