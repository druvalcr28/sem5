#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

int sx,sy,ex,ey;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void bresenhamAlgo()
{
    int dx=ex-sx,dy=ey-sy;
    plot(sx,sy);
    plot(ex,ey);
    int p = (2*dy)-dx;
    int xk=sx,yk=sy;
    while(xk < ex){
        if(p>=0){
            plot(xk+1,yk+1);
            p = p + 2*dy - 2*dx;
            yk++; 
        }
        else{
            plot(xk+1,yk);
            p = p + 2*dy;
        }
        xk++;
    }
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	bresenhamAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);

	glutInit(&argc, argv);                          //initialize the GLUT library
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);                  
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Bresenham Algo");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 0;
}