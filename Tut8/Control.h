#ifndef CONTROLS_H
#define CONTROLS_H

#include <glm/glm.hpp>

using namespace glm;

void computeMatricesFromInputs();
mat4 getProjectionMatrix();
mat4 getViewMatrix();

#endif