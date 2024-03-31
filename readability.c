#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main(){

    string texto = get_string("Texto:");
    float espacos  = 0;
    float frases = 0;

    for(int i = 0, n = strlen(texto); i <= n; i++){
        if(texto[i] == ' '){
            espacos++;
        }
    }

    for(int i = 0, n = strlen(texto); i < n; i++){
        if(texto[i] == '.' || texto[i] == '!' || texto[i] == '?'){
            frases++;
        }
    }

    int n = strlen(texto);
    float L = (n - (espacos+1) - (frases + 1)) / (espacos+1)* 100;
    float S = (frases) / (espacos + 1)* 100;
    int indice = 0;

     if(round(0.0588 * L - 0.296 * S - 15.8) > (0.0588 * L - 0.296 * S - 15.8) && round(0.0588 * L - 0.296 * S - 15.8) - (0.0588 * L - 0.296 * S - 15.8) > 0.3){
        indice = floor(0.0588 * L - 0.296 * S - 15.8);
     }else{
        indice = round(0.0588 * L - 0.296 * S - 15.8);
     }

    if(indice < 1){
        printf("%s\n","Before Grade 1");
    }else if(indice > 16){
        printf("%s\n","Grade 16+");
    }else{
        printf("Grade %i\n", indice);
    }
}

