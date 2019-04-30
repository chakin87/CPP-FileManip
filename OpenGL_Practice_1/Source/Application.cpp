


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "CreateShader.h"

#include <iostream>

//Prototypes




// ---------------------------------- PRACTICE CODE ---------------------------------2

// ----------------------------------END PRACTICE CODE ---------------------------------2


int main(int argc, char** argv) {


	std::cout << "Application.cpp " << __FUNCDNAME__ << "\n\n";


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 800, "OpenGL Practice Sessh", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	
	
	// glewInit() init AFTER glfwMakeContextCurrent(window) !!!!!
	if (glewInit() != GLEW_OK) {
		std::cout << "Glew was not properly Initialized!\n\n";
	}


	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";


	// ---------------------------------- PRACTICE CODE ---------------------------------2

	float buPositions[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};


	unsigned int buffer_uno;
	glGenBuffers(1, &buffer_uno);
	glBindBuffer(GL_ARRAY_BUFFER, buffer_uno);
	glBufferData(GL_ARRAY_BUFFER, (6 * sizeof(float)), buPositions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main(){\n"
		"	gl_Position = position;\n"
		"\n"
		"\n"
		"}\n";
	std::string fragmentShader =
		"#version 330 core\n"
		"#extension GL_ARB_separate_shader_objects : enable\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main(){\n"
		"	color = vec4(1.0, 0.0, 0.0, 0.5);\n"
		"\n"
		"\n"
		"}\n";
	
	unsigned int shader = CreateShader(vertexShader, fragmentShader);

	// Bind the new shader
	glUseProgram(shader);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
		

	// ----------------------------------END PRACTICE CODE ---------------------------------2




	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// ---------------------------------- PRACTICE CODE ---------------------------------2

		glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawElements(GL_TRIANGLES);

// ----------------------------------END PRACTICE CODE ---------------------------------2

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();


	return 0;
}