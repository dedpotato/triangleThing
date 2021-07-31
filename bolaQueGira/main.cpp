#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <math.h>

//codigo para crear circulo
void
crearCirculo(float lista[][2], float r, int num_segments){
    for(int ii = 0; ii < num_segments; ii++){
            float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

            lista[ii][0] = r * cosf(theta);//calculate the x component
            lista[ii][1] = r * sinf(theta);//calculate the y component
        }
}

void
dibujar(){
    int segmentos = 16;

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0f,0.5f,0.0f);

    //segmentos x e y del circulo y el radio
    float circuloA[segmentos][2];
    float radio = 0.05;

    //crea una circulo basado en varias proporciones
    crearCirculo(circuloA,radio,segmentos);
    //glTranslatef(0,0,0);

    glBegin(GL_POLYGON);
    for(int i = 0;i <=segmentos;i++){
        glVertex2f(circuloA[i][0], circuloA[i][1]);
    }
    glEnd();

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
    glutInitWindowSize(600,600);
    glutCreateWindow("potto");
    glutDisplayFunc(dibujar);
    gatillo();
    glutIdleFunc(actualizacion);
    glutMainLoop();

    return 0;
}
