


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "CreateShader.h"
#include "LegacyTriangles.h"
//#include "GL_ErrorHandling.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"







// ---------------------------------- PRACTICE CODE ---------------------------------2

// ----------------------------------END PRACTICE CODE ---------------------------------2


int main(int argc, char** argv) {


	std::cout << "Application.cpp " << __FUNCDNAME__ << "\n\n";

	LegacyTriangles L;

	GLFWwindow* window;

	/* Initialize the library  */
	if (!glfwInit())
		return -1;


	// Set up Core Profile with opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 800, "OpenGL Practice Sessh", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Set G-Sync
	glfwSwapInterval(1);

	// glewInit() init AFTER glfwMakeContextCurrent(window) !!!!!
	if (glewInit() != GLEW_OK) {
		std::cout << "Glew was not properly Initialized!\n\n";
	}


	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";


	// ---------------------------------- PRACTICE CODE ---------------------------------2
	{ // Added scope OPEN to eliminate inf-loop
	float positions[] = {
		-0.5f, -0.5f, //0
		 0.5f, -0.5f, //1
		 0.5f,  0.5f, //2
		-0.5f,  0.5f, //3
	};

	// must use unsigned
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	//---------------------------------Practice 3------------------------------------------------------
		//    This is the Necessary Code to bind and generate the buffers for our square to draw
		// VAO
	unsigned int vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	VertexBuffer vb(positions, 4 * 2 * sizeof(float));
					//unsigned int buffer;
					//glGenBuffers(1, &buffer);
					//glBindBuffer(GL_ARRAY_BUFFER, buffer);
					//glBufferData(GL_ARRAY_BUFFER, (6 * 2 * sizeof(float)), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);// This eneables Array 0
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);// This line links vao and buffer with array 0

	IndexBuffer ib(indices, 6);
					//unsigned int indexBufferObject; //ibo
					//glGenBuffers(1, &indexBufferObject);
					//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
					//glBufferData(GL_ELEMENT_ARRAY_BUFFER, (6 * sizeof(unsigned int)), indices, GL_STATIC_DRAW);


	ShaderProgramSource source = ParseShader("Resources/Shaders/basic.shader");
	std::cout << "Vertex:\n" << source.VertexSource << "\nFragment:\n" << source.FragmentSource << "\n";


	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);

	// Bind the new shader
	glUseProgram(shader);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	int location = glGetUniformLocation(shader, "u_Color");
	ASSERT(location != -1);
	glUniform4f(location, 0.3f, 0.1f, 0.6f, 1.0f);

	float r = 0.0f;
	float rIncr = .05f;
	float b = 0.0f;
	float bIncr = .05f;
	// ----------------------------------END PRACTICE CODE ---------------------------------2




		/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// ---------------------------------- PRACTICE CODE ---------------------------------2
		glUseProgram(shader);
		glUniform4f(location, r, 0.1f, 0.6f, 1.0f);

		glBindVertexArray(vao);
		ib.Bind();
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
// This draws our indices square
		GLCall(glDrawElements(GL_TRIANGLES, 6/*6 indices*/, GL_UNSIGNED_INT, nullptr));

		r += rIncr;
		if (r > 1.0f) {
			rIncr = -0.05f;
		}
		else if (r < 0.0f) {
			rIncr = 0.05f;
		}
		b += bIncr;
		if (b > 1.0f) {
			bIncr = -0.05f;
		}
		else if (b < 0.0f) {
			bIncr = 0.05f;
		}
		// ----------------------------------END PRACTICE CODE ---------------------------------2

				/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	// Make sure to Delete the shader!!!
	glDeleteProgram(shader);

}// Added scope CLOSE to eliminate inf-loop
	glfwTerminate();


	return 0;
}