//
// Created by fuji on 16-5-11.
//

#ifndef GRAPHICS_TEXTURE_H
#define GRAPHICS_TEXTURE_H

#include "global.h"
#include <cmath>
#include "primitive.h"

class Texture:public Primitive{
public:
    Texture();

protected:
    void _init() override;
    void _display() override;
    void _destruct() override;

private:
    void __makeTexImage();
    void __loadTexImage(GLuint texID);  //将texImage中的图像加载入texID中
    void __copyTexImage(GLuint texID);  //将当前的帧缓存载入texID
    void __makeQube(double radius);
    void __drawSurface(std::vector<Vertex> &surface,bool enableTexture,GLuint texID);

    const static int TEX_IMAGE_WIDTH=64;
    const static int TEX_IMAGE_HEIGHT=64;

    //texture
    GLuint __texArray[2];  //0 for texPic; 1 for screen copy
    GLubyte __texImage[TEX_IMAGE_HEIGHT][TEX_IMAGE_WIDTH][4];

    //qube
    std::vector<std::vector<Vertex>> __surfaceVec;

};

#endif //GRAPHICS_TEXTURE_H
