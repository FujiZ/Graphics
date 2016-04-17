//
// Created by fuji on 16-4-12.
//

#include "global.h"
#include "qube.h"

void init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    //glPolygonMode(GL_FRONT,GL_FILL);
    //glPolygonMode(GL_BACK,GL_POINT);
    //去除back面的多边形
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
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
