#include <iostream>
#include <string>
#include <vector>

// Definindo a estrutura de dados para o Produto
    struct produto
    {
    int codigo, qtde; // codigo e a quantidade do produto
    float preco; // preco do produto
    char nome; // nome do produto
    };

// função de vetor de estoque e variáveis auxiliares
    struct produto estoque[100];
    int totalProduto = 0;
    
    void registrarEntrada(char nome[], int codigo, float preco, int quantidade) {

        strcpy(estoque[totalProduto].nome, nome);
        estoque[totalProduto].codigo = codigo;
        estoque[totalProduto].preco = preco;
        estoque[totalProduto].quantidade = quantidade;
        totalProduto++;   
    };
    
// Função para registrar a venda de um produto
    void registrarVenda(int codigo) {

// verificando se o produto existe no estoque
    int indiceProduto = -1
    for (int i = 0; i < totalProduto; i++) {
        if (estoque[i].codigo == codigo) {
            indiceProduto = i
            break;
    }}

// funçao que se o produto não existir, exibe uma mensagem de erro
    if (indiceProduto == -1) {
        printf("Produto não encontrado\n");
        return;
    }

// função para que se a quantidade do produto for maior que zero, decrementa a quantidade
    if (estoque[indiceProduto.quantidade > 0]){
        estoque[indiceProduto].quantidade--;
    }
    else {
    printf("Produto esgotado\n");
    }
    }

// Função para gerar um relatório do estoque
    void gerarRelatorio() {
        // imprimindo um relatorio do estoque
        for(int i = 0; i < totalProduto; i++) {
        printf("Nome: %s\n" estoque[i].nome);
        printf("Codigo: %s\n" estoque[i].codigo);
        printf("Quantidade: %s\n" estoque[i].quantidade);
        printf("Preco: %s\n" estoque[i].preco);
        printf("------------------------\n");
    }}

// Função Principal
    int main() {
        int opcao;

// Loop princiapl do progama
    while (1) {
        printf("============MENU============\n")
        printf("2 Registrar venda de produto\n")
        printf("3 Gerar relatorio de estoque\n")
        print("4 Sair\n")
        printf("Escolha uma opnçao: ")
        scanf("%d", &opcao);

// Realiza uma ação de acordo com a opção escolhida pelo usuário
    switch (opcao) {
        case 1: {
        // Registrar entrada de produto
            char nome[50]
            int codigo;
            float preco;
            int quantidade;

            printf("Informe o nome do produto: ");
            scanf("%s", nome);

            printf("Informe o código do produto: ");
            scanf("%d", &codigo);

            printf("Informe o preço do produto: ");
            scanf("%f", &preco);

            printf("Informe a quantidade do produto: ");
            scanf("%d", &quantidade);

            registrarEntrada(nome, codigo, preco, quantidade);
            break;

        }

        case 2: {
// Registrar venda de produto
            int codigo;

            printf("Informe o código do produto: ");
            scanf("%d", &codigo);

            registrarVenda(codigo);
            break;
        }
        
        case 3:
// Gerar relatório de estoque
            gerarRelatorio();
            break;

        case 4:
            printf("Saindo...\n");
            return 0;

            default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }}}