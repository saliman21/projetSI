#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include <iostream>

float expo=1., anglespot=78.0;
/* Parametre de la lumière*/ 
 /* lumimere */
bool Eclairage=true;
// Lumière 2
GLfloat Lumiere1Position[] = { -2.0, 2.0, 1.0, 1.0 };
GLfloat Lumiere1Diffuse[] = { 1.0, 1.0, 1.0,1.0 };
GLfloat Lumiere1Ambient[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat Lumiere1Specular[] = {1.,1.,1.,1.0};

GLfloat Lumiere2Position[] = { 1.0, 1.0, 1.0,1.0 };
GLfloat Lumiere2Diffuse[] = { 1.0, 1.0, 1.0,1.0 };
GLfloat Lumiere2Ambient[] = { 0.,0.2,0.2,1.0};
GLfloat Lumiere2Specular[] = {1.0, 1.0, 1.0, 1.0};


GLfloat mat_amb_diff[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat gl_Speculaire[] = { 0.0, 0.0, 1.0 };
GLfloat brillance = 100;

	/*Parametre du spot lumineux*/
	//lumiere 0

	GLfloat light0_position[] = {-1,0.86,0.};
	GLfloat spot0_direction[] = {-1.,-1.,0.};


 

void lumieres()
{
	
  /*Paramètre de la lumière*/
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  
	//lumiere 1 
  glLightfv(GL_LIGHT1, GL_DIFFUSE, Lumiere1Diffuse);
  glLightfv(GL_LIGHT1, GL_AMBIENT, Lumiere1Ambient);
  glLightfv(GL_LIGHT1, GL_SPECULAR, Lumiere1Specular);
  glLightfv(GL_LIGHT1, GL_POSITION, Lumiere1Position);
 
 //lumiere 2 avec facteur d'attenuation
  glLightfv(GL_LIGHT2, GL_DIFFUSE, Lumiere2Diffuse);
  glLightfv(GL_LIGHT2, GL_AMBIENT, Lumiere2Ambient);
  glLightfv(GL_LIGHT2, GL_SPECULAR, Lumiere2Specular);
  glLightfv(GL_LIGHT2, GL_POSITION, Lumiere2Position);
  glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.5);
  glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.5);
  glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.2);
  
  /*Paramètre de lampe lumiere 0 */
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);	
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF,anglespot); 
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0_direction);
	glLighti(GL_LIGHT0, GL_SPOT_EXPONENT,expo);/* coefficient d'atténuation angulaire */
 

	/*Paramètre des matériaux*/
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gl_Speculaire);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillance);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, 
            mat_amb_diff);

	/*Activation des lumieres */
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	

}
