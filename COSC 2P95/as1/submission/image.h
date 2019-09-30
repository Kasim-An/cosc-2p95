#define _CRT_SECURE_NO_WARNINGS
#ifndef COLORIMAGE_H
#define COLORIMAGE_H

#include <stdio.h>
#include <stdlib.h>

#define byte unsigned char
#define MIN_BUFFER_SIZE 4096

/*
#define GetColor    (img.isColor)
#define GetGray(i)  (img.gray[i])
#define GetRed(i)   (img.red[i])
#define GetGreen(i) (img.green[i])
#define GetBlue(i)  (img.blue[i])
#define SetGray(i,g)  (img.gray[i] = g)
#define SetRed(i,r)   (img.red[i] = r)
#define SetGreen(i,g) (img.green[i] = g)
#define SetBlue(i,b)  (img.blue[i] = b)
#define GetByte(i)      (b.data[i])
#define SetByte(i,val)  (b.data[i] = val)
*/

#define RED 0
#define GREEN 1
#define BLUE 2

struct Image
{
  byte isColor;  // color = 1 for a color image, 0 for greyscale
  byte *gray, *red, *green, *blue;
  int NofR, NofC;

  // pointers for RGB
  byte *ptrR;
  byte *ptrG;
  byte *ptrB;
  // pointer for greyscale
  byte *ptr;
  int turn;
  int cover_bits;
  int capacity;
  int bytesEmbedded;
};

struct Buffer
{
  byte *data; // data pointer
  int size, max_size;   // true and available size
};

byte extractByte(struct Image *img);
void embedByte(struct Image *img, byte b);

unsigned getlsbs(byte b);

int ReadImage(const char *name, struct Image *Img);
int WriteImage(const char *name, struct Image Img, unsigned bytesToStore);
void PGMtoPPM(struct Image *Img);
int ReadBinaryFile(const char *name, struct Buffer *b);
int WriteBinaryFile(const char *name, struct Buffer b);

#endif