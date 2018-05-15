#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

///house body
glColor3ub (204, 255, 255);
glBegin(GL_POLYGON);

glVertex2d (100, 100);
glVertex2d (400, 100);
glVertex2d (400, 400);
glVertex2d (100, 400);

glEnd();

/// jalala bad er rongin tin
glColor3ub (51, 153, 255);
glBegin(GL_POLYGON);

glVertex2d (80, 400);
glVertex2d (420, 400);
glVertex2d (250, 500);

glEnd();


/// RFL door
glColor3ub (255, 51, 51);
glBegin(GL_POLYGON);

glVertex2d (220, 100);
glVertex2d (280, 100);
glVertex2d (280, 350);
glVertex2d (220, 350);

glEnd();

/// RFL door shadow
glColor3ub (32, 32, 32);
glBegin(GL_POLYGON);

glVertex2d (260, 110);
glVertex2d (280, 100);
glVertex2d (280, 350);
glVertex2d (260, 340);

glEnd();

/// PHP Glass window 1
glColor3ub (250, 128, 0);
glBegin(GL_POLYGON);

glVertex2d (130, 250);
glVertex2d (200, 250);
glVertex2d (200, 300);
glVertex2d (130, 300);

glEnd();

/// PHP Glass window 2
glColor3ub (250, 128, 0);
glBegin(GL_POLYGON);

glVertex2d (300, 250);
glVertex2d (370, 250);
glVertex2d (370, 300);
glVertex2d (300, 300);

glEnd();

/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0, 0, 0, 0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0, 600, 0, 600);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
