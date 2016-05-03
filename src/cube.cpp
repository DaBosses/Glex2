#include "cube.h"
#include "camera.h"

/**
* Deals with cube vertices
*/
Cube::Cube()
{
    Vertex verticies[] = {  Vertex(glm::vec3(-0.5,0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,-0.5,0.5)),


                            Vertex(glm::vec3(-0.5,0.5,-0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,-0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,-0.5)),
                            Vertex(glm::vec3(0.5,-0.5,-0.5)),


                            Vertex(glm::vec3(0.5,0.5,0.5)),
                            Vertex(glm::vec3(0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,0.5,0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(-0.5,0.5,-0.5)),


                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(-0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,-0.5)),
                            Vertex(glm::vec3(0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(0.5,-0.5,-0.5)),


                            Vertex(glm::vec3(-0.5,0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,-0.5,0.5)),
                            Vertex(glm::vec3(0.5,-0.5,-0.5)),


                            Vertex(glm::vec3(-0.5,0.5,0.5)),
                            Vertex(glm::vec3(-0.5,0.5,-0.5)),
                            Vertex(glm::vec3(0.5,0.5,-0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,0.5)),
                            Vertex(glm::vec3(-0.5,-0.5,-0.5)),
                            Vertex(glm::vec3(0.5,-0.5,-0.5)),
                        };


/**
* Loading the cubes to graphics memory
*/
    unsigned int numVerticies = sizeof(verticies)/sizeof(verticies[0]);
    _drawCount = numVerticies;
    glGenVertexArrays(1, &_vertexArrayObject);
    glBindVertexArray(_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS,_vetexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, _vetexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVerticies* sizeof(verticies[0]), verticies, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Cube::~Cube()
{
    glDeleteVertexArrays(1, &_vertexArrayObject);
}

/**
* Method for rending the cubes
*/
void Cube::Draw()
{
    glBindVertexArray(_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, _drawCount);

    glBindVertexArray(0);
}
