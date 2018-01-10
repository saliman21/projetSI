#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "figures.h" 
#include "texture.h" 


void chaise(); //mis
void table(); //mis
void piedTable(); //mis
void carton(int x); //mis
void ouvrantCarton(); //mis
void lampe(); //mis
void donuts(); //mis
void truffes(); // mis
void tuiles(); //mis
void livre(); //mis
void sucre (); //mis
void tasse(); //mis
void theiere(float x); //mis
void assiette(); // mis

void assiette()
{
    tore (0.2, 1.2, 1);  
     glPushMatrix();
  glRotatef(90.,1.,0.,0.);
  glTranslatef(-1.5, 10., -1.1);
   glScalef(1.4, 2, 1);
  tore3 (1.0, 5.0, 4);
     glPopMatrix(); 
}


void theiere(float x)
{
   glPushMatrix(); 
   
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glBindTexture(GL_TEXTURE_2D,ObjTexture[6]);
  glEnable(GL_TEXTURE_2D);
   theire(x);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
 glDisable(GL_TEXTURE_GEN_T);

}


void livre()
{
	glPushMatrix();
	
	glPushMatrix();
  glTranslatef(-1.5, 0., -1.);
  glRotatef(90.,0.,1.,0.);
 
  cylindre (0.15,3.);
  glPopMatrix(); 
  glPushMatrix();
  glScalef(1.5, 0.1, 1);


  cubeT(1.);
  glPopMatrix(); 

  
  glPushMatrix();
  glTranslatef(0., 0.1, 0.1);
  glScalef(1.5, 0.02, 1.1);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[4]); 
  glEnable(GL_TEXTURE_2D);
	cubeT(1.);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
  
  glPushMatrix();
  glTranslatef(0., -0.1, 0.1);
  glScalef(1.5, 0.02, 1.1);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[4]); 
  glEnable(GL_TEXTURE_2D);
  cubeT(1.);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
  glPopMatrix(); 
  glPopMatrix(); 
}

void tuiles()
{

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, ObjTexture[10]); 
  glEnable(GL_TEXTURE_2D);
  glScalef(1.4, 1, 1);
  tore3 (1.0, 5.0, 4);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
}

void truffes()
{
  
  glScalef(1, 4, 1);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, ObjTexture[8]); 
  glEnable(GL_TEXTURE_2D);
  sphere (1.0,20,20);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
}


void sucre()
{
	glPushMatrix();
   glColor3f(1.,1.,1.);
    
	glBindTexture(GL_TEXTURE_2D, ObjTexture[1]); 
  	glEnable(GL_TEXTURE_2D);
	cubeT(0.01);
	glPopMatrix(); 
	glDisable(GL_TEXTURE_2D);
}

void donuts()
{
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, ObjTexture[9]); 
  glEnable(GL_TEXTURE_2D);
	tore(0.1,0.2,1);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
}

void tasse()
{

glColor3f(0.5,0.5,0.5);
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
{
		/*Dessus de la lampe  */
		
		glPushMatrix();
		glColor3f(1.5,0.5,0.5);
		glRotatef(90,1.0,0.0,0.0);
		cylindre(0.1,0.02);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.15,0.063,0.0);
		glRotatef(60,0.0,0.0,1.0);
		glScalef(0.3,0.3,0.5);
		glColor3f(1.0,1.0,1.0);
		tore2(0.05,0.5,3);
		glPopMatrix();	
		
		glPushMatrix();
		glTranslatef(0.129,0.159,0.0);
		glRotatef(180,0.0,1.0,0.0);
		glRotatef(60,0.0,0.0,1.0);
		glScalef(0.3,0.3,0.5);
		glColor3f(1.0,1.0,1.0);
		tore2(0.05,0.5,2);
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(0.1,0.28,0.0);
		glRotatef(-90,0.0,1.0,0.0);
		glRotatef(-45,1.0,0.0,0.0);
		cone(0.06,0.15);
		glPopMatrix();	
					
	
}


void ouvrantCarton()
{
	
	glBegin(GL_POLYGON);
	 glTexCoord2f(0.,0.);
	glVertex2f(-0.5,0.09);
	 glTexCoord2f(1.,0.);
	glVertex2f(0.5,0.09);
	 glTexCoord2f(1.,1.);
	glVertex2f(0.5,0.59);
	glTexCoord2f(0.,1.);
	glVertex2f(-0.5,0.59);
	glEnd();
  
}
//si 1 semi -ouvert
//si 2 ouvert
void carton(int x)
{
  
  glBindTexture(GL_TEXTURE_2D, ObjTexture[3]); 
  glEnable(GL_TEXTURE_2D);
	cubeT(0.5);

  if (1 == x) {
    //ouvrant 1
    glPushMatrix();
  glTranslated(0.,0.43,0.57);
  glRotatef(-45.,1.,0.,0.);
  ouvrantCarton();
  glPopMatrix();
  //ouvrant 2
  glPushMatrix();
  
  glTranslated(0.,0.43,-0.57);
  glRotatef(45.,1.,0.,0.);
  glRotatef(180.,0.,1.,0.);
  
  ouvrantCarton();
  glPopMatrix();
  }
  
  
  
  if (2 == x){
    //ouvrant 1
    glPushMatrix();
  glTranslated(0.,0.43,0.44);
  glRotatef(45.,1.,0.,0.);
  ouvrantCarton();
  glPopMatrix();
  
  //ouvrant 2
  glPushMatrix();
  glTranslated(0.,0.43,-0.44);
  glRotatef(-45.,1.,0.,0.);
  glRotatef(180.,0.,1.,0.);
  
  ouvrantCarton();
  glPopMatrix();
   glDisable(GL_TEXTURE_2D);
  }
  
  
  
}

void chaise()
{

//pied 1 long
glPushMatrix();
    
glTranslated(0,0.06,-0.08);
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
	cylindre (0.01,0.20);
glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);

  //pied 2 long
glPushMatrix();
  
glTranslated(0.06,0,-0.08);
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
cylindre (0.01,0.20);
glPopMatrix();
glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);

//pied 3 court
glPushMatrix();
glTranslated(0,-0.06,0.01);
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
cylindre (0.01,0.11);
glPopMatrix();
glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);
//pied 4 court
glPushMatrix();
glTranslated(-0.06,0,0.01);
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
cylindre (0.01,0.11);
glPopMatrix();
glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);
  
//pied 4 court
//cylindre repose fesse
glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
cylindre (0.07,0.01);

glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_TEXTURE_2D);
//haut dossier
glPushMatrix();
glScalef(0.02,0.013,0.02);
glTranslated(1.4,2.5,-3.60);
glRotatef(90.,0.,1.,0.);
glRotatef(-35.,1.,0.,0.);
glRotatef(5.,0.,0.,1.);
glBindTexture(GL_TEXTURE_2D, ObjTexture[7]); 
  glEnable(GL_TEXTURE_2D);
tore(0.5,3,2);
glPopMatrix(); 
glDisable(GL_TEXTURE_2D);
  
}



void piedTable()
{
  
  glPushMatrix();
  glTranslatef(0.0,0.0,-0.3);
  glRotatef(90,1.0,0.0,0.0);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[5]); 
  glEnable(GL_TEXTURE_2D);
  cone(0.1,0.8);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(0.,-0.7,-0.3);
  glRotatef(90,1.0,0.0,0.0);
  cylindre (0.01, 0.1);
  glPopMatrix();
   glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);

  glDisable(GL_TEXTURE_2D);
}


void table()
{
  
  /*Dessus de la table */
  glPushMatrix();
 
  glTranslatef(0.0,0.85,0.0);
  glRotatef(90,1.0,0.0,0.0);
  glScalef(2.5,1.5,1.5);
 
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[5]); 
  glEnable(GL_TEXTURE_2D);
  cylindre (0.5,0.05);
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);

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


