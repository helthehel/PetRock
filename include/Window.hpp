#include <SDL2/SDL.h>
#include <memory>
#include <functional>

#pragma once
enum windowContition {
    QUIT,
    MINIMIZE,
    EXPAND,
    RESIZE,
    MOVE,
    FOCUS,
    UNFOCUS
};
class Window {
    
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> d_window;   
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> d_renderer;
    const int d_originalSize;
    int d_scale;
    void* (*onQuit)(void* args);
    void* (*onMinimize)(void* args);
    void* (*onExpand)(void* args);
    void* (*onResize)(void* args);
    void* (*onMove)(void* args);
    void* (*onFocus)(void* args);
    void* (*onUnfocus)(void* args);
    

public:
    SDL_Renderer* renderer();
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);
    int originalSize(); 
    int scale();
    void setScale(const int scale);
    void setWindowConditionFunction (windowContition myCondition, void* (*myFunction)(void* args));
};