#include "texture_manager.h"

#include <SDL2/SDL_image.h>
#include <fmt/core.h>

SDL_Texture *TextureManager::load_texture(const char *filename) {
  SDL_Surface *temp_surface = IMG_Load(filename);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
  SDL_FreeSurface(temp_surface);
  return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
  SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
