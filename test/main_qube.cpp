//
// Created by fuji on 16-4-12.
//

#include "global.h"
#include "qube.h"

void init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    //去除back面的多边形
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

int main(int argc,char** argv) {
    Primitive::init(argc,argv);
    std::shared_ptr<Primitive> qube=std::make_shared<Qube>(0.5);
    Primitive::addPrimitive(qube);
    qube->switchPrimitive(qube);
    Primitive::initMenu();
    glutMainLoop();
    return 0;
}
