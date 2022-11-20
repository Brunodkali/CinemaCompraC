#include <stdio.h>
#include <stdlib.h>

int abrirArquivo(char *palavra, int linha); //define apenas o cabeçalho da função. Sem o cabeçalho, a função deve ficar acima do main


int main(){
    char palavraforca[500];
    int linha;

    linha=1; //para pegar a palavra na primeira linha
    abrirArquivo(palavraforca, linha);
    printf("Linha 1: %s\n", palavraforca);

    linha=4; //para pegar a palavra na segunda linha
    abrirArquivo(palavraforca, linha);
    printf("Linha 2: %s\n", palavraforca);

    linha=8; //para pegar a palavra na terceira linha
    abrirArquivo(palavraforca, linha);
    printf("Linha 3: %s\n", palavraforca);

    return 0;
}


int abrirArquivo(char *palavra, int linha){
    FILE *file;
    if((file=fopen("ingresso.txt", "r"))==NULL){ //poupa linha atribuindo e comparando ao mesmo tempo
        printf("ERROR: abrirArquivo fopen == NULL\n"); //informa onde e qual foi o erro
        exit(1); //para o programa nesse ponto.
    }

    /*
    define cont como 0 linhas, a partir da hora que é lida a primeira linha, cont fica com 1 e 
    caso queira pegar a linha 1 o laço é parado, pois cont agora é igual a linha
    */
    int cont=0;
    while(cont!=linha){
        fscanf(file, "%s", palavra); //lê uma linha
        cont++;
    }

    fclose(file);
    return 0;
}