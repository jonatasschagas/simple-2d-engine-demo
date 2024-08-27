#include "GameView.hpp"
#include "input/InputKey.hpp"

GameView::GameView()
    : View(),
      m_starField(300, 0.001f),
      m_rocket(0.01f),
      m_demoTextSprite(1, glm::vec4(1, 1, 1, 1)) {}

GameView::~GameView() {}

void GameView::initialize(ViewManager* pViewManager) {
  addChild(&m_starField);
  addChild(&m_rocket);
  addChild(&m_demoTextSprite);

  m_starField.setXY(0, 0);
  m_starField.setSize(100.f, 100.f);

  m_rocket.setXY(25.f, 50.f);
  m_rocket.setSize(10.f, 15.f);

  m_demoTextSprite.setXY(40, 10);
  m_demoTextSprite.setSize(20.f, 8.f);
  m_demoTextSprite.setText("Sample Game");

  m_pViewManager = pViewManager;  // view manager should be use to
                                  // transition to other game views
}

void GameView::update(float delta) {
  StructuralSprite::update(delta);

  if (m_speedToMove > 0) {
    m_rocket.moveRight();
  } else if (m_speedToMove < 0) {
    m_rocket.moveLeft();
  }

  m_demoTextAccumulatedDelta += delta;
  if (m_demoTextAccumulatedDelta > m_demoTextSpeed) {
    m_demoTextAccumulatedDelta = 0;
    m_demoTextSprite.setColor(glm::vec4(rand() % 100 / 100.0f,
                                        rand() % 100 / 100.0f,
                                        rand() % 100 / 100.0f, 1));
  }
}

void GameView::onKeyPressed(InputKey key) {
  switch (key) {
    case InputKey::KEY_LEFT:
      m_rocket.moveLeft();
      break;
    case InputKey::KEY_RIGHT:
      m_rocket.moveRight();
      break;
    default:
      break;
  }
}

void GameView::onMousePressed(int x, int y) {
  int halfScreen = m_screenSize.x / 2;
  if (x < halfScreen) {
    m_speedToMove = -1;
  } else {
    m_speedToMove = 1;
  }
}

void GameView::onMouseReleased(int x, int y) { m_speedToMove = 0; }

void GameView::renderSprite(GraphicsManager& rGraphicsManager) {
  if (m_screenSize.x == 0 || m_screenSize.y == 0) {
    m_screenSize.x = rGraphicsManager.getScreenWidth();
    m_screenSize.y = rGraphicsManager.getScreenHeight();
  }
}

void GameView::processSounds(SoundManager& rSoundManager) {
  if (!m_songInitialized) {
    string const& soundName = "assets/sounds/music.wav";
    rSoundManager.loadMusic(soundName);
    rSoundManager.playMusic(soundName);
    m_songInitialized = true;
  }
}