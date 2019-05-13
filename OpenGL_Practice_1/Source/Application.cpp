


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//#include "CreateShader.h"
#include "LegacyTriangles.h"
//#include "GL_ErrorHandling.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Functions.h"
#include "Texture.h"





// ---------------------------------- PRACTICE CODE ---------------------------------2

// ----------------------------------END PRACTICE CODE ---------------------------------2


int main(int argc, char** argv) {


	std::cout << "Application.cpp " << __FUNCDNAME__ << "\n\n";


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
		-0.5f, -0.5f, 0.0f, 0.0f, //0
		 0.5f, -0.5f, 1.0f, 0.0f, //1
		 0.5f,  0.5f, 1.0f, 1.0f, //2
		-0.5f,  0.5f, 0.0f, 1.0f  //3
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


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);
				
	Shader shader("Resources/shaders/basic.shader");
	shader.Bind();
	//shader.SetUniform4f("u_Color", 0.3f, 0.1f, 0.6f, 1.0f);


	Texture texture("Resources/Textures/health_pickup.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	shader.Unbind();

	Renderer renderer;

	float r = 0.0f;
	float rIncr = .0005f;
	float b = 0.0f;
	float bIncr = .0005f;
	// ----------------------------------END PRACTICE CODE ---------------------------------2




		/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer.Clear();

		// ---------------------------------- PRACTICE CODE ---------------------------------2
		shader.Bind();
		shader.SetUniform1i("u_Texture", 0);
		
		renderer.Draw(va, ib, shader);

		r += rIncr;
		if (r > 1.0f) {
			rIncr = -rIncr;
		}
		else if (r < 0.0f) {
			rIncr = -rIncr;
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
					//////////glDeleteProgram(shader);

}// Added scope CLOSE to eliminate inf-loop
	glfwTerminate();


	return 0;
}