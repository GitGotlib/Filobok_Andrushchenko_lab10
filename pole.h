#ifndef _POLE_H
#define _POLE_H

#include <stdio.h>

typedef struct _Pole {
	int k;
	int w;
	int il;
	char *kier;
	char *opcja;
	int x, y; //współrzędne dla wyznaczenia położenia mrówki
	int **v;
} Pole;	

int spr(int argc, char **argv);
void matrix(Pole *dane);
int randomp();
void matrixrand(Pole *dane, int pr);
char wczytanie(FILE *in, Pole *dane, int *x, int *y);
void ppole(Pole *dane, int pp, FILE *out);
void move(Pole *dane, FILE *out, int pp);
void pm1x1(int il);
void freePole(Pole *dane);
#endif
