
#include "GLFWInputManager.hpp"
#include "OSXResourceProvider.hpp"
#include "OpenGLGraphicsManager.hpp"
#include "OpenGLRenderer.h"
#include "SDLSoundManager.hpp"
#include "SampleGame.hpp"
#include <string>

using std::string;

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define WORLD_UNITS_X 100

int main(int argc, char** argv) {
  OSXResourceProvider resourceProvider;

  // the window
  float dpiX, dpiY;
  GLFWwindow* pWindow = initializeOpenGLRenderer(
      argc, argv, SCREEN_WIDTH, SCREEN_HEIGHT, "Sample Game", dpiX, dpiY);
  if (pWindow == nullptr) {
    return -1;
  }

  // platform manager can only be created after the OpenGL context is
  // created
  OpenGLGraphicsManager openGLGraphicsManager(
      SCREEN_WIDTH, SCREEN_HEIGHT, WORLD_UNITS_X, dpiX, dpiY, resourceProvider);
  openGLGraphicsManager.initialize();

  openGLGraphicsManager.loadShader("textured", "assets/shaders/osx/sprite.vs",
                                   "assets/shaders/osx/sprite.frag",
                                   resourceProvider);
  openGLGraphicsManager.loadShader("colored", "assets/shaders/osx/color.vs",
                                   "assets/shaders/osx/color.frag",
                                   resourceProvider);
  openGLGraphicsManager.loadShader("circle", "assets/shaders/osx/circle.vs",
                                   "assets/shaders/osx/circle.frag",
                                   resourceProvider);

  openGLGraphicsManager.loadShader("text", "assets/shaders/osx/text.vs",
                                   "assets/shaders/osx/text.frag",
                                   resourceProvider);

  openGLGraphicsManager.loadFont("assets/fonts/arcade_ya/ARCADE_N.TTF");

  GLFWInputManager inputManager(*pWindow);

  // maps GLFW key codes to InputKey values
  inputManager.setKeyTranslatorFunction([](int key) -> InputKey {
    switch (key) {
      case GLFW_KEY_LEFT:
        return InputKey::KEY_LEFT;
      case GLFW_KEY_RIGHT:
        return InputKey::KEY_RIGHT;
    }
  });

  SDLSoundManager sdlSoundManager;

  // the game
  SampleGame sampleGame(openGLGraphicsManager, sdlSoundManager, inputManager);
  int code = mainLoopOpenGLRenderer(pWindow, sampleGame, inputManager);

  return code;
}
