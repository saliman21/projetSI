#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 
#include "robot.h"
void chaise();
void table(); // a faire
void piedTable(); // a faire
void carton(int x); // a faire
void ouvrantCarton(); // a faire
void lampe();  // a faire
void donuts();  // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots();  // a faire
void sucre ();  // a faire
void tasse(); // a faire
void scene(); // a faire

void robots()
{}
void sucre()
{}

void donuts()
{}

void tasse()
{}



void lampe()
{}


void ouvrantCarton()
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



void piedTable()
{}


void table()
{}
void scene()
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


