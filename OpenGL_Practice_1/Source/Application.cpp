


#include <GL/glew.h>
//#include <GLFW/glfw3.h>
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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
///#include "ImGui/imgui.h"
///#include "ImGui/imgui_impl_glfw.h"

// ImGui define and includes and a couple functions for the default menus START{ImGuiImGuiImGuiImGuiImGuiImGui
#define IMGUI_IMPL_OPENGL_LOADER_GLEW

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
const char* glsl_version = "#version 330";

bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}
// ImGui define and includes and a couple functions for the default menus END }ImGuiImGuiImGuiImGuiImGuiImGui



constexpr int c_WindowWidth = 960;
constexpr int c_WindowHeight = 540;
constexpr float c_WindowWidthf = 960.0f;
constexpr float c_WindowHeightf = 540.0f;

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
	window = glfwCreateWindow(c_WindowWidth, c_WindowHeight, "OpenGL Practice Sessh", NULL, NULL);
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



	{ // Added scope OPEN to eliminate inf-loop
	float positions[] = {
		-50.0f, -50.0f, 0.0f, 0.0f, //0
		 50.0f, -50.0f, 1.0f, 0.0f, //1
		 50.0f,  50.0f, 1.0f, 1.0f, //2
		-50.0f,  50.0f, 0.0f, 1.0f  //3
	};

	///float positions[] = {
	///50.0f, 50.0f, 0.0f, 0.0f, //0
	///110.0f, 50.0f, 1.0f, 0.0f, //1
	///110.0f, 110.0f, 1.0f, 1.0f, //2
	///50.0f, 110.0f, 0.0f, 1.0f  //3
	///};

	// must use unsigned
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

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
				

	glm::mat4 proj = glm::ortho(.0f, c_WindowWidthf, 0.0f, c_WindowHeightf, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	Shader shader("Resources/shaders/basic.shader");
	shader.Bind();
	
	//shader.SetUniform4f("u_Color", 0.3f, 0.1f, 0.6f, 1.0f);
	//shader.SetUniformMat4f("u_MVP", mvp);

	Texture texture("Resources/Textures/health_pickup.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	shader.Unbind();

	Renderer renderer;


	// ImGui inits                         START{ ImGuiImGuiImGuiImGuiImGuiImGui
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	// ImGui inits                         END  }ImGuiImGuiImGuiImGuiImGuiImGui


	glm::vec3 translationA(200, 200, 0);
	glm::vec3 translationB(400, 200, 0);

	int tick = 400, tock = 200;

		/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer.Clear();
		// ImGui Render                         START{ImGuiImGuiImGuiImGuiImGuiImGui
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		// ImGui Render                         End  }ImGuiImGuiImGuiImGuiImGuiImGui


		//shader.SetUniform1i("u_Texture", 0);

		
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, ib, shader);
		}
		
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(va, ib, shader);
		}


		--tick;
		if (tick < 0) {
			tick = tock;
		}



		//if (show_demo_window)
		//	ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::SliderFloat3("TranslationA", &translationA.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::SliderFloat3("TranslationB", &translationB.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				translationA.x++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}



		// ImGui Render at end of main loop               START{ImGuiImGuiImGuiImGuiImGuiImGui
		//	by	/* Swap front and back buffers */
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		// ImGui Render at end of main loop               END  }ImGuiImGuiImGuiImGuiImGuiImGui
				/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	//TODO: Make sure to Delete the shader!!!
					//////////glDeleteProgram(shader);

}
// ImGui Cleanup put this out of loop or at death             START{ImGuiImGuiImGuiImGuiImGuiImGui
// Cleanup
ImGui_ImplOpenGL3_Shutdown();
ImGui_ImplGlfw_Shutdown();
ImGui::DestroyContext();
// ImGui Cleanup put this out of loop or at death             End  }ImGuiImGuiImGuiImGuiImGuiImGui
// Added scope CLOSE to eliminate inf-loop
	glfwTerminate();


	return 0;
}