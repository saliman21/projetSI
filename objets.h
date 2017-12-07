#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
#include "robot.h"
void chaise();
void table(); // a faire
void piedTable(); // a faire
void carton(int x); // a faire
void ouvrantCarton(); // a faire
=======
>>>>>>> V1_M
void chaise(); // a faire
void table(); // a faire
void piedTable(); // a faire
void carton(int x); 
void ouvrantCarton(); 
<<<<<<< HEAD
=======
>>>>>>> V1_CSG
>>>>>>> V1_M
void lampe();  // a faire
void donuts();  // a faire
void truffes(); // a faire
void tuiles(); // a faire
void robots();  // a faire
<<<<<<< HEAD
=======
<<<<<<< HEAD
void sucre ();  // a faire
void tasse(); // a faire
void scene(); // a faire
=======
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
>>>>>>> V1_A

void robots()
{}
void sucre()
{}
<<<<<<< HEAD
=======
>>>>>>> V1_M
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
<<<<<<< HEAD
=======
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
=======
>>>>>>> V1_CSG
=======
>>>>>>> V1_M
>>>>>>> V1_A

void donuts()
{}

void tasse()
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
{}
=======
>>>>>>> V1_M
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
<<<<<<< HEAD
=======
>>>>>>> V1_CSG
>>>>>>> V1_M



void lampe()
{}


void ouvrantCarton()
<<<<<<< HEAD
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
=======
<<<<<<< HEAD
>>>>>>> V1_M
=======
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
>>>>>>> V1_A
{}
//si 1 semi -ouvert
//si 2 ouvert
void carton(int x)
{}

void chaise()
<<<<<<< HEAD
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

<<<<<<< HEAD
>>>>>>> V1_A

=======
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
=======
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

>>>>>>> V1_A

>>>>>>> V1_M
