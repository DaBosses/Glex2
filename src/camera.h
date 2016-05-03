

#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include <glm/gtx/transform.hpp>

/**
*Initialising variables and view perspective for game
updates the camera positioning aswell. 
*/
class Camera
{
    public:
        Camera()
        {
            _perspective = glm::perspective(70.0f, 800/600.0f, 0.01f, 100.0f);
            _cameraPosition=glm::vec3(0,0,0);
            forward = glm::vec3(0,0,1);
            up = glm::vec3(0,1,0);
        }

	inline glm::mat4 GetViewProjection() const
	{
		return _perspective * glm::lookAt(_cameraPosition, _cameraPosition + forward, up);
	}

/**
* Deals with forward and backward movement of camera
*/
	void MoveForward(float amt)
	{
		_cameraPosition += forward * amt;
	}

    inline glm::vec3& GetPos() {return _cameraPosition;}

/**
* Deals with right and left movement of camera
*/
	void MoveRight(float amt)
	{
		_cameraPosition += glm::cross(up, forward) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

/**
* deals with y axis invert.
*/
	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

protected:
private:
	glm::mat4 _perspective;
	glm::vec3 _cameraPosition;
	glm::vec3 forward;
	glm::vec3 up;
};

#endif
