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

void ppole(Pole *dane);
void matrix(Pole *dane);
#endif
