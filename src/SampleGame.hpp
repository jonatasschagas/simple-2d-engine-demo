#pragma once

#ifndef SampleGame_hpp
#define SampleGame_hpp

#include "view/Game.hpp"
#include <string>

class SampleGame : public Game {
 public:
  SampleGame(GraphicsManager& rGraphicsManager, SoundManager& rSoundManager,
             InputManager& rInputManager);
  ~SampleGame();

  void initialize() override;

  std::string const& getGameName() override { return "Sample Game"; }

 private:
  void initializeMembers() {}
};

#endif /* SampleGame_hpp */