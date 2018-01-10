#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>  
#include <math.h> 



float Look_x=0.,Look_y=3., Look_z=1.5;

char presse;  
int anglex,angley,x,y,xold,yold;  

void clavierMenu(int x);



void createMenu() {
  
  int menu;
  
  menu = glutCreateMenu(clavierMenu);
  
  
  glutAddMenuEntry(" Eteindre la piece",1);
  glutAddMenuEntry("Allumer la lumire 1 de la piece",2);
  glutAddMenuEntry("Eteindre la lumire 1 de la piece",3);
  glutAddMenuEntry("Allumer la lumire 2 de la piece ",4);
  glutAddMenuEntry("Eteindre  la lumire 2 de la piece",5);
  glutAddMenuEntry(" Allumer la lampe",6);
  glutAddMenuEntry(" Eteindre  la lampe",7);
  glutAddMenuEntry("Animation ",8);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDetachMenu(GLUT_LEFT_BUTTON);
}






void clavierMenu(int x)
{
  switch(x)
  {
  case 1: /* eteindre  eclairage */
	if (Eclairage)
     glDisable(GL_LIGHTING);
     else 
     glEnable(GL_LIGHTING);
     Eclairage=1-Eclairage;
    glutPostRedisplay();
    break;
     case 2: 
      glEnable(GL_LIGHT1);    
	glutPostRedisplay();
	break;
   case 3: /* allumuer  */
      glDisable(GL_LIGHT1);
    glutPostRedisplay();
    break;
     case 4: /* eteindre  lampe */
     glEnable(GL_LIGHT2);   
	glutPostRedisplay();
	break;
	case 5: /* allumuer lumiere 2 */
       glDisable(GL_LIGHT2);
    glutPostRedisplay();
    break;
     case 6: /* eteindre lumiere 2 */
    glEnable(GL_LIGHT0);
	glutPostRedisplay();
	break;
	case 7: /* allumuer lumiere 2 */
       glDisable(GL_LIGHT0);
    glutPostRedisplay();
    break;
	case 8: //animation
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
  case 'Z': Look_z+= 0.1;//Zoomer 
    glutPostRedisplay();
    break;
  case 'z': Look_z-= 0.1;// Dezoomer
    glutPostRedisplay();
    break; 
  case 'q' : /*la touche 'q' permet de quitter le programme */  
    exit(0);  
  }  
} 

/* Clavier permettant de gerer la camera par les touches directionnelles*/
void clavier2( int touche, int x, int y)
{
	switch (touche)
	{
		case GLUT_KEY_DOWN:
			Look_y -= 1.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP:
			Look_y += 1.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			Look_x -= 1.0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			Look_x += 1.0;
			glutPostRedisplay();
			break;
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
