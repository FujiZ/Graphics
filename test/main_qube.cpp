//
// Created by fuji on 16-4-12.
//

#include "global.h"
#include "qube.h"

void init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_BACK,GL_POINT);
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Qube");
    init();
    Qube qube(0.5);
    qube.setCurrentPrimitive(&qube);
    glutDisplayFunc(qube.display);
    glutIdleFunc(qube.rotate);
    glutMainLoop();
    return 0;
}
