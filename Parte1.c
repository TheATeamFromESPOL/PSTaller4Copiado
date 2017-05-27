#include <stdio.h>
#include <string.h>
#define TLINEA 500

char cifrado[TLINEA];
int cifrarFrase(char frase[], int espaciado);

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
			int a = frase[i];
			mov = a + espaciado;
			while(!((mov>=65 && mov<=90)||(mov>=97 && mov<=122))){
				mov = mov - 26;
			}
			char letra = mov;
			cifrado[i] = letra;
		}
	}
	return 0;
}
