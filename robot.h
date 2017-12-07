#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#define Lsocle 2
#define Hsocle 0.5
#define lsocle 1
#define Lbras  2
#define Rbras  0.3
#define Lavbras 1.5
#define Ravbras 0.2
#define Lmain 0.8
#define Hmain 0.2
#define lmain 0.8
#define Ldoigt 0.8
#define Hdoigt 1
#define ldoigt 0.8
#define Rrotule 0.4
float angleRotation=90;


void Creer_Robot()
{
	//glTranslatef(-1.,0.,0.);
	glPushMatrix();
	 
    //socle cube 1
    glPushMatrix();
    glColor3f(0.3,0.3,0.9);
    glScalef(Lsocle,Hsocle,lsocle);
    cube(1.0);
    glPopMatrix();
    
    //pieds du socle
     glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(1.0,-0.6,0.7);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
    
       glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(-1.0,-0.6,-0.7);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
    
   glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(-1.0,-0.6,0.7);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
    
       glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(1.0,-0.6,-0.7);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
    
    glPopMatrix();

    //rotule 1 sphere 1
    glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(0.0,Hsocle/2+1.5*Rrotule,0.0);
    glScalef(Rrotule,Rrotule,Rrotule);
    glutSolidSphere(1.0,20,20);
    glScalef(1.0/Rrotule,1./Rrotule,1./Rrotule);
    glTranslatef(0.0,-(Hsocle/2+1.5*Rrotule),0.0);
    glPopMatrix();

   //avant bras cylindre 1
    glPushMatrix();
    glColor3f(0.5,0.3,0.7);
    glRotatef(-angleRotation,1.,0.,0.);
    glTranslatef(0.,0.,Hsocle/2+Rrotule*2+0.2);
    glutSolidCylinder(Rbras,Lbras,20,20);
    glTranslatef(0.,0.,-(Hsocle/2+Rrotule*2+0.2));
    glRotatef(angleRotation,1.,0.,0.);
    glPopMatrix();
    
            
     // coude rotule 2 sphere 2          
    glPushMatrix();
    glColor3f(0.3,0.7,0.7);
    glTranslatef(0.0,Hsocle/2+Rrotule*3+Lbras,0.0);
    glScalef(Rrotule,Rrotule,Rrotule);
    glutSolidSphere(1.0,20,20);
    glScalef(1.0/Rrotule,1./Rrotule,1./Rrotule);
    glTranslatef(0.,-(Hsocle/2+Rrotule*3+Lbras),0.);
    glPopMatrix();
            
                         
    //bras cylindre 2
    glPushMatrix();
    glColor3f(0.7,0.3,0.7);
    glRotatef(-angleRotation,1.,0.,0.);
    glTranslatef(0.,0.,Hsocle/2+Rrotule*4+Lbras);
    glutSolidCylinder(Rbras,Lbras,20,20);// 
    glTranslatef(0.,0.,-(Hsocle/2+Rrotule*4+Lbras));
    glRotatef(angleRotation,1.,0.,0.);
    glPopMatrix();

	// main cube 2
	   glPushMatrix();
	   glColor3f(0.0,0.0,1.0);
        glTranslatef(0.,(Hsocle/2+Rrotule*4+Lbras*2+Hmain/2),0.0);
	   glScalef(Lmain,Hmain,lmain);
	   glutSolidCube(1.0);
       glScalef(1./Lmain,1.0/Hmain,1.0/lmain);
       glTranslatef(0.,-(Hsocle/2+Rrotule*4+Lbras*2+Hmain/2),0.0);
        glPopMatrix();

	// les deux doigts cube 3 et cube 4
	   glPushMatrix();
         glColor3f(1.0,0.0,0.0);
       glRotatef(-angleRotation,1.,0.,0.);
	   glTranslatef(0.0,(Lmain/2-Hmain/2),Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2);
       glScalef(Lmain,Hmain,lmain);
       glutSolidCube(1.0);
	   glScalef(1./Lmain,1./Hmain,1./lmain); 
	   glTranslatef(0.,-(Lmain/2 - Hmain/2),Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2);
       glRotatef(angleRotation,1.,0.,0.);
	   glPopMatrix();

	   glPushMatrix();
       glColor3f(1.0,0.0,0.0);
        glRotatef(-angleRotation,1.,0.,0.);
       glTranslatef(0.,-(Lmain/2 - Hmain/2),(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2));
       glScalef(Lmain,Hmain,lmain);
       glutSolidCube(1.0);
       glScalef(1./Lmain,1./Hmain,1./lmain);
       glTranslatef(0.,(Lmain/2 - Hmain/2),(Hsocle/2+Rrotule*4+Lbras*2+Hmain+Lmain/2));
       glRotatef(angleRotation,1.,0.,0.);
       glPopMatrix();
       
       glPopMatrix();

	
}
