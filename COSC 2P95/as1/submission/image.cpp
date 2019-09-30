#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"

byte extractByte(struct Image *img)
{
	byte b = 0;
	// if grey scale
	for (int i = 0; i < 8; i++)
	{
		b = b << 1;
		if (img->isColor == 0)
		{
			b |= getlsbs(img->ptr[0]);
			img->ptr++;
		}
		else
		{
			if (img->turn == RED)
			{
				b |= getlsbs(img->ptrR[0]);
				img->ptrR++;
			}
			else if (img->turn == GREEN)
			{
				b |= getlsbs(img->ptrG[0]);
				img->ptrG++;
			}
			else if (img->turn == BLUE)
			{
				b |= getlsbs(img->ptrB[0]);
				img->ptrB++;
			}
			img->turn = (img->turn + 1) % 3;
		}
	}
	return b;
}

void embedByte(struct Image *img, byte b)
{
	byte by = 0;
	int bit = 0;
	// if grey scale
	for (int i = 0; i < 8; i++)
	{
		bit = b >> (7-i) & 1;
		if (img->isColor == 0)
		{
			by = getlsbs(img->ptr[0]);
			if (bit)
				img->ptr[0] |= bit;
			else
				img->ptr[0] &= 0xfe;
			by = getlsbs(img->ptr[0]);
			img->ptr++;
		}
		else
		{
			if (img->turn == RED)
			{
				by = getlsbs(img->ptrR[0]);
				if (bit)
					img->ptrR[0] |= bit;
				else
					img->ptrR[0] &= 0xfe;
				by = getlsbs(img->ptrR[0]);
				img->ptrR++;
			}
			else if (img->turn == GREEN)
			{
				if (bit)
					img->ptrG[0] |= bit;
				else
					img->ptrG[0] &= 0xfe;
				img->ptrG++;
			}
			else if (img->turn == BLUE)
			{
				if (bit)
					img->ptrB[0] |= bit;
				else
					img->ptrB[0] &= 0xfe;
				img->ptrB++;
			}
			img->turn = (img->turn + 1) % 3;
		}
		//b = b >> (8-i);
	}
}

unsigned getlsbs(byte b){
	return b &= 1;
}


unsigned getmsbs(byte b){
	return b &= 128;
}

void PGMtoPPM(struct Image *img)
{
	int i;
	if (img->isColor) return;

	img->isColor = 1;
	if (img->red == NULL) img->red = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
	if (img->green == NULL) img->green = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
	if (img->blue == NULL) img->blue = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);

	for (i = 0; i < img->NofR*img->NofC; i++)
	{
		img->red[i] = img->gray[i];
		img->green[i] = img->gray[i];
		img->blue[i] = img->gray[i];
	}
	free(img->gray);
}

// Read PPM & PGM files (P2, P3, P5, P6)
int ReadImage(const char *name, struct Image *img)
{
	int i, j, pixel, k;
	FILE *fp;
	char s[256];
	int filetype, nlevels;
	byte *in;
	byte buf[4];

	if ((fp = fopen(name, "rb")) == NULL) {
		fprintf(stderr, "Could not open image file.\n");
		return 0;
	}

	if (fgets(s, 80, fp) == NULL)
	{
		fprintf(stderr, "Invalid magic number.\n");
		return 0;
	}

	if (strcmp("P2\n", s) == 0) filetype = 2;
	else if (strcmp("P3\n", s) == 0) filetype = 3;
	else if (strcmp("P5\n", s) == 0) filetype = 5;
	else if (strcmp("P6\n", s) == 0) filetype = 6;
	else {
		fprintf(stderr, "Invalid magic number.\n", name, s);
		return 0;
	}

	do{
		if (fgets(s, 80, fp) == NULL) {
			fprintf(stderr, "Invalid magic number.\n", name);
			return 0;
		}
	} while (s[0] == '#');
	sscanf(s, "%d %d", &(img->NofC), &(img->NofR));

	do{
		if (fgets(s, 80, fp) == NULL) {
			fprintf(stderr, "Invalid magic number.\n", name);
			return 0;
		}
	} while (s[0] == '#');

	sscanf(s, "%d", &nlevels);

	switch (filetype) {
	case 2:  // P2 - ascii file, gray level image
		img->isColor = 0;
		if (img->gray == NULL) img->gray = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
		k = 0;
		for (i = 0; i < img->NofR; i++)
		for (j = 0; j < img->NofC; j++) {
			fscanf(fp, "%d", &pixel);
			img->gray[k++] = pixel;
		}

		break;
	case 3:  // P3 - ascii file, color image
		img->isColor = 1;

		if (img->red == NULL) img->red = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
		if (img->green == NULL) img->green = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
		if (img->blue == NULL) img->blue = (byte *)malloc(sizeof(byte)*img->NofC*img->NofR);
		k = 0;
		for (i = 0; i < img->NofR; i++)
		for (j = 0; j < img->NofC; j++) {
			fscanf(fp, "%d", &pixel);      img->red[k] = pixel;
			fscanf(fp, "%d", &pixel);      img->green[k] = pixel;
			fscanf(fp, "%d", &pixel);      img->blue[k++] = pixel;
		}
		break;
	}

	if (img->isColor)
	{
		img->cover_bits = 3 * img->NofR * img->NofC;
	}
	else
		img->cover_bits = img->NofR * img->NofC;

	img->capacity = (img->cover_bits / 8) - 4;
	img->ptrR = img->red;
	img->ptrG = img->green;
	img->ptrB = img->blue;
	img->ptr = img->gray;
	img->turn = 0;

	// extracting first 4 bytes 
	for (int i = 0; i < 4; i++)
	{
		buf[i] = extractByte(img);
	}

	// convert to integer to get bits of data
	img->bytesEmbedded = buf[3] | buf[2] << 8 | buf[1] << 16 | buf[0] << 24;
	

	fclose(fp);
	return 1;
}

// Read binary file
int ReadBinaryFile(const char *name, struct Buffer *b)
{
	int i, j, k;
	FILE *fp;
	byte *in, *aux;

	if ((fp = fopen(name, "rb")) == NULL) {
		fprintf(stderr, "Can't open input file %s\n", name);
		return 0;
	}

	// make space for data
	//b->data = (byte *)malloc(sizeof(byte)*MIN_BUFFER_SIZE);
	b->data = new byte[MIN_BUFFER_SIZE];
	b->size = 0;
	b->max_size = MIN_BUFFER_SIZE;

	//in = (byte *)malloc(sizeof(byte)*MIN_BUFFER_SIZE);
	in = new byte[MIN_BUFFER_SIZE];
	while ((j = fread((void *)in, sizeof(byte), MIN_BUFFER_SIZE, fp)) > 0)
	{
		if ((j + b->size) > b->max_size)
		{
			//aux = (byte *)malloc(sizeof(byte)*b->max_size * 2);
			aux = new byte[b->max_size * 2];
			b->max_size *= 2;
			for (i = 0; i < b->size; i++) aux[i] = b->data[i];
			//free(b->data);
			delete[] b->data;
			b->data = aux;
		}
		for (i = 0; i < j; i++) b->data[b->size + i] = in[i];
		b->size += j;
		if (j < MIN_BUFFER_SIZE)
			break;
	}
	//free(in);
	delete[] in;
	fclose(fp);
	return 1;
}

// Write gray or color images
int WriteImage(const char *file, struct Image img, unsigned bytesToStore)
{
	int k = 0;
	FILE *fo;
	int size;
	byte buf[4];

	if ((fo = fopen(file, "wb")) == NULL) {
		fprintf(stderr, "Can't create output file \'%s\'\n", file);
		return 0;
	}

	size = img.NofC * img.NofR * 3;
	fprintf(fo, "P3\n%3d %3d\n255\n", img.NofC, img.NofR);

	buf[3] = bytesToStore;
	buf[2] = bytesToStore >> 8;
	buf[1] = bytesToStore >> 16;
	buf[0] = bytesToStore >> 24;

	int kat = buf[3] | buf[2] << 8 | buf[1] << 16 | buf[0] << 24;

	img.ptrR = img.red;
	img.ptrG = img.green;
	img.ptrB = img.blue;
	img.turn = RED;

	for (int i = 0; i < 4; i++)
	{
		embedByte(&img, buf[i]);
	}

	for (int i = 0; i < img.NofC; i++)
	{
		for (int j = 0; j < img.NofR; j++) {
			fprintf(fo,"%3d ", img.red[k]);
			fprintf(fo, "%3d ", img.green[k]);
			fprintf(fo, "%3d ", img.blue[k]);
			k++;
		}
		fprintf(fo, "\n");
	}
	fclose(fo);
	return 1;
}


// Write gray or color images
int WriteBinaryFile(const char *name, struct Buffer b)
{
	FILE *fo;

	if ((fo = fopen(name, "wb")) == NULL) {
		fprintf(stderr, "Can't create output file \'%s\'\n", name);
		return 0;
	}

	fwrite(b.data, sizeof(byte), b.size, fo);
	fclose(fo);
	return 1;
}

