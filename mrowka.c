#include "pole.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define ANSI_GREEN_TEXT       "\x1b[32m"
#define ANSI_BACKGROUND_BLACK "\x1b[30m"
#define ANSI_BACKGROUND_WHITE "\x1b[47m"
#define ANSI_RESET            "\x1b[0m"
void move(Pole *dane, FILE *out, int pp) {
	char buf[100];	
	if (dane->v[dane->y][dane->x] == 1) {
		dane->v[dane->y][dane->x] = 0;
		if(strcmp(dane->kier, "r") == 0) {
			printf(ANSI_BACKGROUND_BLACK ANSI_GREEN_TEXT ">"ANSI_RESET );
			if(pp == dane->il-1)
				fprintf(out, ">");
			strcpy(buf, "b");
			strcpy(dane->kier, buf);
			if(dane->y == dane->w - 1) {
				dane->y = 0;
			} else {
			dane->y += 1; }
			return;
		}
		else if(strcmp(dane->kier, "b") == 0) {
		 	printf(ANSI_BACKGROUND_BLACK ANSI_GREEN_TEXT "v"ANSI_RESET );
			if(pp == dane->il-1){
				fprintf(out, "v");
			}
			strcpy(buf, "l");
			strcpy(dane->kier, buf);
			if(dane->x == 0) {
				dane->x = dane->k - 1;
			} else {
			dane->x -= 1; }
			return;
		}
		else if(strcmp(dane->kier, "l") == 0) {
			printf(ANSI_BACKGROUND_BLACK ANSI_GREEN_TEXT "<"ANSI_RESET );
			if(pp == dane->il-1){
				fprintf(out, "<");
			}
			strcpy(buf, "u");
			strcpy(dane->kier, buf);
			if(dane->y == 0) {
				dane->y = dane->w - 1;
			} else {
			dane->y -= 1; }
			return;
		}	
		else if(strcmp(dane->kier, "u") == 0) {
			printf(ANSI_BACKGROUND_BLACK ANSI_GREEN_TEXT "^"ANSI_RESET );
			if(pp == dane->il-1){
				fprintf(out, "^");
			}
			strcpy(buf, "r");
			strcpy(dane->kier, buf);
			if(dane->x == dane->k - 1) {
				dane->x = 0;
			} else {
			dane->x += 1; }
			return;
		}
		else { 
			fprintf(stderr, "Błąd w zaznaczeniu kierunku");
		}
	}
	else if (dane->v[dane->y][dane->x] == 0) {
		dane->v[dane->y][dane->x] = 1;
			if(strcmp(dane->kier, "r") == 0) {
				printf(ANSI_BACKGROUND_WHITE ANSI_GREEN_TEXT ">"ANSI_RESET );
				if(pp == dane->il-1){
                                	fprintf(out, ">");
                        	}  
				strcpy(buf, "u");
				strcpy(dane->kier, buf);
				if(dane->y == 0) {
					dane->y = dane->w - 1;
				} else {
				dane->y -= 1; }
				return;
			}
			else if(strcmp(dane->kier, "u") == 0) {
				printf(ANSI_BACKGROUND_WHITE ANSI_GREEN_TEXT "^"ANSI_RESET );
				if(pp == dane->il-1){
                           	     fprintf(out, "^");
                        	}  
				strcpy(buf, "l");
				strcpy(dane->kier, buf);
				if(dane->x == 0) {
					dane->x = dane->k - 1;
				} else {
				dane->x -= 1;
				}
				return;
			}
			else if(strcmp(dane->kier, "l") == 0) {
				printf(ANSI_BACKGROUND_WHITE ANSI_GREEN_TEXT "<"ANSI_RESET );
				if(pp == dane->il-1){
                                	fprintf(out, "<");
                        	}  
				strcpy(buf, "b");
				strcpy(dane->kier, buf);
				if(dane->y == dane->w - 1) {
					dane->y = 0;
				} else {
				dane->y += 1;
				}
				return;
			}
			else if(strcmp(dane->kier, "b") == 0) {
				printf(ANSI_BACKGROUND_WHITE ANSI_GREEN_TEXT "v"ANSI_RESET );
				if(pp == dane->il-1){
                                	fprintf(out, "v");
                        	}  
				strcpy(buf, "r");
				strcpy(dane->kier, buf);
				if(dane->x == dane->k - 1) {
					dane->x = 0;
				} else {
					dane->x += 1;
				}
				return;
			}
			else {
				fprintf(stderr, "Błąd w zaznaczeniu kierunku");
			}
		}
		else {
			fprintf(stderr, "Błąd w macierzy");
		}
	}

