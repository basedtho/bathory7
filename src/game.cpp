#include "game.h"
#include "texture_manager.h"
#include <cstdlib>
#include <fmt/core.h>

SDL_Renderer *Game::renderer{nullptr};

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    fmt::print("Subsystems initialized\n");
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window) {
      fmt::print("Window created\n");
    } else {
      std::exit(EXIT_FAILURE);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      fmt::print("Renderer created\n");
    } else {
      std::exit(EXIT_FAILURE);
    }
    is_running = true;
  } else {
    std::exit(EXIT_FAILURE);
  }
  player = new GameObject("../assets/hero.png", 320, 240);
  map = new Map();
}

void Game::handle_events() {
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    is_running = false;
    break;
  case SDL_KEYDOWN:
    player->moves(true);
    switch (event.key.keysym.sym) {
    case SDLK_UP:
      player->move(0, -1);
      break;
    case SDLK_DOWN:
      player->move(0, 1);
      break;
    case SDLK_LEFT:
      player->move(-1, 0);
      break;
    case SDLK_RIGHT:
      player->move(1, 0);
      break;
    default:
      break;
    }
  case SDL_KEYUP:
    player->moves(false);
    break;
  default:
    break;
  }
}

void Game::update() { player->update(); }

void Game::render() {
  SDL_RenderClear(renderer);
  map->draw_map();
  player->render();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  fmt::print("Game cleaned\n");
}
