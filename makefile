all: estatico dinamico

main.o: main.c
	gcc -Wall -c ./src/main.c -o ./obj/main.o $@

libdatos.a: ./src/cifrado.c ./src/codificacion.c
	gcc -Wall -c ./src/cifrado.c -o ./obj/cifrado.o
	gcc -Wall -c ./src/codificacion.c -o ./obj/codificacion.o
	ar rcs lib.a ./obj/cifrado.o ./obj/codificacion.o 

compartida.so: ./src/cifrado.c
	gcc -Wall -shared -fPIC ./src/cifrado.c -o ./lib/compartida.so $@

dinamico: main.o cifrado.o codificacion.o lib.so 
	gcc -L./ -I./ ./obj/main.o ./obj/cifrado.o ./obj/codificacion.o -lm -ldatos -o dinamico $@

estatico: main.o lib.a
	gcc ./obj/main.o lib.a -lm -o m $@

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.so
	rm -f ./bin/*
