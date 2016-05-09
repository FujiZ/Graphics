//
// Created by fuji on 16-3-28.
//
#include "primitive.h"

std::shared_ptr<Primitive> Primitive::__curPrimitive = nullptr;
std::vector<std::shared_ptr<Primitive>> Primitive::__primitives;

Primitive::Primitive(char const* name):NAME(name) { }

void Primitive::display() {
    __curPrimitive->_display();
}

void Primitive::idle() {
    __curPrimitive->_idle();
}

void Primitive::switchPrimitive(std::shared_ptr<Primitive> newPrimitive) {
    if(__curPrimitive)
        __curPrimitive->_destruct();
    __curPrimitive=newPrimitive;
    __curPrimitive->_init();
    glutPostRedisplay();
}

void Primitive::addPrimitive(std::shared_ptr<Primitive> newPrimitive) {
    __primitives.push_back(newPrimitive);
}

const char* Primitive::name() {
    return NAME;
}

void Primitive::__setMenu() {
    glutCreateMenu(__processMenuEvents);
    for(unsigned int i=0;i<__primitives.size();++i){
        //给菜单增加条目
        glutAddMenuEntry(__primitives[i]->name(),i);
    }
    // 把菜单和鼠标右键关联起来。
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Primitive::__processMenuEvents(int option) {
    switchPrimitive(__primitives[option]);
}

void Primitive::init(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Graphics");
    glutDisplayFunc(display);
    glutMouseFunc(__processMouseEvents);
    glutIdleFunc(NULL);
}

void Primitive::__processMouseEvents(int button, int state, int x, int y) {
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(idle);
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

void Primitive::_idle() {

}

void Primitive::_destruct() {

}
