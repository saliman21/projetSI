#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 
<<<<<<< HEAD
#include "robot.h"
void chaise();
void table(); // a faire
void piedTable(); // a faire
void carton(int x); // a faire
void ouvrantCarton(); // a faire
=======
void chaise(); // a faire
void table(); // a faire
void piedTable(); // a faire
void carton(int x); 
void ouvrantCarton(); 
>>>>>>> V1_CSG
void lampe();  // a faire
void donuts();  // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots();  // a faire
<<<<<<< HEAD
void sucre ();  // a faire
void tasse(); // a faire
void scene(); // a faire

void robots()
{}
void sucre()
{}
=======
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
>>>>>>> V1_CSG

void donuts()
{}

void tasse()
<<<<<<< HEAD
{}
=======
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
>>>>>>> V1_CSG



void lampe()
{}


void ouvrantCarton()
<<<<<<< HEAD
{}
//si 1 semi -ouvert
//si 2 ouvert
void carton(int x)
{}

void chaise()
{

//pied 1 long
glPushMatrix();
    glColor3f(0.3,0.3,1);
glTranslated(0,0.06,-0.08);
cylindre (0.01,0.20);
glPopMatrix();

//pied 2 long
glPushMatrix();
    glColor3f(0.3,0.3,1);
glTranslated(0.06,0,-0.08);
cylindre (0.01,0.20);
glPopMatrix();
glColor3f(1,0.3,1);
//pied 3 court
glPushMatrix();
glTranslated(0,-0.06,0.01);
cylindre (0.01,0.11);
glPopMatrix();

//pied 4 court
glPushMatrix();
glTranslated(-0.06,0,0.01);
cylindre (0.01,0.11);
glPopMatrix();

//cylindre repose fesse
cylindre (0.07,0.01);

//haut dossier
glPushMatrix();
glScalef(0.02,0.013,0.02);
glTranslated(1.4,2.5,-3.60);
glRotatef(90.,0.,1.,0.);
glRotatef(-35.,1.,0.,0.);
glRotatef(5.,0.,0.,1.);
tore(0.5,3,2);
glPopMatrix();  
}

=======
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

>>>>>>> V1_CSG


void piedTable()
{}


void table()
{}
void scene()
<<<<<<< HEAD
{
    glPushMatrix();
    //debut Maison
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, ObjTexture[0]); 
    glEnable(GL_TEXTURE_2D);
    //glColor3f(1.,0.,1.);
      cubeT(0.5);
     glPopMatrix();// fin maison
     glDisable(GL_TEXTURE_2D);
     //debut porte maison
    glPushMatrix();
   glTranslatef(0.49, -0.25, 0.0);
    glScalef(0.05, 0.5, 0.25);
    //glColor3f(1.,0.,0.);
   glBindTexture(GL_TEXTURE_2D, ObjTexture[1]); 
    glEnable(GL_TEXTURE_2D);
    cubeT(0.5);
   glPopMatrix();// fin porte maison
   glDisable(GL_TEXTURE_2D);
  // debut lampe de la maison
   glPushMatrix();
  glTranslatef(0.0, 0.7, 0.0);
  glRotatef(90, 1.0, 0.0, 0.0);
  cylindre(0.1, 0.08);
   glPopMatrix();// fin lampe
  glPopMatrix();// fin scene

}

=======
{}
>>>>>>> V1_CSG

