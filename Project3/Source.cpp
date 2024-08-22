#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>


#include "Window.h"
#include "Events.h"


int WIDTH = 1280;
int HEIGHT = 720;

float vertices[] = {
	// x    y     z     u     v
   0.0f,0.0f,0.0f,
   1.0f,0.0f,0.0f,
   0.0f,1.0f,0.0f,
};


int main() {
	Window::initialize(WIDTH, HEIGHT, "Window 2.0");
	Events::initialize();


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

		Window::swapBuffers();
	}

	

	Window::terminate();
	return 0;
}