#include "game_object.h"
#include "texture_manager.h"
#include <chrono>
#include <fmt/core.h>
#include <thread>

GameObject::GameObject(const char *texture_sheet, int x, int y) {
  object_texture = TextureManager::load_texture(texture_sheet);
  destRect.x = x;
  destRect.y = y;
  destRect.h = 32;
  destRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.h = 32;
  srcRect.w = 3200;
}

void GameObject::update() {
  //  if (destRect.y == 0 && destRect.x < WIDTH - destRect.w) {
  //    destRect.x++;
  //  }
  //  if (destRect.x == WIDTH - destRect.w && destRect.y < HEIGHT - destRect.h)
  //  {
  //    destRect.y++;
  //  }
  //  if (destRect.y == HEIGHT - destRect.h && destRect.x > 0) {
  //    destRect.x--;
  //  }
  //  if (destRect.x == 0 && destRect.y > 0) {
  //    destRect.y--;
  //  }
}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, object_texture, &srcRect, &destRect);
}

void GameObject::move(int x, int y) {
  while (is_moving) {
    if (0 < destRect.x && destRect.x < WIDTH) {
      destRect.x += x;
    }
    if (0 < destRect.y && destRect.y < HEIGHT) {
      destRect.y += y;
    }
    fmt::print("x: {}, y: {}, is_moving: {}\n", destRect.x, destRect.y, is_moving);
    SDL_Delay(20);
  }
}
