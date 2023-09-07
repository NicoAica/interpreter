//
// Created by Nicolò Aicardi on 09/08/23.
//

#include "../Header/Block.h"
#include "../../Visitor/Visitor.h"

void Block::accept(Visitor *v) {
    v->visitBlock(this);
}
