#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TLINEA 500

char *morse[37]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----.","/"};
char cambios[37]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
               'P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3',
                '4','5','6','7','8','9',' '};
char cifrado[TLINEA];
char *morseado[TLINEA];
int cifrarFrase(char frase[], int espaciado);
int morseFrase(char frase[]);
int indiceMorse(char caracter);

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
		printf("Morse: ");
                morseFrase(frase);
		printf("%s",*morseado);
	}
	else if(argc==3){
		int num = atoi(argv[1]);
		printf("%d",num);
		cifrarFrase(argv[2],num);
		printf("Frase cifrada: ");
                printf("%s\n",cifrado);
		printf("Morse: ");
		morseFrase(argv[2]);
		printf("%s",*morseado);
	}
	else{
		printf("Debe colocar la correcta cantidad de argumentos\n");
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

int morseFrase(char frase[]){
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]==' '){
                        morseado[i] = "/";
                }
		else{
			int indice;
			int a = frase[i];
			if(a>=65 && a<=90){
				a = a + 37;
			}
			if(a>=48 && a<=57){
				int num = a - 48;
				char c = (char)num;
				indice = indiceMorse(c);
				morseado[i] = morse[indice];
			}else if(a>=97 && a<=122){
				char c = a;
				indice = indiceMorse(c);
				morseado[i] = morse[indice];
			}
		}
	}
	return 0;
}

int indiceMorse(char caracter){
	int a = -1;
	for(int i=0;i<37;i++){
		if(cambios[i]==caracter){
			a = i;
		}
	}
	return a;
}

int imprMorse(char *morseado[]){
	for(int i=0;sizeof(*morseado);i++){
		if(morseado[i]!='\0'){
			printf("%s ",morseado[i]);
		}
	}
	return 0;
}
