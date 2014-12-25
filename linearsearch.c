#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include <time.h>
#include<string.h>
#define MAX_H 400
#define MAX_V 400
char** names;
int n = 5, *values,key,pos=0,end=0;

void textWrite(char * s)
{
    int j,len = (int) strlen(s);
    for (j = 0; j < len; j++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[j]);
    }
}
void keyPress()
{
    char *s;
    glClear(GL_COLOR_BUFFER_BIT);
    display();
    if(values[pos]==key)
        glColor3f(0.2,1,0.2);
    else
        glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(280+pos*100,376);
    glVertex2f(380+pos*100,376);
    glVertex2f(380+pos*100,476);
    glVertex2f(280+pos*100,476);
    glEnd();
    glFlush();

    glRasterPos2f(10,100);

    if(values[pos]==key)
        textWrite("Found!!");

    else if(pos==5)
    {
        textWrite("Not found!");
    }
    else
    {
        textWrite("Unequal!");
        pos++;
    }
    glFlush();
}
void display()
{
    int i=0,j,off_x=20,off_y=0,gap;
    char s[30];
    glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(0,0,1);
   	 glRasterPos2f(300,600);
     textWrite("Linear search simulation");

     glRasterPos2f(300,100);
     sprintf(s,"Key = %d",key);
   	 textWrite(s);

    for(i = 0; i<n;i++)
    {
   	 glRasterPos2f(300+100*i,400);
     textWrite(names[i]);
    }
    glFlush();


}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1024.0,0.0,768.0);
}

void main(int argc,char **argv)
{
    int i;
    /*
    printf("Enter the number of values\n");
    scanf("%d",&n);
    */
    printf("Enter %d numbers:\t",n);
    values = (int *) calloc(n,sizeof(int));
    names = (char **) calloc(n,sizeof(char *));

    for(i = 0;i<n;i++)
    {
         scanf("%d",&values[i]);
         names[i] = (char*)malloc(5*sizeof(char));
         sprintf(names[i],"%d",values[i]);
    }
    printf("Enter key");
    scanf("%d",&key);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,200);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Linear search - Assignment");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPress);
    myinit();
    glutMainLoop();
}


