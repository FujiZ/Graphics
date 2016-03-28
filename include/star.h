//
// Created by fuji on 16-3-28.
//

#ifndef GRAPHICS_STAR_H
#define GRAPHICS_STAR_H

#include "global.h"
#include <cmath>
#include <vector>
#include "primitive.h"

class Star:public Primitive{
public:
    Star(double radius);

protected:
    void _display() override;

private:
    void _drawLine();
    void _drawPoint();
    void _drawPolygon();

    double __radius;
    std::vector<Vertex> __outVertex;
    std::vector<Vertex> __inVertex;
};

#endif //GRAPHICS_STAR_H
