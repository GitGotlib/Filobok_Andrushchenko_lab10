CFLAGS = -Wall -g
LDFLAGS = -lm

all: final


final: main.o pole.o mrowka.o file.o error.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c
	gcc $(CFLAGS) -c -o $@ $<

pole.o: pole.c pole.h
	gcc $(CFLAGS) -c -o $@ $<

mrowka.o: mrowka.c
	gcc $(CFLAGS) -c -o $@ $<

file.o: file.c
	gcc $(CFLAGS) -c -o $@ $<

error.o: error.c
	gcc $(CFLAGS) -c -o $@ $<

clean: 
	rm -f main.o pole.o mrowka.o file.o error.o final
