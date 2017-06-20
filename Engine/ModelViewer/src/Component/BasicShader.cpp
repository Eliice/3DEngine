#include "Helpers\GlewHelper.h"
#include "Component\BasicShader.h"
#include "Service\ServiceLocator.h"

BasicShader::BasicShader()
{
}


BasicShader::~BasicShader()
{
}

void BasicShader::LoadAndCreateShaders(std::string const& vertexShader, std::string const& fragmentShader)
{
	LoadShader(GL_VERTEX_SHADER, vertexShader.c_str());
	LoadShader(GL_FRAGMENT_SHADER, fragmentShader.c_str());
	Create();
}

bool BasicShader::LoadShader(uint32_t type, const char * path)
{
	uint32_t shaderID;
	shaderID = glCreateShader(type);

	switch (type)
	{
		case GL_VERTEX_SHADER:
			m_VertexShader = shaderID;
			break;
		case GL_FRAGMENT_SHADER:
			m_FragmentShader = shaderID;
			break;
		case GL_GEOMETRY_SHADER:
			m_GeometryShader = shaderID;
			break;
		case GL_TESS_CONTROL_SHADER:
			m_ControlShader = shaderID;
			break;
		case GL_TESS_EVALUATION_SHADER:
			m_EvaluationShader = shaderID;
			break;
		default:
			break;
	}

	std::ifstream fileStream;
	fileStream.open(path, std::ios::binary);
	if (!fileStream.is_open())
	{
		std::string error = "GLShader::LoadShader(): can't open file";
		ERROR_MANAGER->Fatal(error);
		return false;
	}

	std::streampos begin = fileStream.tellg();
	fileStream.seekg(0, std::ios::end);
	std::streamoff file_len = fileStream.tellg() - begin;
	char* buffer = new char[file_len + 1];
	fileStream.seekg(0, std::ios::beg);
	fileStream.read(buffer, file_len);
	fileStream.close();

	buffer[file_len] = '\0';
	glShaderSource(shaderID, 1, &buffer, nullptr);
	delete[] buffer;

	glCompileShader(shaderID);

	int compileSuccess = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileSuccess);
	if (!compileSuccess)
	{
		char errorBuffer[4096];
		int error_len;
		glGetShaderInfoLog(shaderID, 4096, &error_len, errorBuffer);
		std::string shader = type == GL_VERTEX_SHADER ? "vertex " : "fragment ";
		std::string error = " erreur dans le " + shader + "shader: " + errorBuffer;
		ERROR_MANAGER->Fatal(error);
		return false;
	}
	return true;
}

bool BasicShader::Create()
{
	m_Program = glCreateProgram();
	ERROR_MANAGER->CheckReturn(m_Program);
	glAttachShader(m_Program, m_VertexShader);
	/*glAttachShader(m_Program, m_GeometryShader);*/
	glAttachShader(m_Program, m_FragmentShader);
	/*glAttachShader(m_Program, m_ControlShader);
	glAttachShader(m_Program, m_EvaluationShader);*/

	if (LinkCallback != nullptr) {
		LinkCallback(m_Program);
	}

	glLinkProgram(m_Program);

	// TODO check result of linkage
	int linkSuccess;
	glGetProgramiv(m_Program, GL_LINK_STATUS, &linkSuccess);
	if (!linkSuccess)
	{
		char errorBuffer[4096];
		int error_len;
		glGetProgramInfoLog(m_Program, 4096, &error_len, errorBuffer);
		std::string buffer = errorBuffer;
		std::string error = " erreur de linkage : " + buffer;
		ERROR_MANAGER->Fatal(error);
		return false;
	}
	return true;
}

void BasicShader::Destroy()
{
	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);
	glDeleteShader(m_GeometryShader);
	glDeleteShader(m_ControlShader);
	glDeleteShader(m_EvaluationShader);
	glDeleteProgram(m_Program);
}

void BasicShader::Bind()
{
	glUseProgram(m_Program);
}

void BasicShader::Unbind()
{
	glUseProgram(0);
}
