#include <stdio.h>  
#include <stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include "objets.h" 
#include "robot.h" 
#include "courbes.h"
#include <unistd.h> 
#include <iostream>


void affichageScene();
void murSolPlafond();
void AffichageAnimationRobots();
void AnimationRobots(void);


//position robot
float xT=-3;
float yT=0.18;
float zT=0;
//position sucre
float xS=0.1;
float yS=0.86;
float zS=-0.25;

int play=0;
int Pos=0;
int pposs=0;
int t=0;
float etape=0;



//extern unsigned int sleep (unsigned int 10seconds);

void AnimationRobots(void)
{
	
      
  if(play>0)
{
      if(Pos<=87)
      {
      xT=CBPT[Pos].x;
      zT=CBPT[Pos].y;
      Pos++;
      sleep(0.9);
      }
      if(Pos>86)
      {
  //descente de l'avant bras
  if(etape==0 && rotation_descente>91)
    {etape++;}
	else if(etape==0 && rotation_descente<100)
	{
	 rotation_descente+=2;
   	
	}
	if(etape==1)
	{
		scale_bras+=0.5/20;
	if (scale_bras >= 1.9) etape++;
	
	}

	
	}
	// fermeture des mains
	if(etape==2 && fermeture_main>0.19)
    {etape++;}
	else if(etape==2 && fermeture_main<0.20)
	{
   	   fermeture_main+=0.02;
		yS+=0.01;
	}
	

if(etape==3 && rotation_droite>42)
    {etape++;}
	else if(etape==3 && rotation_droite<50)
	{
	 rotation_droite+=2;
	xS-=0.024;
	zS-=0.0055;
   	
	}
	// ouverture des mains
	
	if(etape==4 && ouverture_main>0.19)
		    {etape++;}
	else if(etape==4 && ouverture_main<0.2)
	{
   	   ouverture_main+=0.02;
		yS-=0.01;
	}
	 
	
	if(etape==5)
	{
		scale_bras-=0.5/20;
	if (scale_bras <= 1.) etape++;

      }
    glutPostRedisplay();

}
}

//fonction qui affiche et fait l'animation du robot
void AffichageAnimationRobots()
{
 
      
  glTranslatef(xT,yT,zT);
  glRotatef(90.,0.,1.,0.);
  glScalef(0.15, 0.19, 0.15);
  
  glPushMatrix();
  Creer_Robot();
  glPopMatrix(); 

}


void murSolPlafond()
{
  
  //sol
  glPushMatrix();
  glColor3f(1.,1.,1.);
  glScalef(4., 0.04, 2);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[2]); 
  glEnable(GL_TEXTURE_2D);
  cubeT(1.);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);
  
  glColor3f(0.5,0.5,0.5);
  
  //les murs
  glPushMatrix();
  glTranslatef(0., 2., -2.);
  glRotatef(90.,1.,0.,0.);
  glScalef(4., 0.04, 2);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[0]); 
  glEnable(GL_TEXTURE_2D);
  cubeT(1.);
  glPopMatrix(); 
  glDisable(GL_TEXTURE_2D);

  glPushMatrix();
  glTranslatef(4., 2.,0);
  glRotatef(90.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(2., 0.04, 2);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[0]); 
  glEnable(GL_TEXTURE_2D);
  cubeT(1.);
  glPopMatrix(); 
   glDisable(GL_TEXTURE_2D);
   
  glPushMatrix();
  glTranslatef(-4., 2.,0);
  glRotatef(90.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(2., 0.04, 2);
  glBindTexture(GL_TEXTURE_2D, ObjTexture[0]); 
  glEnable(GL_TEXTURE_2D);
  cubeT(1.);
  glPopMatrix(); 
	glDisable(GL_TEXTURE_2D);
  
}



void affichageScene()
{
  
  
  CatmullRom();
  murSolPlafond();
  
 // table
 glPushMatrix();
	table();
	glPopMatrix();
	
  //chaise 1
  glPushMatrix();
  glTranslatef(0.5,0.5,0.65);
  glRotatef(-40.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(4,4,4);
  chaise();
  glPopMatrix();

  //chaise 2
  glPushMatrix();
  glTranslatef(-0.4,0.5,0.7);
  glRotatef(-60.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(4,4,4);
  chaise();
  glPopMatrix();
  
  
  //chaise 1
  glPushMatrix();
  glTranslatef(0.4,0.5,-0.72);
  glRotatef(-240.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(4,4,4);
  chaise();
  glPopMatrix();
  
  //chaise 2
  glPushMatrix();
  glTranslatef(-0.4,0.5,-0.65);
  glRotatef(-220.,0.,1.,0.);
  glRotatef(90.,1.,0.,0.);
  glScalef(4,4,4);
  chaise();
  glPopMatrix();
  
  //1er carton
  glPushMatrix();
  glScalef(0.3,0.3,0.3);
  glTranslatef(5.,0.5,0.);
  carton(1);
  glPopMatrix();
  
  //2eme carton
  glPushMatrix();
  glScalef(0.3,0.3,0.3);
  glTranslatef(-5.,0.5,-4.);
  carton(2);
  glPopMatrix();
  
  
  //3eme carton
  glPushMatrix();
  glScalef(0.3,0.3,0.3);
  glTranslatef(6.,0.5,-5.);
  carton(1);
  glPopMatrix();
  
  
  //4eme carton
  glPushMatrix();
  glScalef(0.3,0.3,0.3);
  glTranslatef(-5.,0.5,5.);
  carton(2);
  glPopMatrix();
  
  //lampe
  glPushMatrix();
  glTranslatef(-0.5,0.86,0.);
  lampe(); 
  glPopMatrix();
  
  //theiere
  glPushMatrix();
  glTranslatef(-0.5,0.93,-0.2);
  theiere(0.1);
  glPopMatrix();
  
  //tasse 1
  glPushMatrix();
  glTranslatef(-0.4,0.93,0.4);
  glRotatef(180.,1.,0.,0.);
  tasse();
  glPopMatrix();
  
  
  //tasse 2
  glPushMatrix();
  glTranslatef(0.4,0.93,0.4);
  glRotatef(180.,1.,0.,0.);
  tasse();
  glPopMatrix();
  
  
  
  //tasse 3
  glPushMatrix();
  glTranslatef(-0.4,0.93,-0.4);
  glRotatef(180.,1.,0.,0.);
  tasse();
  glPopMatrix();
  
  //tasse 4
  glPushMatrix();
  glTranslatef(0.4,0.93,-0.4);
  glRotatef(180.,1.,0.,0.);
  tasse();
  glPopMatrix();
  
  //livres 
  glPushMatrix();
  glTranslatef(0.,0.87,0.0);
  glScalef(0.1, 0.1, 0.1);
  livre();
  glPopMatrix();
  
  
  glPushMatrix();
  glTranslatef(0.0,0.89,0.0);
  glScalef(0.06, 0.06, 0.06);
  livre();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-0.11,0.90,0.0);
  glRotatef(20.,0.,0.,1.);
  glRotatef(20.,0.,1.,0.);
  glScalef(0.08, 0.08, 0.08);
  livre();
  glPopMatrix();

  //sucre 1
  glPushMatrix();
  glTranslatef(xS,yS,zS);
  sucre();
  glPopMatrix();

  //sucre 2
  glPushMatrix();
  glTranslatef(0.3,0.86,-0.3);
  sucre();
  glPopMatrix();
  
  //assiette
  glPushMatrix();
  glTranslatef(0.4,0.86,0.0);
  glScalef(0.1, 0.1, 0.1);
  glRotatef(-90.,1.,0.,0.);
  assiette();
  glPopMatrix();
  
   
    //truffes
  glPushMatrix();
  glTranslatef(0.32,0.9,0.1);
  glScalef(0.015, 0.015, 0.009);
  glRotatef(-90.,1.,0.,0.);
  truffes();
  glPopMatrix();
  
    glPushMatrix();
  glTranslatef(0.35,0.9,0.1);
  glScalef(0.015, 0.015, 0.009);
  glRotatef(-90.,1.,0.,0.);
  truffes();
  glPopMatrix();
  
    glPushMatrix();
  glTranslatef(0.39,0.9,0.1);
  glScalef(0.015, 0.015, 0.009);
  glRotatef(-90.,1.,0.,0.);
  truffes();
  glPopMatrix();
  
   glPushMatrix();
  glTranslatef(0.43,0.9,0.1);
  glScalef(0.015, 0.015, 0.009);
  glRotatef(-90.,1.,0.,0.);
  truffes();
  glPopMatrix();

//donuts
     //donuts 1
  glPushMatrix();
  glTranslatef(0.32,0.92,-0.06);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(-70.,1.,0.,0.);
  donuts();
  glPopMatrix();
    // donuts 2
  glPushMatrix();
  glTranslatef(0.4,0.93,-0.06);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(-90.,1.,0.,0.);
  donuts();
  glPopMatrix();
      // donuts 3
  glPushMatrix();
  glTranslatef(0.48,0.93,-0.05);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(-100.,1.,0.,0.);
  donuts();
  glPopMatrix();
  
	//tuiles
	// tuile 1
  glPushMatrix();
  glTranslatef(0.4,0.98,0.15);
  glScalef(0.03, 0.03, 0.03);
  glRotatef(60.,1.,0.,0.);
  tuiles();
  glPopMatrix(); 
  
          //tuile 2
  
  glPushMatrix();
  glTranslatef(0.3,0.98,0.15);
  glScalef(0.03, 0.03, 0.03);
  glRotatef(60.,1.,0.,0.);
  tuiles();
  glPopMatrix(); 
  
        //tuile 3
  
  glPushMatrix();
  glTranslatef(0.35,0.98,0.15);
  glScalef(0.03, 0.03, 0.03);
  glRotatef(60.,1.,0.,0.);
  tuiles();
  glPopMatrix();
  
	
  
 AffichageAnimationRobots();
  

}

