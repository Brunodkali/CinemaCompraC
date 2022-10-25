#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 


// ---- Funções ---- //

void menu();
void filme1();
void filme2();
void filme3();
void comprar();
void pagamento();

// ---- Variaváveis Globais ---- //

int quant_bilhetes;
int horario_sessao;
int FP;
int op;
char sessao[61];

// ---- Início do código ---- //

int main(void) {

    menu();

    setlocale(LC_ALL, "");
    return 0;
}

void menu() {
    system("cls");
    printf("================================================\n");
    printf("\t\tCinema da Cidade\n");
    printf("================================================\n");

    printf("SELECIONE UMA DAS OPÇÕES ABAIXO:\n");
    printf("\t |--> FILMES EM CARTAZ <--| \n");
    printf("\t[1] | A Bela e a Fera | \n");
    printf("\t[2] | O mágico de OZ | \n");
    printf("\t[3] | Se eu fosse você 2 | \n");
    printf("\t[0] | Sair | \n");
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
            ("Opção inválida!");
            getchar();
            break;
    }
}

void filme1() {
    int ci;

    char nome_filme[61] = "A Bela e a Fera";
    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Esta é a história de Bela, uma jovem destemida que, em troca da liberdade do pai, oferece a sua companhia a um ser monstruoso que vive num castelo enfeitiçado. O que ela mais tarde vem a perceber é que, debaixo da sua estranha aparência, ele é na realidade um príncipe sob uma maldição...\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
        case 1:
            comprar(nome_filme);
            break;
        case 2:
            menu();
            break;
        default:
            ("Opção inválida!");
            getchar();
            break;
    }
    printf("================================================\n");
    getchar();
}

void filme2() {
    int ci;

    char nome_filme[61] = "O magico de OZ";
    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Dorothy e seu cachorro Totó são levados para a terra mágica de Oz quando um ciclone passa pela fazenda de seus avós no Kansas. Eles viajam em direção à Cidade Esmeralda para encontrar o Mago Oz e no caminho encontram um Espantalho, que precisa de um cérebro, um Homem de Lata sem um coração e um Leão Covarde que quer coragem....\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
        case 1:
            comprar(nome_filme);
            break;
        case 2:
            menu();
            break;
        default:
            ("Opção inválida!");
            getchar();
            break;
    }
    printf("================================================\n");
    getchar();
}

void filme3() {
    int ci;

    char nome_filme[61] = "Se eu fosse você 2";
    system("cls");

    printf("================================================\n");
    printf("Nome: %s\n", nome_filme);
    printf("\nSinopse:\n");
    printf("Cláudio e Helena estão prestes a se separar. Durante uma discussão, eles trocam de corpos mais uma vez e são obrigados a viver a vida do outro. Para complicar ainda mais a situação, a filha do casal está grávida e não sabe como contar aos pais...\n");
    printf("================================================\n");
    printf("\t[1] Comprar ingresso\n");
    printf("\t[2] Retornar ao menu\n");
    scanf("%d", &ci);
    switch (ci) {
        case 1:
            comprar(nome_filme);
            break;
        case 2:
            menu();
            break;
        default:
            ("Opção inválida!");
            getchar();
            break;
    }
    printf("================================================\n");
    getchar();
}

void comprar(nome_filme) {
    int cc;
    
    printf("Filme: %s\n", nome_filme);
    printf("Digite a quantidade de ingressos(Ex: 2, 3...):\n");
    scanf("%d", &quant_bilhetes);
    printf("================================================\n");
    printf("Selecione a sessao desejada:\n");
    if (nome_filme == "A Bela e a Fera")
    {
        printf("[1] Sessao 1 - Sala 2 15:00 Leg.\n");
        printf("[2] Sessao 2 - Sala 2 16:00 3D Dub.\n");
        printf("[3] Sessao 3 - Sala 3 15:30 Dub.\n");
    }
    else if (nome_filme == "O magico de OZ")
    {
        printf("[1] Sessao 1 - Sala 2 14:00 Leg.\n");
        printf("[2] Sessao 2 - Sala 2 15:00 3D Dub.\n");
        printf("[3] Sessao 3 - Sala 3 14:30 Dub.\n");
    }
    else
    {
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
    scanf("%d", &cc);
    switch (cc) {
        case 1:
            //imprimir();
            break;
        case 2:
            menu();
            break;
        default:
            ("Opção inválida!");
            getchar();
            break;
    }
    getchar();
}

void pagamento(){
     
}