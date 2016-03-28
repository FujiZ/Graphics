// OpenGLtest.cpp : 定义控制台应用程序的入口点。
//
#include <GL/glut.h>

void display()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0,0.0,0.0,1.0);     // set the quad color
    glBegin(GL_POLYGON);
        glVertex2f(-0.5,-0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(-0.5,0.5);
    glEnd();
    glFlush();

}

void display(int a,int b)
{
    display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("First OpenGL Program");
    glutReshapeFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

