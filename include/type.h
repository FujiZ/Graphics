//
// Created by fuji on 16-3-28.
//

#ifndef GRAPHICS_TYPE_H
#define GRAPHICS_TYPE_H

#include <GL/glut.h>

class Vertex{
public:
    Vertex(double px, double py, double pz):x(px),y(py),z(pz){}
    void toGl(){
        glVertex3d(x,y,z);
    }
    double x;
    double y;
    double z;
};

#endif //GRAPHICS_TYPE_H
