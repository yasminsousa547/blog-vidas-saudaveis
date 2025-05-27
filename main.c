#include <stdio.h>
#include <stdlib.h>

#define TAM 100

// Structs
typedef struct {
    char nome[100];
    char ingredientes[300];
    char preparo[300];
    char valorNutricional[100];
} Receita;

typedef struct {
    char nome[100];
    char descricao[200];
    float preco;
    char beneficios[200];
} Produto;

// Funções de receita
void cadastrarReceita(Receita receitas[], int *total) {
    if (*total >= TAM) {
        printf("Limite de receitas atingido.\n");
        return;
    }

    printf("\n--- Cadastro de Receita ---\n");
    getchar(); // Limpa o buffer
    printf("Nome: ");
    fgets(receitas[*total].nome, sizeof(receitas[*total].nome), stdin);
    printf("Ingredientes: ");
    fgets(receitas[*total].ingredientes, sizeof(receitas[*total].ingredientes), stdin);
    printf("Modo de Preparo: ");
    fgets(receitas[*total].preparo, sizeof(receitas[*total].preparo), stdin);
    printf("Valor Nutricional: ");
    fgets(receitas[*total].valorNutricional, sizeof(receitas[*total].valorNutricional), stdin);

    // Remove o '\n' no final das strings
    receitas[*total].nome[strcspn(receitas[*total].nome, "\n")] = 0;
    receitas[*total].ingredientes[strcspn(receitas[*total].ingredientes, "\n")] = 0;
    receitas[*total].preparo[strcspn(receitas[*total].preparo, "\n")] = 0;
    receitas[*total].valorNutricional[strcspn(receitas[*total].valorNutricional, "\n")] = 0;

    (*total)++;
    printf("Receita cadastrada com sucesso!\n");
}

void listarReceitas(Receita receitas[], int total) {
    if (total == 0) {
        printf("Nenhuma receita cadastrada.\n");
        return;
    }

    printf("\n--- Lista de Receitas ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nReceita %d:\n", i + 1);
        printf("Nome: %s\n", receitas[i].nome);
        printf("Ingredientes: %s\n", receitas[i].ingredientes);
        printf("Preparo: %s\n", receitas[i].preparo);
        printf("Valor Nutricional: %s\n", receitas[i].valorNutricional);
    }
}

// Funções de produto
void cadastrarProduto(Produto produtos[], int *total) {
    if (*total >= TAM) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("\n--- Cadastro de Produto ---\n");
    getchar(); // Limpa o buffer
    printf("Nome: ");
    fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);
    printf("Descrição: ");
    fgets(produtos[*total].descricao, sizeof(produtos[*total].descricao), stdin);
    printf("Preço: R$ ");
    scanf("%f", &produtos[*total].preco);
    getchar(); // Limpa o buffer
    printf("Benefícios: ");
    fgets(produtos[*total].beneficios, sizeof(produtos[*total].beneficios), stdin);

    // Remove o '\n' no final das strings
    produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = 0;
    produtos[*total].descricao[strcspn(produtos[*total].descricao, "\n")] = 0;
    produtos[*total].beneficios[strcspn(produtos[*total].beneficios, "\n")] = 0;

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < total; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Preço: R$ %.2f\n", produtos[i].preco);
        printf("Benefícios: %s\n", produtos[i].beneficios);
    }
}

// Funções para salvar e carregar
void salvarReceitas(Receita receitas[], int total) {
    FILE *file = fopen("receitas.dat", "wb");
    if (file) {
        fwrite(receitas, sizeof(Receita), total, file);
        fclose(file);
    } else {
        printf("Erro ao salvar receitas.\n");
    }
}

int carregarReceitas(Receita receitas[]) {
    FILE *file = fopen("receitas.dat", "rb");
    int total = 0;
    if (file) {
        total = fread(receitas, sizeof(Receita), TAM, file);
        fclose(file);
    }
    return total;
}

void salvarProdutos(Produto produtos[], int total) {
    FILE *file = fopen("produtos.dat", "wb");
    if (file) {
        fwrite(produtos, sizeof(Produto), total, file);
        fclose(file);
    } else {
        printf("Erro ao salvar produtos.\n");
    }
}

int carregarProdutos(Produto produtos[]) {
    FILE *file = fopen("produtos.dat", "rb");
    int total = 0;
    if (file) {
        total = fread(produtos, sizeof(Produto), TAM, file);
        fclose(file);
    }
    return total;
}

// Função principal
int main() {
    Receita receitas[TAM];
    Produto produtos[TAM];
    int totalReceitas = carregarReceitas(receitas);
    int totalProdutos = carregarProdutos(produtos);
    int opcao;

    do {
        printf("\n===== BLOG - MERCADO NATURAL =====\n");
        printf("1. Cadastrar receita\n");
        printf("2. Listar receitas\n");
        printf("3. Cadastrar produto natural\n");
        printf("4. Listar produtos\n");
        printf("5. Sair\n");
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
                salvarReceitas(receitas, totalReceitas);
                salvarProdutos(produtos, totalProdutos);
                printf("Dados salvos. Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
