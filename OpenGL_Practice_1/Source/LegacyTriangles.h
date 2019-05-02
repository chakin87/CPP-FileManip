



#include <GL/glew.h>
#include <GLFW/glfw3.h>


// Does not work with Core Profile. Might need VAO bound?
class LegacyTriangles {



// ---------------------------------- PRACTICE CODE ----------------------------------1

//GLfloat triangle_vertices[] = {
GLfloat tv0[6] = {
-0.1, 0.0,
 0.1, 0.0,
 0.0, .2 };

float tvmod0[6] =
{ .001f, .001f,
  .002f, .004f,
  .001f, .003f };

GLfloat tv1[6] = {
 0.1, 0.0,
 -0.1, 0.0,
 0.0, -.2 };

float tvmod1[6] =
{ .001f, .001f,
  .002f, .004f,
  .001f, .003f };

unsigned short timer = 0;


void trimove(GLfloat tv[], float tvmod[]) {

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





// ---------------------------------- PRACTICE CODE ----------------------------------1
public:
void BouncingTriangles() {

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

}
// -------------------------------- END PRACTICE CODE --------------------------------1
};