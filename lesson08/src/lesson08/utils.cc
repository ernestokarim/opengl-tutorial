
#include <IL/il.h>
#include <IL/ilu.h>

#include "lesson08/dbg.h"
#include "lesson08/utils.h"
#include "lesson08/texture.h"


Texture gBoard;


GLfloat gCameraX = 0.f, gCameraY = 0.f;


bool initGL() {
  glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();

  glClearColor(0.f, 0.5f, 0.5f, 1.f);
  glEnable(GL_TEXTURE_2D);

  checkGL("init failed");

  ilInit();
  iluInit();
  ilClearColour(255, 0, 0, 0);  // used to pad the textueres

  checkIL("init failed");

  return true;

error:
  return false;
}


void update() {
  // empty
}


void render() {
  glClear(GL_COLOR_BUFFER_BIT);

  GLfloat x = (SCREEN_WIDTH - gBoard.width())/2.f;
  GLfloat y = (SCREEN_HEIGHT - gBoard.height())/2.f;
  gBoard.render(x, y);

  glutSwapBuffers();
}


bool loadMedia() {
  return gBoard.loadFromFile("assets/texture.png");
}

