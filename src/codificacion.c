#include <string.h>

char* morse[37]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----.","/"};
char cambios[37]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',' '};

char* claveMorse(char* mensaje){
        char *morseado = "";
        for(int i=0;i<strlen(mensaje);i++){
                int indice=100;
                int a = mensaje[i];
                if(a>=97 && a<=122){
                        a = a - 32;
                }
                char c = a;
                for(int j=0;j<37;j++){
                        if(cambios[j]==c){
                                indice = j;
                        }
                }
                if(indice!=100){
                        strcat(morseado,morse[indice]);
                }
                else{
                        strcat(morseado,"*");
                }
        }
        return morseado;
}
