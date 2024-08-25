#include "Shaders.h"
#include <string>
#include <iostream>

namespace ShadersNS {
	Shaders::Shaders(const std::string& vertex_shader, const std::string& fragment_shader) {
		GLuint vertex_shader_id;
		if (!create_shader(vertex_shader, GL_VERTEX_SHADER, vertex_shader_id)){
			std::cerr << "Vertex shader error" << std::endl;
			return;
		}
		GLuint fragment_shader_id;
		if (!create_shader(fragment_shader, GL_FRAGMENT_SHADER, fragment_shader_id)) {
			std::cerr << "Fragment shader error" << std::endl;
			glDeleteShader(vertex_shader_id);
			return;
		}
		ID = glCreateProgram();
		glAttachShader(ID, vertex_shader_id);
		glAttachShader(ID, fragment_shader_id);
		glLinkProgram(ID);
		GLint success;
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success) {
			GLchar infolog[1024];
			glGetShaderInfoLog(ID, 1024, nullptr, infolog);
			std::cerr << "Program Link Error\t" << infolog << "\n";
			return;
		}
		else {
			isCompiled = true;
		}
		glDeleteShader(vertex_shader_id);
		glDeleteShader(fragment_shader_id);

	}
	bool Shaders::create_shader(const std::string& source, const GLenum shaderType, GLuint& ShaderID) {
		ShaderID = glCreateShader(shaderType);
		const char* code = source.c_str();
		glShaderSource(ShaderID,1,&code,nullptr);
		glCompileShader(ShaderID);

		GLint success;
		glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			GLchar infolog[1024];
			glGetShaderInfoLog(ShaderID, 1024, nullptr, infolog);
			std::cerr << "Shader Compile Error\t" << infolog << "\n";
			return 0;
		}
		return 1;
	}

	void Shaders::use(){
		glUseProgram(ID);
	}

	Shaders& Shaders::operator = (Shaders&& Shaders) {
		glDeleteProgram(ID);
		ID = Shaders.ID;
		isCompiled = Shaders.isCompiled;

		Shaders.ID = 0;
		Shaders.isCompiled = 0;
		return *this;
	}

	Shaders::Shaders(Shaders&& Shaders) {
		ID = Shaders.ID;
		isCompiled = Shaders.isCompiled;

		Shaders.ID = 0;
		Shaders.isCompiled = 0;
	}

	Shaders::~Shaders() {
		glDeleteProgram(ID);
	}

}
