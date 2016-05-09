//
// Created by fuji on 16-4-17.
//

#ifndef GRAPHICS_TEAPOT_H
#define GRAPHICS_TEAPOT_H

#include "global.h"
#include "primitive.h"

class Teapot:public Primitive{

public:
    Teapot(double size);

protected:
    void _init() override;
    void _display() override;
    void _idle() override;
    void _destruct() override;

private:
    double __size;
    double __spin=0;

};

#endif //GRAPHICS_TEAPOT_H
