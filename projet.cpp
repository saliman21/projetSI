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
void reshape(int x,int y);  
void idle();  
void mouse(int bouton,int etat,int x,int y);  
void mousemotion(int x,int y);  
void Repere();
void Initialise();

void Initialise()
{
  //Chargement des textures
  ChargementImages();
  glutPostRedisplay();
}



int main(int argc,char **argv)  
{  	

		
  
  glutInit(&argc,argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |GLUT_DOUBLE);  
  glutInitWindowPosition(200,200);  
  glutInitWindowSize(600,600);  
  glutCreateWindow("Projet 17-18 chez Adele"); 
  Initialise();
  lumieres();
   
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glColor3f(1.0,1.0,1.0);  
  glPointSize(2.0); 
  glShadeModel(GL_FLAT); 
  glEnable(GL_DEPTH_TEST);  
  
  /*Inittialisation des textures*/
  
  glutDisplayFunc(affichage);  
  glutKeyboardFunc(clavier);  
  glutReshapeFunc(reshape);  
  glutMouseFunc(mouse);  
  glutMotionFunc(mousemotion); 

  glutMainLoop();  
  return 0;  
}  

void affichage()  
{  
  /*Application des transfos de visualisation */  
  //glRotated(r,0.0,1.0,0.0);  
  //glTranslatef(-px,0.0,-pz);  
   
  /* effacement de l'image avec la couleur de fond */  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-zoom,zoom,-zoom,zoom,-zoom,zoom);
  
  /*glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 1.0, 1.5, 0., 0., 0.0, 0.0, 1.0, 0.0);*/
  glRotatef(-angley,1.0,0.0,0.0);  
  glRotatef(-anglex,0.0,1.0,0.0);  
  
  
  glPushMatrix();
  affichageScene();
  glPopMatrix();
 //Repère
   // Repere();
  /*glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 1, 0.001, 10);*/
    glFlush();  
  //glutPostRedisplay(); 
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




