#include "game.h"

int main() {
  const int FPS{60};
  const int frame_delay{1000 / FPS};
  Uint32 frame_start{0};
  int frame_time{0};
  Game *game = new Game();
  game->init("The game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH,
             HEIGHT, SDL_FALSE);
  while (game->running()) {
    frame_start = SDL_GetTicks();
    game->handle_events();
    game->update();
    game->render();
    frame_time = SDL_GetTicks() - frame_start;
    if (frame_delay > frame_time) {
      SDL_Delay((frame_delay - frame_time) / 2);
    }
  }

  game->clean();
}
