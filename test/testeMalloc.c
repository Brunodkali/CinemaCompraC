#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int dia, mes, ano;
} data;

int main() {
    data *d;
    if((d = (data *) malloc (sizeof (data))) == NULL) {
        printf("Espaco insuficiente para alocar buffer \n");
        exit(1);
    }

    d->dia = 13;
    d->mes = 06;
    d->ano = 2017;
    printf ("%d/%d/%d\n", d->dia, d->mes, d->ano);
    free(d);
} 