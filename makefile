all: estatico dinamico

main.o: ./src/main.c
	gcc -Wall -c ./src/main.c -o ./obj/$@

lib.a: ./src/cifrado.c ./src/codificacion.c
	gcc -Wall -c ./src/cifrado.c -o ./obj/cifrado.o
	gcc -Wall -c ./src/codificacion.c -o ./obj/codificacion.o
	ar rcs ./lib/lib.a ./obj/cifrado.o ./obj/codificacion.o 

lib.so: ./src/cifrado.c
	gcc -Wall -shared -fPIC ./src/cifrado.c -o ./lib/$@

dinamico: main.o cifrado.o codificacion.o lib.so 
	gcc -L./ -I./ ./obj/main.o ./obj/cifrado.o ./obj/codificacion.o -lm -o $@

estatico: main.o lib.a
	gcc ./obj/main.o ./lib/lib.a -lm -o ./lib/$@

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.so
	rm -f ./bin/*
