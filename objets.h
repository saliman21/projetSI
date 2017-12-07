#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 
void chaise(); // a faire
void table(); // a faire
void piedTable(); // a faire
void carton(int x); 
void ouvrantCarton(); 
void lampe();  // a faire
void donuts();  // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots();  // a faire
void sucre (); 
void tasse();
void scene(); // a faire
void robots() 
{}
void sucre()
{
	glPushMatrix();
	//glTranslatef(-0.25f, 1.95f, 0.0f);
        glScalef(1.5, 0.5, 1);
	//glColor3f(0.3, 0.3, 1);
	glBindTexture(GL_TEXTURE_2D, ObjTexture[3]); 
  	glEnable(GL_TEXTURE_2D);
	cubeT(1.);
	glPopMatrix(); 
	glDisable(GL_TEXTURE_2D);
}

void donuts()
{}

void tasse()
{

glPushMatrix();
glScalef(0.02,0.013,0.02);
glRotatef(5.,0.,0.,1.);
tore(0.5,3,2);
glPopMatrix(); 


glPushMatrix();
glTranslatef(-0.04,0.01,0.0);
hyperboloide (0.05, 0.07, 20, 1.);
glRotatef(180.,1.,0.,0.);
glPopMatrix(); 



}



void lampe()
{}


void ouvrantCarton()
{
  glColor3f(0.3,0.3,0.5);
  glRectd(-0.5,  0.09,  0.5,  0.59);  
  
}
//si 1 semi -ouvert
//si 2 ouvert
void carton(int x)
{
  glColor3f(0.3,0.3,0.5);
  cube (0.5);
  
  if (1 == x) {
    //ouvrant 1
    glPushMatrix();
  glColor3f(0.3,0.3,1);
  glTranslated(0.,0.43,0.57);
  glRotatef(-45.,1.,0.,0.);
  ouvrantCarton();
  glPopMatrix();
  //ouvrant 2
  glPushMatrix();
  glColor3f(0.3,0.3,1);
  glTranslated(0.,0.43,-0.57);
  glRotatef(45.,1.,0.,0.);
  glRotatef(180.,0.,1.,0.);
  
  ouvrantCarton();
  glPopMatrix();}
  
  
  
  if (2 == x){
    //ouvrant 1
    glPushMatrix();
  glColor3f(0.3,0.3,1);
  glTranslated(0.,0.43,0.44);
  glRotatef(45.,1.,0.,0.);
  ouvrantCarton();
  glPopMatrix();
  
  //ouvrant 2
  glPushMatrix();
  glColor3f(0.3,0.3,1);
  glTranslated(0.,0.43,-0.44);
  glRotatef(-45.,1.,0.,0.);
  glRotatef(180.,0.,1.,0.);
  
  ouvrantCarton();
  glPopMatrix();
  }
  
  
  
}

void chaise()
{}



void piedTable()
{}


void table()
{}
void scene()
{}

