#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int xx1, xx2, yy1, yy2, dx, dy, pnot;

void display(void) {
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */

    // Center circle
    glColor3ub (255, 51, 51);
    
    int currx = xx1, curry = yy1;
    glBegin(GL_POINTS);    
    while (currx <= xx2 && curry <= yy2){
        glVertex2d(currx, curry);
        currx ++;
        if (pnot < 0){
            pnot = pnot + (2 * dy);
        }
        else{
            pnot = pnot + (2 * dy) - (2 * dx);
            curry ++;
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
    glClearColor (1, 1, 1, 1);
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
    cout << "Coordinate of 1st endpoint: " << endl;
    cin >> xx1 >> yy1;
    cout << "Coordinate of 2nd endpoint: " << endl;
    cin >> xx2 >> yy2;
    if (xx1 > xx2){
        int temp = xx1;
        xx1 = xx2;
        xx2 = temp;
        temp = yy1;
        yy1 = yy2;
        yy2 = temp;
    }

    dx = xx2-xx1;
    dy = yy2-yy1;
    pnot = (2 * dy) - dx;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1080, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0; /* ISO C requires main to return int. */
}

