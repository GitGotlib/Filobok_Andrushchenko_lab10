#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "pole.h"
int main(int argc, char **argv) {
	Pole *dane = malloc(sizeof(Pole));

	if(dane == NULL) {
		fprintf(stderr, "Błąd wydzielenia pamięci\n");
			return 1;
	}


	//int sp = spr(argc, argv);
	/*
	if(sp != 0)
	{	
		free(dane);
		return 1;
	}
	*/
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
	
	
	char **arg = malloc(sizeof *arg * 10);
	if(arg == NULL)
	{
		free(dane);
		return 0;
	}
	int ato = 5;
	for(int i = 0; i < 7; i++)
	{
		arg[i] = malloc(sizeof(char)*10);
		if(arg[i] == NULL)
		{
			free(arg);
			free(dane);
			return 1;
		}
	}


	arg[0] = argv[0];
	sprintf(arg[1], "%d", dane->w);
	sprintf(arg[2], "%d", dane->k);
	sprintf(arg[3], "%d", dane->il);
	arg[4] = strdup(dane->kier);
	arg[5] = strdup(dane->opcja);
	/*	
	dane->w = argc > 1 ? atoi(argv[1]) : 10; //ustawienie liczby kolumn
	dane->k = argc > 2 ? atoi(argv[2]) : 10; //wiersz
	dane->il = argc > 3 ? atoi(argv[3]) : 20; //ilość kroków
	dane->kier = argc > 4 ? strdup(argv[4]) : strdup("r"); //ustawienie kierunku r -right itd.
	dane->opcja = argc > 5 ? strdup(argv[5]) : strdup("los");
	*/
	int sp = spr(ato, arg);
	if(sp != 0)
        {       
                free(dane);
                return 1;
        }

	
	FILE *in;
	int w = 0;
	if(strcmp("los", arg[5]) != 0){
		in = fopen(arg[5], "r"); // użytkownik wybiera opcje: dodać swój plik do wczytania pola, lub zainicjować losowy
		w = 1;
	} else {
		printf("Czy chcesz podać plik do wczytania? (wpicz tak lub nie)\n");
		char buf[100];
		scanf("%100s", buf);
		if(strcmp(buf, "tak") == 0)
		{
			
			if(dane->w == 1 || dane->k == 1)
			{
				fprintf(stderr, "Z formatem %d x %d nie możemy pozwolić zczytanie z pliku\n", dane->w, dane->k);
				free(dane);
				
				return 1;
			}
			printf("Wpisz nazwę pliku:\n");
			scanf("%100s", buf);
			in = fopen(buf, "r");
			if(in == NULL)
			{
				for(int i = 0; i < 10; i++)
        			{
               				 free(arg[i]);
        			}

        			
				fprintf(stderr, "Plik nie został wczytany\n");
				free(dane);
				return 1;
			}
			w = 1;	
		} else if(strcmp(buf, "nie") == 0){
			w = 0;
		} else {
			fprintf(stderr, "Niepoprawna odpowiedź\n");
			
			free(dane);
			return 1;
		}
	}
	
	

	int il;
	if(dane->k == 1 || dane->w == 1) {
		il = dane->il;       
		goto macierz_1x1;
	}
	
	dane->x = (dane->k / 2) - 1;
	dane->y = (dane->w / 2) - 1;
	if (dane->kier == NULL || dane->opcja == NULL) {
		fprintf(stderr, "Błąd wydzielenia pamięci\n");
		if (dane->kier != NULL) {
			free(dane->kier);
		}
		if (dane->opcja != NULL) {
			free(dane->opcja);
		}
		free(dane);
		
		return 1;
	}


	matrix(dane);
	

	if(w == 0){
		printf("Czy chcesz mieć losowo ustawione pole czy standartowo (wprowadź losowo lub standartowo\n)");
		char buf[100];
                scanf("%100s", buf);
                if(strcmp(buf, "losowo") == 0)
                {
			char pr[100];
			printf("Wpisz procent zapełnienia planszy\n");
			scanf("%100s\n", pr);
			char *endp;
                	double x = strtod(pr, &endp);
                	int y = x*1;
                	double u = fmod(x, (double)y);
    
                	if(strlen(endp) == 0 && u == 0.0)
                	{    
                        	if(x < 0 && x > 100)
                        	{
                                	fprintf(stderr, "%s: nie poprawny procent wpisany\n", arg[0]); 
					free(dane);
                                	return 1;
                        	}
                	} else if(strlen(endp) != 0) {
                        	fprintf(stderr, "%s: podana jakaś bzdura zamiast liczby: %s\n", arg[0], pr);
                        	return 1;
                	} else if(u != 0.0){
                        	fprintf(stderr, "%s: podana jakaś zmiennoprzecinkowa liczba a nie całkowita: %s\n", arg[0], pr);
				return 1;
                	}

                        matrixrand(dane, y);
                } else if(strcmp(buf, "standartowo") == 0){ 
                       printf("\n");
                } else {
                        fprintf(stderr, "Niepoprawna odpowiedź\n");
                        freePole(dane);
			
                        return 1;
                }

	}

	if(w == 1)
	{
		
		if(dane->w == 1 || dane->k == 1)
                {
                        fprintf(stderr, "Z formatem %d x %d nie możemy pozwolić zczytanie z pliku\n", dane->w, dane->k);
			freePole(dane);
		
			return 1;
                } 
		int xx, yy;
		char ki = wczytanie(in, dane, &xx, &yy);
		if(ki == ' '){
			if(dane->kier != NULL)
			{
				free(dane->kier);
			}
			if(dane->opcja != NULL)
			{
				free(dane->opcja);
			}
			
			free(dane);
			return 1;
		} else {
			if(ki == '>'){
				dane->kier = strdup("r");
			} else if(ki == '<'){
				dane->kier = strdup("l");
			} else if(ki == 'v'){
				dane->kier = strdup("b");
			} else if(ki == '^'){
				dane->kier = strdup("u");
			}
			dane->x = yy;
			dane->y = xx;
		}
	}


	char buff[100];
	sprintf(buff, "file%d", dane->il);
	FILE *out = fopen(buff, "w");

	if(out == NULL)
	{
		fprintf(stderr, "Plik do zapisu nie można otworzyć\n");
		freePole(dane);
		if(w == 1){
			fclose(in);
		}
		return 1;
	}	
	
	int i;
	for(i = 0; i < dane->il; i++) {
		ppole(dane, i, out);
	}
	
	freePole(dane);
macierz_1x1: {
		     pm1x1(il); //funkcja w ppole dla macierzy 1x1
	     }
	if(w == 1)
	{
		fclose(in);
	}
	fclose(out);
	return 0;
}
