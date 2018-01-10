#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include <iostream>
float ldoigt =0.8, Lsocle =2.,Hsocle =0.5, Lbras= 2.2, Rbras =0.3, Ravbras=0.2, Lmain =0.8 ,Hmain=0.2,
 Rrotule =0.4, lmain=0.8, Ldoigt=0.8 , Hdoigt=1.,lsocle =1.;

//variable pour animation
float fermeture_main=0.;
float ouverture_main=0.;
float rotation_descente=0.;
float rotation_droite=0.;
float xbras=0.;
float ybras=0.;
float zbras=0.;
float scale_bras=1.;
float angleTest = .0;




void Creer_Robot()
{
  //socle cube 1
  glPushMatrix();
  //glColor3f(0.3,0.3,0.9);
  glScalef(Lsocle,Hsocle,lsocle);
  cubeT(0.7);
  glPopMatrix();
  //pieds du socle
  glPushMatrix();
  //glColor3f(0.3,0.7,0.7);
  glTranslatef(0.8,-0.6,0.5);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
 // glColor3f(0.3,0.7,0.7);
  glTranslatef(-0.8,-0.6,-0.5);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
 // glColor3f(0.3,0.7,0.7);
  glTranslatef(-0.8,-0.6,0.5);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
  //glColor3f(0.3,0.7,0.7);
  glTranslatef(0.8,-0.6,-0.5);
  sphere(0.2,20,20);
  glPopMatrix();
  
  //rotule 1 sphere 1
  glPushMatrix();
  //glColor3f(0.3,0.7,0.7);
  glTranslatef(0.0,Hsocle/2+1.5*Rrotule,0.0);
  glScalef(Rrotule,Rrotule,Rrotule);
  sphere(1.0,20,20);
  glPopMatrix();
  
  //avant bras cylindre 1
  glPushMatrix();
  //glColor3f(0.5,0.3,0.7);
  glRotatef(-90,1.,0.,0.);
  glTranslatef(0.,0.,Hsocle/2+Rrotule*2+0.2);
  cylindre(Rbras,Lbras);
  glPopMatrix();
  
  // coude rotule 2 sphere 2          
  glPushMatrix();
  glTranslatef(0.0,Hsocle/2+Rrotule*3+Lbras,0.0);
  glScalef(Rrotule,Rrotule,Rrotule);
  sphere(1.0,20,20);
    glPopMatrix();
  
  
	//bras cylindre 2
	glPushMatrix();
	glTranslatef(0,(Hsocle/2+Rrotule*4+Lbras), 0);
	glRotatef(-rotation_descente,-0.1,0.,-0.9);
	glRotatef(-rotation_droite,1.,0.,0.);
	glScalef(1.,scale_bras,1.);
	glTranslatef(0,-(Hsocle/2+Rrotule*4+Lbras), 0);
	glPushMatrix();

	//glColor3f(0.7,0.3,0.7);
	glRotatef(-90,1.,0.,0.);
	glTranslatef(0,0,Hsocle/2+Rrotule*4+Lbras);
	cylindre(Rbras,Lbras);// 
	glPopMatrix();



  // main cube 2
  glPushMatrix();
  glTranslatef(0.,(Hsocle/2+Rrotule*4+Lbras*2+Hmain/2),0.0);
  glScalef(Lmain,Hmain,lmain);
  cubeT(0.5);
  glPopMatrix();
  
  // les deux doigts cube 3 et cube 4
  glPushMatrix();
  glRotatef(-90,1.,0.,0.);
  glTranslatef(0.0,(Lmain/2-Hmain/2)-fermeture_main+ouverture_main,(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2)-0.25);
  glScalef(Lmain,Hmain,lmain);
  cubeT(0.2);
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(-90,1.,0.,0.);
  glTranslatef(0.,-(Lmain/2 - Hmain/2)+fermeture_main-ouverture_main,(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2)-0.25);
  glScalef(Lmain,Hmain,lmain);
  cubeT(0.2);
  glPopMatrix();

  glPopMatrix();
  
  
}
