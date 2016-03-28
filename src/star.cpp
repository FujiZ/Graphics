//
// Created by fuji on 16-3-28.
//

#include "star.h"


Star::Star(double radius):__radius(radius){
    double aa=cos(54.0/360.0*2*M_PI);
    double bb=aa*tan(36.0/360.0*2*M_PI);
    double cc=sin(54.0/360.0*2*M_PI)-bb;

    int rotate=18;  //代表旋转的角度
    for(int i=rotate;i<360+rotate;i+=72){
        __outVertex.emplace_back(__radius*cos(i/360.0*2.0*M_PI),__radius*sin(i/360.0*2.0*M_PI),0);
        __inVertex.emplace_back(cc*__radius*cos((i+36)/360.0*2.0*M_PI),cc*__radius*sin((i+36)/360.0*2.0*M_PI),0);
    }

}

void Star::_display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glRotated(9,0,0,1); //对坐标进行旋转
    _drawPolygon();
    _drawLine();
    _drawPoint();
    glFlush();
}

void Star::_drawPolygon() {
    //填充颜色
    glColor3d(1.0,1.0,0.0); //黄色
    glBegin(GL_POLYGON);
    for(Vertex &vertex:__inVertex)
        glVertex2d(vertex.x,vertex.y);
    glEnd();
}

void Star::_drawPoint() {
    glPointSize(8);
    glColor3d(0.0,0.0,0.0); //黑色
    //生成点
    glBegin(GL_POINTS);
    for(Vertex &vertex:__outVertex)
        glVertex2d(vertex.x,vertex.y);
    glEnd();
}

void Star::_drawLine() {
    glLineWidth(2); //设置线宽
    glColor3d(0.0,0.0,0.0); //黑色
    //生成轮廓
    glBegin(GL_LINES);

    int size=(int)__outVertex.size();
    for(int i=0;i<size;++i){
        glVertex2d(__outVertex[i].x,__outVertex[i].y);
        int j=(i+2)%size;
        glVertex2d(__outVertex[j].x,__outVertex[j].y);
    }

    glEnd();
}
