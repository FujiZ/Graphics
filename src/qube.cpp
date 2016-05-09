//
// Created by fuji on 16-4-12.
//

#include "qube.h"


Qube::Qube(double radius):Primitive("Qube"),__radius(radius) {
    double len=radius/std::sqrt(3);
    //生成8个顶点
    Vertex points[]={
            Vertex(len,-len,len),
            Vertex(len,-len,-len),
            Vertex(-len,-len,-len),
            Vertex(-len,-len,len),

            Vertex(len,len,len),
            Vertex(len,len,-len),
            Vertex(-len,len,-len),
            Vertex(-len,len,len)
    };
    //生成6个面的坐标vector,点以逆时针方式分布
    __surfaceVec.resize(6);
    //bottom(1,0,3,2)
    __surfaceVec[0].push_back(points[1]);
    __surfaceVec[0].push_back(points[0]);
    __surfaceVec[0].push_back(points[3]);
    __surfaceVec[0].push_back(points[2]);
    //top(4,5,6,7)
    for(int i=4;i<=7;++i){
        __surfaceVec[1].push_back(points[i]);
    }
    //front(0,4,7,3)
    __surfaceVec[2].push_back(points[0]);
    __surfaceVec[2].push_back(points[4]);
    __surfaceVec[2].push_back(points[7]);
    __surfaceVec[2].push_back(points[3]);
    //back(2,6,5,1)
    __surfaceVec[3].push_back(points[2]);
    __surfaceVec[3].push_back(points[6]);
    __surfaceVec[3].push_back(points[5]);
    __surfaceVec[3].push_back(points[1]);
    //left(3,7,6,2)
    __surfaceVec[4].push_back(points[3]);
    __surfaceVec[4].push_back(points[7]);
    __surfaceVec[4].push_back(points[6]);
    __surfaceVec[4].push_back(points[2]);
    //right(1,5,4,0)
    __surfaceVec[5].push_back(points[1]);
    __surfaceVec[5].push_back(points[5]);
    __surfaceVec[5].push_back(points[4]);
    __surfaceVec[5].push_back(points[0]);

}

void Qube::_display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    double eyePos=__radius/std::sqrt(3);
    gluLookAt(eyePos,eyePos,eyePos,0,0,0,-1,1,-1);
    glPushMatrix();
    glRotated(__spin,0,1,0);
    unsigned int color=1;
    for(auto& surface:__surfaceVec)
        __drawSurface(surface,color++);
    glPopMatrix();
    glutSwapBuffers();
}

void Qube::__drawSurface(std::vector<Vertex> &surface, unsigned int color) {
    //set color
    double colorR=(color&4)?1:0;
    double colorG=(color&2)?1:0;
    double colorB=(color&1)?1:0;
    glColor3d(colorR,colorG,colorB);
    glBegin(GL_POLYGON);
    for(auto& vertex:surface)
        glVertex3d(vertex.x,vertex.y,vertex.z);
    glEnd();
}

void Qube::_idle() {
    __spin+=2;
    if(__spin>360) __spin-=360;
    glutPostRedisplay();
}

void Qube::_init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);
    //去除back面的多边形
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}