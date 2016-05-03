#include "shader.h"
#include <iostream>
#include <fstream>

//static void CheckShaderError(GLuintShader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader (const std::string& text, GLenum shaderType);

Shader::Shader(){}

/**
* constructor to load rgb shader values from file
*/
Shader::Shader(const std::string& fileName)
{
    _program = glCreateProgram();
    _shaders[0] = CreateShader(LoadShader(fileName+".vs"), GL_VERTEX_SHADER);
    _shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i=0; i< NUM_SHADERS; i++)
    {
        glAttachShader(_program, _shaders[i]);
    }

    glBindAttribLocation(_program, 0, "position");

    glLinkProgram(_program);
    glValidateProgram(_program);
    CheckShaderError(_program, GL_LINK_STATUS, true, "Error: program link failed");
    CheckShaderError(_program, GL_VALIDATE_STATUS, true, "Error: program link failed");

    _uniforms[TRANSFORM_U] = glGetUniformLocation(_program, "transform");
}

/**
* cleaning up any left over data
*/
Shader::~Shader()
{
    for(unsigned int i=0; i< NUM_SHADERS; i++)
    {
        glDetachShader(_program, _shaders[i]);
        glDeleteShader(_shaders[i]);
    }

    glDeleteProgram(_program);
}

/**
* creates shadersb
*/

static GLuint CreateShader (const std::string& text, unsigned int type)
{
    GLuint shader = glCreateShader(type);

    if(shader == 0)
        std::cerr << "Error: Shader creation Failed" << std::endl;

    const GLchar* p[1];
    GLint sLengths[1];
    p[0] = text.c_str();
    sLengths[0] = text.length();

    glShaderSource(shader, 1, p, sLengths);
    glCompileShader(shader);
    Shader::CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: shadr compilation failed");

    return shader;
}

/**
* binding the shaders
*/
void Shader::Bind()
{
    glUseProgram(_program);
}

void Shader::Update(const Transform& transform,const Camera& camera)
{
    glm::mat4 model = camera.GetViewProjection()*transform.GetModel();

    glUniformMatrix4fv(_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

/**
* loads shader from file
*/
std::string Shader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

/**
* shader error check method
*/
void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
