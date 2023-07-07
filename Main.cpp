#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// initiate glfw
	glfwInit();

	// give glfw context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLTest", NULL, NULL);
	// null check window
	if (window == NULL)
	{
		// terminate
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// make window the current context
	glfwMakeContextCurrent(window);

	// load glad
	gladLoadGL();
	// tell it screensize
	glViewport(0, 0, 800, 800);

	// colour the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// swap the buffers
	glfwSwapBuffers(window);

	// game loop
	while (!glfwWindowShouldClose(window))
	{
		// check events
		glfwPollEvents();
	}

	// terminate
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}