#include <stdio.h>
#include <string.h>

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao;

    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%s", nome);
            fprintf(file, "%s", nome);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            scanf("%c");
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}