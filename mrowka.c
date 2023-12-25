#include "pole.h"
#include <stdio.h>

void move(Pole *dane) {
	int i;

	for (i = 0; i < dane->il; i++) {

		if(dane->kier == "r") {
			dane->kier = "b";
			dane->x += 1;
		}
                if(dane->kier == "b") {
                        dane->kier = "l";
			dane->y -= 1;
		}
                if(dane->kier == "l") {
			dane->kier = "u";
			dane->x -= 1;
		}	
                if(dane->kier == "u") {
			dane->kier = "r";
                        dane->y += 1;
		}
