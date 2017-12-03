#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 
#include "robot.h"
void chaise();// a faire
void table();// a faire
void piedTable();
void carton(int x);// a faire
void ouvrantCarton();// a faire
void lampe(); 
void donuts(); // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots(); // a faire
void sucre (); // a faire
void tasse();// a faire
void scene();// a faire

void robots()
{}
void sucre()
{}

void donuts()
{}

void tasse()
{}

void lampe()
{
		/*Dessus de la lampe  */
		glPushMatrix();
		//glTranslatef(0.0,0.0,0.0);
		glRotatef(90,1.0,0.0,0.0);
		//glScalef(4.5,2.0,2.0);
		glColor3f(1.0,1.0,0.0);
		cylindre(0.1,0.02);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15,0.063,0.0);
		glRotatef(60,0.0,0.0,1.0);
		glScalef(0.3,0.3,0.5);
		glColor3f(1.0,0.0,1.0);
		tore2(0.05,0.5,3);
		glPopMatrix();	
		
		glPushMatrix();
		glTranslatef(0.129,0.159,0.0);
		glRotatef(180,0.0,1.0,0.0);
		glRotatef(60,0.0,0.0,1.0);
		glScalef(0.3,0.3,0.5);
		glColor3f(1.0,0.0,1.0);
		tore2(0.05,0.5,2);
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(0.15,0.29,0.0);
		glRotatef(-90,0.0,1.0,0.0);
		cone(0.06,0.15);
		glPopMatrix();	
		
}


void ouvrantCarton()
{}
//si 1 semi -ouvert
//si 2 ouvert
void carton(int x)
{}

void chaise()
{}



void piedTable()
{
  
  glPushMatrix();
  glTranslatef(0.0,0.0,-0.3);
  glRotatef(90,1.0,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  cone(0.1,0.8);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(0.,-0.7,-0.3);
  glRotatef(90,1.0,0.0,0.0);
  cylindre (0.01, 0.1);
  glPopMatrix();
  
}


void table()
{
  
  /*Dessus de la table */
  glPushMatrix();
  glColor3f(1.0,0.0,0.5);
  glTranslatef(0.0,0.85,0.0);
  glRotatef(90,1.0,0.0,0.0);
  glScalef(2.5,1.5,1.5);
 // glColor3f(1.0,1.0,0.0);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[3]); 
  glEnable(GL_TEXTURE_2D);
  cylindre (0.5,0.05);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  
  /*Pied gauche */
  glPushMatrix();
  glTranslatef(-0.8,0.8,0.0);
  piedTable();
  
  /*Pied droit */
  glPushMatrix();
  glTranslatef(0.,0.,0.6);
  piedTable();
  glPopMatrix();
  
  glPopMatrix();
  
  
  /*Pied avant */
  glPushMatrix();
  glTranslatef(0.8,0.8,0.0);
  glPushMatrix();
  piedTable();
  
  glPopMatrix();
  
  /*Pied arriere*/
  glPushMatrix();
  glTranslatef(0.,0.,0.6);
  piedTable();
  glPopMatrix();
  
  glPopMatrix();
}
void scene()
{

}


