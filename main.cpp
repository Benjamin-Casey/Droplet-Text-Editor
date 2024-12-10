#include <iostream>
#include "include/GLFW/glfw3.h"
#include <string>

void error_callback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}

int main()
{
	std::cout << "Hello, Droplet!" << std::endl;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		std::cerr << "GLFW initialization failed!" << std::endl;
		return 1;
	}

	GLFWwindow *window = glfwCreateWindow(640, 480, "Droplet", NULL, NULL);
	if (!window)
	{
		std::cerr << "GLFW window creation or OpenGL context creation failed!" << std::endl;
	}

	glfwTerminate();
	return 0;
}
