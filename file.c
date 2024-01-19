#include <stdio.h>
#include <stdlib.h>
#include "pole.h"



char wczytanie(FILE *in, Pole *dane, int *x, int *y)
{

	char ki = ' ';
	if(in == NULL)
	{
		fprintf(stderr, "Plik nie jest wczytany");
		return ki;
	}
	
	int r = 0;
	int rr = 0;
	int w = 0;
	char c = ' ';
	while((c = fgetc(in)) != EOF)
	{
		if(c == '\n')
		{
			w++; 
			r = 0;
			continue;
		}
	
		if(c != '1' && c != '0' && c != '>' && c != '<' && c != 'v' && c != '^')
		{
			fprintf(stderr, "Nie poprawny symbol w pliku: %c\n", c);
			ki = ' ';
			return ki;
		} else if(c == ' '){
			continue;
		} else {
			if(c == '1')
			{
				if(w < dane->w && r < dane->k){
					dane->v[w][r++] = 1;
				} else {
					fprintf(stderr, "Nie poprawny format siatki w pliku. Nie zgadza się z podanym w jako argumenty wywołania formatem.\n");
					return ' ';
				}
			} else if(c == '0') {
				if(w < dane->w && r < dane->k){
					dane->v[w][r++] = 0;
				} else {
					fprintf(stderr, "Nie poprawny format siatki w pliku. Nie zgadza się z podanym w jako argumenty wywołania formatem.\n");
					return ' ';
				}
			} else {
				if(w < dane->w && r < dane->k){
					dane->v[w][r++] = 1;
				} else {
					fprintf(stderr, "Nie poprawny format siatki w pliku. Nie zgadza się z podanym w jako argumenty wywołania formatem.\n");
					return ' ';
				}
				ki = c;
				*x = w;
				*y = r-1;
			}
		} 
		rr = r;
	}
	

	if(dane->w != w || dane->k != rr)
	{
		fprintf(stderr, "Nie poprawny format siatki w pliku.\n");
		fprintf(stderr, "Podany jako argumenty wywołania format siatki: %dx%d\n", dane->w, dane->k);
		fprintf(stderr, "Format siatki w pliku: %dx%d\n", w, rr);
		ki = ' ';
	}
	
	return ki;
}




