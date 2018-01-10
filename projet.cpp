#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>  
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>  
#include "scene.h" 
#include <jpeglib.h>
#include <jerror.h>
#define PI 3.141592
#pragma comment (lib, "jpeg.lib");
#include "lumieres.h"
#include "controleurs.h"


 
void affichage();  
void clavier(unsigned char touche,int x,int y); 
void clavier2(int touche, int x, int y); 
void reshape(int x,int y);  
void idle();  
void mouse(int bouton,int etat,int x,int y);  
void mousemotion(int x,int y);  
void Repere();
void Initialise();
void CamOn();

void AnimationRobots(void);



void Initialise()
{
  //Chargement des textures
  ChargementImages();
  glutPostRedisplay();
}

void CamOn()
{
	gluLookAt(Look_x, Look_y, Look_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
int main(int argc,char **argv)  
{  	
  
  glutInit(&argc,argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |GLUT_DOUBLE | GLUT_DEPTH);  
  glutInitWindowPosition(20,20);  
  glutInitWindowSize(1000,1000);  
  glutCreateWindow("Projet 17-18 chez Adele"); 
  Initialise();
  lumieres();
   
  glClearColor(0.8, 0.8, 0.8, 20);
  glColor3f(1.0,1.0,1.0);  
  glPointSize(2.0); 
  glShadeModel(GL_FLAT); 
  glEnable(GL_DEPTH_TEST);  
  
  /*Inittialisation des textures*/
  
  glutDisplayFunc(affichage);  
  glutKeyboardFunc(clavier); 
  glutSpecialFunc(clavier2); 
  glutReshapeFunc(reshape);  
  glutMouseFunc(mouse);  
  glutMotionFunc(mousemotion); 
  glutIdleFunc(AnimationRobots);
  
	createMenu() ;
  glutMainLoop();  
  return 0;  
}  



void affichage()  
{  
  /* effacement de l'image avec la couleur de fond */  
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
	gluPerspective(70.0, float(1000/1000),  0.1, -10.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CamOn();
  glRotatef(-angley,1.0,0.0,0.0);  
  glRotatef(-anglex,0.0,1.0,0.0);  
  
	glPushMatrix();
    affichageScene();
	glPopMatrix();
    Repere();
  
    glFlush();  
  glutPostRedisplay(); 
  /* On echange les buffers */  
  glutSwapBuffers();  
}  

/* Dessin  */  
void Repere()
{
//axe x en rouge
  glBegin(GL_LINES);
  glColor3f(1.0,0.0,0.0);
  glVertex3f(0, 0,0.0);
  glVertex3f(1, 0,0.0);
  glEnd();
  //axe des y en vert
  glBegin(GL_LINES);
  glColor3f(0.0,1.0,0.0);
  glVertex3f(0, 0,0.0);
  glVertex3f(0, 1,0.0);
  glEnd();
  //axe des z en bleu
  glBegin(GL_LINES); 
  glColor3f(0.0,0.0,1.0);  
  glVertex3f(0, 0,0.0);
  glVertex3f(0, 0,1.0);
  glEnd();
}




