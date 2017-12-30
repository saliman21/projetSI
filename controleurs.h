#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>  
#include <math.h> 



float zoom=2.,zoom_OnCenter=0.;

char presse;  
int anglex,angley,x,y,xold,yold;  

void clavierMenu(int x);



void createMenu() {
  
  int menu;
  
  menu = glutCreateMenu(clavierMenu);
  
  glutAddMenuEntry("Allumage lumiere piece",1);
  glutAddMenuEntry("Extinction lumiere piece",2);
  glutAddMenuEntry("Allumage Lumiere Lampe ",3);
  glutAddMenuEntry("Extinction lumiere Lampe ",4);
  glutAddMenuEntry("Animation ",6);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDetachMenu(GLUT_LEFT_BUTTON);
}






void clavierMenu(int x)
{
  switch(x)
  {
  case 1:/* bascule brouillard */
    if (Brouillard)
      glEnable(GL_FOG);
    else
      glDisable(GL_FOG);
    Brouillard = 1 - Brouillard;
    glutPostRedisplay();
    break;
  case 2: //Bascule de la lumière 1
    if (lumiere1)
      glEnable(GL_LIGHT1);
    else glDisable(GL_LIGHT1);
    lumiere1 = 1 - lumiere1;
    glutPostRedisplay();
    break;
  case 3: //Bascule de la lumière 0
    if (lumiere0)
      glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);
    lumiere0 = 1 - lumiere0;
    glutPostRedisplay();
    break;
  case 4: /* bascule eclairage */
    if (Eclairage)
      glEnable(GL_LIGHTING);
    else
      glDisable(GL_LIGHTING);
    Eclairage = 1 - Eclairage;
    glutPostRedisplay();
    
    break;
  case 5: //Bascule de la lumière 0
    if (lumiere0)
      glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);
    lumiere2 = 1 - lumiere2;
    glutPostRedisplay();
    break;
  case 6: //animation
    play=1;
    break;
  }
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
  case 'Z': zoom+= 0.1;
    glutPostRedisplay();
    break;
  case 'z': zoom-= 0.1;
    glutPostRedisplay();
    break;
  case '5':/* bascule brouillard */
  if (Brouillard)
    glEnable(GL_FOG);
  else
    glDisable(GL_FOG);
  Brouillard = 1 - Brouillard;
  glutPostRedisplay();
  break;
  case 'L': //Bascule de la lumière 1
    if (lumiere1)
      glEnable(GL_LIGHT1);
    else glDisable(GL_LIGHT1);
    lumiere1 = 1 - lumiere1;
    glutPostRedisplay();
    break;
  case 'l': //Bascule de la lumière 0
    if (lumiere0)
      glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);
    lumiere0 = 1 - lumiere0;
    glutPostRedisplay();
    break;
  case 'S': /* bascule eclairage */
  if (Eclairage)
    glEnable(GL_LIGHTING);
  else
    glDisable(GL_LIGHTING);
  Eclairage = 1 - Eclairage;
  glutPostRedisplay();

  break;
 case 't': //Bascule de la lumière 0
    if (lumiere0)
      glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);
    lumiere2 = 1 - lumiere2;
    glutPostRedisplay();
    break;
case 'C':
zoom_OnCenter += 0.01;
glutPostRedisplay();
break;
case 'c':	// zOOMER
zoom_OnCenter -= 0.01;
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
  { 
    glViewport(0,(y-x)/2,x,x); 
    glutPostRedisplay();
  }
  else 
  { 
    glViewport((x-y)/2,0,y,y); 
    glutPostRedisplay(); 
  }
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
