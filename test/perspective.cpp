//
// Created by fuji on 16-5-9.
//

#include "GL/glut.h"

void display(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glClear(GL_COLOR_BUFFER_BIT);

 glColor4f(1.0,0.0,0.0,1.0);
 glRectf(-10.0, 10.0, 10.0, -10.0);

 glFlush();
}

void init(void)
{
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
 glViewport(0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode(GL_PROJECTION); //没有使用ModelView矩阵模式，也能显示出物体。因在ModelView变换之前默认转为此模式
 glLoadIdentity();
 //gluPerspective(120.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

 gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); //减小fovy，发现物体变大

//gluPerspective(150.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); //增大fovy，发现物体变小

//gluPerspective(120.0, (GLfloat) w/(GLfloat) h, 15.0, 20.0); // 可看到物体，物体的大小并没有随着ZNear,ZFar而改变

//gluPerspective(120.0, (GLfloat) w/(GLfloat) h, 16.0, 20.0); // 不能看到物体

 glTranslatef(0,0,-15.0); //该句可以放到display()函数的一开始，注意在glTranslate之前没有显式的设置MatrixMode为GL_MODELVIEW

//默认将加上此函数的声明。
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(150, 150);
 glutInitWindowSize(400, 400);
 glutCreateWindow("Perspective");
 init();
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}