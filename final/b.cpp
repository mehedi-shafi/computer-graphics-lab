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
    
    // circular borders of glass.
    glColor3ub(0, 0, 0);
    drawCircle(400, 400, 105);
    drawCircle(635, 400, 105);

    // left handle

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(300, 400);
    glVertex2d(200, 600);
    glVertex2d(200, 610);
    glVertex2d(300, 410);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(200, 600);
    glVertex2d(180, 550);
    glVertex2d(175, 550);
    glVertex2d(200, 610);
    glEnd();

    // left glass
    glColor3ub (158, 234, 239);
    drawCircle(400, 400, 100);

    // right handle
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(735, 400);
    glVertex2d(735, 410);
    glVertex2d(635, 610);
    glVertex2d(635, 600);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(635, 600);
    glVertex2d(615, 550);
    glVertex2d(610, 550);
    glVertex2d(635, 610);
    glEnd();

    //right glass
    glColor3ub (158, 234, 239);
    drawCircle(635, 400, 100);

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(500, 400);
    glVertex2d(500, 410);
    glVertex2d(535, 410);
    glVertex2d(535, 400);
    glEnd();    

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