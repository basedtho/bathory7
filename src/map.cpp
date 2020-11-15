#include "map.h"
#include "texture_manager.h"

Map::Map() {
  water = TextureManager::load_texture("../assets/water.png");
  grass = TextureManager::load_texture("../assets/grass.png");
  dirt = TextureManager::load_texture("../assets/dirt.png");
  load_map(lvl1);
  src.x = dest.x = 0;
  src.y = dest.y = 0;
  src.h = dest.h = 32;
  src.w = dest.w = 32;
}

void Map::load_map(int arr[map_width][map_height]) {
  for (int row = 0; row < map_height; ++row) {
    for (int col = 0; col < map_width; ++col) {
      map[row][col] = arr[row][col];
    }
  }
}

void Map::draw_map() {
  int type = 0;
  for (int row = 0; row < map_height; ++row) {
    for (int col = 0; col < map_width; ++col) {
      type = map[row][col];
      dest.x = col * 32;
      dest.y = row * 32;
      switch (type) {
      case 0:
        TextureManager::draw(water, src, dest);
        break;
      case 1:
        TextureManager::draw(grass, src, dest);
        break;
      case 2:
        TextureManager::draw(dirt, src, dest);
        break;
      default:
        break;
      }
    }
  }
}
