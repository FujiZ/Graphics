//
// Created by fuji on 16-3-28.
//

#include "star.h"


Star::Star(double radius):Primitive("Star"),__radius(radius){
    double aa=std::cos(54.0/360.0*2*M_PI);
    double bb=aa*std::tan(36.0/360.0*2*M_PI);
    double cc=std::sin(54.0/360.0*2*M_PI)-bb;

    int rotate=18;  //代表旋转的角度
    for(int i=rotate;i<360+rotate;i+=72){
        __outVertex.emplace_back(__radius*std::cos(i/360.0*2.0*M_PI),__radius*std::sin(i/360.0*2.0*M_PI),0);
        __inVertex.emplace_back(cc*__radius*std::cos((i+36)/360.0*2.0*M_PI),cc*__radius*std::sin((i+36)/360.0*2.0*M_PI),0);
    }

}

void Star::_display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    //坐标平移
    glTranslated(__outVertex[__rotateCenter].x,__outVertex[__rotateCenter].y,0);
    glRotated(__spin,0,0,1);    //旋转
    glTranslated(-__outVertex[__rotateCenter].x,-__outVertex[__rotateCenter].y,0);
    __drawPolygon();
    __drawLine();
    __drawPoint();
    glPopMatrix();
    glutSwapBuffers();
}

void Star::__drawPolygon() {
    //填充颜色
    glColor3d(1.0,1.0,0.0); //黄色
    glBegin(GL_POLYGON);
    for(auto& vertex:__inVertex)
        glVertex2d(vertex.x,vertex.y);
    glEnd();
}

void Star::__drawPoint() {
    glPointSize(8);
    glColor3d(0.0,0.0,0.0); //黑色
    //生成点
    glBegin(GL_POINTS);
    for(auto& vertex:__outVertex)
        glVertex2d(vertex.x,vertex.y);
    glEnd();
}

void Star::__drawLine() {
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

void Star::_idle() {
    __spin+=2;
    if(__spin>360) __spin-=360;
    glutPostRedisplay();
}

void Star::_init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
}