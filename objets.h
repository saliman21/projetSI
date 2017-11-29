#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 

void chaise();// a faire
void table();
void piedTable();
void carton(int x);// a faire
void ouvrantCarton();// a faire
void lampe(); // a faire
void donuts(); // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots(); // a faire
void sucre (); // a faire
void tasse();// a faire

void robots()
{}

void sucre()
{
}

void donuts()
{
}

void tasse()
{}



void lampe()
{
}


void ouvrantCarton()
{
}

void carton(int x)
{
}

void chaise()
{

}


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
  glColor3f(1.0,1.0,0.0);
  cylindre (0.5,0.05);
  glPopMatrix();
  
  
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

