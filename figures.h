#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 


void cylindre (double r, double h);
void sphere (float rayon,int nlat,int nlon);
void cube (float c);
void cubeT(float c);
void theire (float taille);
void hyperboloide (float r, float h, int N, float alpha);
void ellipsoide ();
void tore (float r, float R, int demi);  // avec barre
void tore2 (float r, float R, int demi); // sans barre
void tore3 (float r, float R, int demi); // pour tuiles
void cone (float r,float h);
<<<<<<< HEAD
=======
//void Ellipsoloide(float radiusX, float radiusY);
//const float DEG2RAD = 3.14159/180.0;


/*void Ellipsoloide(float xradius, float radiusY)
{
  int i;
  
  glBegin(GL_LINE_LOOP);
  
  for(int i=0; i < 360; i++)
  {
    //convert degrees into radians
    float degInRad = i*DEG2RAD;
    glVertex2f(cos(degInRad)*xradius,sin(degInRad)*radiusY);
  } 
  glEnd();
}*/

>>>>>>> V1.2_A
//construction ellipsoide
void cone (float r,float h)
{glutSolidCone(r,h, 20,20);}



//construction ellipsoide
void ellipsoide ()
{}

//construction hyperboloide
void hyperboloide (float r, float h, int N, float alpha)
{
 
  // tableau des sommets
  float X[100];
  float Y[100];
  float Z[100];
  
  // tableau des Faces
  int Face[100][4];
  int FaceN[100][3];
  int FaceS[100][3];
  
    float  theta =0.0, dtheta= 2*M_PI/N;
    for (int i = 0; i < N; i++)
    {
      
      X[i]=r*sin(theta);
      Y[i]= h*-1;
      Z[i]=r*cos(theta);
      
      X[i+N]=r*sin(theta + alpha);
      Y[i+N]=h* 1;
      Z[i+N]=r*cos(theta + alpha);
      
      theta= theta + dtheta;
    }
    
    // POle Nord
    X[2*N]= 0;
    Y[2*N]= h*-1;
    Z[2*N]= 0;
    
    // Pole Sudf
    X[2*N+1]= 0;
    Y[2*N+1]= h*1;
    Z[2*N+1]= 0;
    
    //Pour les faces
    // Pour les faces avant
    for (int i = 0; i < N; i++)
    {
      
      
      Face[i][0]=i;
      Face[i][1]=(i+1)%N;
      Face[i][2]=(i+1)%N+N;
      Face[i][3]=i+N;
    }
    //Pole Nord
    for (int i = 0; i < N; i++)
    {
      
      FaceN[i][0]=i;
      FaceN[i][1]=2*N;
      FaceN[i][2]=(i+1)%N;
    }
    
    // Pole Sud
    for (int i = N-1; i>=0; i--)
    {
      
      FaceS[i][0]=(i+1)%N+N;
      FaceS[i][1]=2*N;
      FaceS[i][2]=i+N;
      
    }
  
  /* Dessin des quadriques*/
  for( int i=0; i< N ; i++)
  {
    
    glBegin(GL_QUADS);
    //glColor3f(1,0,1);
    glVertex3f(X[Face[i][0]],Y[Face[i][0]],Z[Face[i][0]]);
    glVertex3f(X[Face[i][1]],Y[Face[i][1]],Z[Face[i][1]]);
    //glColor3f(1,1,0);
    glVertex3f(X[Face[i][2]],Y[Face[i][2]],Z[Face[i][2]]);
    glVertex3f(X[Face[i][3]],Y[Face[i][3]],Z[Face[i][3]]);
    glEnd();
  }
  /* Dessin des triangles Pole Nord*/
  
 /* for( int i=0; i< N ; i++)
  {
    
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,1);
    glVertex3f(X[FaceN[i][0]],Y[FaceN[i][0]],Z[FaceN[i][0]]);
    glVertex3f(0,h*-1,0);
    glColor3f(1,1,0.5);
    glVertex3f(X[FaceN[i][2]],Y[FaceN[i][2]],Z[FaceN[i][2]]);
    glEnd();
    
  }*/
  /* Dessin des triangles Pole SUD*/
  
  for( int i=0; i< N ; i++)
  {
    
    glBegin(GL_TRIANGLES);
    //glColor3f(1,1,0);
    glVertex3f(X[FaceS[i][0]],Y[FaceS[i][0]],Z[FaceS[i][0]]);
    glVertex3f(0,h*1,0);
    //glColor3f(0,1,1);
    glVertex3f(X[FaceS[i][2]],Y[FaceS[i][2]],Z[FaceS[i][2]]);
    glEnd();
    
    
  }
  
  
  
}

//construction tore
//demi =1 alors tore entier
//demi =2 alors demi tore

void tore (float r, float R, int demi)
{
  
  const int NM=24;// nombre de cercles
  const int NP=6;// nombre de cotés
  
  float CordX[NM*NP];
  float CordY[NM*NP];//
  float CordZ[NM*NP];
  int TabCor[NM*NP][4];
    
    //float r= 0.2, R=1.0;
    
    float phiT=0, dphiT=2*M_PI/NP;
    float thetaT=0;
    float dThetaT=2*M_PI/NM/demi;
    // indice des sommets
    for (int i = 0; i <=NM-1 ; i++)
    {
      for(int j=0;j <=NP-1; j++){
        
        
        CordX[i*NP+j]=(R+r*cos(j*dphiT+phiT))*sin(i*dThetaT+thetaT);
        CordY[i*NP+j]=r*sin(j*dphiT+phiT);
        CordZ[i*NP+j]=(R+r*cos(j*dphiT+phiT))*cos(i*dThetaT+thetaT);
      }
    }
    //indices des faces
    
    for (int i = 0; i <=NM-1 ; i++)
    {
      for(int j=0;j <=NP-1; j++)
      {
        TabCor[i*NP+j][0]=i*NP+j;
        TabCor[i*NP+j][1]=((i+1)%NM)*NP+j;
        TabCor[i*NP+j][2]=((i+1)%NM)*NP+((j+1)%NP);
        TabCor[i*NP+j][3]=i*NP+((j+1)%NP);
      }
      
    }
  
  
  
    glRotatef(90,1.0,0.0,0.0);
    for(int i=0;i<=(NM-1);i++)
    {
      for(int j=0; j<=NP-1;j++)
      {
<<<<<<< HEAD
     
=======
     //   glColor3f(0.5,1.0,1.0);
>>>>>>> V1.2_A
        glBegin(GL_QUADS);

     glTexCoord2f(thetaT/(2*M_PI),phiT/(2*M_PI));

    glVertex3f(CordX[TabCor[i*NP+j][0]],CordY[TabCor[i*NP+j][0]],CordZ[TabCor[i*NP+j][0]]);

  glTexCoord2f(dThetaT/(2*M_PI),phiT/(2*M_PI));
        glVertex3f(CordX[TabCor[i*NP+j][1]],CordY[TabCor[i*NP+j][1]],CordZ[TabCor[i*NP+j][1]]);
    
  glTexCoord2f(dThetaT/(2*M_PI),dphiT/(2*M_PI));
        glVertex3f(CordX[TabCor[i*NP+j][2]],CordY[TabCor[i*NP+j][2]],CordZ[TabCor[i*NP+j][2]]);

  glTexCoord2f(thetaT/(2*M_PI),dphiT/(2*M_PI));
        glVertex3f(CordX[TabCor[i*NP+j][3]],CordY[TabCor[i*NP+j][3]],CordZ[TabCor[i*NP+j][3]]);

        glEnd();
      }
  }
  
    
}


//construction tore
//demi =1 alors tore entier
//demi =2 alors demi tore
void tore2 (float r, float R, int demi)
{
  
  const int NM=24;// nombre de cercles
  const int NP=6;// nombre de cotés
  
  float CordX[NM*NP];
  float CordY[NM*NP];//
  float CordZ[NM*NP];
  int TabCor[NM*NP][4];
    
    //float r= 0.2, R=1.0;
    
    float phiT=0, dphiT=2*M_PI/NP;
    float thetaT=0;
    float dThetaT=2*M_PI/NM/demi;
    // indice des sommets
    for (int i = 0; i <=NM-1 ; i++)
    {
      for(int j=0;j <=NP-1; j++){
        
        
        CordX[i*NP+j]=(R+r*cos(j*dphiT+phiT))*sin(i*dThetaT+thetaT);
        CordY[i*NP+j]=r*sin(j*dphiT+phiT);
        CordZ[i*NP+j]=(R+r*cos(j*dphiT+phiT))*cos(i*dThetaT+thetaT);
      }
    }
    //indices des faces
    
    for (int i = 0; i <=NM-1 ; i++)
    {
      for(int j=0;j <=NP-1; j++)
      {
        TabCor[i*NP+j][0]=i*NP+j;
        TabCor[i*NP+j][1]=((i+1)%NM)*NP+j;
        TabCor[i*NP+j][2]=((i+1)%NM)*NP+((j+1)%NP);
        TabCor[i*NP+j][3]=i*NP+((j+1)%NP);
      }
      
    }
  
  
  
    glRotatef(90,1.0,0.0,0.0);
    for(int i=0;i<=(NM-1)/demi;i++)
    {
      for(int j=0; j<=NP-1;j++)
      {
<<<<<<< HEAD
        
=======
        //glColor3f(0.5,1.0,1.0);
>>>>>>> V1.2_A
        glBegin(GL_QUADS);

        glTexCoord2f(thetaT/(2*M_PI),phiT/(2*M_PI));

        glVertex3f(CordX[TabCor[i*NP+j][0]],CordY[TabCor[i*NP+j][0]],CordZ[TabCor[i*NP+j][0]]);

        glTexCoord2f(dThetaT/(2*M_PI),phiT/(2*M_PI));

        glVertex3f(CordX[TabCor[i*NP+j][1]],CordY[TabCor[i*NP+j][1]],CordZ[TabCor[i*NP+j][1]]);

         glTexCoord2f(dThetaT/(2*M_PI),dphiT/(2*M_PI));

        glVertex3f(CordX[TabCor[i*NP+j][2]],CordY[TabCor[i*NP+j][2]],CordZ[TabCor[i*NP+j][2]]);

        glTexCoord2f(thetaT/(2*M_PI),dphiT/(2*M_PI));

        glVertex3f(CordX[TabCor[i*NP+j][3]],CordY[TabCor[i*NP+j][3]],CordZ[TabCor[i*NP+j][3]]);

        glEnd();
      }
    
    
  }
  
    
}


//construction tore
//demi =1 alors tore entier
//demi =2 alors demi tore
void tore3 (float r, float R, int demi)
{
  
  const int NM=50;// nombre de cercles
  const int NP=25;// nombre de cotés
  
  float CordX[NM*NP];
  float CordY[NM*NP];//
  float CordZ[NM*NP];
  int TabCor[NM*NP][4];
  
  //float r= 0.2, R=1.0;
  
  float phiT=0, dphiT=2*M_PI/NP;
  float thetaT=0;
  float dThetaT=2*M_PI/NM/demi;
  // indice des sommets
  for (int i = 0; i <=NM-1 ; i++)
  {
    for(int j=0;j <=NP-1; j++){
      
      
      CordX[i*NP+j]=(R+r*cos(j*dphiT+phiT))*sin(i*dThetaT+thetaT);
      CordY[i*NP+j]=r*sin(j*dphiT+phiT);
      CordZ[i*NP+j]=(R+r*cos(j*dphiT+phiT))*cos(i*dThetaT+thetaT);
    }
  }
  //indices des faces
  
  for (int i = 0; i <=NM-1 ; i++)
  {
    for(int j=0;j <=NP-1; j++)
    {
      TabCor[i*NP+j][0]=i*NP+j;
      TabCor[i*NP+j][1]=((i+1)%NM)*NP+j;
      TabCor[i*NP+j][2]=((i+1)%NM)*NP+((j+1)%NP);
      TabCor[i*NP+j][3]=i*NP+((j+1)%NP);
    }
    
  }
  
  
  
  glRotatef(90,1.0,0.0,0.0);
  for(int i=0;i<=(NM-1)/demi;i++)
  {
    for(int j=0; j<=(NP-1)/2;j++)
    {
<<<<<<< HEAD
      
      glBegin(GL_QUADS);

       glTexCoord2f(thetaT/(2*M_PI),phiT/(2*M_PI));

      glVertex3f(CordX[TabCor[i*NP+j][0]],CordY[TabCor[i*NP+j][0]],CordZ[TabCor[i*NP+j][0]]);

      glTexCoord2f(dThetaT/(2*M_PI),phiT/(2*M_PI));

      glVertex3f(CordX[TabCor[i*NP+j][1]],CordY[TabCor[i*NP+j][1]],CordZ[TabCor[i*NP+j][1]]);

       glTexCoord2f(dThetaT/(2*M_PI),dphiT/(2*M_PI));
      glVertex3f(CordX[TabCor[i*NP+j][2]],CordY[TabCor[i*NP+j][2]],CordZ[TabCor[i*NP+j][2]]);

      glTexCoord2f(thetaT/(2*M_PI),dphiT/(2*M_PI));

      glVertex3f(CordX[TabCor[i*NP+j][3]],CordY[TabCor[i*NP+j][3]],CordZ[TabCor[i*NP+j][3]]);

=======
      //glColor3f(0.5,1.0,1.0);
      glBegin(GL_QUADS);
      glVertex3f(CordX[TabCor[i*NP+j][0]],CordY[TabCor[i*NP+j][0]],CordZ[TabCor[i*NP+j][0]]);
      glVertex3f(CordX[TabCor[i*NP+j][1]],CordY[TabCor[i*NP+j][1]],CordZ[TabCor[i*NP+j][1]]);
      glVertex3f(CordX[TabCor[i*NP+j][2]],CordY[TabCor[i*NP+j][2]],CordZ[TabCor[i*NP+j][2]]);
      glVertex3f(CordX[TabCor[i*NP+j][3]],CordY[TabCor[i*NP+j][3]],CordZ[TabCor[i*NP+j][3]]);
>>>>>>> V1.2_A
      glEnd();
    }
    
    
  }
  
  
}

<<<<<<< HEAD


=======
>>>>>>> V1.2_A
//construction theire
void theire (float taille)
{
  glutSolidTeapot(taille);
} 

//construction cylindre
void cylindre (double r, double h)
{
glutSolidCylinder(r,h,20,20);
}

<<<<<<< HEAD
//construction sphere  modifier(fonctionne)

void sphere(float rayon,int nlat,int nlon) 
{
  float fi, theta, incr_fi, incr_theta, D, theta1, fi1, D1;
    int i,j;
  incr_theta = 2.0*M_PI/nlat;
  incr_fi = M_PI/nlon;
  theta=0;
  glBegin(GL_QUADS);
    for(i=0; i<nlat; i++){
      theta1 = theta+incr_theta;
      fi=0;
      for(j=0; j<nlat; j++){
        fi1=fi + incr_fi;
        D= rayon*sin(fi);
        D1=rayon*sin(fi1);

//        coordonnées de texture ici
          glTexCoord2f(theta/(2*M_PI),fi/(M_PI));
        glVertex3f(D*cos(theta), D*sin(theta), rayon*cos(fi));

//        coordonnées de texture ici
          glTexCoord2f(theta1/(2*M_PI),fi/(M_PI));
        glVertex3f(D*cos(theta1), D*sin(theta1), rayon*cos(fi));
  
//        coordonnées de texture
          glTexCoord2f(theta1/(2*M_PI),fi1/(M_PI));
        glVertex3f(D1*cos(theta1), D1*sin(theta1), rayon*cos(fi1));

//        coordonnées de texture
          glTexCoord2f(theta/(2*M_PI),fi1/(M_PI));
        glVertex3f(D1*cos(theta), D1*sin(theta), rayon*cos(fi1));

        fi += incr_fi;
      }
      theta +=incr_theta;
    }
  glEnd();
=======
//construction sphere (fonctionne)
void sphere(float rayon,int nlat,int nlon) 
{		  float tx1, ty1;
  for ( int i = 0 ; i < nlat ; i++ ) 
  {
    float a1 = -M_PI/2.0F + i*M_PI/nlat ;
    float a2 = a1 + M_PI/nlat ;
    float cs1 = cos(a1);
    float cs2 = cos(a2);
    float sn1 = sin(a1);
    float sn2 = sin(a2);
    glBegin(GL_QUAD_STRIP);
    for ( int j = 0 ; j <= nlon ; j++ ) {
      float a = j*2*M_PI/nlon;
      float cs = cos(a);
      float sn = sin(a);
      float x1 = cs1*cs;
      float z1 = cs1*sn;
      float x2 = cs2*cs;
      float z2 = cs2*sn;
      glNormal3f(x1,sn1,z1);
      glVertex3f(rayon*x1,rayon*sn1,rayon*z1);
      glNormal3f(x2,sn2,z2);
      glVertex3f(rayon*x2,rayon*sn2,rayon*z2); }
    glEnd(); }
>>>>>>> V1.2_A
}



/*//construction cube (fonctionne)
void cube(float c)
{
  
  glPushMatrix();
  glNormal3f(0.0F,0.0F,1.0F);
  glBegin(GL_QUADS);
  { glNormal3f(0.0F,0.0F,-1.0F);
      glVertex3f(c,c,-c);
      glVertex3f(c,-c,-c);
      glVertex3f(-c,-c,-c);
      glVertex3f(-c,c,-c); }
      { glNormal3f(0.0F,0.0F,1.0F);
      glVertex3f(c,c,c);
      glVertex3f(-c,c,c);
      glVertex3f(-c,-c,c);
      glVertex3f(c,-c,c); }
      { glNormal3f(-1.0F,0.0F,0.0F);
      glVertex3f(-c,c,-c);
      glVertex3f(-c,-c,-c);
      glVertex3f(-c,-c,c);
      glVertex3f(-c,c,c); }
      { glNormal3f(1.0F,0.0F,0.0F);
      glVertex3f(c,c,c);
      glVertex3f(c,-c,c);
      glVertex3f(c,-c,-c);
      glVertex3f(c,c,-c); }
      { glNormal3f(0.0F,-1.0F,0.0F);
      glVertex3f(-c,-c,c);
      glVertex3f(-c,-c,-c);
      glVertex3f(c,-c,-c);
      glVertex3f(c,-c,c); }
      { glNormal3f(0.0F,1.0F,0.0F);
      glVertex3f(c,c,c);
      glVertex3f(c,c,-c);
      glVertex3f(-c,c,-c);
      glVertex3f(-c,c,c); }
  glEnd();
  glPopMatrix();
  
}*/

//construction cube (fonctionne) avec coordonnes Textures
void cubeT(float c)
{      glColor3f(1.,1.,1.);
      glPushMatrix();
   //glNormal3f(0.0F,0.0F,1.0F);
   
    glBegin(GL_POLYGON);
    glNormal3f(0.0F,0.0F,-1.0F);
       glTexCoord2f(0.,0.);glVertex3f(c,c,-c);
       glTexCoord2f(0.,1.);glVertex3f(c,-c,-c);
       glTexCoord2f(1.,0.);glVertex3f(-c,-c,-c);
       glTexCoord2f(1.,1.);glVertex3f(-c,c,-c);
      glEnd();
      
       glBegin(GL_POLYGON);
        glNormal3f(0.0F,0.0F,1.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(-c,c,c);
      glTexCoord2f(1.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(1.,1.);glVertex3f(c,-c,c); 
      glEnd();
      
      glBegin(GL_POLYGON);
       glNormal3f(-1.0F,0.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(-c,c,-c);
      glTexCoord2f(0.,1.);glVertex3f(-c,-c,-c);
      glTexCoord2f(1.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(1.,1.);glVertex3f(-c,c,c);
      glEnd(); 
      
      glBegin(GL_POLYGON);
        glNormal3f(1.0F,0.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(c,-c,c);
      glTexCoord2f(1.,0.);glVertex3f(c,-c,-c);
      glTexCoord2f(1.,1.);glVertex3f(c,c,-c);
      glEnd();  
      
       glBegin(GL_POLYGON);
      glNormal3f(0.0F,-1.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(0.,1.);glVertex3f(-c,-c,-c);
      glTexCoord2f(1.,0.);glVertex3f(c,-c,-c);
      glTexCoord2f(1.,1.);glVertex3f(c,-c,c); 
      glEnd();  
      glBegin(GL_POLYGON);
       glNormal3f(0.0F,1.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(c,c,-c);
      glTexCoord2f(1.,0.);glVertex3f(-c,c,-c);
      glTexCoord2f(1.,1.);glVertex3f(-c,c,c); 
       glEnd();
 
  glPopMatrix();

}

//construction cube (fonctionne) avec coordonnes Textures
void cubeT(float c)
{
      glPushMatrix();
   //glNormal3f(0.0F,0.0F,1.0F);
   
    glBegin(GL_POLYGON);
    glNormal3f(0.0F,0.0F,-1.0F);
       glTexCoord2f(0.,0.);glVertex3f(c,c,-c);
       glTexCoord2f(0.,1.);glVertex3f(c,-c,-c);
       glTexCoord2f(1.,0.);glVertex3f(-c,-c,-c);
       glTexCoord2f(1.,1.);glVertex3f(-c,c,-c);
      glEnd();
      
       glBegin(GL_POLYGON);
        glNormal3f(0.0F,0.0F,1.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(-c,c,c);
      glTexCoord2f(1.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(1.,1.);glVertex3f(c,-c,c); 
      glEnd();
      
      glBegin(GL_POLYGON);
       glNormal3f(-1.0F,0.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(-c,c,-c);
      glTexCoord2f(0.,1.);glVertex3f(-c,-c,-c);
      glTexCoord2f(1.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(1.,1.);glVertex3f(-c,c,c);
      glEnd(); 
      
      glBegin(GL_POLYGON);
        glNormal3f(1.0F,0.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(c,-c,c);
      glTexCoord2f(1.,0.);glVertex3f(c,-c,-c);
      glTexCoord2f(1.,1.);glVertex3f(c,c,-c);
      glEnd();  
      
       glBegin(GL_POLYGON);
      glNormal3f(0.0F,-1.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(-c,-c,c);
      glTexCoord2f(0.,1.);glVertex3f(-c,-c,-c);
      glTexCoord2f(1.,0.);glVertex3f(c,-c,-c);
      glTexCoord2f(1.,1.);glVertex3f(c,-c,c); 
      glEnd();  
      glBegin(GL_POLYGON);
       glNormal3f(0.0F,1.0F,0.0F);
      glTexCoord2f(0.,0.);glVertex3f(c,c,c);
      glTexCoord2f(0.,1.);glVertex3f(c,c,-c);
      glTexCoord2f(1.,0.);glVertex3f(-c,c,-c);
      glTexCoord2f(1.,1.);glVertex3f(-c,c,c); 
       glEnd();
 
  glPopMatrix();

}
