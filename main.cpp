/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%     Computer Graphics                       %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Both irrKlang and math headers are required to run the code, and the other   %
%% Setups made during Computer Graphics Laboratory Course						%
%% Written and mantained by Carlos 					                            %
%% 2023-1 Extraordinario Computacion Grafica                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include "irrKlang.h"
/*
#include "SFML/include/SFML/Audio.hpp"


// Cargar el archivo de sonido
sf :: SoundBuffer buffer;
if (!buffer.loadFromFile("cannonshot.mp3"))
{
	// Manejo de error si no se puede cargar el archivo de sonido
	return EXIT_FAILURE;

}

// Crear el objeto Sound y asignarle el buffer de sonido cargado
sf::Sound sound(buffer);

// Reproducir el sonido
sound.play();

// Declarar el objeto de la clase ISoundEngine
//irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
*/
static GLuint ciudad_display_list;
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float giroBrazo = 0;
#define MAX_FRAMES 200
int maxsteps = 90;
int currentsteps = 0;

typedef struct _frame {
	float posX;
	float posY;
	float posZ;
	float incX;
	float incY;
	float incZ;
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float giroBrazo;
	float giroBrazoInc;
	float rotate_ballX;
	float rotate_ballY;
	float rotate_ballZ;
	float movement_ballX;
	float movement_ballY;
	float movement_ballZ;
} FRAME;

FRAME KeyFrame[MAX_FRAMES]; 
int FrameIndex=0;			//Introducir datos 
bool play=false;
int playIndex=0;


//	Nuevo

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];


float x = 0.0f;          // Posición x del cilindro
float y = 0.0f;          // Posición y del cilindro
float z = 0.0f;          // Posición z del cilindro
float angle = 0.0f;      // Ángulo de rotación del cilindro
float r = 1.0f;          // Componente rojo del color del cilindro
float g = 1.0f;          // Componente verde del color del cilindro
float b = 1.0f;          // Componente azul del color del cilindro
const float PI = 3.14159265f;  // Valor de PI
float angleStep = PI / 18.0f;  // Paso angular para la construcción del cilindro
float radius = 5.0f;     // Radio del cilindro (mayor valor)
float height = 30.0f;    // Altura del cilindro (mayor valor)
float sphereRadius = 5.0f;

//Variables de la esfera (bala)

float spherePosX = x;  // Posición inicial de la esfera en el eje X
float spherePosY = y;  // Posición inicial de la esfera en el eje y
float spherePosZ = z;  // Posición inicial de la esfera en el eje Z
float initialPosX = 0.0f;   // Posición inicial de la esfera en el eje X
float initialPosY = 0.0f;   // Posición inicial de la esfera en el eje y
float initialPosZ = 0.0f;   // Posición inicial de la esfera en el eje Z
float initialVelocityX = 1.0f;  // Velocidad inicial de la esfera en el eje X
float initialVelocityY = 5.0f;  // Velocidad inicial de la esfera en el eje Y
float initialVelocityZ = 0.0f;  // Velocidad inicial de la esfera en el eje Z
float gravity = -9.8f;     // Gravedad (aceleración) aplicada a la esfera
float timeStep = 0.1f;     // Paso de tiempo para la animación
float elapsedTime = 0.0f;  // Tiempo transcurrido desde el inicio de la animación
bool isAnimating = false;  // Bandera para indicar si la animación está en curso




// Objeto para dibujar figuras

//Figures figures ;		// CPH

CCamera objCamera;	//Crea el objeto Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;



//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position


GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};
GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
//NEW///////////////////////////7

//***ROSE****
CTexture textCannon; 
CTexture metal2;
CTexture texturaCilindro;
CTexture texturaBlack;	
CTexture texturaEsfera;
CTexture texturaBala;
//CFiguras fig1;
//CFiguras fig5;
//*****ROSE*****

CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;

float abrirPuerta = 0;
////////////////////////////////END NEW/////////////////////////////////////




CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;
CModel casita;
CModel oldhouse;

//Animacion del coche
float angRot = 0.0;
float movKitX = 0.0;
float movKitZ = 0.0;
float movKitXFinal = 0.0;
float movKitZFinal = 0.0;
float movKitXInc = 0.0;
float movKitZInc = 0.0;
float rotKit = 0.0;
float rotTires = 0.0;
bool g_fanimacion = false;
bool g_avanza = true;


int timer = 0;



GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
    //glColor4f(1.0f, 1.0f, 1.0f, 0.5); 
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	//text2.LoadBMP("hulkcara.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	kit._3dsLoad("kitt.3ds");	
	//kit.VertexNormals();
	
	
	//NEW////////////////////////////////////////////

	textCannon.LoadBMP("cannon.bmp");
	textCannon.BuildGLTexture();
	textCannon.ReleaseImage();

	metal2.LoadBMP("metal2.bmp");
	metal2.BuildGLTexture();
	metal2.ReleaseImage();

	texturaCilindro.LoadBMP("metal2.bmp");
	texturaCilindro.BuildGLTexture();
	texturaCilindro.ReleaseImage();

	texturaBlack.LoadBMP("black.bmp");
	texturaBlack.BuildGLTexture();
	texturaBlack.ReleaseImage();

	texturaEsfera.LoadBMP("esfera.bmp");
	texturaEsfera.BuildGLTexture();
	texturaEsfera.ReleaseImage();

	texturaBala.LoadBMP("bullet.bmp");
	texturaBala.BuildGLTexture();
	texturaBala.ReleaseImage();

	objCamera.Position_Camera(10.0,2.5f,3, //posicion de la camara
								0,2.5f,0,  //punto de mira
								0, 1, 0); // inclinacion
	


	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
		KeyFrame[i].giroBrazo =0;
		KeyFrame[i].giroBrazoInc = 0;

	}
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}
void updateSpherePosition() {
	if (isAnimating) {
		// Calcula la nueva posición de la esfera
		float newX = initialPosX + initialVelocityX * elapsedTime;
		float newY = initialPosY + initialVelocityY * elapsedTime + 0.5f * gravity * elapsedTime * elapsedTime;
		float newZ = initialPosZ + initialVelocityZ * elapsedTime;

		// Actualiza la posición de la esfera
		spherePosX = newX;
		spherePosY = newY;
		spherePosZ = newZ;

		// Actualiza el tiempo transcurrido
		elapsedTime += timeStep;

		// Detiene la animación si la esfera ha alcanzado el suelo
		if (newY <= 0.0f) {
			isAnimating = false;
		}
	}
}

void display ( void )   // Creamos la funcion donde se dibuja
{





	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Proyecto Extraordinario");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(0, -4.9f, 0);  // Posición del piso en el espacio
		// Escala del piso
		float floorScaleX = 61.0f;
		float floorScaleY = 61.0f;
		float floorScaleZ = 61.0f;

		// Aplicar textura al piso
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, text5.GLindex);

		// Dibujar el piso como un cuadro con textura
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-floorScaleX, 0.0f, -floorScaleZ);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(floorScaleX, 0.0f, -floorScaleZ);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(floorScaleX, 0.0f, floorScaleZ);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-floorScaleX, 0.0f, floorScaleZ);
		glEnd();

		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			


			// Antes de dibujar el cilindro
			if (textCannon.GLindex != 0) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, texturaCilindro.GLindex);
			}
			//cilindro
			glPushMatrix();
			glTranslatef(x, y, z);       // Posición del cilindro en el espacio
			glRotatef(angle, 0, 1, 0);   // Rotación del cilindro (si es necesario)
			glTranslatef(0.0f, 15.0f, 0.0f);     // Traslación en el eje Y para elevar el cilindro

			// Aplicar textura al cilindro
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texturaCilindro.GLindex);

			// Dibujar cilindro
			glPushMatrix();
			glDisable(GL_LIGHTING);
			// Configuraciones adicionales de material y textura aquí...

			glRotatef(30.0f, 1.0f, 0.0f, 0.0f);  // Rotación de 90 grados en el eje X

	
			// Antes de llamar a glBegin(GL_QUAD_STRIP)
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textCannon.GLindex);
			
			// Dibuja el cilindro utilizando primitivas GL_QUAD_STRIP o GL_TRIANGLES
			glBegin(GL_QUAD_STRIP);
			// Dentro del bucle para dibujar el cilindro
			for (float theta = 0; theta <= 2 * PI; theta += angleStep)
			{
				float x = radius * cos(theta);
				float y = radius * sin(theta);
				float u = theta / (2 * PI);  // Coordenada de textura U (proporcional al ángulo)

				glTexCoord2f(u, 0.0f);
				glVertex3f(x, y, 0.0f);      // Punto en la base del cilindro

				glTexCoord2f(u, 1.0f);
				glVertex3f(x, y, height);    // Punto en la parte superior del cilindro
			}
			glEnd();

			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);

			// Dibuja las bases del cilindro
			


			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(0.0f, 0.0f, height);    // Centro de la base superior
			for (float theta = 0; theta <= 2 * PI; theta += angleStep)
			{
				float x = radius * cos(theta);
				float y = radius * sin(theta);

				glVertex3f(x, y, height);    // Puntos en la base superior del cilindro
			}
			glEnd();

			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();



			// Configuraciones adicionales de material y textura aquí...

			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);

			// Esfera 1 (media esfera)
			glBindTexture(GL_TEXTURE_2D, texturaEsfera.GLindex);
			glPushMatrix();
			glTranslatef(x - radius - sphereRadius, y, z + 30.0f);  // Nueva posición de la esfera a la izquierda y debajo del cilindro
			glutSolidSphere(sphereRadius, 20, 10);  // Dibujar media esfera (10 segmentos en lugar de 20)
			// Asociar la textura "black" a la esfera
			glBindTexture(GL_TEXTURE_2D, texturaEsfera.GLindex);
			glPopMatrix();

			// Esfera 2
			glPushMatrix();
			glTranslatef(x + radius + sphereRadius, y, z + 30.0f);  // Nueva posición de la esfera a la derecha y debajo del cilindro
			glutSolidSphere(sphereRadius, 20, 20);  // Dibujar la esfera
			// Asociar la textura "black" a la esfera
			glPopMatrix();

			// Desactivar la textura
			glDisable(GL_TEXTURE_2D);



			//activate texture
			glEnable(GL_TEXTURE_2D);

			// Dibuja la esfera 3 en su posición actual
			glPushMatrix();
			glTranslatef(0, 15.0f, 0);
			glTranslatef(spherePosX, spherePosY, spherePosZ);
			glutSolidSphere(sphereRadius, 20, 20);
			glBindTexture(GL_TEXTURE_2D, texturaBala.GLindex);  // Textura "black" para las esferas
			glPopMatrix();


			if (isAnimating) {
				// Calcular el movimiento parabólico de la esfera
				float t = elapsedTime;
				float displacementX = 0.0f;  // Desplazamiento en el eje x
				float displacementY = 0.0f;  // Desplazamiento en el eje y
				float displacementZ = 0.0f;  // Desplazamiento en el eje z

				// Ajustar los valores de initialVelocityX, initialVelocityY e initialVelocityZ
				float initialVelocityX = 0.0f;  // Velocidad inicial en el eje x
				float initialVelocityY = 20.0f;  // Velocidad inicial en el eje y
				float initialVelocityZ = -12.0f;  // Velocidad inicial en el eje z

				spherePosX = initialPosX + initialVelocityX * t + displacementX;
				spherePosY = initialPosY + initialVelocityY * t + 0.5f * gravity * t * t + displacementY;
				spherePosZ = initialPosZ + initialVelocityZ * t + displacementZ;

				// Verificar si la esfera ha llegado al suelo
				if (spherePosY <= -15.0f) {
					isAnimating = false;
					spherePosX = 0.0f;
					spherePosY = 0.0f;
					spherePosZ = 0.0f;

				}

				// Actualizar el tiempo transcurrido
				elapsedTime += timeStep;
			}




			
	glutSwapBuffers ( );




}


	void reshape(int width, int height)	// Creamos funcion Reshape
	{

		if (height == 0)										// Prevenir division entre cero
		{
			height = 1;
		}

		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
		glLoadIdentity();

		// Tipo de Vista

		glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

		glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
		glLoadIdentity();
	}


void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;


		case 'x':
		case 'X':
			if (!isAnimating) {
				isAnimating = true;
				elapsedTime = 0.0f;
				// Establecer la posición y velocidad inicial de la esfera
				initialPosX = posX;
				initialPosY = posY;
				initialPosZ = posZ;
				initialVelocityX = 1.0f;  // Modificar según sea necesario
				initialVelocityY = 5.0f;  // Modificar según sea necesario
				initialVelocityZ = 0.0f;  // Modificar según sea necesario
				// Reproducir el sonido
				//engine->play2D("cannonshot.mp3", false);
			}
			break;

		case 27:        // Cuando Esc es presionado...
			//exit(0);   // Salimos del programa
			break;        
			default:        // Cualquier otra
			break;

  }

  glutPostRedisplay();
}



void arrow_keys(int a_keys, int x, int y)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		// Mover la cámara hacia arriba
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		// Mover la cámara hacia abajo
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:
		// Disminuir la inclinación hacia arriba de la vista
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:
		// Aumentar la inclinación hacia abajo de la vista
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		// Girar la vista hacia la izquierda
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		// Girar la vista hacia la derecha
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);			
				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				KeyFrame[FrameIndex].giroMonito=giroMonito;
			
				FrameIndex++;
			}
			
		
			break;

		case 1:
			if(play==false && FrameIndex >1)
			{
				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				giroMonito=KeyFrame[0].giroMonito;

				play=true;
				playIndex=0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	switch (id)
	{
		case 1:
			g_fanimacion^= true; //Activamos/desactivamos la animac�on
			break;


	}
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto CG"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funcion de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funcion en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funcion de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}
