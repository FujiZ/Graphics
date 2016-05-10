//
// Created by fuji on 16-3-28.
//

#ifndef GRAPHICS_PRIMITIVE_H
#define GRAPHICS_PRIMITIVE_H

#include "global.h"

class Primitive{
public:
    Primitive(const char* name);
    static void addPrimitive(std::shared_ptr<Primitive> newPrimitive);
    static void switchPrimitive(std::shared_ptr<Primitive> newPrimitive);
    static void init(int argc,char** argv);
    static void display();
    static void idle();
    static void reshape(int w,int h);
    static void initMenu();
    const char* name();

protected:
    virtual void _init()=0;
    virtual void _display()=0;
    virtual void _idle();
    virtual void _reshape(int w,int h);
    virtual void _destruct();

    static int window_width;
    static int window_height;

private:
    static void __processMenuEvents(int option);
    static void __processMouseEvents(int button, int state, int x, int y);

    static std::shared_ptr<Primitive> __curPrimitive;
    static std::vector<std::shared_ptr<Primitive>> __primitives;

    const char* NAME;

};

#endif //GRAPHICS_PRIMITIVE_H
