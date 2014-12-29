#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//header file
#include "Control.h"

using namespace glm;

extern GLFWwindow *window;
vec3 position = vec3(0, 0, 5);		//position
float horizontalAngle = 3.14f;		//horizontal angle: toward -Z
float verticalAngle = 0.0f;			//vertical angle: 0, look at the horizon
float initialFoV = 45.0f;			//initial Field of View
float speed = 3.0f;					// 3 units per second
float mouseSpeed = 0.005f;
mat4 viewMatrix;
mat4 projectionMatrix;

void computeMatricesFromInputs() {
	int windowWidth = 700;
	int windowHeight = 500;
	double xpos, ypos;

	//glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	//Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	//get mouse position
	glfwGetCursorPos(window, &xpos, &ypos);

	//reset mouse position for next frame
	glfwSetCursorPos(window, windowWidth / 2, windowHeight / 2);

	//compute new orientation
	horizontalAngle += mouseSpeed * float(windowWidth / 2 - xpos);
	verticalAngle += mouseSpeed * float(windowHeight / 2 - ypos);

	//Direction or Forward vector: Spherical coordinates to Cartesian coordinates
	vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);

	//Right vector
	vec3 right = vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);

	//Up vector
	vec3 up = cross(right, direction);

	//move camera forward
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		position += direction * deltaTime * speed;

	//move camera backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		position -= direction * deltaTime * speed;

	//strafe camera right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		position += right * deltaTime * speed;

	//strafe camera left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		position -= right * deltaTime * speed;

	//Projection matrix: 45° Field of View, 4:3 ratio, display range: [0.1, 100]
	projectionMatrix = perspective(initialFoV, 4.0f / 3.0f, 0.1f, 100.0f);
	//Camera matrix
	viewMatrix = lookAt(
		position,				//Camera is here
		position + direction,	//and looks here: at the same position, plus "direction"
		up						//Head is up (set to 0, -1, 0 to look upside-down)
		);

	//for the next frame, the "last time" will be "now"
	lastTime = currentTime;
}

mat4 getProjectionMatrix() {
	return projectionMatrix;
}

mat4 getViewMatrix() {
	return viewMatrix;
}