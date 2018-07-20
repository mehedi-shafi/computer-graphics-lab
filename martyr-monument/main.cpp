#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int radius, centerx, centery, pnot;

int getParaMeter(int currx, int curry)
{
    if (pnot < 0){
        return pnot + (2*currx) + 1;
    }
    else{
        return pnot + (2*currx) + 1 - (2*curry);
    }
}


void display(void) {
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */

    // Center circle
    glColor3ub (255, 51, 51);
    glBegin(GL_POLYGON);

    int currx = 0;
    int curry = radius;

    while (currx <= curry){
        glVertex2d(centerx+currx, centery+curry);
        glVertex2d(centerx-currx, centery+curry);
        glVertex2d(centerx+currx, centery-curry);
        glVertex2d(centerx-currx, centery-curry);
        glVertex2d(centery+curry, centerx+currx);
        glVertex2d(centery-curry, centerx+currx);
        glVertex2d(centery+curry, centerx-currx);
        glVertex2d(centery-curry, centerx-currx);

        if (pnot < 0){
            currx ++;
            pnot = getParaMeter(currx, curry);
        }
        else{
            currx ++;
            curry --;
            pnot = getParaMeter(currx, curry);
        }
    }

    glEnd();

    // Monument body
    glColor3ub(255,255,255);

    // left column 1
    glBegin(GL_POLYGON);
    glVertex2d(50, 50);
    glVertex2d(80, 50);
    glVertex2d(80, 400);
    glVertex2d(50, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(50, 400);
    glVertex2d(50, 430);
    glVertex2d(180, 430);
    glVertex2d(180, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(150, 50);
    glVertex2d(180, 50);
    glVertex2d(180, 400);
    glVertex2d(150, 400);
    glEnd();

    // left column 2
    glBegin(GL_POLYGON);
    glVertex2d(210, 50);
    glVertex2d(240, 50);
    glVertex2d(240, 500);
    glVertex2d(210, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(210, 500);
    glVertex2d(210, 530);
    glVertex2d(340, 530);
    glVertex2d(340, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(310, 50);
    glVertex2d(340, 50);
    glVertex2d(340, 500);
    glVertex2d(310, 500);
    glEnd();

    // Center Column bars
    
    // bar #1
    glBegin(GL_POLYGON);
    glVertex2d(400, 50);
    glVertex2d(450, 50);
    glVertex2d(450, 700);
    glVertex2d(400, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(400, 700);
    glVertex2d(450, 700);
    glVertex2d(420, 1000);
    glVertex2d(380, 1000);
    glEnd();

    // bar #2
    glBegin(GL_POLYGON);
    glVertex2d(550, 50);
    glVertex2d(600, 50);
    glVertex2d(600, 700);
    glVertex2d(550, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(550, 700);
    glVertex2d(600, 700);
    glVertex2d(610, 1000);
    glVertex2d(540, 1000);
    glEnd();

    // bar #3
    glBegin(GL_POLYGON);
    glVertex2d(700, 50);
    glVertex2d(750, 50);
    glVertex2d(750, 700);
    glVertex2d(700, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(700, 700);
    glVertex2d(750, 700);
    glVertex2d(770, 1000);
    glVertex2d(730, 1000);
    glEnd();

    // center top
    glBegin(GL_POLYGON);
    glVertex2d(390, 970);
    glVertex2d(380, 1000);
    glVertex2d(770, 1000);
    glVertex2d(760, 970);
    glEnd();

    // right column 1
    glBegin(GL_POLYGON);
    glVertex2d(810, 50);
    glVertex2d(840, 50);
    glVertex2d(840, 500);
    glVertex2d(810, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(810, 500);
    glVertex2d(810, 530);
    glVertex2d(940, 530);
    glVertex2d(940, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(910, 50);
    glVertex2d(940, 50);
    glVertex2d(940, 500);
    glVertex2d(910, 500);
    glEnd();

    // right column 2
    glBegin(GL_POLYGON);
    glVertex2d(980, 50);
    glVertex2d(1010, 50);
    glVertex2d(1010, 400);
    glVertex2d(980, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(980, 400);
    glVertex2d(980, 430);
    glVertex2d(1110, 430);
    glVertex2d(1110, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(1080, 50);
    glVertex2d(1110, 50);
    glVertex2d(1110, 400);
    glVertex2d(1080, 400);
    glEnd();    

    // ground bar.
    glColor3ub(100, 24, 24);
    glBegin(GL_POLYGON);
    glVertex2d(0, 50);
    glVertex2d(0, 20);
    glVertex2d(1180, 20);
    glVertex2d(1180, 50);
    glEnd();
    /* don't wait!
    * start processing buffered OpenGL routines
    */
    glFlush ();
}
void init (void) {
    /* select clearing (background) color */
    glClearColor (0, 0, 0, 0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1980, 0, 1980);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv) {
    radius = 300;
    centerx = 575;
    centery = 575;
    pnot = 1 - radius;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1080, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Monument of Martyrs");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0; /* ISO C requires main to return int. */
}

