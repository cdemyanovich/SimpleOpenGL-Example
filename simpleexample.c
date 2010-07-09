#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_X 100
#define WINDOW_Y 100

const GLdouble pi = 3.1415926535897932384626433832795;

typedef GLdouble point[3];

void DrawGLScene(void);
void ChangeSize(GLsizei w, GLsizei h);
void drawShapes(void);
void pentagon(void);
void triangle(point a, point b, point c);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(WINDOW_X, WINDOW_Y);
  glutCreateWindow ("simple opengl example");
  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(DrawGLScene);
  glutReshapeFunc(ChangeSize);

  glutMainLoop();
  return 0;
}

void DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -5.0f);

  drawShapes();
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Change the viewport each time the window is resized
  // otherwise the image can be distorted.
  // You do not have to match the window size - that's just simple.
  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(60.0f, w/h, 1.0, 400.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawShapes(void)
{
  glRotatef(120.f, 0.0f, 0.0f, 0.0f);
  pentagon();
  glPushMatrix();

  glLoadIdentity();
  glTranslatef(-4.0f, 0.0f, -10.0f);
  pentagon();
  glPushMatrix();

  glTranslatef(12.0f, 0.0f, -15.0f);
  pentagon();
  glPopMatrix();
}

void pentagon(void)
{
  GLdouble c1 = cos(2.0f * pi / 5.0f);
  GLdouble c2 = cos(pi / 5.0f);
  GLdouble s1 = sin(2.0f * pi / 5.0f);
  GLdouble s2 = sin(4.0f * pi / 5.0f);

  point v[6] = {{0.0, 0.0, 1.0},
                {0.0, 1.0, -0.333333},
                {s1, c1, -0.333333},
                {s2, -c2, -0.333333},
                {-s2, -c2, -0.333333},
                {-s1, c1, -0.333333}};

  triangle(v[0], v[1], v[2]);
  triangle(v[0], v[2], v[3]);
  triangle(v[0], v[3], v[4]);
  triangle(v[0], v[4], v[5]);
  triangle(v[0], v[5], v[1]);
}

void triangle( point a, point b, point c)
{
  glBegin(GL_LINE_LOOP);
  glVertex3dv(a);
  glVertex3dv(b);
  glVertex3dv(c);
  glEnd();
}