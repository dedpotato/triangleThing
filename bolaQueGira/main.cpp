#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <math.h>

const int segmentos = 16;
const float radio = 0.05;
//segmentos x e y del circulo y el radio
float circuloA[segmentos][2];


//recibe una matriz, radio, y segmentos, y regresa las corrdenadas del los segmentos de un  circulo
//[0]=x [1]=y
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
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0f,0.5f,0.0f);

    //glTranslatef(0,0,0);

    //dibuja el circulo
    glBegin(GL_POLYGON);
    for(int i = 0;i <=segmentos;i++){
        glVertex2f(circuloA[i][0], circuloA[i][1]);
    }glEnd();

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

    //crea una circulo basado en varias proporciones
    crearCirculo(circuloA,radio,segmentos);

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
