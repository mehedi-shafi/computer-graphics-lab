#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int radius, centerx, centery;

int getParaMeter(int currx, int curry, int pnot)
{
    if (pnot < 0){
        return pnot + (2*currx) + 1;
    }
    else{
        return pnot + (2*currx) + 1 - (2*curry);
    }
}


void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3ub (0, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2d(100, 200);
    glVertex2d(400, 200);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(400, 175);
    glVertex2d(400, 425);
    glVertex2d(500, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(500, 300);
    glVertex2d(800, 300);
    glVertex2d(800, 500);
    glVertex2d(500, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(800, 275);
    glVertex2d(800, 525);
    glVertex2d(900, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(500, 300);
    glVertex2d(500, 120);
    glVertex2d(650, 120);
    glEnd();

    glFlush ();
}
void init (void) {
    /* select clearing (background) color */
    glClearColor (1, 1, 1, 1);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0, 1080, 0, 720);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1080, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0; /* ISO C requires main to return int. */
}

