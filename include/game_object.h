#pragma once

#include <SDL2/SDL.h>

class GameObject {
public:
  GameObject(const char *texture_sheet, int x, int y);
  ~GameObject();
  void update();
  void render();

private:
  SDL_Texture *object_texture;
  SDL_Rect srcRect, destRect;
};
