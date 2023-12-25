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
	         }
        for(i = 0; i < dane->w; i++) {
                printf("\n");
                for(j = 0; j < dane->k; j++) {
	                        dane->v[i][j] = 0;
		                        printf("%d", dane->v[i][j]);
			                }
        }
        printf("\n");
}	
void ppole(Pole *dane) {
	int i, j;
	printf(ANSI_GREEN_TEXT " ");
	for (i = 0; i < dane->k; i++) {
		printf("_");
	}
	printf("\n");
	for (i = 0; i < dane->w - 1; i++) {
		printf("|");
		for (j = 0; j < dane->k; j++) {
			if(i == (dane->w / 2) && j == (dane->k / 2)) {
				dane->v[i][j] = 1;
				j++;
				if (strcmp(dane->kier, "r") == 0) {
					    printf(ANSI_BACKGROUND_WHITE ">"ANSI_RESET ANSI_GREEN_TEXT );
				} else if (strcmp(dane->kier, "b") == 0) {
					    printf("V");
				} else if (strcmp(dane->kier, "l") == 0) {
					    printf("<");
				} else if (strcmp(dane->kier, "u") == 0) {
					    printf("^");
				} else {
					    fprintf(stderr, "Błąd w zaznaczeniu kierunku");
				}
			}

		printf(" ");
		}
		printf("|\n");
	}
		printf("|");
	for (i = 0; i < dane->k; i++) {
		printf("_");
	};
	printf("|\n" ANSI_RESET);
	        for(i = 0; i < dane->w; i++) {
			printf("\n");
	                for(j = 0; j < dane->k; j++) {
                                dane->v[i][j] = 0;
                                printf("%d", dane->v[i][j]);
			}
		}
		printf("\n");
}

