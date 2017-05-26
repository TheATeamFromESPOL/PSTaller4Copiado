#include <stdio.h>
#define TLINEA 1000

char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(void){
	char frase[TLINEA];
	int num;
	printf("Ingrese la frase a cifrar: ");
	scanf("%[^\n]s",frase);
	printf("Ingrese la cantidad de espacios: ");
	scanf("%d",&num);
	printf("%s %d\n",frase,num);
	/*for(int i=0;i<sizeof(alfabeto);i++){
		printf("%c",alfabeto[i]);
		printf("\n");
	}*/
}
