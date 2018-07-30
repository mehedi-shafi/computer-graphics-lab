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

void drawCircle(int cx, int cy, int rad){
    int pnot = 1 - rad;

    glBegin(GL_POLYGON);

    int currx = 0, curry = rad;
    while (curry > currx){

        // glVertex2d(currx+centerx, curry+centery);
        // glVertex2d(currx+centerx, -curry+centery);
        // glVertex2d(-currx+centerx, curry+centery);
        // glVertex2d(-currx+centerx, -curry+centery);
        // glVertex2d(curry+centerx, currx+centery);
        // glVertex2d(-curry+centerx, currx+centery);
        // glVertex2d(curry+centerx, -currx+centery);
        // glVertex2d(-curry+centerx, -currx+centery);

        glVertex2d(centerx+currx, centery+curry);
        glVertex2d(centerx-currx, centery+curry);
        glVertex2d(centerx+currx, centery-curry);
        glVertex2d(centerx-currx, centery-curry);
        glVertex2d(centerx+curry, centery+currx);
        glVertex2d(centerx-curry, centery+currx);
        glVertex2d(centerx+curry, centery-currx);
        glVertex2d(centerx-curry, centery-currx);

        if (pnot < 0){
            currx ++;
            pnot = getParaMeter(currx, curry, pnot);
        }
        else{
            currx ++;
            curry --;
            pnot = getParaMeter(currx, curry, pnot);
        }
    }
    glEnd();
}


void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3ub (255, 0, 0);

    drawCircle(centerx, centery, radius);

    glFlush ();
}
void init (void) {
    /* select clearing (background) color */
    glClearColor (1, 1, 1, 1);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    gluOrtho2D(-500, 500, -500, 500);
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

    // pnot = 1 - radius;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (720, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0; /* ISO C requires main to return int. */
}

