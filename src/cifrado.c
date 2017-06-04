#include <string.h>

char abecedario[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
'P','Q','R','S','T','U','V','W','X','Y','Z'}

char* cifradoCiclico(char* mensaje,int llave){
	int mov;
	char *cifrado = "";

	for(int i=0;i<strlen(mensaje);i++){
		if(mensaje[i]==' '){
			strcat(cifrado," ");
		}
		else{
			int a = mensaje[i];
			mov = a + llave;
			if(llave>=0){
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
			char *aconcatenar = "";
			aconcatenar[0]=letra;
			strcat(cifrado,aconcatenar);
		}
	}
	return cifrado;
}

/*
char* cifradoAutollave(char* mensaje, char* llave){

}
*/
char* cifradoContrasena(char* mensaje, char* llave){
	int longitud = strlen(mensaje);
	int num;
	char abecedarioNuevo[26];
	for(int i=0;i<26;i++){
		if(i<longitud){
			abecedarioNuevo[i] = mensaje[i];
		}
		else{
			num = i-longitud;
			abecedarioNuevo[i] = abecedario[num];
		}
	}
	char* cifrado;
	for(int j=0;j<longitud;j++){
		for(int k=0;k<26;i++){
			if(abecedario[k]==mensaje[j]){
				cifrado[j]=abecedarioNuevo[k];
			}
		}
	}
	return cifrado;
}
