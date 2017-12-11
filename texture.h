#include<stdio.h>  
#include<stdlib.h>  
#include <GL/glut.h>
#include <GL/freeglut.h>  
#include <math.h> 
#include <jpeglib.h>
#include <jerror.h>

unsigned char image[256*256*3];
//Identifiants des textures
static GLuint ObjTexture[7];


void ChargementImages();
void loadJpegImage(char *fichier);
void ChargementImages()
{
  //Génération d'objets textures
  glGenTextures(7, ObjTexture);

  //Association de l'image dans le tableau d'idntifiant de texture
  glBindTexture(GL_TEXTURE_2D, ObjTexture[0]);
  /* Chargement de l'image */
  loadJpegImage("textures/brique1.jpg");

  glBindTexture(GL_TEXTURE_2D, ObjTexture[1]);
  loadJpegImage("textures/sucre.jpg");

  glBindTexture(GL_TEXTURE_2D, ObjTexture[2]);
  loadJpegImage("textures/sol.jpg");

   glBindTexture(GL_TEXTURE_2D, ObjTexture[3]);
  loadJpegImage("textures/cartonB.jpg");
  
  glBindTexture(GL_TEXTURE_2D, ObjTexture[4]);
  loadJpegImage("textures/bois.jpg");
	
	glBindTexture(GL_TEXTURE_2D, ObjTexture[5]);
	loadJpegImage("textures/livre.jpg");
  
	glBindTexture(GL_TEXTURE_2D, ObjTexture[6]);
	loadJpegImage("textures/boisC.jpg");
	
	
}
void loadJpegImage(char *fichier)
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE *file;
  unsigned char *ligne;

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  if ((file = fopen(fichier,"rb")) == 0)
    {
      fprintf(stderr,"Erreur : impossible d'ouvrir le fichier image.jpg\n");
      exit(1);
    }
  jpeg_stdio_src(&cinfo, file);
  jpeg_read_header(&cinfo, TRUE);

  if ((cinfo.image_width != 256) || (cinfo.image_height != 256)) {
    fprintf(stdout, "Erreur : l'image doit etre de taille 256x256\n");
    exit(1);
  }
  if (cinfo.jpeg_color_space == JCS_GRAYSCALE) {
    fprintf(stdout, "Erreur : l'image doit etre de type RGB\n");
    exit(1);
  }

  jpeg_start_decompress(&cinfo);
  ligne = image;
  while (cinfo.output_scanline<cinfo.output_height)
  {
    ligne = image + 3 * 256 * cinfo.output_scanline;
    jpeg_read_scanlines(&cinfo, &ligne, 1);
  }
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,256,256,0,GL_RGB,GL_UNSIGNED_BYTE,image);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glEnable(GL_TEXTURE_2D);
  
  }
