#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define quant_bilhetes_MAX 10
#define valor_int 24
#define valor_meia 12

int codigo_filme;
int quant_bilhetes;
int valor_final;
int valor_bilhetes;
int horario_sessao;
int FP;
char nome[15];

void menu();
void filme();
void pagamento();
void imprimir();
void gerar();
void geracao();

//  Função main, responsável por iniciar o software.
int main(void) {
    menu();
    setlocale(LC_ALL, "");
    return 0;
}

// Função de menu, responsável por disponibilizar os filmes disponíveis e encaminha
// o código de cada filme como parâmetro para a próxima função.
void menu() {
    int op;

    system("cls");
    geracao();
    printf("\t\tCinema da Cidade\n");
    geracao();
    printf("\tSELECIONE UMA DAS OPCOES ABAIXO:\n\n");
    printf("\t |--> FILMES EM CARTAZ <--| \n\n");
    printf("\t[1] | A Bela e a Fera\n");
    printf("\t[2] | O Magico de OZ\n");
    printf("\t[3] | Se eu fosse voce 2\n");
    printf("\t[0] | Sair\n");
    geracao();
    scanf("%d", &op);
    switch (op) {
        case 1:
            filme(codigo_filme=1);
            break;
        case 2:
            filme(codigo_filme=2);
            break;
        case 3:
            filme(codigo_filme=3);
            break;
        default:
            printf("Opcao invalida!");
            getchar();
            break;
    }
    return;
}

// Função que disponibiliza informações referentes ao filme selecionado.
// Recebe como parâmetros o código do filme selecionado.
void filme(codigo_filme) {
    int ci;

    system("cls");
    if (codigo_filme == 1)
    {
        char nome_filme[61] = "A Bela e a Fera";

        geracao();
        printf("Nome: %s\n", nome_filme);
        printf("\nSinopse:\n");
        printf("Esta e a historia de Bela, uma jovem destemida que, em troca da liberdade do pai,\n");
        printf("oferece a sua companhia a um ser monstruoso que vive num castelo enfeiticado. O que ela mais tarde vem a perceber e que,\n");
        printf("debaixo da sua estranha aparencia, ele e na realidade um principe sob uma maldicao...\n");
        geracao();
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
        geracao();
        getchar();
    }
    else if (codigo_filme == 2)
    {
        char nome_filme[61] = "O magico de OZ";

        geracao();
        printf("Nome: %s\n", nome_filme);
        printf("\nSinopse:\n");
        printf("Dorothy e seu cachorro Toto sao levados para a terra magica de Oz quando um ciclone passa pela fazenda de seus avos no Kansas.\n");
        printf("Eles viajam em direcao a Cidade Esmeralda para encontrar o Mago Oz e no caminho encontram um Espantalho, que precisa de um cerebro,\n");
        printf("um Homem de Lata sem um coracao e um Leao Covarde que quer coragem....\n");
        geracao();
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
        geracao();
        getchar();
    }
    else if (codigo_filme == 3)
    {
        char nome_filme[61] = "Se eu fosse voce 2";

        geracao();
        printf("Nome: %s\n", nome_filme);
        printf("\nSinopse:\n");
        printf("Claudio e Helena estao prestes a se separar. Durante uma discussao, \n");
        printf("eles trocam de corpos mais uma vez e sao obrigados a viver a vida do outro.\n");
        printf("Para complicar ainda mais a situacao, a filha do casal esta gravida e nao sabe como contar aos pais...\n");
        geracao();
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
        geracao();
        getchar();
    }
    return;
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
        }
        else {
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
    return;
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
    return;
}

// Função que permite confirmar as informações ou retonar ao menu.
// Recebe como parâmetros o nome do usuário, forma de pagamento selecionada,
// nome do filme e o valor final da compra.
void imprimir(nome, FP, nome_filme, valor_final) {
    int cf;

    // if (FP = 1)
    // {
    //     char Pag[61] = "Cartao de debito";
    // }
    // else if (FP = 2)
    // {
    //     char Pag[61] = "Cartao de credito";
    // }
    // else if (FP = 3)
    // {
    //     char Pag[61] = "Dinheiro (cedula)";
    // }
    // else if (FP = 4)
    // {
    //     char Pag[61] = "Pix";;
    // }
    
    system("cls");
    geracao();
    printf("Confirme as informacoes abaixo: \n");
    printf("Nome: %s\n", nome);
    printf("Forma de pagamento: %s\n", FP);
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
    return;
}

// Função que recebe como parâmetro o nome do usuário, nome do filme, quantidade de bilhetes,
// sessão selecionada e valor final a ser pago.
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
    return;
}

// Workaround para gerar conteúdo visual
void geracao() {
    printf("================================================\n");
    return;
}