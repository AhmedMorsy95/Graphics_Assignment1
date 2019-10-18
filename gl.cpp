#include <GL/glut.h>
#include <math.h>

void set_background_color()
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // background color
  glClear(GL_COLOR_BUFFER_BIT);     // says that bit values in the color buffer (refresh buffer) that are to be
                                    //set to the values indicated in the glClearColor function
}

void set_shape_color()
{
  glColor3f(0.0, 0.4, 0.2); // choose a variety of color schemes for the objects we want to display in a scene
}
void two_dimensional_drawing()
{
  // openGL treats 2D as a special case of 3D drawings so we need to tell it to project the shape
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 500.0, 0.0, 250.0); // orthogonal projection
}

// display callback function
void draw_m()
{
  set_background_color();
  set_shape_color();
  glBegin(GL_LINE_STRIP);
  // GL_LINE_STRIP used to connect each 2 consecutive points together
  glVertex2i(125, 50);
  glVertex2i(150, 150);
  glVertex2i(175, 100);
  glVertex2i(200, 150);
  glVertex2i(225, 50);
  glEnd();
  glFlush();
}
void draw_l()
{
  set_background_color();
  set_shape_color();
  two_dimensional_drawing();
  glBegin(GL_LINE_STRIP);
  // GL_LINE_STRIP used to connect each 2 consecutive points together
  glVertex2i(125, 200);
  glVertex2i(125, 50);
  glVertex2i(225, 50);
  glEnd();
  glFlush();
}
void draw_l_3D(void)
{
  set_background_color();
  set_shape_color();
  glBegin(GL_LINE_LOOP);
  glVertex3i(100, 200,1);
  glVertex3i(100, 100,1);
  glVertex3i(200, 120,1);
  glVertex3i(195, 80,0);
  glVertex3i(70, 60,0);
  glVertex3i(70, 175,0);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == '3')
    draw_l_3D();
  if(key == 'm')
    draw_m();  
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //display mode
  glClearDepth(1.0f);
  glutInitWindowPosition(50, 25);
  glutInitWindowSize(500, 250);     // resolution
  glutCreateWindow("Lab 1"); // name

  glutDisplayFunc(draw_l); // register callback function to be called while displaying
  glutKeyboardFunc(keyboard); // handle pressing keyboard
  glutMainLoop(); // infinite loop waiting for events
  return 0;
}