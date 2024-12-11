#include <iostream>
#include "include/GLFW/glfw3.h"
#include <string>

void error_callback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
	std::cout << "Hello, Droplet!" << std::endl;

	// Initialize glfw and give it our error callback for when it encounters errors
	if (!glfwInit())
	{
		std::cerr << "GLFW initialization failed!" << std::endl;
		return 1;
	}
	glfwSetErrorCallback(error_callback);

	// Create window
	GLFWwindow *window = glfwCreateWindow(640, 480, "Droplet", NULL, NULL);
	if (!window)
	{
		std::cerr << "GLFW window creation or OpenGL context creation failed!" << std::endl;
	}

	// Make context for our window
	glfwMakeContextCurrent(window);

	// Create a key callback to close our window
	glfwSetKeyCallback(window, key_callback);

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
