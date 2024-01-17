#ifndef _POLE_H
#define _POLE_H

typedef struct _Pole {
	int k;
	int w;
	int il;
	char *kier;
	char *opcja;
	int x, y; //współrzędne dla wyznaczenia położenia mrówki
	int **v;
} Pole;
void matrix(Pole *dane);
void ppole(Pole *dane);
void move(Pole *dane);
void pm1x1(int il);
#endif
