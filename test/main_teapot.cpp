//
// Created by fuji on 16-4-17.
//

#include "global.h"
#include "teapot.h"

void init() {
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Teapot");
    init();
    Teapot teapot(0.4);
    teapot.setCurrentPrimitive(&teapot);
    glutDisplayFunc(teapot.display);
    glutIdleFunc(teapot.idle);
    glutMainLoop();
    return 0;
}
