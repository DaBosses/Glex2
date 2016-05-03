/**
* vertex processing and buffer objects and dealing with positioning. 
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "transform.h"

class Transform
{
    public:
        Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)):

        _pos(pos),
        _rot(rot),
        _scale(scale)
        {}

        inline glm::mat4 GetModel() const
        {
            glm::mat4 posMatrix = glm::translate(_pos);

            glm::mat4 rotxMatrix = glm::rotate(_rot.x,glm::vec3(1,0,0));
            glm::mat4 rotyMatrix = glm::rotate(_rot.y,glm::vec3(0,1,0));
            glm::mat4 rotzMatrix = glm::rotate(_rot.z,glm::vec3(0,0,1));

            glm::mat4 scaleMatrix = glm::scale(_scale);

            glm::mat4 rotMatrix = rotzMatrix * rotyMatrix * rotxMatrix;

            return posMatrix * rotMatrix * scaleMatrix;
        }

        inline glm::vec3& GetPos() {return _pos;}
        inline glm::vec3& GetRot() {return _rot;}
        inline glm::vec3& GetScale() {return _scale;}

        //virtual ~Transform();
    protected:
    private:
        glm::vec3 _pos;
        glm::vec3 _rot;
        glm::vec3 _scale;
};

#endif // TRANSFORM_H
