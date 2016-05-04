#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#include <GL/gl.h>

#include "common.h"
#include "GameAssetManager.h"
#include "CubeAsset.h"

#include "ColourManager.h"


class GameWorld {
 public:
  
  GameWorld(ApplicationMode);

 
  void Draw();


void UpdateCameraPosition(Input, int mouse_x, int mouse_y);


 private:
  ColourManager colour_manager;
  std::shared_ptr<GameAssetManager> asset_manager;

};
#endif // GAMEWORLD_H
