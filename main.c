#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante com o tamanho máximo de receitas e produtos
#define TAM 100

// Estrutura para armazenar uma receita
typedef struct {
    char nome[100];
    char ingredientes[300];
    char preparo[300];
    char valorNutricional[100];
} Receita;

// Estrutura para armazenar um produto
typedef struct {
    char nome[100];
    char descricao[200];
    float preco;
    char beneficios[200];
} Produto;

// Função para cadastrar uma nova receita
void cadastrarReceita(Receita receitas[], int *total) {
    if (*total >= TAM) {
        printf("Limite de receitas atingido.\n");
        return;
    }

    getchar(); // Limpa o buffer do teclado
    printf("\n--- Cadastrar Receita ---\n");
    printf("Nome da receita: ");
    fgets(receitas[*total].nome, sizeof(receitas[*total].nome), stdin);

    printf("Ingredientes: ");
    fgets(receitas[*total].ingredientes, sizeof(receitas[*total].ingredientes), stdin);

    printf("Modo de preparo: ");
    fgets(receitas[*total].preparo, sizeof(receitas[*total].preparo), stdin);

    printf("Valor nutricional: ");
    fgets(receitas[*total].valorNutricional, sizeof(receitas[*total].valorNutricional), stdin);

    (*total)++;
    printf("Receita cadastrada com sucesso!\n");
}

// Função para mostrar todas as receitas cadastradas
void listarReceitas(Receita receitas[], int total) {
    if (total == 0) {
        printf("Nenhuma receita cadastrada.\n");
        return;
    }

    printf("\n--- Lista de Receitas ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nReceita %d:\n", i + 1);
        printf("Nome: %s", receitas[i].nome);
        printf("Ingredientes: %s", receitas[i].ingredientes);
        printf("Preparo: %s", receitas[i].preparo);
        printf("Valor Nutricional: %s", receitas[i].valorNutricional);
    }
}

// Função para cadastrar um novo produto
void cadastrarProduto(Produto produtos[], int *total) {
    if (*total >= TAM) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    getchar(); // Limpa o buffer
    printf("\n--- Cadastrar Produto ---\n");
    printf("Nome do produto: ");
    fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);

    printf("Descrição: ");
    fgets(produtos[*total].descricao, sizeof(produtos[*total].descricao), stdin);

    printf("Preço (R$): ");
    scanf("%f", &produtos[*total].preco);

    getchar(); // Limpa buffer
    printf("Benefícios: ");
    fgets(produtos[*total].beneficios, sizeof(produtos[*total].beneficios), stdin);

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Função para mostrar todos os produtos cadastrados
void listarProdutos(Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos Naturais ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s", produtos[i].nome);
        printf("Descrição: %s", produtos[i].descricao);
        printf("Preço: R$ %.2f\n", produtos[i].preco);
        printf("Benefícios: %s", produtos[i].beneficios);
    }
}

// Função para simular o envio de receita pelo leitor (sem salvar)
void enviarReceitaLeitor() {
    char nome[100];
    char receita[500];

    getchar(); // Limpa buffer
    printf("\n--- Enviar Receita para o Blog ---\n");
    printf("Seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Sua receita (resumo): ");
    fgets(receita, sizeof(receita), stdin);

    printf("\nObrigado, %s", nome);
    printf("Receita enviada: %s\n", receita);
}

// Função principal com o menu
int main() {
    Receita receitas[TAM];
    Produto produtos[TAM];
    int totalReceitas = 0;
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n===== BLOG DE PRODUTOS FITNESS =====\n");
        printf("1 - Cadastrar receita\n");
        printf("2 - Listar receitas\n");
        printf("3 - Cadastrar produto natural\n");
        printf("4 - Listar produtos naturais\n");
        printf("5 - Enviar receita (leitor)\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarReceita(receitas, &totalReceitas);
                break;
            case 2:
                listarReceitas(receitas, totalReceitas);
                break;
            case 3:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 4:
                listarProdutos(produtos, totalProdutos);
                break;
            case 5:
                enviarReceitaLeitor();
                break;
            case 6:
                printf("Saindo do programa... Obrigado por usar!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}
