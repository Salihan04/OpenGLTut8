#ifndef CONTROLS_H
#define CONTROLS_H

#include <glm/glm.hpp>

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif