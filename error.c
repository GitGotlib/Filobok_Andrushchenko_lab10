#include <stdio.h>
#include <stdlib.h>
#include "pole.h"
#include <string.h>
#include <math.h>


void freePole(Pole *dane)
{
        if (dane->v != NULL) {
        	for (int i = 0; i < dane->w; i++) {
                	free(dane->v[i]);
        	}
        	free(dane->v);
        }

        free(dane->kier);
        free(dane->opcja);
        free(dane);
}



int spr(int argc, char **argv)
{
	if(argc > 6)
	{
		fprintf(stderr, "Za dużo argumentów wywołania\n");
		return 1;
	}

	if(argc > 1)
	{
		char *endp;
	        double x = strtod(argv[1], &endp);
    
        	int y = x*1;
        	double u = fmod(x, (double)y);
    
   	     	if(strlen(endp) == 0 && u == 0.0)
        	{										
                	if(x < 1)
                	{
                        	fprintf(stderr, "%s: to jest niemożliwe zrobić siatkę z rozmiarem mniejszym od 1\n", argv[0]); 
                        	return 1;
               		}
        	} else if(strlen(endp) != 0) {
                	fprintf(stderr, "%s: podana jakaś bzdura zamiast liczby: %s\n", argv[0], argv[1]);
                	return 1;
        	} else if(u != 0.0){
                	fprintf(stderr, "%s: podana jakaś zmiennoprzecinkowa liczba a nie całkowita: %s\n", argv[0], argv[1]);
                	return 1;
        	}
	}


	if(argc > 2)
	{
                char *endp;
                double x = strtod(argv[2], &endp);
    
                int y = x*1;
                double u = fmod(x, (double)y);
    
                if(strlen(endp) == 0 && u == 0.0)
                {    
                        if(x < 1)
                        {
                                fprintf(stderr, "%s: to jest niemożliwe zrobić siatkę z rozmiarem mniejszym od 1\n", argv[0]); 
                                return 1;
                        }
                } else if(strlen(endp) != 0) {
                        fprintf(stderr, "%s: podana jakaś bzdura zamiast liczby: %s\n", argv[0], argv[2]);
                        return 1;
                } else if(u != 0.0){
                        fprintf(stderr, "%s: podana jakaś zmiennoprzecinkowa liczba a nie całkowita: %s\n", argv[0], argv[2]);
                        return 1;
                }
        }
	
	
	if(argc > 3)
	{
		char *endp;
                double x = strtod(argv[3], &endp);

                int y = x*1;
                double u = fmod(x, (double)y);

                if(strlen(endp) == 0 && u == 0.0)
                {
                        if(x < 1)
                        {
                                fprintf(stderr, "%s: to jest niemożliwe zrobić kiedy jest mniej niż jedna iteracja\n", argv[0]);
                                return 1;
                        }
                } else if(strlen(endp) != 0) {
                        fprintf(stderr, "%s: podana jakaś bzdura zamiast liczby: %s\n", argv[0], argv[3]);
                        return 1;
                } else if(u != 0.0){
                        fprintf(stderr, "%s: podana jakaś zmiennoprzecinkowa liczba a nie całkowita: %s\n", argv[0], argv[3]);
                        return 1;
                }

	}
	
	if(argc > 4)
	{
		if(strcmp("r", argv[4]) != 0 && strcmp("l", argv[4]) != 0 && strcmp("u", argv[4]) != 0 && strcmp("b", argv[4]) != 0)
		{
			fprintf(stderr, "%s: podano coś co nie jest kierunkiem w 4 argumencie wywołania: %s\n", argv[0], argv[4]);
			return 1;
		}
	}
	
	return 0;
}




















