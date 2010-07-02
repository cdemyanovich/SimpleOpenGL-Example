#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 400
#define kWindowHeight 300

const GLdouble pi = 3.1415926535897932384626433832795;

typedef GLdouble point[3];

GLvoid DrawGLScene(void);
void pentagon(void);
void triangle(point a, point b, point c);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow ("simple opengl example");

  glutDisplayFunc(DrawGLScene);

  glutMainLoop();
  return 0;
}

GLvoid DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0);
  glLoadIdentity();

  pentagon();
  glutSwapBuffers();
}

void triangle( point a, point b, point c)
{
  glBegin(GL_LINE_LOOP);
  glVertex3dv(a);
  glVertex3dv(b);
  glVertex3dv(c);
  glEnd();
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
