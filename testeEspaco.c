#include <stdio.h>
#include <string.h>

int main(void) {
    char *str;
    int aux;

    printf("Digite alguma coisa:");
    scanf("%s", str);
    for(aux = 0; aux < strlen(str); aux++) {
        if(str[aux] == ' ') {
            str[aux] = str[aux + 1];
        }
        printf("%s\n", str);
    }
    return 0;
}