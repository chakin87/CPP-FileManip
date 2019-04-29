


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

//Prototypes

// ---------------------------------- PRACTICE CODE ----------------------------------

//GLfloat triangle_vertices[] = {
GLfloat tv[] = {
-0.5, 0.0,
 0.5, 0.0,
 0.0, 1.0 };

float tvmod[] =
{ .001f, .001f,
  .001f, .001f,
  .001f, .001f };

unsigned short timer = 0;


void trimove(){

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

// -------------------------------- END PRACTICE CODE --------------------------------


int main(int argc, char** argv) {


	std::cout << "Application.cpp " << __FUNCDNAME__ << "\n\n";


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "OpenGL Practice Sessh", NULL, NULL);
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





	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);




		// ---------------------------------- PRACTICE CODE ----------------------------------


		trimove();
		glBegin(GL_TRIANGLES);
		glVertex2f(tv[0], tv[1]);
		glVertex2f(tv[2], tv[3]);
		glVertex2f(tv[4], tv[5]);
		glEnd();
		// -------------------------------- END PRACTICE CODE --------------------------------

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();


	return 0;
}