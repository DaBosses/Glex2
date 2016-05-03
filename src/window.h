/**
* window class methods etc.
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>


class Window
{
    public:
        Window(int width, int height, const std::string& title);
        virtual ~Window();
        void Update();
        bool IsClosed();
    protected:
    private:
        bool _isClosed;
        SDL_Window* window;
        SDL_GLContext glContext;
};

#endif // WINDOW_H
