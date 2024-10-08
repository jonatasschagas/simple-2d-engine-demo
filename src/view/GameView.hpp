#pragma once
#ifndef GameView_hpp
#define GameView_hpp

#include "core/TextSprite.hpp"
#include "objects/Rocket.hpp"
#include "objects/StarField.hpp"
#include "view/View.h"
#include <vector>

class GameView : public View {
 public:
  GameView();
  ~GameView();

  void initialize(ViewManager* pViewManager) override;

  void update(float delta) override;

  void onKeyPressed(InputKey key) override;

  void onMousePressed(int x, int y) override;

  void onMouseReleased(int x, int y) override;

  void renderSprite(GraphicsManager& rGraphicsManager) override;

  void processSounds(SoundManager& rSoundManager) override;

 private:
  StarField m_starField;
  Rocket m_rocket;
  ViewManager* m_pViewManager = nullptr;
  glm::vec2 m_screenSize = {0, 0};
  float m_speedToMove = 0;
  bool m_songInitialized = false;
  TextSprite m_demoTextSprite;
  float m_demoTextAccumulatedDelta = 0.0f;
  float m_demoTextSpeed = 0.5f;
};

#endif /* GameView_hpp */
