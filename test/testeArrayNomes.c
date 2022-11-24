#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char filme_disponivel[][20] = {"A Bela e a Fera", "O Magico de OZ", "Se eu fosse voce 2"};
char *nome_filme;

void main() {
    nome_filme = filme_disponivel[1];

    printf("Titulo 1: %s\n", nome_filme);
    printf("Titulo 2: %s\n", nome_filme);
    printf("Titulo 3: %s\n", nome_filme);

    return 0; 
}
