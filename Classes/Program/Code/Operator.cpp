//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/Operator.h"
#include "../../Visitor/Visitor.h"

void Operator::accept(Visitor *v) {
    v->visitOperator(this);
}
