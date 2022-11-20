#include <stdio.h>

void main()
{
  FILE *arq;
  char Linha[500];
  char *result;
  int i;

  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("ingresso.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 0;
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 500, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (i == 0)  // Se foi possível ler
	  printf("Conteudo: %s", Linha);
      i++;
  }
  fclose(arq);
}