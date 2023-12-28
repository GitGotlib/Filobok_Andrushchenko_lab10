#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pole.h"
int main(int argc, char **argv) {
	Pole *dane = malloc(sizeof(Pole));

	if(dane == NULL) {
		fprintf(stderr, "Błęd wydzielenia pamięci\n");
			return 1;
	}

	dane->k = argc > 1 ? atoi(argv[1]) : 10; //ustawienie liczby kolumn
	dane->w = argc > 2 ? atoi(argv[2]) : 10; //wiersz
	dane->il = argc > 3 ? atoi(argv[3]) : 20; //ilość kroków
	dane->kier = argc > 4 ? strdup(argv[4]) : strdup("r"); //ustawienie kierunku r -right itd.
	dane->opcja = argc > 5 ? strdup(argv[5]) : strdup("los"); // użytkownik wybiera opcje: dodać swój plik do wczytania pola, lub zainicjować losowy	
	dane->x = (dane->k / 2) - 1;
	dane->y = (dane->w / 2) - 1;
	if (dane->kier == NULL || dane->opcja == NULL) {
		fprintf(stderr, "Błęd wydzielenia pamięci");
		if (dane->kier != NULL) {
			free(dane->kier);
		}
		if (dane->opcja != NULL) {
			free(dane->opcja);
		}
		free(dane);
		return 1;
	}

	printf("%d %d %s %s \n", dane->k, dane->w, dane->opcja, dane->kier);
	matrix(dane);
	int i;
	for(i = 0; i < dane->il; i++) {
	ppole(dane);
	}
	if (dane->v != NULL) {
	for (int i = 0; i < dane->w; i++) {
		    free(dane->v[i]);
	}
	free(dane->v);
	}

	free(dane->kier);
	free(dane->opcja);
	free(dane);
	
	return 0;
}
