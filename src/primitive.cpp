//
// Created by fuji on 16-3-28.
//
#include "primitive.h"

Primitive *Primitive::__cur = nullptr;

void Primitive::display() {
    __cur->_display();
}

void Primitive::setCurrentPrimitive(Primitive *p_primitive) {
    __cur=p_primitive;
}

void Primitive::rotate() {
    __cur->_rotate();
}