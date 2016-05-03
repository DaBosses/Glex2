/**
* link relevant classes needed for shaders
*/

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include "transform.h"
#include "camera.h"

class Shader
{
    public:
        Shader();
        Shader(const std::string& filename);
        static void CheckShaderError(GLuint Shader, GLuint flag, bool isProgram, const std::string& errorMessage);
        std::string LoadShader(const std::string& fileName);
        void Bind();
        void Update(const Transform& transform, const Camera& camera);

        virtual ~Shader();
    protected:
    private:
    static const unsigned int NUM_SHADERS =2;


        enum
        {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint _program;
        GLuint _shaders[NUM_SHADERS];
        GLuint _uniforms[NUM_UNIFORMS];

};

#endif // SHADER_H
