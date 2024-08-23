#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>


#include "Window.h"
#include "Events.h"


int WIDTH = 1280;
int HEIGHT = 720;

GLfloat points[] = {
	// x    y     z     u     v
   0.0f,0.5f,0.0f,
   0.5f,-0.5f,0.0f,
   -0.5f,-0.5f,0.0f
};
GLfloat colors[]{
	1.0f,0.0f,0.0f,
	0.4f,0.2f,0.1f,
	1.0f,0.0f,0.5f
};

const char* vertex_shader =
"#version 460\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color; 	"
"out vec3 color;"
"void main() { "
"	color = vertex_color;"
"	gl_Position = vec4(vertex_position,1.0);"
"}";

const char* fragment_shader =
"#version 460\n"
"in vec3 color;"
"out vec4 color_frag;"
"void main() {"
"	color_frag = vec4(color,1.0);"
"}";



int main() {
	Window::initialize(WIDTH, HEIGHT, "Window 2.0");
	Events::initialize();

	GLuint vshad = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshad, 1, &vertex_shader, nullptr);
	glCompileShader(vshad);

	GLuint fshad = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshad, 1, &fragment_shader, nullptr);
	glCompileShader(fshad);

	GLuint shadProg = glCreateProgram();

	glAttachShader(shadProg, vshad);
	glAttachShader(shadProg, fshad);
	glLinkProgram(shadProg);

	glDeleteShader(vshad);
	glDeleteShader(fshad);

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

	glEnableVertexAttribArray(1);
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

		}
		else if (Events::jpressed(GLFW_KEY_W)) {
			glClearColor(0.5f, 0.4f, 0.2f, 1);
			
		}
		else if (Events::jpressed(GLFW_KEY_A)) {
			glClearColor(0.1f, 0.4f, 0.2f, 1);
			
		}
		else if (Events::jpressed(GLFW_KEY_S)) {
			glClearColor(0.8f, 0.1f, 0.2f, 1);
		}
		else if (Events::jpressed(GLFW_KEY_D)) {
			glClearColor(0.6f, 0.4f, 0.7f, 1);
		}
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shadProg);
		glBindVertexArray(vertexArrayObj);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		Window::swapBuffers();
	}

	

	Window::terminate();
	return 0;
}