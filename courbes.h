#include<stdio.h>  
#include<stdlib.h>  
#include <string.h>
#include <GL/glut.h>
#include <GL/freeglut.h>  

const int NMAX = 100000000;
int N = 11;
void CatmullRom(float s);

float Y=0.18;

float s= 0.5;


struct Point 
{
  float x,y;
  Point(float a=0, float b=0) {set(a,b);}
  void set(float a, float b) {x=a;y=b;}
};

Point P[NMAX];
Point CBPT[NMAX];
int numbersCBPT=0;

void CatmullRom()
  
{
 // points de controle
  P[0].x=-3;
  P[0].y=0;

  P[1].x=-3;
  P[1].y=0;

  P[2].x=-1.5;
  P[2].y=0.75;

  P[3].x=0.;
  P[3].y=1.5;

  P[4].x=1.5;
  P[4].y=1.5;

  P[5].x=2.;
  P[5].y=0.5;

  P[6].x=2.5;
  P[6].y=-0.5;
  
  P[7].x=1.;
  P[7].y=-0.9;
  
  P[8].x=0.7;
  P[8].y=-1.2;
  
  P[9].x=0.;
  P[9].y=-1.;

  /*glBegin(GL_POINTS);
  for( int i=0; i<10; i++)
  {
  glVertex3f(P[i].x,Y,	P[i].y);
  }
  glEnd();*/
  
  
  if(N>=3)
  {
    float MatCatR[4][4]={{-s, 2-s, s-2, s},{2*s, s-3, 3-2*s, -s},{-s, 0, s, 0},{0, 1, 0,0}};
    for(int i=0;i<N-3;i++)
    {
      
      float MatPx[4], MatPy[4];
      for(int j=0;j<4;j++)
      {
        MatPx[j]=MatCatR[j][0]*P[i].x+MatCatR[j][1]*P[i+1].x+MatCatR[j][2]*P[i+2].x+MatCatR[j][3]*P[i+3].x;
        MatPy[j]=MatCatR[j][0]*P[i].y+MatCatR[j][1]*P[i+1].y+MatCatR[j][2]*P[i+2].y+MatCatR[j][3]*P[i+3].y;
      }
      
      //glBegin(GL_LINE_STRIP);
      //glColor3f(1.0,0.0,1.0);
      float t; int k;
      for(k=0,t=0.0;k<=10;k++,t+=0.1)
      {
        float PPX=0.0,PPY=0.0;
        float vecT[4]={t*t*t, t*t, t, 1};
        for(int j=0;j<4;j++)
        {
          PPX+=vecT[j]*MatPx[j];
          PPY+=vecT[j]*MatPy[j];
        }
        CBPT[numbersCBPT].x=PPX;
        CBPT[numbersCBPT].y=PPY;
        
      numbersCBPT++;
      //glVertex3f(PPX,Y,PPY);
              }
     glEnd();

    }
    
  }
	//on lui donne sa position de fin afin de faire l'animation
        CBPT[87].x=0;
        CBPT[87].y=-1;
}
