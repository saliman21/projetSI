#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 

float ldoigt =0.8, Lsocle =2.,Hsocle =0.5, Lbras= 2., Rbras =0.3, Ravbras=0.2, Lmain =0.8 ,Hmain=0.2,
 Rrotule =0.4, lmain=0.8, Ldoigt=0.8 , Hdoigt=1.,lsocle =1.;

float angleRotation=90;



void Creer_Robot()
{
  //socle cube 1
  glPushMatrix();
  glColor3f(0.3,0.3,0.9);
  glScalef(Lsocle,Hsocle,lsocle);
  cubeT(1.0);
  glPopMatrix();
  //pieds du socle
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(1.0,-0.6,0.7);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(-1.0,-0.6,-0.7);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(-1.0,-0.6,0.7);
  sphere(0.2,20,20);
  glPopMatrix();
  
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(1.0,-0.6,-0.7);
  sphere(0.2,20,20);
  glPopMatrix();
  
  //rotule 1 sphere 1
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(0.0,Hsocle/2+1.5*Rrotule,0.0);
  glScalef(Rrotule,Rrotule,Rrotule);
  sphere(1.0,20,20);
  glScalef(1.0/Rrotule,1./Rrotule,1./Rrotule);
  glTranslatef(0.0,-(Hsocle/2+1.5*Rrotule),0.0);
  glPopMatrix();
  
  //avant bras cylindre 1
  glPushMatrix();
  glColor3f(0.5,0.3,0.7);
  glRotatef(-angleRotation,1.,0.,0.);
  glTranslatef(0.,0.,Hsocle/2+Rrotule*2+0.2);
  cylindre(Rbras,Lbras);
  glTranslatef(0.,0.,-(Hsocle/2+Rrotule*2+0.2));
  glRotatef(angleRotation,1.,0.,0.);
  glPopMatrix();
  
  
  // coude rotule 2 sphere 2          
  glPushMatrix();
  glColor3f(0.3,0.7,0.7);
  glTranslatef(0.0,Hsocle/2+Rrotule*3+Lbras,0.0);
  glScalef(Rrotule,Rrotule,Rrotule);
  sphere(1.0,20,20);
  glScalef(1.0/Rrotule,1./Rrotule,1./Rrotule);
  glTranslatef(0.,-(Hsocle/2+Rrotule*3+Lbras),0.);
  glPopMatrix();
  
  
  //bras cylindre 2
  glPushMatrix();
  glColor3f(0.7,0.3,0.7);
  glRotatef(-angleRotation,1.,0.,0.);
  glTranslatef(0.,0.,Hsocle/2+Rrotule*4+Lbras);
  cylindre(Rbras,Lbras);// 
  glTranslatef(0.,0.,-(Hsocle/2+Rrotule*4+Lbras));
  glRotatef(angleRotation,1.,0.,0.);
  glPopMatrix();
  
  // main cube 2
  glPushMatrix();
  glColor3f(0.0,0.0,1.0);
  glTranslatef(0.,(Hsocle/2+Rrotule*4+Lbras*2+Hmain/2),0.0);
  glScalef(Lmain,Hmain,lmain);
  cubeT(1.0);
  glScalef(1./Lmain,1.0/Hmain,1.0/lmain);
  glTranslatef(0.,-(Hsocle/2+Rrotule*4+Lbras*2+Hmain/2),0.0);
  glPopMatrix();
  
  // les deux doigts cube 3 et cube 4
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glRotatef(-angleRotation,1.,0.,0.);
  glTranslatef(0.0,(Lmain/2-Hmain/2),Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2);
  glScalef(Lmain,Hmain,lmain);
  cubeT(1.0);
  glScalef(1./Lmain,1./Hmain,1./lmain); 
  glTranslatef(0.,-(Lmain/2 - Hmain/2),Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2);
  glRotatef(angleRotation,1.,0.,0.);
  glPopMatrix();
  
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glRotatef(-angleRotation,1.,0.,0.);
  glTranslatef(0.,-(Lmain/2 - Hmain/2),(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2));
  glScalef(Lmain,Hmain,lmain);
  cubeT(1.0);
  glScalef(1./Lmain,1./Hmain,1./lmain);
  glTranslatef(0.,(Lmain/2 - Hmain/2),(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2));
  glRotatef(angleRotation,1.,0.,0.);
  glPopMatrix();
  
  
}