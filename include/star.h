//
// Created by fuji on 16-3-28.
//

#ifndef GRAPHICS_STAR_H
#define GRAPHICS_STAR_H

#include "global.h"
#include <cmath>
#include "primitive.h"

class Star:public Primitive{
public:
    Star(double radius);

protected:
    void _init() override;
    void _display() override;
    void _idle() override;
    void _destruct() override;

private:
    void __drawLine();
    void __drawPoint();
    void __drawPolygon();

    double __radius;    //半径
    double __spin=0;    //旋转角度
    int __rotateCenter=0;  //旋转中心
    std::vector<Vertex> __outVertex;
    std::vector<Vertex> __inVertex;
};

#endif //GRAPHICS_STAR_H
