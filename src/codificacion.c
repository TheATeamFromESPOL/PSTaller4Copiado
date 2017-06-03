#include <string.h>

char* morse[37]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----.","/"};
char cambios[37]= {'A','B','C','D','E','F','G','H','I','J','K','L','M'$
               'P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2'$
                '4','5','6','7','8','9',' '};

char* claveMorse(char* mensaje){
        char *morseado = "";
        pointer = mensaje;
        for(int i=0;i<strlen(mensaje);i++){
                int indice;
                int a = mensaje;
                if(a>=97 && a<=122){
                        a = a - 32;
                }
                char c = a;
                indice = indiceMorse(c);
                if(indice!=100){
                        strcat(morseado,morse[indice]);
                }
                else{
                        strcat(morseado,"*");
                }
        }
        return morseado;
}

int indiceMorse(char caracter){
        int a = 100;
        for(int i=0;i<37;i++){
                if(cambios[i]==caracter){
                        a = i;
                }
        }
        return a;
}
