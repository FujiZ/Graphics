//
// Created by fuji on 16-4-12.
//

#include "qube.h"


Qube::Qube(double radius) {
    double len=radius/sqrt(3);
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
    //bottom(0,1,2,3)
    for(int i=0;i<=3;++i){
        __surfaceVec[0].push_back(points[i]);
    }
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

    glutSwapBuffers();
}