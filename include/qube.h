//
// Created by fuji on 16-4-12.
//

#ifndef GRAPHICS_QUBE_H
#define GRAPHICS_QUBE_H

#include "global.h"
#include <cmath>
#include "primitive.h"

class Qube:public Primitive{
public:
    Qube(double radius);

protected:
    void _init() override;
    void _display() override;
    void _idle() override;
    //void _destruct() override;

private:
    void __drawSurface(std::vector<Vertex>& surface, unsigned int color);
    double __radius;
    double __spin=0;
    std::vector<std::vector<Vertex>> __surfaceVec;

};

#endif //GRAPHICS_QUBE_H
