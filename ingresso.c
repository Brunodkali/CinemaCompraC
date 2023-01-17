#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define quant_bilhetes_MAX 10
#define valor_int 24
#define valor_meia 12

int codigo_filme;
int quant_bilhetes;
int valor_final;
int valor_bilhetes;
int horario_sessao;
int fp;
char filme_disponivel[][20] = {"A Bela e a Fera", "O Magico de OZ", "Se eu fosse voce 2"};
char filme_disponivel_menu[][200] = {"\t[1] | A Bela e a Fera\n", "\t[2] | O Magico de OZ\n", "\t[3] | Se eu fosse voce 2\n", "\t[4] | Sair\n"};
char nome[15];
char *result;
char linha[500];

int filme(int codigo_filme);
void menu();
void pagamento();
void imprimir();
void gerar();
void geracao();

// Função main, responsável por iniciar o software.
int main(void) {
    menu();
    setlocale(LC_ALL, "");

    return 0;
}

// Função de menu, responsável por disponibilizar os filmes disponíveis e encaminha
// o código de cada filme como parâmetro para a próxima função.
void menu() {    
    int cont;
    char auxText;

    do {
        system("cls");
        geracao();
        printf("\t\Teatro da Cidade\n");
        geracao();
        printf("\tSELECIONE UMA DAS OPCOES ABAIXO:\n\n");
        printf("\t |--> ESPETACULOS EM CARTAZ <--| \n\n");

        for (cont = 0; cont < 5; cont++) {
            printf("%s", filme_disponivel_menu[cont]);
        }

        scanf("%c", &auxText);

        switch (auxText) {
            case '1':
                filme(codigo_filme = 0);
                break;
            case '2':
                filme(codigo_filme = 1);
                break;
            case '3':
                filme(codigo_filme = 2);
                break;
            case '4':
                exit(0);
                break;
            default:
                break;
       }
    } while (auxText != '4');

    return 0;
}

// Função que disponibiliza informações referentes ao filme selecionado.
// Recebe como parâmetros o código do filme selecionado.
int filme(int codigo_filme) {
    int codigo = 0;
    int auxText;
    char *nome_filme;
    FILE *arq = fopen("sinopses/sinopses.txt", "rt");

    if (arq == NULL) {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }

    system("cls");
    if (codigo_filme == 0) {
        nome_filme = filme_disponivel[0];
        
        geracao();

        printf("Nome: %s\n", nome_filme);
        while (!feof(arq)) {
            result = fgets(linha, 500, arq);
            if (codigo == codigo_filme) 
            printf("\nSinopse: %s\n", linha);
            codigo++;
        }
        fclose(arq);

        geracao();

        printf("\t[1] Comprar ingresso\n");
        printf("\t[2] Retornar ao menu\n");
        scanf("%d", &auxText);
        switch (auxText) {
            case 1:
                comprar(nome_filme, codigo_filme);
                break;
            case 2:
                menu();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                menu();
                break;
        }
    }
    else if (codigo_filme == 1) {
        nome_filme = filme_disponivel[1];

        geracao();

        printf("Nome: %s\n", nome_filme);
        while (!feof(arq)) {
            result = fgets(linha, 500, arq);
            if (codigo == codigo_filme) 
            printf("\nSinopse: %s\n", linha);
            codigo++;
        }
        fclose(arq);

        geracao();

        printf("\t[1] Comprar ingresso\n");
        printf("\t[2] Retornar ao menu\n");
        scanf("%d", &auxText);
        switch (auxText) {
            case 1:
                comprar(nome_filme, codigo_filme);
                break;
            case 2:
                menu();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                break;
        }
        geracao();
        getchar();
    }
    else if (codigo_filme == 2) {
        nome_filme = filme_disponivel[2];

        geracao();

        printf("Nome: %s\n", nome_filme);
        while (!feof(arq)) {
            result = fgets(linha, 500, arq);
            if (codigo == codigo_filme) 
            printf("\nSinopse: %s\n", linha);
            codigo++;
        }
        fclose(arq);

        geracao();

        printf("\t[1] Comprar ingresso\n");
        printf("\t[2] Retornar ao menu\n");
        scanf("%d", &auxText);
        switch (auxText) {
            case 1:
                comprar(nome_filme, codigo_filme);
                break;
            case 2:
                menu();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                break;
        }
        geracao();
        getchar();
    }
    return 0;
}

// Função que permite a seleção de ingressos, quantidades e sessão desejada.
// Recebe como parâmetros o nome do filme e o código do filme selecionado.
void comprar(nome_filme, codigo_filme) {
    int cc;
    int rt;
    int ig;

    system("cls");
    printf("Filme: %s\n", nome_filme);
    printf("Selecione se o ingresso e inteiro ou meia-entrada: \n");
    printf("[1] Inteiro\n");
    printf("[2] Meia-entrada\n");
    printf("[3] Retornar ao menu\n");
    scanf("%d", &ig);
        switch (ig) {
            case 1:
                valor_bilhetes = valor_int;
                break;
            case 2:
                valor_bilhetes = valor_meia;
                break;
            case 3:
                menu();
                break;
            default:
                comprar();
                break;
        }
    system("cls");
    printf("Digite a quantidade de ingressos (Ex: 2, 3...):\n");
    scanf("%d", &quant_bilhetes); 

    if (quant_bilhetes > quant_bilhetes_MAX) {
        printf("Essa quantidade ultrapassa a quantidade de bilhetes disponiveis: %d\n", quant_bilhetes_MAX);
        printf("[1] Retornar ao menu\n");
        scanf("%d", &rt);
        switch (rt) {
            case 1:
                menu();
                break;      
            default:
                printf("Opcao invalida!\n");
                Sleep(1000);
                menu();
                break;
        }
    }else { 
        geracao();

        printf("Selecione a sessao desejada:\n");
        if (codigo_filme == 1) {
            printf("[1] Sessao 1 - Sala 2 15:00 Leg.\n");
            printf("[2] Sessao 2 - Sala 2 16:00 3D Dub.\n");
            printf("[3] Sessao 3 - Sala 3 15:30 Dub.\n");
        }
        else if (codigo_filme == 2) {
            printf("[1] Sessao 1 - Sala 2 14:00 Leg.\n");
            printf("[2] Sessao 2 - Sala 2 15:00 3D Dub.\n");
            printf("[3] Sessao 3 - Sala 3 14:30 Dub.\n");
        }else {
            printf("[1] Sessao 1 - Sala 2 14:00 Leg.\n");
            printf("[2] Sessao 2 - Sala 2 16:00 3D Dub.\n");
            printf("[3] Sessao 3 - Sala 3 17:30 Dub.\n");
        }
        scanf("%d", &horario_sessao);

        geracao();

        printf("Confirme as informacoes abaixo:\n");
        printf("Quantidade de ingressos: %d\n", quant_bilhetes);
        printf("Sessao selecionada: %d\n", horario_sessao);
        printf("\t[1] Confirmar compra\n");
        printf("\t[2] Retornar ao menu\n");

        geracao();

        scanf("%d", &cc);
        switch (cc) {
            case 1:
                pagamento(nome_filme);
                break;
            case 2:
                menu();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                break;
        }
    }
    return 0;
}

// Função que permite a seleção da forma de pagamento e imprime o valor final da compra.
// Recebe como parâmetros o nome do filme.
void pagamento(nome_filme){
    int valor_final = (quant_bilhetes * valor_bilhetes);

    system("cls");
    geracao();
    printf("Digite seu nome: \n");
    scanf ("%s", nome);
    printf("Valor final de sua compra: %d\n", valor_final);
    printf("Selecione a forma de pagamento: \n");
    printf("\t[1] Cartao de debito\n");
    printf("\t[2] Cartao de credito\n");
    printf("\t[3] Dinheiro (cedulas)\n");
    printf("\t[4] Pix\n");

    geracao();

    scanf("%d", &fp);
    switch (fp) {
        case 1:
            imprimir(nome, fp, nome_filme, valor_final);
            break;
        case 2:
            imprimir(nome, fp, nome_filme, valor_final);
            break;
        case 3:
            imprimir(nome, fp, nome_filme, valor_final);
            break;
        case 4:
            imprimir(nome, fp, nome_filme, valor_final);
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            break;
    }
    getchar();
    return 0;
}

// Função que permite confirmar as informações ou retonar ao menu.
// Recebe como parâmetros o nome do usuário, forma de pagamento selecionada,
// nome do filme e o valor final da compra.
void imprimir(nome, fp, nome_filme, valor_final) {
    int cf;
    
    system("cls");

    geracao();

    printf("Confirme as informacoes abaixo: \n");
    printf("Nome: %s\n", nome);
    printf("Nome do filme: %s\n", nome_filme);
    printf("Quantidade de bilhetes: %d\n", quant_bilhetes);
    printf("Sessao: %d\n", horario_sessao);
    printf("Valor: %d\n", valor_final);
    printf("\t[1] Sim\n");
    printf("\t[2] Nao\n");
    scanf("%d", &cf);

    geracao();

    switch (cf) {
        case 1:
            gerar(nome, nome_filme, quant_bilhetes, horario_sessao, valor_final);
            break;
        case 2:
            menu();
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            break;
    }  
}

// Função que recebe como parâmetro o nome do usuário, nome do filme, quantidade de bilhetes,
// sessão selecionada e valor final a ser pago.
void gerar(nome, nome_filme, quant_bilhetes, horario_sessao, valor_final) {
    char ingresso[] = { "ingressoDigital.txt" };
    FILE *file = fopen(ingresso, "w");

    system("cls");
    printf("|-------------------------------------->>\n");
    printf("| \tINGRESSO DIGITAL\n"); 
    printf("| \tNOME:  %s\n", nome );
    printf("| \tFILME:  %s\n", nome_filme);
    printf("| \tBILHETE(S):  %d\n", quant_bilhetes);
    printf("| \tSESSAO:  %d\n", horario_sessao);
    printf("| \tVALOR:  %d\n", valor_final);
    printf("|-------------------------------------->>\n");

    if(file) {
        fprintf(file, "|-------------------------------------->>\n");
        fprintf(file, "| \tINGRESSO DIGITAL\n"); 
        fprintf(file, "| \tNOME:  %s\n", nome );
        fprintf(file, "| \tFILME:  %s\n", nome_filme);
        fprintf(file, "| \tBILHETE(S):  %d\n", quant_bilhetes);
        fprintf(file, "| \tSESSAO:  %d\n", horario_sessao);
        fprintf(file, "| \tVALOR:  %d\n", valor_final);
        fprintf(file, "|-------------------------------------->>\n");
        fclose(file);
        printf("\nIngresso digital gerado!\n");
    }else {
        printf("\nERRO ao gerar arquivo!\n");
    }
    getchar();
    exit(0);
    return 0;
}

// Workaround para gerar conteúdo visual
void geracao() {
    printf("================================================\n");
    return;
}