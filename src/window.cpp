/**
* setting up SDL window and GLEW 
*/

#include "window.h"
#include <GL/glew.h>
#include <iostream>


Window::Window(int width, int height, const std::string& title)
{

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);

    GLenum status =glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Glew Failed to initalize" << std::endl;
    }

    _isClosed=false;
}

/**
* delete any left over data
*/
Window::~Window()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);

}

/**
* closing window method
*/

bool Window::IsClosed()
{
    return _isClosed;
}

/**
* updates window after event occurs
*/
void Window::Update()
{
    SDL_GL_SwapWindow(window);

    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
        {
            _isClosed=true;
        }
    }
}
