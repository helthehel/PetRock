#include <SDL2/SDL.h>
#include <memory>
class Window {
    int x, y, w, h;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window; 
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
    
};