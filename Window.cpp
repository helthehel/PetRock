#include "Window.hpp"
#include <stdexcept>


Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) : d_window(SDL_CreateWindow(title, x, y, w, h, flags), SDL_DestroyWindow), d_renderer(SDL_CreateRenderer(d_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer), d_originalSize(w) {
    if (d_window == nullptr) {
        throw std::runtime_error("Failed to create window");
    }
    if (d_renderer == nullptr) {
        throw std::runtime_error("Failed to create renderer");
    }
}

int Window::originalSize() {
    return d_originalSize;
}

int Window::scale() {
    return d_scale;
}

void Window::setScale(const int scale) {
    d_scale = scale;
}
SDL_Renderer* Window::renderer() {
    return d_renderer.get();
}
void Window::setWindowConditionFunction (windowContition myCondition, void* (*myFunction)(void* args)) {
    switch (myCondition) {
        case QUIT:
            onQuit = myFunction;
            break;
        case MINIMIZE:
            onMinimize = myFunction;
            break;
        case EXPAND:
            onExpand = myFunction;
            break;
        case RESIZE:
            onResize = myFunction;
            break;
        case MOVE:
            onMove = myFunction;
            break;
        case FOCUS:
            onFocus = myFunction;
            break;
        case UNFOCUS:
            onUnfocus = myFunction;
            break;
        default:
            break;
    }
}
