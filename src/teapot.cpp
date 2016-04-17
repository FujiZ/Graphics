//
// Created by fuji on 16-4-17.
//

#include "teapot.h"


Teapot::Teapot(double size):__size(size) { }

void Teapot::_display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glRotated(__spin,0,1,0);
    glutSolidTeapot(__size);
    glPopMatrix();
    glutSwapBuffers();
}

void Teapot::_rotate() {
    __spin+=2;
    if(__spin>360) __spin-=360;
    glutPostRedisplay();
}
