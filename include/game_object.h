#pragma once

#include <SDL2/SDL.h>
#include <fmt/core.h>

class GameObject {
public:
  GameObject(const char *texture_sheet, int x, int y);
  ~GameObject();
  void update();
  void render();
  void move(int x, int y);
  void moves(bool moving) { is_moving = moving; }

private:
  bool is_moving{false};
  SDL_Texture *object_texture;
  SDL_Rect srcRect, destRect;
};
