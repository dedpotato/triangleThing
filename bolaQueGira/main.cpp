#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <math.h>

void
dibujaCirculo(float r, int num_segments){
glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x, y);//output vertex

    }
    glEnd();}

void
dibujar(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0f,0.5f,0.0f);
    dibujaCirculo(0.05f,16);

    glPopMatrix();

    glutSwapBuffers();
}

void
gatillo(){
    glClearColor(0.5,0.5,0.5,1);

    glOrtho(800,0,600,0,-1,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int aro=0, iter=5;
float radio=0;
void
actualizacion(){
    /*float theta = 2.0f * 3.1415926f * float(aro) / float(iter);//get the current angle

        float x = radio * cosf(theta);//calculate the x component
        float y = radio * sinf(theta);//calculate the y component

        //glTranslatef(x, y,0.0f);
        //glTranslatef(0,0,0);

    aro=(aro+1)%iter;*/
    glutPostRedisplay();
}

int
main(int argc, char * args[]){

    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(600,600);
    glutCreateWindow("potto");
    glutDisplayFunc(dibujar);
    gatillo();
    glutIdleFunc(actualizacion);
    glutMainLoop();


    return 0;
}
