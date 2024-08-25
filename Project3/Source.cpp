#include <iostream>
#include <random>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

#include "Shaders.h"
#include "Window.h"
#include "Events.h"


int WIDTH = 600;
int HEIGHT = 600;

GLfloat points[] = {
	// x    y     z     u     v
   0.0f,0.5f,0.0f,
   0.5f,-0.5f,0.0f,
   -0.5f,-0.5f,0.0f
};
GLfloat colors[]{
	1.0f,0.0f,0.0f,
	0.4f,0.2f,0.1f,
	0.5f,0.0f,0.5f
};
int randik = 1;
bool someflag = 0;

const char* vertex_shader =
"#version 330\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color; 	"
"out vec3 color;"
"void main() { "
"	color = vertex_color;"
"	gl_Position = vec4(vertex_position,1.0);"
"}";

const char* fragment_shader =
"#version 330\n"
"in vec3 color;"
"out vec4 color_frag;"
"void main() {"
"	color_frag = vec4(color,1.0);"
"}";



int main() {
	Window::initialize(WIDTH, HEIGHT, "Window 2.0");
	Events::initialize();

	std::string vertex_shader_str = vertex_shader;
	std::string fragment_shader_str = fragment_shader;

	ShadersNS::Shaders shaders(vertex_shader_str, fragment_shader_str);

	if (!shaders.isCompiledF()) {
		std::cout << "Couldn't compile shader Program" << std::endl;
		return -1;
	}


	GLuint points_vbo = 0;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint colors_vbo = 0;
	glGenBuffers(1, &colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	GLuint vertexArrayObj = 0;
	glGenVertexArrays(1, &vertexArrayObj);
	glBindVertexArray(vertexArrayObj);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0,nullptr);


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		
//	glClearColor(0.6f, 0.62f, 0.65f, 1);


	while (!Window::isShouldClose()) {

		Events::pullEvents();
		
		if (Events::jpressed(GLFW_KEY_ESCAPE)) {
			Window::setShouldClose(true);
		}
		else if (Events::jclicked(GLFW_MOUSE_BUTTON_1)) {
			glClearColor(0.8f, 0.4f, 0.2f, 1);
			std::cout << "LMB pressed\n";

		}
		else if (Events::jpressed(GLFW_KEY_W)) {
			glClearColor(0.5f, 0.4f, 0.2f, 1);
			std::cout << "W Key pressed\n";
			
		}
		else if (Events::jpressed(GLFW_KEY_A)) {
			glClearColor(0.1f, 0.4f, 0.2f, 1);
			std::cout << "A Key pressed\n";
		}
		else if (Events::jpressed(GLFW_KEY_S)) {
			glClearColor(0.8f, 0.1f, 0.2f, 1);
			std::cout << "S Key pressed\n";
		}
		else if (Events::jpressed(GLFW_KEY_D)) {
			glClearColor(0.6f, 0.4f, 0.7f, 1);
			std::cout << "D Key pressed\n";
		}

		if (Events::_cursor_started && Events::deltaX+Events::deltaY != 0) {
			
			std::cout << "x= " << Events::x << "y= " << Events::y << "\n";

		}
		glClear(GL_COLOR_BUFFER_BIT);

		shaders.use();
		glBindVertexArray(vertexArrayObj);
		glDrawArrays(GL_TRIANGLES, 1, 3);

		Window::swapBuffers();
	}

	

	Window::terminate();
	return 0;
}