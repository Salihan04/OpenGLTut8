#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <GLFW/glfw3.h>

GLFWwindow* createWindow(int windowWidth, int windowHeight, char *title);
void renderScene();
void createCubeVertexBuffer();
void createCubeTextureCoordBuffer();
void prepareMVP();

#endif