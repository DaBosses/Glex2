/**
* calling for cubes and methods
*/

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "shader.h"
#include "cube.h"
#include "camera.h"
#include "transform.h"
#include "window.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();
        void loop();
        void update();
    protected:
    private:
    Transform tCube, tCube2, tCube3, tCube4, tCube5;
    Shader shader;
    Camera camera;
    Cube cube, cube2, cube3, cube4, cube5;
};

#endif // GAMEMANAGER_H
