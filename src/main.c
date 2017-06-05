#include <stdio.h>
#include "../include/cifrado.h"
#include "../include/codificacion.h"

int main(int argc, char *argv[0]){
	int num;
	char* tipoCifrado;
	char* frase;
	if(argc==1){
                printf("Tipo de cifrado: ");
                scanf("%[^\n]s",tipoCifrado);
		printf("Ingrese la frase a cifrar: ");
		scanf("%[^\n]s",frase);
		char* fraseCifrada;
		if(tipoCifrado=='C' || tipoCifrado=='c'||tipoCifrado=="-c"){
			fraseCifrada = cifradoCiclico(frase,num);
			printf("Cifrado ciclico: %s\n",fraseCifrada);
			char* morse = claveMorse(frase);
			printf("Morse: ");
			printf("%s\n",morse);
		}
		else if(tipoCifrado=="A"||tipoCifrado=="a"||tipoCifrado=="-a"){
			char* contra;
			printf("Ingrese la contrasena: ");
		        scanf("%[^\n]s",contra);
			fraseCifrada = cifradoAutollave(frase,contra);
			printf("Cifrado Autollave: %s\n",fraseCifrada");
		}
		else if(tipoCifrado=="P"||tipoCifrado=="p"||tipoCifrado=="-p"){
			char* contra;
		        printf("Ingrese la contrasena: ");
		        scanf("%[^\n]s",contra);
		        fraseCifrada = cifradoContrasena(frase,contra);
		        printf("Cifrado Contrasena: %s\n",fraseCifrada");
		}
		else{
			printf("\nEse tipo de cifrado no esta disponible");
			fraseCifrada = "";
		}
	}
	else if(argc==4){
		int num = atoi(argv[1]);
		tipoCifrado = argv[3];
		frase = argv[2];
	}
	else{
		printf("Debe colocar la correcta cantidad de argumentos\n");
	}

}
