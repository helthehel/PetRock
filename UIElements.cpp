#include "UIElements.hpp"
float UIElement::margin() {
    return d_margin;
}
float UIElement::padding() {
    return d_padding;
}
SDL_Rect UIElement::vectorProperties() {
    return d_vectorProperties;
}
void UIElement::setMargin(float margin) {
    d_margin = margin;
}
void UIElement::setPadding(float padding) {
    d_padding = padding;
}
void UIElement::setBorderData(UIBorder* borderData) {
    d_borderData = borderData;
}
UIBorder UIElement::borderData() {
    return *d_borderData;
}

UIButton::UIButton(UIBorder* borderData) {
    if (borderData != NULL) 
        this->d_borderData = borderData;
}