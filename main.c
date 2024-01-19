#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "pole.h"
int main(int argc, char **argv) {
	Pole *dane = malloc(sizeof(Pole));

	if(dane == NULL) {
		fprintf(stderr, "Błęd wydzielenia pamięci\n");
			return 1;
	}
	int opt;
	while ((opt = getopt(argc, argv, "k:w:i:r:o:")) != -1) {
		switch (opt) {
			case 'k':
				dane->k = atoi(optarg);
				break;
			case 'w':
				dane->w = atoi(optarg);
				break;
			case 'i':
				dane->il = atoi(optarg);
				break;
			case 'r':
				dane->kier = strdup(optarg);
				break;
			case 'o':
				dane->opcja = strdup(optarg);
				break;
			default:
				fprintf(stderr, "Niepoprawnie wprowadzanie argumentów.\n Poprawne użycie: %s -k K -w W -i I -d D -o O\n", argv[0]);
				return 1;
		}
	}
	if (dane->k == 0) dane->k = 10; //ustawienie liczby kolumn
	if (dane->w == 0) dane->w = 10; //ustawienie liczby wierszów
	if (dane->il == 0) dane->il = 20; //ilość kroków
	if (dane->kier == NULL) dane->kier = strdup("r"); //ustawienie kierunku r -right itd.
	if (dane->opcja == NULL) dane->opcja = strdup("los"); // użytkownik wybiera opcje: dodać swój plik do wczytania pola, lub zainicjować losowy

	int il;
	if(dane->k == 1 || dane->w == 1) {
		il = dane->il;       
		goto macierz_1x1;
	}
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
macierz_1x1: {
		     pm1x1(il); //funkcja w ppole dla macierzy 1x1
	     }
	
	return 0;
}
