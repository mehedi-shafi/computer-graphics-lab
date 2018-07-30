#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

int getParaMeter(int currx, int curry, int pnot)
{
    if (pnot < 0){
        return pnot + (2*currx) + 1;
    }
    else{
        return pnot + (2*currx) + 1 - (2*curry);
    }
}

void drawCircle(int centerx, int centery, int rad){
    int pnot = 1 - rad;

    glBegin(GL_POLYGON);

    int currx = 0, curry = rad;
    while (curry > currx){

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
    glColor3ub (119, 61, 19);

    // tyres
    drawCircle(300, 300, 100);
    drawCircle(600, 300, 100);
    
    // tyres centers 
    glColor3ub(51, 49, 47);
    drawCircle(300, 300, 20);
    drawCircle(600, 300, 20);
    //

    glFlush ();
}
void init (void) {
    glClearColor (1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
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
    return 0; 
}