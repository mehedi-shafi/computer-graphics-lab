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

    glColor3ub(255, 128, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-270, 160);
    glVertex2d(-285, 160);
    glVertex2d(-285, -260);
    glVertex2d(-270, -260);
    glEnd();

    glColor3ub(51, 25, 0);
    glBegin(GL_POLYGON);

    glVertex2d(-285, -260);
    glVertex2d(-285, -280);
    glVertex2d(-255, -280);
    glVertex2d(-255, -260);

    glEnd();

    glColor3ub(51, 25, 0);
    glBegin(GL_POLYGON);

    glVertex2d(-300, -280);
    glVertex2d(-300, -300);
    glVertex2d(-240, -300);
    glVertex2d(-240, -280);

    glEnd();

    /// flag body
    glColor3ub(0,102,0);
    glBegin(GL_POLYGON);

    glVertex2d(-270, 150);
    glVertex2d(-270, -150);
    glVertex2d(270, -150);
    glVertex2d(270, 150);

    glEnd();
/*
    glColor3ub(0, 0, 255);
    glBegin(GL_LINES);

    glVertex2d(0, -300);
    glVertex2d(0, 300);

    glVertex2d(-300, 0);
    glVertex2d(300, 0);

    glEnd();
*/
    glColor3ub (255, 0, 0);
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

/*
        glVertex2d(actualX(currx), actualY(curry));
        glVertex2d(actualX(currx), -actualY(curry));
        glVertex2d(-actualX(currx), actualY(curry));
        glVertex2d(-actualX(currx), -actualY(curry));
        glVertex2d(actualY(curry), actualX(currx));
        glVertex2d(actualY(curry), -actualX(currx));
        glVertex2d(-actualY(curry), actualX(currx));
        glVertex2d(-actualY(curry), -actualX(currx));
*/
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
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    gluOrtho2D(-300, 300, -300, 300);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv) {

    cout << "Enter radius: ";
    cin >> radius;
    cout << "Center coordinate: ";
    cin >> centerx >> centery;

    pnot = 1 - radius;

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

