#pragma comment (lib, "OpenGL32.lib")
#include <GLFW/glfw3.h>
#include<iostream>

void errorCallback(int error, const char* description) 
{
	std::cerr << "GLFW Error: " << description << std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
}

int main() 
{
	GLFWwindow* window;
	

	
	if (!glfwInit())
		return -1;


	window = glfwCreateWindow(1280, 768, "HOHOHo himnae", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwMakeContextCurrent(window);
	// main gameroop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	int red = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
	if (red==GLFW_PRESS)
	{
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwTerminate();
	return 0;
}
