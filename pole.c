#include "pole.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANSI_GREEN_TEXT       "\x1b[32m"
#define ANSI_BACKGROUND_BLACK "\x1b[30m"
#define ANSI_BACKGROUND_WHITE "\x1b[47m"
#define ANSI_RESET            "\x1b[0m"

void matrix(Pole *dane) { // pole w postaci 0 i 1 dla programowania ruchu, gdzie 0 - czarny kwadrat, a 1 - biały
        int i, j;
        dane->v = (int **)malloc(dane->w * sizeof(int *));

        for( i = 0; i < dane->w; i++) {
	                 dane->v[i] = (int *)malloc(dane->k * sizeof(int));
			 for(j = 0; j < dane->k; j++) {
				 dane->v[i][j] = 0; 
			 }
	         }
}	
void ppole(Pole *dane) {
	int i, j;
	int *idi, *idj; // wskażnik dla i oraz j ( id i ) itd.
	printf(ANSI_GREEN_TEXT "\u250C");
	for (i = 0; i < dane->k; i++) {
		printf("\u2500");
	}
	printf("\u2510\n");
	for (i = 0; i < dane->w; i++) {
		printf("\u2502");
		for (j = 0; j < dane->k; j++) {
			if(i == dane->y && j == dane->x) {
				j++;
				idi = &i;
				idj = &j;
				move(dane);
				goto next;		
			} else {
				if (dane->v[i][j] == 0) {	
					printf(ANSI_BACKGROUND_BLACK " "ANSI_RESET ANSI_GREEN_TEXT );
				}
				else if (dane->v[i][j] == 1) {
					 printf(ANSI_BACKGROUND_WHITE " "ANSI_RESET ANSI_GREEN_TEXT ); 
				}
				else {
					fprintf(stderr, "Błąd w macierzy");
				}
			}
		}
		printf(ANSI_GREEN_TEXT "\u2502\n");
	}
	next: {
		      for (j = *idj; j < dane->k; j++) {
			      i = *idi;
			      if (dane->v[i][j] == 0) {
				      printf(ANSI_GREEN_TEXT ANSI_BACKGROUND_BLACK " "ANSI_RESET ANSI_GREEN_TEXT );
			      }
			      else if (dane->v[i][j] == 1) {
				      printf(ANSI_GREEN_TEXT ANSI_BACKGROUND_WHITE " "ANSI_RESET ANSI_GREEN_TEXT );
			      }
			      else {
				      fprintf(stderr, "Błąd w macierzy");
			      }
		      }
		      printf(ANSI_GREEN_TEXT "\u2502\n");
		      i++;
		      idi = &i;
	        for (i = *idi; i < dane->w; i++) {
			printf(ANSI_GREEN_TEXT "\u2502");
			for (j = 0; j < dane->k; j++) {
				if (dane->v[i][j] == 0) {
					printf(ANSI_BACKGROUND_BLACK " "ANSI_RESET);
					}
				else if (dane->v[i][j] == 1) {
					printf(ANSI_BACKGROUND_WHITE " "ANSI_RESET);
				}
				else {
					fprintf(stderr, "Błąd w macierzy");
				}
			}
			printf(ANSI_GREEN_TEXT "\u2502\n");
		}
	      }

	printf(ANSI_GREEN_TEXT "\u2514");
	for (i = 0; i < dane->k; i++) {
		printf("\u2500");
	}
	printf("\u2518\n" ANSI_RESET);
/*	        for(i = 0; i < dane->w; i++) {
			printf("\n");
	                for(j = 0; j < dane->k; j++) {
                                printf("%d", dane->v[i][j]);
			}
		}
		printf("\n");*/
}
void pm1x1(int il) {
	int i;
	for(i = 0; i < il; i++) {
		printf(ANSI_GREEN_TEXT "\u250C\u2500\u2510\n");
		printf("\u2502");
		if(i % 2 == 1) {
			printf(ANSI_BACKGROUND_BLACK " "ANSI_RESET);
		} else {
			printf(ANSI_BACKGROUND_WHITE " "ANSI_RESET);
		}
		printf(ANSI_GREEN_TEXT "\u2502\n");
		printf(ANSI_GREEN_TEXT "\u2514\u2500\u2518\n" ANSI_RESET);
	}
}

