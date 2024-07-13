#include <stdio.h>
#include "UIElements.hpp"
#include "Window.hpp"
void* onWindowQuit(void* args) {
    printf("Window quit\n");
    return NULL;
}
int main(int, char**){
    Window window("Hello World", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    window.setWindowConditionFunction(QUIT, onWindowQuit);
    bool running = true;
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
        switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }
    return 0;
}