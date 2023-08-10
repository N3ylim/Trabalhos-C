#include <iostream>
#include <string>
#include <vector>

// Definindo a estrutura de dados para o Produto
struct Produto {
    int codigo, quantidade; // código e a quantidade do produto
    float preco; // preço do produto
    std::string nome; // nome do produto
};

// Vetor de estoque e variáveis auxiliares
std::vector<Produto> estoque;
int totalProduto = 0;

void registrarEntrada(std::string nome, int codigo, float preco, int quantidade) {
    Produto novoProduto;
    novoProduto.nome = nome;
    novoProduto.codigo = codigo;
    novoProduto.preco = preco;
    novoProduto.quantidade = quantidade;
    estoque.push_back(novoProduto);
    totalProduto++;
}

// Função para registrar a venda de um produto
void registrarVenda(int codigo) {
    // Verificando se o produto existe no estoque
    int indiceProduto = -1;
    for (int i = 0; i < totalProduto; i++) {
        if (estoque[i].codigo == codigo) {
            indiceProduto = i;
            break;
        }
    }

    // Se o produto não existir, exibe uma mensagem de erro
    if (indiceProduto == -1) {
        printf("Produto não encontrado\n");
        return;
    }

    // Se a quantidade do produto for maior que zero, decrementa a quantidade
    if (estoque[indiceProduto].quantidade > 0) {
        estoque[indiceProduto].quantidade--;
    } else {
        printf("Produto esgotado\n");
    }
}

// Função para gerar um relatório do estoque
void gerarRelatorio() {
    // Imprimindo um relatório do estoque
    for (int i = 0; i < totalProduto; i++) {
        printf("Nome: %s\n", estoque[i].nome.c_str());
        printf("Codigo: %d\n", estoque[i].codigo);
        printf("Quantidade: %d\n", estoque[i].quantidade);
        printf("Preco: %.2f\n", estoque[i].preco * estoque[i].quantidade);
        printf("------------------------\n");
    }
}

// Função Principal
int main() {
    int opcao;

    // Loop principal do programa
    while (true) {
        printf("============MENU============\n");
        printf("1 Registrar entrada de produto\n");
        printf("2 Registrar venda de produto\n");
        printf("3 Gerar relatorio de estoque\n");
        printf("4 Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Realiza uma ação de acordo com a opção escolhida pelo usuário
        switch (opcao) {
            case 1: {
                // Registrar entrada de produto
                std::string nome;
                int codigo, quantidade;
                float preco;

                printf("Informe o nome do produto: ");
                std::cin >> nome;

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
        }
    }

    return 0;
}
