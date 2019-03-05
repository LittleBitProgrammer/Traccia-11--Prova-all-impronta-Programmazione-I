//
//  main.c
//  Traccia 11- Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 18/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

//Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo in italiano, determina e restituisce come parametro di output il numero delle parole contenute nel testo che hanno almeno 5 vocali. Nel testo le parole sono separate da un unico spazio.

#include <stdio.h>
#include <string.h>

int wordWithAandE(char *);
int returnEqual(char);

int main(int argc, const char * argv[]) {
    int numbers_of_are;
    char phrase[50];
    
    printf("inserisci la frase:\n");
    fgets(phrase, 4096, stdin);
    
    numbers_of_are  = wordWithAandE(phrase);
    printf("parole che hanno 5 vocali= %d\n", numbers_of_are);
    
    return 0;
}

int returnEqual(char lettera){
    return (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u');
}

int wordWithAandE(char *word){
    int j;
    int numeri_di_vocali = 0;
    int contatore = 0;
    char separators[] = {' ','\0','\t','\n'};
    char *token = strtok(word, separators);
    
    while (token != NULL) {
        numeri_di_vocali = 0;
        for (j = 0; j < strlen(token) && strlen(token) >= 5; j++) {
            
            if (returnEqual(token[j]) == 1) {
                numeri_di_vocali += 1;
            }
        }
        
        if(numeri_di_vocali >= 5){
            contatore += 1;
        }
        
        token = strtok(NULL," \n");
        
    }
    return contatore;
}
