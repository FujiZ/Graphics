//
// Created by fuji on 16-4-17.
//

#include "teapot.h"


Teapot::Teapot(double size):Primitive("Teapot"),__size(size) { }

void Teapot::_display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glRotated(__spin,0,1,0);
    glutSolidTeapot(__size);
    glPopMatrix();
    glutSwapBuffers();
}

void Teapot::_idle() {
    __spin+=2;
    if(__spin>360) __spin-=360;
    glutPostRedisplay();
}

void Teapot::_init() {
    GLfloat mat_specular[]={1,1,1,1};
    GLfloat mat_shininess[]={50};
    GLfloat light_position0[]={1,1,0,0};
    GLfloat light_position1[]={-1,1,0,0};
    GLfloat white_light[]={1,1,1,1};
    GLfloat red_light[]={1,0,0,1};
    GLfloat lmodel_ambient[]={0.1,0.1,0.1,1.0};
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    //light0
    glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
    glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);
    //light1
    glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,red_light);
    glLightfv(GL_LIGHT1,GL_SPECULAR,red_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
}

void Teapot::_destruct() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}