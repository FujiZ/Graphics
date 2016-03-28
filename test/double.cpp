//
// Created by fuji on 16-3-27.
//
#include <GL/glut.h>

static GLfloat spin =0.0;

void init()
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin,0,0,1);
    glColor3f(1,1,1);
    glRectf(-25,-25,25,25);
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay()
{
    spin+=2;
    if(spin>360) spin-=360;
    glutPostRedisplay();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50,50,-50,50,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button,int state,int x,int y)
{
    switch (button){
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Double buffer test");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
