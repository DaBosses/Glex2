#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <GL/glew.h>
#include "window.h"
#include "shader.h"
#include "cube.h"
#include "camera.h"
#include "transform.h"
#include "gamemanager.h"


using namespace std;

/**
* calling classes and creating objects
*/
Camera camera;
Transform tCube;
Transform tCube2;
Transform tCube3;
Transform tCube4;
Transform tCube5;


void CameraDir();


/**
* intialising SDL window and creating different cubes and positioning of *cubes, linking shaders and calling render fucntion draw for cubes to 	* render
*/
int main()
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(0);
    SDL_Window * _WINDOW = SDL_CreateWindow("BlockWorld"
                   , SDL_WINDOWPOS_CENTERED
                   , SDL_WINDOWPOS_CENTERED
                   , 840
                   , 640
                   , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    Window window(840,640, "shaderexample");

    int x, y;
    SDL_PumpEvents();
    SDL_GetMouseState(&x, &y); 
    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
    SDL_WarpMouseInWindow(_WINDOW, 840/2, 640/2); 
    SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);
    SDL_PumpEvents(); 

    Shader shader("src/res/redcube");
    Shader shader2("src/res/whitecube");

    Cube cube;
    Cube cube2;
    Cube cube3;
    Cube cube4;
    Cube cube5;

//left front row cube
    tCube.GetPos().z=4;
    tCube.GetPos().x=4.5f;

//middle front row cube
   tCube2.GetPos().z=4;
  tCube2.GetPos().x=2;

    //right front row cube
    tCube3.GetPos().z=4;
    tCube3.GetPos().x=-0.5;

   //second row cube
   tCube4.GetPos().z=6;
    tCube4.GetPos().x=2;

    //endgoal cube
    tCube5.GetPos().z=10;
    tCube5.GetPos().x=2;



    while(!window.IsClosed())
    {
        glClearColor(0.0f, 0.15f, 0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        CameraDir();
//        collide.Collision(camera , cube);

        shader.Update(tCube,camera);
        cube.Draw();

        shader2.Update(tCube4,camera);
         cube4.Draw();

        shader2.Update(tCube3,camera);
         cube3.Draw();

         shader2.Update(tCube2,camera);
         cube2.Draw();
         shader2.Bind();


         shader2.Update(tCube5,camera);
         cube5.Draw();

        shader.Bind();

        window.Update();
    }
    SDL_QUIT;
    return 0;

}

/**
* switch statement with sdl keys linked to player movement i.e w key *moves player forward and collision dection with x, y, z cordinates.
*/
void CameraDir()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
      {
         if (event.type == SDL_KEYDOWN)
            switch (event.key.keysym.sym)
            {
               case SDLK_w:
                  camera.MoveForward(0.1);

                   if(abs(camera.GetPos().x-tCube.GetPos().x)<1 && abs(camera.GetPos().y-tCube.GetPos().y)<1 && abs(camera.GetPos().z-tCube.GetPos().z)<1)
                  {
                    camera.MoveForward(-0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube2.GetPos().x)<1 && abs(camera.GetPos().y-tCube2.GetPos().y)<1 && abs(camera.GetPos().z-tCube2.GetPos().z)<1)
                  {
                    camera.MoveForward(-0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube3.GetPos().x)<1 && abs(camera.GetPos().y-tCube3.GetPos().y)<1 && abs(camera.GetPos().z-tCube3.GetPos().z)<1)
                  {
                    camera.MoveForward(-0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube4.GetPos().x)<1 && abs(camera.GetPos().y-tCube4.GetPos().y)<1 && abs(camera.GetPos().z-tCube4.GetPos().z)<1)
                  {
                    camera.MoveForward(-0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube5.GetPos().x)<1 && abs(camera.GetPos().y-tCube5.GetPos().y)<1 && abs(camera.GetPos().z-tCube5.GetPos().z)<1)
                  {

                    camera.MoveForward(-0.1);
                    cout << "Reached the targeted Red cube, Well Done!" << endl;
                    
                  }

                break;

                case SDLK_s:
                camera.MoveForward(-0.1);

                  if(abs(camera.GetPos().x-tCube.GetPos().x)<=1 && abs(camera.GetPos().y-tCube.GetPos().y)<=1 && abs(camera.GetPos().z-tCube.GetPos().z)<=1)
                  {
                    camera.MoveForward(0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }
                  if(abs(camera.GetPos().x-tCube2.GetPos().x)<=1 && abs(camera.GetPos().y-tCube2.GetPos().y)<=1 && abs(camera.GetPos().z-tCube2.GetPos().z)<=1)
                  {
                    camera.MoveForward(0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }
                  if(abs(camera.GetPos().x-tCube3.GetPos().x)<=1 && abs(camera.GetPos().y-tCube3.GetPos().y)<=1 && abs(camera.GetPos().z-tCube3.GetPos().z)<=1)
                  {
                    camera.MoveForward(0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }
                  if(abs(camera.GetPos().x-tCube4.GetPos().x)<=1 && abs(camera.GetPos().y-tCube4.GetPos().y)<=1 && abs(camera.GetPos().z-tCube4.GetPos().z)<=1)
                  {
                    camera.MoveForward(0.1);
                    cout << "Crashed! Back OFF!" << endl;
                  }
                  if(abs(camera.GetPos().x-tCube5.GetPos().x)<=1 && abs(camera.GetPos().y-tCube5.GetPos().y)<=1 && abs(camera.GetPos().z-tCube5.GetPos().z)<=1)
                  {
                    camera.MoveForward(0.1);
                    cout << "Reached the targeted Red cube, Well Done!" << endl;
                    
                  }

                break;

                case SDLK_d:
                  camera.MoveRight(-0.1);

                  if(abs(camera.GetPos().x-tCube.GetPos().x)<=1 && abs(camera.GetPos().y-tCube.GetPos().y)<=1 && abs(camera.GetPos().z-tCube.GetPos().z)<=1)
                  {
                    camera.MoveRight(0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube2.GetPos().x)<=1 && abs(camera.GetPos().y-tCube2.GetPos().y)<=1 && abs(camera.GetPos().z-tCube2.GetPos().z)<=1)
                  {
                    camera.MoveRight(0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                   if(abs(camera.GetPos().x-tCube3.GetPos().x)<=1 && abs(camera.GetPos().y-tCube3.GetPos().y)<=1 && abs(camera.GetPos().z-tCube3.GetPos().z)<=1)
                  {
                    camera.MoveRight(0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                   if(abs(camera.GetPos().x-tCube4.GetPos().x)<=1 && abs(camera.GetPos().y-tCube4.GetPos().y)<=1 && abs(camera.GetPos().z-tCube4.GetPos().z)<=1)
                  {
                    camera.MoveRight(0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                    if(abs(camera.GetPos().x-tCube5.GetPos().x)<=1 && abs(camera.GetPos().y-tCube5.GetPos().y)<=1 && abs(camera.GetPos().z-tCube5.GetPos().z)<=1)
                  {
                    camera.MoveRight(0.1);
 		    cout << "Reached the targeted Red cube, Well Done!" << endl;
                   
                  }

                break;
                case SDLK_a:
                  camera.MoveRight(0.1);

                  if(abs(camera.GetPos().x-tCube.GetPos().x)<=1 && abs(camera.GetPos().y-tCube.GetPos().y)<=1 && abs(camera.GetPos().z-tCube.GetPos().z)<=1)
                  {
                    camera.MoveRight(-0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube2.GetPos().x)<=1 && abs(camera.GetPos().y-tCube2.GetPos().y)<=1 && abs(camera.GetPos().z-tCube2.GetPos().z)<=1)
                  {
                    camera.MoveRight(-0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                   if(abs(camera.GetPos().x-tCube3.GetPos().x)<=1 && abs(camera.GetPos().y-tCube3.GetPos().y)<=1 && abs(camera.GetPos().z-tCube3.GetPos().z)<=1)
                  {
                    camera.MoveRight(-0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                  if(abs(camera.GetPos().x-tCube4.GetPos().x)<=1 && abs(camera.GetPos().y-tCube4.GetPos().y)<=1 && abs(camera.GetPos().z-tCube4.GetPos().z)<=1)
                  {
                    camera.MoveRight(-0.1);
    cout << "Crashed! Back OFF!" << endl;
                  }

                   if(abs(camera.GetPos().x-tCube5.GetPos().x)<=1 && abs(camera.GetPos().y-tCube5.GetPos().y)<=1 && abs(camera.GetPos().z-tCube5.GetPos().z)<=1)
                  {
                    camera.MoveRight(-0.1);
                    cout << "Reached the targeted Red cube, Well Done!" << endl;
                    
                  }

                break;
            }
         }
         if (event.type == SDL_MOUSEMOTION)
         {
            camera.RotateY(-event.motion.xrel/2);
            camera.Pitch(event.motion.yrel/2);
         }
      }



