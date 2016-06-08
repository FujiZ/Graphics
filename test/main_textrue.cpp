//
// Created by fuji on 16-5-20.
//

#include "global.h"
#include "texture.h"

int main(int argc,char** argv) {
    Primitive::init(argc,argv);
    auto primitive=std::make_shared<Texture>();
    Primitive::addPrimitive(primitive);
    Primitive::initMenu();
    Primitive::switchPrimitive(primitive);
    glutMainLoop();
    return 0;
}
