#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

double xx1, yy1, xx2, yy2, dx, dy, m, step, x, y;

void display(void) {
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */
    glColor3ub (255, 0, 0);
    glBegin(GL_POINTS);

    x = xx1, y =yy1;

    glVertex2d((int) x, (int) y);
    int i = 0;
    for (i = 0; i < step; i++){
        x += dx;
        y += dy;
        glVertex2d((int)x,(int)y);
        printf("x = %lf y = %lf\n", x, y);
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
    gluOrtho2D(0, 300, 0, 300);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv) {

    scanf("%lf %lf %lf %lf", &xx1, &yy1, &xx2, &yy2);

    if (xx1 > xx2){double temp = xx1; xx1 = xx2; xx2 = temp; temp = yy1; yy1 = yy2; yy2 = temp;}


    dy = yy2 - yy1;
    dx = xx2 - xx1;

    printf("dx = %lf dy = %lf\n", dx, dy);

    if (dx >= dy){
        step = dx;
    }
    else{
        step = dy;
    }

    printf("step = %lf\n",step);

    dx /= step;
    dy /= step;

    printf("dx = %lf dy = %lf\n", dx, dy);


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

