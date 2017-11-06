#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>  
#include <GL/freeglut.h>
#include <math.h>  
#include "csg.h" 



#define PI 3.14159265  


char presse;  
int anglex,angley,x,y,xold,yold;  


void affichage();  
void clavier(unsigned char touche,int x,int y);  
void reshape(int x,int y);  
void idle();  
void mouse(int bouton,int etat,int x,int y);  
void mousemotion(int x,int y);  
void pied();
void table();




int main(int argc,char **argv)  
{  
  
  
  
  glutInit(&argc,argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
  glutInitWindowPosition(200,200);  
  glutInitWindowSize(600,600);  
  glutCreateWindow("Projet 17-18 chez Adele");  
  
  glClearColor(0.0,0.0,0.0,0.0);  
  glColor3f(1.0,1.0,1.0);  
  glPointSize(2.0);  
  glEnable(GL_DEPTH_TEST);  
  
  
  glutDisplayFunc(affichage);  
  glutKeyboardFunc(clavier);  
  glutReshapeFunc(reshape);  
  glutMouseFunc(mouse);  
  glutMotionFunc(mousemotion);  
  pied();
  table();
  glutMainLoop();  
  return 0;  
}  
void pied()
{
  
  
  
  
}

void table()
{
  
 // cylindre (0.1,1);
  //tore(0.2,0.5,1);
  //hyperboloide(0.2,0.5,12,0);
  cone(0.2,0.8);
}

void affichage()  
{  
  /*Application des transfos de visualisation */  
  //glRotated(r,0.0,1.0,0.0);  
  //glTranslatef(-px,0.0,-pz);  
  int j;  
  /* effacement de l'image avec la couleur de fond */  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
  glLoadIdentity();  
  glRotatef(-angley,1.0,0.0,0.0);  
  glRotatef(-anglex,0.0,1.0,0.0);  
  
  /* Dessin  */  
  glColor3f(0.1,0.1,0.5);
  
  table();
  //theire(0.1);
  //sphere(0.5,60,40) ;
  //cube(0.5);

  //Repère
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
  glFlush();  
  
  /* On echange les buffers */  
  glutSwapBuffers();  
}  

void clavier(unsigned char touche,int x,int y)  
{  
  switch (touche)  
  {  
  case 'p': /* affichage du carre plein */  
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);  
    glutPostRedisplay();  
    break;  
  case 'f': /* affichage en mode fil de fer */  
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);  
    glutPostRedisplay();  
    break;  
  case 's' : /* Affichage en mode sommets seuls */  
  glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);  
    glutPostRedisplay();  
    break;  
  case 'd':  
    glEnable(GL_DEPTH_TEST);  
    glutPostRedisplay();  
    break;  
  case 'D':  
    glDisable(GL_DEPTH_TEST);  
    glutPostRedisplay();  
    break;  
    ////////////////////////   
    
  
    ////////////////////////////  
  case 'q' : /*la touche 'q' permet de quitter le programme */  
    exit(0);  
  }  
}  

void reshape(int x,int y)  
{  
  if (x<y)  
    glViewport(0,(y-x)/2,x,x);  
  else   
    glViewport((x-y)/2,0,y,y);  
}  

void mouse(int button, int state,int x,int y)  
{  
  /* si on appuie sur le bouton gauche */  
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
  {  
    presse = 1; /* le booleen presse passe a 1 (vrai) */  
  xold = x; /* on sauvegarde la position de la souris */  
  yold=y;  
  }  
  /* si on relache le bouton gauche */  
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)   
    presse=0; /* le booleen presse passe a 0 (faux) */  
}  

void mousemotion(int x,int y)  
{  
  if (presse) /* si le bouton gauche est presse */  
  {  
    /* on modifie les angles de rotation de l'objet 
     en fonction de la position actuelle de la souris et de la derniere 
     position sauvegardee */  
    anglex=anglex+(x-xold);   
    angley=angley+(y-yold);  
    glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */  
  }  
  
  xold=x; /* sauvegarde des valeurs courante de le position de la souris */  
    yold=y;  
}  

