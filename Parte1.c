#include <stdio.h>
#include <string.h>
#define TLINEA 500

char cifrado[TLINEA];
int cifrarFrase(char frase[], int espaciado);

int main(int argc, char *argv[0]){
	if(argc==1){
		char frase[TLINEA];
		int num;
		printf("Ingrese la frase a cifrar: ");
		scanf("%[^\n]s",frase);
		printf("Ingrese la cantidad de espacios: ");
		scanf("%d",&num);
		//printf("%s %d\n",frase,num);
		//int longitud = strlen(frase);
		//printf("%s %d\n","Longitud de frase",longitud);
		//printf("\n");*/
		cifrarFrase(frase,num);
		printf("Frase cifrada: ");
		printf("%s\n",cifrado);
	}
	else if(argc==3){
		int num = argv[1][0];
		cifrarFrase(argv[2],num);
		printf("Frase cifrada: ");
                printf("%s\n",cifrado);
	}
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
			if(espaciado>=0){
				if(a>=65 && a<=90){
					while(mov<=65 || mov>=90){
						mov = mov - 26;
					}
				}
				if(a>=97 && a<=122){
                                       	while(mov<=97 || mov>=122){
                                               	mov = mov - 26;
                                       	}
				}
			}
			else{
                                if(a>=65 && a<=90){
                                       	while(mov<=65 || mov>=90){
                                               	mov = mov + 26;
                                       	}
                                }
                                if(a>=97 && a<=122){
                                       	while(mov<=97 || mov>=122){
                                               	mov = mov + 26;
                                       	}
                                }
			}
			char letra = mov;
                        cifrado[i] = letra;
		}
	}
	return 0;
}
