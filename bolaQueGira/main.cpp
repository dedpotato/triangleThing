#include <GL/glut.h>
#include <windows.h>
#include <iostream>

void
dibujar(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    //glTranslatef(-0.1,0,0);



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


void
actualizacion(){

    glutPostRedisplay();
}

int
main(int argc, char * args[]){

    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("potto");
    glutDisplayFunc(dibujar);
    gatillo();
    glutIdleFunc(actualizacion);
    glutMainLoop();


    return 0;
}
