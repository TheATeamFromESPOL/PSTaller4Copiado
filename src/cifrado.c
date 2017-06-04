#include <string.h>

char abecedario[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
'P','Q','R','S','T','U','V','W','X','Y','Z'}

char tabla[26][26]={
"ABCDEFGHIJKLMNOPQRSTUVWXYZ","BCDEFGHIJKLMNOPQRSTUVWXYZA","CDEFGHIJKLMNOPQRSTUVWXYZAB",
"DEFGHIJKLMNOPQRSTUVWXYZABC","EFGHIJKLMNOPQRSTUVWXYZABCD","FGHIJKLMNOPQRSTUVWXYZABCDE",
"GHIJKLMNOPQRSTUVWXYZABCDEF","HIJKLMNOPQRSTUVWXYZABCDEFG","IJKLMNOPQRSTUVWXYZABCDEFGH",
"JKLMNOPQRSTUVWXYZABCDEFGHI","KLMNOPQRSTUVWXYZABCDEFGHIJ","LMNOPQRSTUVWXYZABCDEFGHIJK",
"MNOPQRSTUVWXYZABCDEFGHIJKL","NOPQRSTUVWXYZABCDEFGHIJKLM","OPQRSTUVWXYZABCDEFGHIJKLMN",
"PQRSTUVWXYZABCDEFGHIJKLMNO","QRSTUVWXYZABCDEFGHIJKLMNOP","RSTUVWXYABCDEFGHIJKLMNOPQZ",
"STUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRS","UVWXYZABCDEFGHIJKLMNOPQRST",
"VWXYZABCDEFGHIJKLMNOPQRSTU","WXYZABCDEFGHIJKLMNOPQRSTUV","XYZABCDEFGHIJKLMNOPQRSTUVW"
,"YZABCDEFGHIJKLMNOPQRSTUVWX","ZABCDEFGHIJKLMNOPQRSTUVWXY"}

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


char* cifradoAutollave(char* mensaje, char* llave){
	int longitud = strlen(mensaje);
	int a,b= 0;
	char* anexado;
	char* cifrado;
	for(int i=0;i<longitud;i++){
		if(llave[i]!='\0'){
			if(mensaje[i]!=' '){
				anexado[i]=llave[b];
				b++;
			}
			else{
				anexado[i]=' ';
			}
		}
		else{
			if(mensaje[i]!=' '){
				if(mensaje[a]==' '){
					a++;
				}
				anexado[i]=mensaje[a];
				a++;
			}
			else{
				anexado[i]=' ';
			}
		}
	}
	
	for(int j=0;j<longitud;j++){
		int x,y;
		char ch = mensaje[j];
		char d = anexado[j];
		x = ind(ch);
		y = ind(d);
		if(x==27){
			cifrado[j]=' ';
		}
		else{
			cifrado[j]=tabla[x][y];
		}		
	}
	return cifrado;
}

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

int ind(char c){
	int n = 27;
        for(int i=0;i<26;i++){
                if(abecedario[i]==c){
                        n = i;
                }
        }
        return n;
}
