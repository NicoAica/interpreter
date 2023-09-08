//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/Number.h"
#include "../../Visitor/Visitor.h"

void Number::accept(Visitor *v) {
    v->visitNumber(this);
}
