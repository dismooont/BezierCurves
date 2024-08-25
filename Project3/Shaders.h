#pragma once
#include <string>
#include <glew.h>

namespace ShadersNS {
	class Shaders
	{
	public:
		Shaders(const std::string& vertex_shader, const std::string& fragment_shader);
		~Shaders();

		bool isCompiledF() {
			return isCompiled;
		}
		void use();

		Shaders() = delete;

		Shaders(Shaders&) = delete;

		Shaders& operator = (const Shaders&) = delete;

		Shaders& operator = (Shaders&& Shaders);

		Shaders(Shaders&& Shaders);

	private:
		bool create_shader(const std::string& source, const GLenum shaderType, GLuint& ShaderID);
		bool isCompiled = false;
		GLuint ID = 0;

	};
}
