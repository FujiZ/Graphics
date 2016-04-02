//
// Created by fuji on 16-3-28.
//

#ifndef GRAPHICS_PRIMITIVE_H
#define GRAPHICS_PRIMITIVE_H

#include "global.h"

class Primitive{
public:
    static void setCurrentPrimitive(Primitive* p_primitive);
    static void display();
    static void rotate();

protected:
    virtual void _display()=0;
    virtual void _rotate()=0;

private:
    static Primitive *__cur;

};

#endif //GRAPHICS_PRIMITIVE_H
