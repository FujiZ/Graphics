//
// Created by fuji on 16-5-9.
//

#include "global.h"
#include "star.h"
#include "qube.h"
#include "teapot.h"
#include "texture.h"

int main(int argc,char** argv) {
    Primitive::init(argc,argv);
    std::shared_ptr<Primitive> primitive=std::make_shared<Star>(0.5);
    Primitive::addPrimitive(primitive);
    auto star=primitive;
    primitive=std::make_shared<Qube>(0.3);
    Primitive::addPrimitive(primitive);
    primitive=std::make_shared<Teapot>(0.5);
    Primitive::addPrimitive(primitive);
    primitive=std::make_shared<Texture>();
    Primitive::addPrimitive(primitive);
    Primitive::initMenu();
    Primitive::switchPrimitive(star);
    glutMainLoop();
    return 0;
}
