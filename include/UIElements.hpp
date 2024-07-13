#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>   
#include <cstddef>
#include <vector>
#include <unordered_map>
#pragma once
class UIBorder {
    float radius;
    float thickness;
    SDL_Color color;
};

class UIElement {
    SDL_Rect d_vectorProperties;
    float d_margin;
    float d_padding;
    //Fires when the user clicks the element
    void* (*onClick)(void* args);
    
    //Fires when cursor hovers over the element
    void* (*onHover)(void* args);
    UIBorder* d_borderData;

public:
    virtual SDL_Rect vectorProperties();
    float margin();
    float padding();
    UIBorder borderData();
    void setMargin(float margin);
    void setPadding(float padding);
    void setBorderData(UIBorder* borderData);
};

class UIText : UIElement {
    static std::unordered_map<const char*, std::vector<SDL_Texture>> UIGlyphCache;
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
    
    void setBorderData(UIBorder* borderData); 
};
