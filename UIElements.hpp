#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <cstddef>
class UIElement {
    SDL_Rect d_vectorProperties;
    float d_margin;
    float d_padding;
    //Fires when the user clicks the element
    void* (*onClick)(void* args);
    
    //Fires when the user hovers over the element
    void* (*onHover)(void* args);

    virtual SDL_Rect vectorProperties();
    float margin();
    float padding();
};

class UIText : UIElement {

};
class UIBorder : UIElement {
    float radius;
    float thickness;
    SDL_Color color;
};
class UIButton : UIElement {
    float d_borderRadius;
    float d_borderThickness; 
    SDL_Color d_borderColor;
    float d_borderOffsetX, d_borderOffsetY;
    SDL_Color d_backgroundColor;
    UIText* text;
    SDL_Rect vectorProperties();
    SDL_Color borderColor();
    SDL_Color backgroundColor();
    UIButton(UIBorder* borderData = NULL);
};
