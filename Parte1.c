#include <stdio.h>
#include <string.h>
#define TLINEA 500

char cifrado[TLINEA];
int indiceDeCaracter(char caracter);
int cifrarFrase(char frase[], int espaciado);
char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(void){
	char frase[TLINEA];
	int num;
	printf("Ingrese la frase a cifrar: ");
	scanf("%[^\n]s",frase);
	printf("Ingrese la cantidad de espacios: ");
	scanf("%d",&num);
	printf("%s %d\n",frase,num);
	int longitud = strlen(frase);
	printf("%s %d\n","Longitud de frase",longitud);
	printf("\n");
	cifrarFrase(frase,num);
	printf("Frase cifrada: ");
	printf("%s\n",cifrado);
}

int cifrarFrase(char frase[], int espaciado){
	int mov;
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]==' '){
			cifrado[i] = ' ';
		}
		else{
			mov = indiceDeCaracter(frase[i]) + espaciado;
			if(mov>=sizeof(alfabeto)){
				mov = mov%26;
			}
			cifrado[i] = alfabeto[mov];
		}
	}
	return 0;
}

int indiceDeCaracter(char caracter){
	int pos;
	for(int i=0;i<sizeof(alfabeto);i++){
		if(alfabeto[i]==caracter){
			pos=i;
		}
	}
	printf("%d",pos);
	return pos;
}
