//
// Created by fuji on 16-3-28.
//
#include "global.h"
#include "star.h"

void init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Star");
    init();
    Star star(0.5);
    star.setCurrentPrimitive(&star);
    glutDisplayFunc(star.display);
    glutIdleFunc(star.rotate);
    glutMainLoop();
    return 0;
}
