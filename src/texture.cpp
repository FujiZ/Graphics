//
// Created by fuji on 16-5-11.
//

#include "texture.h"

Texture::Texture():Primitive("Texture") {
    __makeTexImage();
    __makeQube(0.2);    //0.2 for radius
}

void Texture::_init() {
    glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);
    //去除back面的多边形
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);

    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glGenTextures(2,__texArray);

    __loadTexImage(__texArray[0]);

}

void Texture::__loadTexImage(GLuint texID) {
    glBindTexture(GL_TEXTURE_2D,texID);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,TEX_IMAGE_WIDTH,TEX_IMAGE_HEIGHT,0,GL_RGBA,GL_UNSIGNED_BYTE,__texImage);

}

void Texture::_display() {
    //load screen copy to texArray[1]
    __copyTexImage(__texArray[1]);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //设置视点
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.2,0.2,0.2,0,0,0,0,1,0);

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glPushMatrix();
    glTranslated(-0.35,0,0);

    int i=0;
    for(auto iter=__surfaceVec.begin();
        iter!=__surfaceVec.end();
        ++iter,++i){
        //给surface2贴纹理
        switch (i){
            case 2:
                __drawSurface(*iter, true,__texArray[0]);
            case 5:
                __drawSurface(*iter, true,__texArray[1]);
            default:
                __drawSurface(*iter, false,0);
        }
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glColor3d(1,0,0);
    glutSolidTeapot(0.07);

    glutSwapBuffers();
}

void Texture::__copyTexImage(GLuint texID) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //设置视点
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-0.5,0,0,0,0,0,0,1,0);
    //draw a teapot
    glColor3d(1,0,0);
    glutSolidTeapot(0.5);

    glBindTexture(GL_TEXTURE_2D,texID);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glCopyTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,0,0,window_width,window_height,0);

}

void Texture::__drawSurface(std::vector<Vertex> &surface, bool enableTexture,GLuint texID){
    if(enableTexture){
        glColor3d(1,1,1);
        glBindTexture(GL_TEXTURE_2D,texID);
        glBegin(GL_QUADS);
        glTexCoord2f(0,0);surface[0].toGl();
        glTexCoord2f(0,1);surface[1].toGl();
        glTexCoord2f(1,1);surface[2].toGl();
        glTexCoord2f(1,0);surface[3].toGl();
        glEnd();
    }
    else {
        glColor3d(0,1,1);
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        for (auto &vertex:surface) {
            vertex.toGl();
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
    }
    glEnd();
}

void Texture::__makeTexImage(){
    for(int i=0;i<TEX_IMAGE_HEIGHT;++i){
        for(int j=0;j<TEX_IMAGE_WIDTH;++j){
            int c=((((i&0x8)==0)^((j&0x8)==0)))*255;
            __texImage[i][j][0]=(GLubyte)c;
            __texImage[i][j][1]=(GLubyte)c;
            __texImage[i][j][2]=(GLubyte)c;
            __texImage[i][j][3]=(GLubyte)255;
        }
    }
}

void Texture::__makeQube(double radius) {

    double len=radius/std::sqrt(3);
    //生成8个顶点
    Vertex points[]={
            Vertex(len,-len,len),
            Vertex(len,-len,-len),
            Vertex(-len,-len,-len),
            Vertex(-len,-len,len),

            Vertex(len,len,len),
            Vertex(len,len,-len),
            Vertex(-len,len,-len),
            Vertex(-len,len,len)
    };
    //生成6个面的坐标vector,点以逆时针方式分布
    __surfaceVec.resize(6);
    //bottom(1,0,3,2)
    __surfaceVec[0].push_back(points[1]);
    __surfaceVec[0].push_back(points[0]);
    __surfaceVec[0].push_back(points[3]);
    __surfaceVec[0].push_back(points[2]);
    //top(4,5,6,7)
    for(int i=4;i<=7;++i){
        __surfaceVec[1].push_back(points[i]);
    }
    //front(0,4,7,3)
    __surfaceVec[2].push_back(points[0]);
    __surfaceVec[2].push_back(points[4]);
    __surfaceVec[2].push_back(points[7]);
    __surfaceVec[2].push_back(points[3]);
    //back(2,6,5,1)
    __surfaceVec[3].push_back(points[2]);
    __surfaceVec[3].push_back(points[6]);
    __surfaceVec[3].push_back(points[5]);
    __surfaceVec[3].push_back(points[1]);
    //left(3,7,6,2)
    __surfaceVec[4].push_back(points[3]);
    __surfaceVec[4].push_back(points[7]);
    __surfaceVec[4].push_back(points[6]);
    __surfaceVec[4].push_back(points[2]);
    //right(1,5,4,0)
    __surfaceVec[5].push_back(points[1]);
    __surfaceVec[5].push_back(points[5]);
    __surfaceVec[5].push_back(points[4]);
    __surfaceVec[5].push_back(points[0]);

}

void Texture::_destruct() {
    glDeleteTextures(2,__texArray);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
}