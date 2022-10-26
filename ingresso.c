#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define quant_bilhetes_MAX 10
#define valor_int 20
#define valor_meia 10

// ---- Funções ---- //

void menu();
void filme1();
void filme2();
void filme3();
void comprar();
void pagamento();
void imprimir();
void gerar();

// ---- Variaváveis Globais ---- //

int codigo_filme;
int quant_bilhetes;
int valor_final;
int valor_bilhetes;
int horario_sessao;
int FP;
char nome[61];

// ---- Início do código ---- //

int main(void) {

    menu();

    setlocale(LC_ALL, "");
    return 0;
}

void menu() {
    int op;

    system("cls");
    printf("================================================\n");
    printf("\t\tCinema da Cidade\n");
    printf("================================================\n");

    printf("\tSELECIONE UMA DAS OPCOES ABAIXO:\n\n");
    printf("\t |--> FILMES EM CARTAZ <--| \n\n");
    printf("\t[1] | A Bela e a Fera\n");
    printf("\t[2] | O Magico de OZ\n");
    printf("\t[3] | Se eu fosse voce 2\n");
    printf("\t[0] | Sair\n");
    printf("================================================\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            filme1();
            break;
        case 2:
            filme2();
            break;
        case 3:
            filme3();
            break;
        default:
            printf("Opcao invalida!");
            getchar();
            break;
    }
}

void filme1() {
    int ci;
    char nome_filme[61] = "A Bela e a Fera";
    codigo_filme = 1;

    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Esta e a historia de Bela, uma jovem destemida que, em troca da liberdade do pai,\n");
    printf("oferece a sua companhia a um ser monstruoso que vive num castelo enfeiticado. O que ela mais tarde vem a perceber e que,\n");
    printf("debaixo da sua estranha aparencia, ele e na realidade um principe sob uma maldicao...\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
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
    printf("================================================\n");
    getchar();
}

void filme2() {
    int ci;
    char nome_filme[61] = "O Magico de OZ";
    codigo_filme = 2;

    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Dorothy e seu cachorro Toto são levados para a terra magica de Oz quando um ciclone passa pela fazenda de seus avos no Kansas.\n");
    printf("Eles viajam em direcao a Cidade Esmeralda para encontrar o Mago Oz e no caminho encontram um Espantalho, que precisa de um cerebro,\n");
    printf("um Homem de Lata sem um coracao e um Leao Covarde que quer coragem....\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
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
    printf("================================================\n");
    getchar();
}

void filme3() {
    int ci;
    char nome_filme[61] = "Se eu fosse voce 2";
    codigo_filme = 3;

    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Claudio e Helena estao prestes a se separar. Durante uma discussao, \n");
    printf("eles trocam de corpos mais uma vez e sao obrigados a viver a vida do outro.\n");
    printf("Para complicar ainda mais a situacao, a filha do casal esta gravida e nao sabe como contar aos pais...\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
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
    printf("================================================\n");
    getchar();
}

void comprar(nome_filme, codigo_filme) {
    int cc;
    int rt;
    int ig;

    system("cls");

    printf("Filme: %s\n", nome_filme);
    printf("Selecione se o ingresso e inteiro ou meia-entrada: \n");
    printf("[1] Inteiro\n");
    printf("[2] Meia-entrada\n");
    scanf("%d", &ig);
        switch (ig) {
            case 1:
                valor_bilhetes = valor_int;
                break;
            case 2:
                valor_bilhetes = valor_meia;
                break;
            default:
                comprar();
                break;
        }
    printf("Digite a quantidade de ingressos (Ex: 2, 3...):\n");
    scanf("%d", &quant_bilhetes);

    if (quant_bilhetes > quant_bilhetes_MAX)
    {
        printf("Essa quantidade de bilhetes nao esta disponivel no momento!\n");
        printf("\t[1] Retornar ao menu\n");
        scanf("%d", &rt);
        switch (rt) {
            case 1:
                menu();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                break;
        }
        getchar();
    }else
    {
        printf("================================================\n");
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
        }
        else {
            printf("[1] Sessao 1 - Sala 2 14:00 Leg.\n");
            printf("[2] Sessao 2 - Sala 2 16:00 3D Dub.\n");
            printf("[3] Sessao 3 - Sala 3 17:30 Dub.\n");
        }
 
        scanf("%d", &horario_sessao);
        printf("================================================\n");
        printf("Confirme as informacoes abaixo:\n");
        printf("Quantidade de ingressos: %d\n", quant_bilhetes);
        printf("Sessao selecionada: %d\n", horario_sessao);
        printf("\t[1] Confirmar compra\n");
        printf("\t[2] Retornar ao menu\n");
        printf("================================================\n");
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
}

void pagamento(nome_filme){
    int valor_final = quant_bilhetes * valor_bilhetes;

    system("cls");
    printf("================================================\n");
    printf("Digite seu nome: \n");
    scanf ("%s", nome);
    printf("Valor final de sua compra: %d\n", valor_final);
    printf("Selecione a forma de pagamento: \n");
    printf("\t[1] Cartao de debito\n");
    printf("\t[2] Cartao de credito\n");
    printf("\t[3] Dinheiro (cedulas)\n");
    printf("\t[4] Pix\n");
    printf("================================================\n");
    scanf("%d", &FP);
    switch (FP) {
        case 1:
            imprimir(nome, FP, nome_filme, valor_final);
            break;
        case 2:
            imprimir(nome, FP, nome_filme, valor_final);
            break;
        case 3:
            imprimir(nome, FP, nome_filme, valor_final);
            break;
        case 4:
            imprimir(nome, FP, nome_filme, valor_final);
            break;
        default:
            printf("Opcao invalida!\n");
            getchar();
            break;
    }
    getchar();
}

void imprimir(nome, FP, nome_filme, valor_final) {
    int cf;

    system("cls");
    printf("================================================\n");
    printf("Confirme as informacoes abaixo: \n");
    printf("Nome: %s\n", nome);
    printf("Forma de pagamento: %d\n", FP);
    printf("Nome do filme: %s\n", nome_filme);
    printf("Quantidade de bilhetes: %d\n", quant_bilhetes);
    printf("Sessao: %d\n", horario_sessao);
    printf("Valor: %d\n", valor_final);
    printf("\t[1] Sim\n");
    printf("\t[2] Nao\n");
    scanf("%d", &cf);
    printf("================================================\n");
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

void gerar(nome, nome_filme, quant_bilhetes, horario_sessao, valor_final) {
    system("cls");
    printf("|-------------------------------------->>\n");
    printf("| \tINGRESSO DIGITAL\n");
    printf("| \tNOME:  %s\n", nome );
    printf("| \tFILME:  %s\n", nome_filme);
    printf("| \tBILHETE(S):  %d\n", quant_bilhetes);
    printf("| \tSESSAO:  %d\n", horario_sessao);
    printf("| \tVALOR:  %d\n", valor_final);
    printf("|-------------------------------------->>\n");


    FILE *arq;

    arq = fopen("ingresso.txt", "w");
    if (arq != NULL)
    {
        fprintf(arq, "%s" "%s" "%d" "%d" "%d", nome, nome_filme, quant_bilhetes, horario_sessao, valor_final);
    }
    else
    { 
        printf("ERRO!\n");
    }

    fclose(arq);

    getchar(); 
}