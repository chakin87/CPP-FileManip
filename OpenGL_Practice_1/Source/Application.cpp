


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

//Prototypes

// ---------------------------------- PRACTICE CODE ----------------------------------1

//GLfloat triangle_vertices[] = {
GLfloat tv0[] = {
-0.1, 0.0,
 0.1, 0.0,
 0.0, .2 };

float tvmod0[] =
{ .001f, .001f,
  .002f, .004f,
  .001f, .003f };

GLfloat tv1[] = {
 0.1, 0.0,
 -0.1, 0.0,
 0.0, -.2 };

float tvmod1[] =
{ .001f, .001f,
  .002f, .004f,
  .001f, .003f };

unsigned short timer = 0;


void trimove(GLfloat tv[], float tvmod[]){

	for (int i = 0; i < 6; ++i) {
		if (tv[i] <= -1.0f) {
			tvmod[i] = -tvmod[i];
		}
		else if (tv[i] >= 1.0f) {
			tvmod[i] = -tvmod[i];
		}
		tv[i] += tvmod[i];

	}
}

// -------------------------------- END PRACTICE CODE --------------------------------1


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

	glBindBuffer(GL_ARRAY_BUFFER, 0);
		

	// ----------------------------------END PRACTICE CODE ---------------------------------2




	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);




		// ---------------------------------- PRACTICE CODE ----------------------------------1


		glColor3f(0.7f, 0.4f, 1.0f);
		trimove(tv0, tvmod0);
		glBegin(GL_TRIANGLES);
		glVertex2f(tv0[0], tv0[1]);
		glVertex2f(tv0[2], tv0[3]);
		glVertex2f(tv0[4], tv0[5]);
		glEnd();

		glColor3f(0.5f, 0.0f, 1.0f);
		trimove(tv1, tvmod1);
		glBegin(GL_TRIANGLES);
		glVertex2f(tv1[0], tv1[1]);
		glVertex2f(tv1[2], tv1[3]);
		glVertex2f(tv1[4], tv1[5]);
		glEnd();
		// -------------------------------- END PRACTICE CODE --------------------------------1




		// ---------------------------------- PRACTICE CODE ---------------------------------2

		//glDrawArrays(GL_TRIANGLES, 0, 3);
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