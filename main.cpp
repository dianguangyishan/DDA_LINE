//#include <iostream>
#include <windows.h>
#include <GL/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<time.h>
//#define random(x) (rand()%x)
using namespace std;
#define SIZE 500.0
void DDA_line()
{

    int p[6][2] =
    {
        {210, 150},
        {120, 100},
        {155, 180},
        {190, 100},
        {100, 150},
        {210, 150}
    };
    glClear (GL_COLOR_BUFFER_BIT);
    //srand((int)time(0));
    for (int i=0; i <5; i++)
    {
        double x,y,dx,dy,L,x1=p[i][0],x2=p[i+1][0],y1=p[i][1],y2=p[i+1][1];
        if(abs(x2-x1)>=abs(y2-y1))
            L=abs(x2-x1);
        else
            L=abs(y2-y1);
        dx=(x2-x1)/(L);
        dy=(y2-y1)/(L);
        x=x1,y=y1;
        for (int k=0; k < L ; k++)
        {

            glBegin(GL_POINTS);
            //glColor3f(random(11)/10+0.5,random(11)/10+0.5,random(11)/10+0.5 );
            glVertex2f(x, y);
            glEnd();
            glFlush();
            x=x+dx;
            y=y+dy;
            Sleep(10);
        }
    }
}
void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, SIZE, 0.0, SIZE);
}

//void display()
//{
//    glClear (GL_COLOR_BUFFER_BIT);
//    DDA_line();
//}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SIZE, SIZE);
    glutCreateWindow("DDA_line");
    init();
    glutDisplayFunc(DDA_line);
    glutMainLoop();
    return 0;
}

