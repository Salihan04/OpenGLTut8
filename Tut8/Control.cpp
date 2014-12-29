#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//header file
#include "Control.h"

extern GLFWwindow *window;
//position
glm::vec3 position = glm::vec3(0, 0, 5);
//horizontal angle : toward -Z
float horizontalAngle = 3.14f;
//vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
//initial Field of View
float initialFoV = 45.0f;
float speed = 3.0f;				// 3 units per second
float mouseSpeed = 0.005f;

void computeMatricesFromInputs() {
	int windowWidth = 500;
	int windowHeight = 500;
	double xpos, ypos;

	//get mouse position
	glfwGetCursorPos(window, &xpos, &ypos);

	//reset mouse position for next frame
	glfwSetCursorPos(window, windowWidth / 2, windowHeight / 2);

	//compute new orientation
	horizontalAngle += mouseSpeed * float(windowWidth / 2 - xpos);
	verticalAngle += mouseSpeed * float(windowHeight / 2 - ypos);
}