//#include <windows.h>
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include "glut.h"   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
//Gutiérrez Gutiérrez Mario Alberto

#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Blanco de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
		
	//glPointSize(10.0);
	glLineWidth(1.0);
	//glBegin(GL_POINTS);
	//glBegin(GL_LINE_STRIP);

	//brazo izquierdo
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
		glVertex3f(-4.0,-10.0,-0.2);
		glVertex3f(-3.8,-9.5,-0.2);
		glVertex3f(-3.0,-10.0,-0.2);
		
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-4.0,-10.0,-0.2);
		glVertex3f(-3.8,-9.5,-0.2);
		glVertex3f(-3.0,-10.0,-0.2);
	glEnd();


		//Manga izquierda
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
		glVertex3f(-3.9,-9.4,-2.0);
		glVertex3f(-4.1,-9.0,-2.0);
		glVertex3f(-3.5,-8.0,-2.0);
		glVertex3f(-3.0,-7.5,-2.0);
		glVertex3f(-2.5,-7.0,-2.0);
		glVertex3f(-1.9,-6.8,-2.0);
		glVertex3f(-2.0,-7.0,-2.0);
		glVertex3f(-2.1,-7.5,-2.0);
		glVertex3f(-2.2,-8.0,-2.0);
		glVertex3f(-2.3,-8.5,-2.0);
		glVertex3f(-2.3,-9.0,-2.0);
		glVertex3f(-2.5,-9.5,-2.0);
		glVertex3f(-2.8,-9.7,-2.0);
		glVertex3f(-3.0,-10.0,-2.0);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-3.9,-9.4,-2.0);
		glVertex3f(-4.1,-9.0,-2.0);
		glVertex3f(-3.5,-8.0,-2.0);
		glVertex3f(-3.0,-7.5,-2.0);
		glVertex3f(-2.5,-7.0,-2.0);
		glVertex3f(-1.9,-6.8,-2.0);
		glVertex3f(-2.0,-7.0,-2.0);
		glVertex3f(-2.1,-7.5,-2.0);
		glVertex3f(-2.2,-8.0,-2.0);
		glVertex3f(-2.3,-8.5,-2.0);
		glVertex3f(-2.3,-9.0,-2.0);
		glVertex3f(-2.5,-9.5,-2.0);
		glVertex3f(-2.8,-9.7,-2.0);
		glVertex3f(-3.0,-10.0,-2.0);
	glEnd();


//Manga derecha
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
		glVertex3f(4.0,-10.0,-2.0);
		glVertex3f(3.5,-9.9,-2.0);
		glVertex3f(3.0,-9.7,-2.0);
		glVertex3f(2.7,-9.5,-2.0);
		glVertex3f(2.8,-9.0,-2.0);
		glVertex3f(3.0,-8.2,-2.0);
		glVertex3f(3.5,-7.4,-2.0);
		glVertex3f(4.0,-7.1,-2.0);
		glVertex3f(4.1,-7.0,-2.0);
		glVertex3f(4.5,-6.9,-2.0);
		glVertex3f(5.0,-7.0,-2.0);
		glVertex3f(5.8,-7.3,-2.0);
		glVertex3f(6.2,-8.0,-2.0);
		glVertex3f(6.5,-9.0,-2.0);
		glVertex3f(6.5,-9.3,-2.0);
		glVertex3f(6.0,-9.8,-2.0);
		glVertex3f(5.5,-10.0,-2.0);
		
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(4.0,-10.0,-2.0);
		glVertex3f(3.5,-9.9,-2.0);
		glVertex3f(3.0,-9.7,-2.0);
		glVertex3f(2.7,-9.5,-2.0);
		glVertex3f(2.8,-9.0,-2.0);
		glVertex3f(3.0,-8.2,-2.0);
		glVertex3f(3.5,-7.4,-2.0);
		glVertex3f(4.0,-7.1,-2.0);
		glVertex3f(4.1,-7.0,-2.0);
		glVertex3f(4.5,-6.9,-2.0);
		glVertex3f(5.0,-7.0,-2.0);
		glVertex3f(5.8,-7.3,-2.0);
		glVertex3f(6.2,-8.0,-2.0);
		glVertex3f(6.5,-9.0,-2.0);
		glVertex3f(6.5,-9.3,-2.0);
		glVertex3f(6.0,-9.8,-2.0);
		glVertex3f(5.5,-10.0,-2.0);
	glEnd();


	//Cuerpo
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
		glVertex3f(-3.0,-10.0,-2.0);
		glVertex3f(-2.8,-9.7,-2.0);
		glVertex3f(-2.5,-9.5,-2.0);
		glVertex3f(-2.3,-9.0,-2.0);
		glVertex3f(-2.3,-8.5,-2.0);
		glVertex3f(-2.2,-8.0,-2.0);
		glVertex3f(-2.1,-7.5,-2.0);
		glVertex3f(-2.0,-7.0,-2.0);
		glVertex3f(-1.9,-6.8,-2.0);
		glVertex3f(-1.8,-6.3,-2.0);
		glVertex3f(-1.6,-6.0,-2.0);
		glVertex3f(-1.4,-5.6,-2.0);
		glVertex3f(-1.3,-5.4,-2.0);
		glVertex3f(-1.0,-5.6,-2.0);
		glVertex3f(-0.8,-5.8,-2.0);
		glVertex3f(-0.2,-6.0,-2.0);
		glVertex3f(1.0,-6.0,-2.0);
		glVertex3f(1.6,-5.9,-2.0);
		glVertex3f(2.0,-5.7,-2.0);
		glVertex3f(2.5,-5.5,-2.0);
		glVertex3f(2.7,-5.2,-2.0);
		glVertex3f(2.7,-5.0,-2.0);
		glVertex3f(3.2,-5.2,-2.0);
		glVertex3f(3.6,-5.6,-2.0);
		glVertex3f(3.8,-6.0,-2.0);
		glVertex3f(4.1,-7.0,-2.0);
		glVertex3f(4.0,-7.1,-2.0);
		glVertex3f(3.5,-7.4,-2.0);
		glVertex3f(3.0,-8.2,-2.0);
		glVertex3f(2.8,-9.0,-2.0);
		glVertex3f(2.7,-9.5,-2.0);
		glVertex3f(3.0,-9.7,-2.0);
		glVertex3f(3.5,-9.9,-2.0);
		glVertex3f(4.0,-10.0,-2.0);
		
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-3.0,-10.0,-2.0);
		glVertex3f(-2.8,-9.7,-2.0);
		glVertex3f(-2.5,-9.5,-2.0);
		glVertex3f(-2.3,-9.0,-2.0);
		glVertex3f(-2.3,-8.5,-2.0);
		glVertex3f(-2.2,-8.0,-2.0);
		glVertex3f(-2.1,-7.5,-2.0);
		glVertex3f(-2.0,-7.0,-2.0);
		glVertex3f(-1.9,-6.8,-2.0);
		glVertex3f(-1.8,-6.3,-2.0);
		glVertex3f(-1.6,-6.0,-2.0);
		glVertex3f(-1.4,-5.6,-2.0);
		glVertex3f(-1.3,-5.4,-2.0);
		glVertex3f(-1.0,-5.6,-2.0);
		glVertex3f(-0.8,-5.8,-2.0);
		glVertex3f(-0.2,-6.0,-2.0);
		glVertex3f(1.0,-6.0,-2.0);
		glVertex3f(1.6,-5.9,-2.0);
		glVertex3f(2.0,-5.7,-2.0);
		glVertex3f(2.5,-5.5,-2.0);
		glVertex3f(2.7,-5.2,-2.0);
		glVertex3f(2.7,-5.0,-2.0);
		glVertex3f(3.2,-5.2,-2.0);
		glVertex3f(3.6,-5.6,-2.0);
		glVertex3f(3.8,-6.0,-2.0);
		glVertex3f(4.1,-7.0,-2.0);
		glVertex3f(4.0,-7.1,-2.0);
		glVertex3f(3.5,-7.4,-2.0);
		glVertex3f(3.0,-8.2,-2.0);
		glVertex3f(2.8,-9.0,-2.0);
		glVertex3f(2.7,-9.5,-2.0);
		glVertex3f(3.0,-9.7,-2.0);
		glVertex3f(3.5,-9.9,-2.0);
		glVertex3f(4.0,-10.0,-2.0);
	glEnd();

	//Cabeza
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	   glVertex3f(2.7,-5.0,-2.0);
	   glVertex3f(2.5,-3.0,-2.0);
	   glVertex3f(2.5,-2.4,-2.0);
	   glVertex3f(2.7,-2.4,-2.0);
	   glVertex3f(3.0,-2.3,-2.0);
	   glVertex3f(3.2,-2.0,-2.0);
	   glVertex3f(3.2,-1.7,-2.0);
	   glVertex3f(3.1,-1.4,-2.0);
	   glVertex3f(3.0,-1.0,-2.0);
	   glVertex3f(2.8,-0.9,-2.0);
	   glVertex3f(2.6,-0.8,-2.0);
	   glVertex3f(3.0,1.0,-2.0);
	   glVertex3f(3.4,3.0,-2.0);
	   glVertex3f(4.0,5.0,-2.0);
	   glVertex3f(4.5,7.0,-2.0);
	   glVertex3f(4.9,8.0,-2.0);
	   glVertex3f(5.2,8.5,-2.0);
	   glVertex3f(5.5,9.0,-2.0);
	   glVertex3f(5.0,9.0,-2.0);
	   glVertex3f(4.5,8.8,-2.0);
	   glVertex3f(4.1,8.5,-2.0);
	   glVertex3f(4.1,9.0,-2.0);
	   glVertex3f(4.0,9.6,-2.0);
	   glVertex3f(3.5,9.5,-2.0);
	   glVertex3f(2.9,9.0,-2.0);
	   glVertex3f(2.7,9.6,-2.0);
	   glVertex3f(2.5,10.0,-2.0);
	   glVertex3f(2.0,9.8,-2.0);
	   glVertex3f(1.5,9.5,-2.0);
	   glVertex3f(1.1,10.0,-2.0);
	   glVertex3f(0.7,10.5,-2.0);
	   glVertex3f(0.0,10.2,-2.0);
	   glVertex3f(-0.2,10.0,-2.0);
	   glVertex3f(-0.6,9.7,-2.0);
	   glVertex3f(-0.9,10.4,-2.0);
	   glVertex3f(-1.2,10.8,-2.0);
	   glVertex3f(-1.8,10.5,-2.0);
	   glVertex3f(-2.4,9.9,-2.0);
	   glVertex3f(-2.7,10.4,-2.0);
	   glVertex3f(-3.0,10.6,-2.0);
	   glVertex3f(-3.4,10.8,-2.0);
	   glVertex3f(-3.9,11.0,-2.0);
	   glVertex3f(-3.8,10.6,-2.0);
	   glVertex3f(-3.8,10.0,-2.0);
	   glVertex3f(-3.8,9.5,-2.0);
	   glVertex3f(-3.9,9.0,-2.0);
	   glVertex3f(-4.4,6.5,-2.0);
	   glVertex3f(-4.6,6.3,-2.0);
	   glVertex3f(-4.9,6.2,-2.0);
	   glVertex3f(-5.1,6.0,-2.0);
	   glVertex3f(-5.3,5.7,-2.0);
	   glVertex3f(-5.2,5.3,-2.0);
	   glVertex3f(-5.0,5.0,-2.0);
	   glVertex3f(-5.4,4.7,-2.0);
	   glVertex3f(-5.7,4.4,-2.0);
	   glVertex3f(-5.9,4.0,-2.0);
	   glVertex3f(-6.0,3.5,-2.0);
	   glVertex3f(-6.0,3.0,-2.0);
	   glVertex3f(-5.9,2.5,-2.0);
	   glVertex3f(-5.6,2.0,-2.0);
	   glVertex3f(-6.2,0.0,-2.0);
	   glVertex3f(-6.8,-2.0,-2.0);
	   glVertex3f(-6.7,-2.2,-2.0);
	   glVertex3f(-6.5,-2.5,-2.0);
	   glVertex3f(-6.0,-2.8,-2.0);
	   glVertex3f(-5.0,-3.3,-2.0);
	   glVertex3f(-4.0,-3.6,-2.0);
	   glVertex3f(-3.0,-3.8,-2.0);
	   glVertex3f(-2.4,-3.9,-2.0);
	   glVertex3f(-2.1,-4.0,-2.0);
	   glVertex3f(-2.3,-4.2,-2.0);
	   glVertex3f(-2.3,-4.6,-2.0);
	   glVertex3f(-1.6,-5.0,-2.0);
	   glVertex3f(-1.2,-5.3,-2.0);
	   glVertex3f(-1.3,-5.4,-2.0);
	   glVertex3f(-1.0,-5.6,-2.0);
   	   glVertex3f(-0.8,-5.8,-2.0);
	   glVertex3f(-0.2,-6.0,-2.0);
	   glVertex3f(1.0,-6.0,-2.0);
	   glVertex3f(1.6,-5.9,-2.0);
	   glVertex3f(2.0,-5.7,-2.0);
	   glVertex3f(2.5,-5.5,-2.0);
	   glVertex3f(2.7,-5.2,-2.0);

	glEnd();
       
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	   glVertex3f(2.7,-5.0,-2.0);
	   glVertex3f(2.5,-3.0,-2.0);
	   glVertex3f(2.5,-2.4,-2.0);
	   glVertex3f(2.7,-2.4,-2.0);
	   glVertex3f(3.0,-2.3,-2.0);
	   glVertex3f(3.2,-2.0,-2.0);
	   glVertex3f(3.2,-1.7,-2.0);
	   glVertex3f(3.1,-1.4,-2.0);
	   glVertex3f(3.0,-1.0,-2.0);
	   glVertex3f(2.8,-0.9,-2.0);
	   glVertex3f(2.6,-0.8,-2.0);
	   glVertex3f(3.0,1.0,-2.0);
	   glVertex3f(3.4,3.0,-2.0);
	   glVertex3f(4.0,5.0,-2.0);
	   glVertex3f(4.5,7.0,-2.0);
	   glVertex3f(4.9,8.0,-2.0);
	   glVertex3f(5.2,8.5,-2.0);
	   glVertex3f(5.5,9.0,-2.0);
	   glVertex3f(5.0,9.0,-2.0);
	   glVertex3f(4.5,8.8,-2.0);
	   glVertex3f(4.1,8.5,-2.0);
	   glVertex3f(4.1,9.0,-2.0);
	   glVertex3f(4.0,9.6,-2.0);
	   glVertex3f(3.5,9.5,-2.0);
	   glVertex3f(2.9,9.0,-2.0);
	   glVertex3f(2.7,9.6,-2.0);
	   glVertex3f(2.5,10.0,-2.0);
	   glVertex3f(2.0,9.8,-2.0);
	   glVertex3f(1.5,9.5,-2.0);
	   glVertex3f(1.1,10.0,-2.0);
	   glVertex3f(0.7,10.5,-2.0);
	   glVertex3f(0.0,10.2,-2.0);
	   glVertex3f(-0.2,10.0,-2.0);
	   glVertex3f(-0.6,9.7,-2.0);
	   glVertex3f(-0.9,10.4,-2.0);
	   glVertex3f(-1.2,10.8,-2.0);
	   glVertex3f(-1.8,10.5,-2.0);
	   glVertex3f(-2.4,9.9,-2.0);
	   glVertex3f(-2.7,10.4,-2.0);
	   glVertex3f(-3.0,10.6,-2.0);
	   glVertex3f(-3.4,10.8,-2.0);
	   glVertex3f(-3.9,11.0,-2.0);
	   glVertex3f(-3.8,10.6,-2.0);
	   glVertex3f(-3.8,10.0,-2.0);
	   glVertex3f(-3.8,9.5,-2.0);
	   glVertex3f(-3.9,9.0,-2.0);
	   glVertex3f(-4.4,6.5,-2.0);
	   glVertex3f(-4.6,6.3,-2.0);
	   glVertex3f(-4.9,6.2,-2.0);
	   glVertex3f(-5.1,6.0,-2.0);
	   glVertex3f(-5.3,5.7,-2.0);
	   glVertex3f(-5.2,5.3,-2.0);
	   glVertex3f(-5.0,5.0,-2.0);
	   glVertex3f(-5.4,4.7,-2.0);
	   glVertex3f(-5.7,4.4,-2.0);
	   glVertex3f(-5.9,4.0,-2.0);
	   glVertex3f(-6.0,3.5,-2.0);
	   glVertex3f(-6.0,3.0,-2.0);
	   glVertex3f(-5.9,2.5,-2.0);
	   glVertex3f(-5.6,2.0,-2.0);
	   glVertex3f(-6.2,0.0,-2.0);
	   glVertex3f(-6.8,-2.0,-2.0);
	   glVertex3f(-6.7,-2.2,-2.0);
	   glVertex3f(-6.5,-2.5,-2.0);
	   glVertex3f(-6.0,-2.8,-2.0);
	   glVertex3f(-5.0,-3.3,-2.0);
	   glVertex3f(-4.0,-3.6,-2.0);
	   glVertex3f(-3.0,-3.8,-2.0);
	   glVertex3f(-2.4,-3.9,-2.0);
	   glVertex3f(-2.1,-4.0,-2.0);
	   glVertex3f(-2.3,-4.2,-2.0);
	   glVertex3f(-2.3,-4.6,-2.0);
	   glVertex3f(-1.6,-5.0,-2.0);
	   glVertex3f(-1.2,-5.3,-2.0);
	   glVertex3f(-1.3,-5.4,-2.0);
	   glVertex3f(-1.0,-5.6,-2.0);
   	   glVertex3f(-0.8,-5.8,-2.0);
	   glVertex3f(-0.2,-6.0,-2.0);
	   glVertex3f(1.0,-6.0,-2.0);
	   glVertex3f(1.6,-5.9,-2.0);
	   glVertex3f(2.0,-5.7,-2.0);
	   glVertex3f(2.5,-5.5,-2.0);
	   glVertex3f(2.7,-5.2,-2.0);

	glEnd();

	//Ojo izquierdo
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	   glVertex3f(-5.0,5.0,-2.0);
	   glVertex3f(-5.4,4.7,-2.0);
	   glVertex3f(-5.7,4.4,-2.0);
	   glVertex3f(-5.9,4.0,-2.0);
	   glVertex3f(-6.0,3.5,-2.0);
	   glVertex3f(-6.0,3.0,-2.0);
	   glVertex3f(-5.9,2.5,-2.0);
	   glVertex3f(-5.6,2.0,-2.0);
	   glVertex3f(-5.2,1.7,-2.0);
	   glVertex3f(-4.7,1.7,-2.0);
	   glVertex3f(-4.5,2.0,-2.0);
	   glVertex3f(-4.0,2.0,-2.0);
	   glVertex3f(-3.5,2.1,-2.0);
	   glVertex3f(-3.0,2.2,-2.0);
	   glVertex3f(-3.1,2.6,-2.0);
	   glVertex3f(-3.0,3.2,-2.0);
	   glVertex3f(-2.8,3.7,-2.0);
	   glVertex3f(-2.6,4.0,-2.0);
	   glVertex3f(-2.4,4.4,-2.0);
	   glVertex3f(-2.7,4.8,-2.0);
	   glVertex3f(-3.0,5.1,-2.0);
	   glVertex3f(-3.5,5.2,-2.0);
	   glVertex3f(-4.0,5.3,-2.0);
	   glVertex3f(-4.5,5.2,-2.0);
		
	glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-5.0,5.0,-2.0);
	   glVertex3f(-5.4,4.7,-2.0);
	   glVertex3f(-5.7,4.4,-2.0);
	   glVertex3f(-5.9,4.0,-2.0);
	   glVertex3f(-6.0,3.5,-2.0);
	   glVertex3f(-6.0,3.0,-2.0);
	   glVertex3f(-5.9,2.5,-2.0);
	   glVertex3f(-5.6,2.0,-2.0);
	   glVertex3f(-5.2,1.7,-2.0);
	   glVertex3f(-4.7,1.7,-2.0);
	   glVertex3f(-4.5,2.0,-2.0);
	   glVertex3f(-4.0,2.0,-2.0);
	   glVertex3f(-3.5,2.1,-2.0);
	   glVertex3f(-3.0,2.2,-2.0);
	   glVertex3f(-3.1,2.6,-2.0);
	   glVertex3f(-3.0,3.2,-2.0);
	   glVertex3f(-2.8,3.7,-2.0);
	   glVertex3f(-2.6,4.0,-2.0);
	   glVertex3f(-2.4,4.4,-2.0);
	   glVertex3f(-2.7,4.8,-2.0);
	   glVertex3f(-3.0,5.1,-2.0);
	   glVertex3f(-3.5,5.2,-2.0);
	   glVertex3f(-4.0,5.3,-2.0);
	   glVertex3f(-4.5,5.2,-2.0);

    glEnd();

	//Ojo derecho
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-2.0,4.5,-2.0);
		glVertex3f(-1.5,4.7,-2.0);
		glVertex3f(-1.0,4.8,-2.0);
		glVertex3f(-0.4,4.6,-2.0);
		glVertex3f(0.0,4.3,-2.0);
		glVertex3f(0.3,4.0,-2.0);
		glVertex3f(0.5,3.5,-2.0);
		glVertex3f(0.6,3.0,-2.0);
		glVertex3f(0.6,2.5,-2.0);
		glVertex3f(0.5,2.0,-2.0);
		glVertex3f(0.3,1.6,-2.0);
		glVertex3f(-0.2,1.3,-2.0);
		glVertex3f(-0.7,1.1,-2.0);
		glVertex3f(-1.2,1.0,-2.0);
		glVertex3f(-2.0,1.2,-2.0);
		glVertex3f(-2.5,1.5,-2.0);
		glVertex3f(-2.8,1.8,-2.0);
		glVertex3f(-3.0,2.2,-2.0);
	    glVertex3f(-3.1,2.6,-2.0);
	    glVertex3f(-3.0,3.2,-2.0);
	    glVertex3f(-2.8,3.7,-2.0);
	    glVertex3f(-2.6,4.0,-2.0);
	    glVertex3f(-2.4,4.4,-2.0);
		
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-2.0,4.5,-2.0);
		glVertex3f(-1.5,4.7,-2.0);
		glVertex3f(-1.0,4.8,-2.0);
		glVertex3f(-0.4,4.6,-2.0);
		glVertex3f(0.0,4.3,-2.0);
		glVertex3f(0.3,4.0,-2.0);
		glVertex3f(0.5,3.5,-2.0);
		glVertex3f(0.6,3.0,-2.0);
		glVertex3f(0.6,2.5,-2.0);
		glVertex3f(0.5,2.0,-2.0);
		glVertex3f(0.3,1.6,-2.0);
		glVertex3f(-0.2,1.3,-2.0);
		glVertex3f(-0.7,1.1,-2.0);
		glVertex3f(-1.2,1.0,-2.0);
		glVertex3f(-2.0,1.2,-2.0);
		glVertex3f(-2.5,1.5,-2.0);
		glVertex3f(-2.8,1.8,-2.0);
		glVertex3f(-3.0,2.2,-2.0);
	    glVertex3f(-3.1,2.6,-2.0);
	    glVertex3f(-3.0,3.2,-2.0);
	    glVertex3f(-2.8,3.7,-2.0);
	    glVertex3f(-2.6,4.0,-2.0);
	    glVertex3f(-2.4,4.4,-2.0);
	glEnd();

    //Nariz
	glLineWidth(1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	   glVertex3f(-3.0,2.2,-2.0);
       glVertex3f(-3.5,2.1,-2.0);
       glVertex3f(-4.0,2.0,-2.0);
	   glVertex3f(-4.5,2.0,-2.0);
       glVertex3f(-4.7,1.7,-2.0);
	   glVertex3f(-4.7,1.0,-2.0);
	   glVertex3f(-4.5,0.7,-2.0);
	   glVertex3f(-4.0,0.5,-2.0);
	   glVertex3f(-3.0,0.5,-2.0);
	glEnd();

    //Pupila izquierda
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-4.8,4.5,-2.0);
	   glVertex3f(-4.7,4.7,-2.0);
       glVertex3f(-4.5,4.8,-2.0);
	   glVertex3f(-4.3,4.7,-2.0);
       glVertex3f(-4.2,4.5,-2.0);
	   glVertex3f(-4.3,4.3,-2.0);
	   glVertex3f(-4.5,4.2,-2.0);
	   
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-4.8,4.5,-2.0);
       glVertex3f(-4.5,4.8,-2.0);
       glVertex3f(-4.2,4.5,-2.0);
	   glVertex3f(-4.5,4.2,-2.0);

    glEnd();

    //Pupila derecha
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-1.8,4.0,-2.0);
	   glVertex3f(-1.7,4.1,-2.0);
       glVertex3f(-1.5,4.2,-2.0);
	   glVertex3f(-1.4,4.3,-2.0);
       glVertex3f(-1.2,4.0,-2.0);
	   glVertex3f(-1.5,3.6,-2.0);
	   
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-1.8,4.0,-2.0);
       glVertex3f(-1.5,4.2,-2.0);
       glVertex3f(-1.2,4.0,-2.0);
	   glVertex3f(-1.5,3.8,-2.0);

    glEnd();

	//linea boca
    glLineWidth(1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	   glVertex3f(2.7,-0.8,-2.0);
	   glVertex3f(2.0,-1.0,-2.0);
	glEnd();

    //linea oreja
    glLineWidth(1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	   glVertex3f(-2.1,-4.0,-2.0);
	   glVertex3f(-0.8,-4.5,-2.0);
	glEnd();

	glPopMatrix();
	glutSwapBuffers ( );
  //glFlush();
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glOrtho(-11,11,-11,14,0.1,2.5);
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (400, 400);	// Tamaño de la Ventana
  glutInitWindowPosition (500, 130);	//Posicion de la Ventana
  glutCreateWindow    ("Dibujo: Patricio"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  //glutSpecialFunc     ( arrow_keys );	//Otras
  //glutIdleFunc		  ( display );	//Hace animacíon
  glutMainLoop        ( );          // 

  return 0;
}