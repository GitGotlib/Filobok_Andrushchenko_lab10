#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pole.h"
int main(int argc, char **argv) {
	struct _Pole *dane = malloc(sizeof(Pole));

	if(dane == NULL) {
		fprintf(stderr, "Błęd wydzielenia pamięci\n");
			return 1;
	}

	dane->k = argc > 1 ? atoi(argv[1]) : 10; //ustawienie liczby kolumn
	dane->w = argc > 2 ? atoi(argv[2]) : 10; //wiersz
	dane->il = argc > 3 ? atoi(argv[3]) : 20; //ilość kroków
	dane->kier = argc > 4 ? strdup(argv[4]) : strdup("r"); //ustawienie kierunku r -right itd.
	dane->opcja = argc > 5 ? strdup(argv[5]) : strdup("los"); // użytkownik wybiera opcje: dodać swój plik do wczytania pola, lub zainicjować losowy	
	if (dane->kier == NULL || dane->opcja == NULL) {
		fprintf(stderr, "Błęd wydzielenia pamięci");
		free(dane->kier);
		free(dane->opcja);
		free(dane);
		return 1;
	}

	printf("%d %d %s %s \n", dane->k, dane->w, dane->opcja, dane->kier);
	matrix(dane);
	ppole(dane);
	
	
	free(dane->kier);
	free(dane->opcja);
	free(dane);
	
	return 0;
}
