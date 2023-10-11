#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Estrutura para armazenar informações da viagem
struct Viagem {
    double quilometrosRodados;
    double horasDescanso;
};

// Função para calcular o custo de cada quilômetro com base no preço do diesel (fixo em R$ 6,10 por litro)
double calcularCustoPorQuilometro() {
    return 6.10 / 5.0; // Supondo um consumo de 5 km por litro de diesel
}

// Função para obter entrada inteira
int obterEntradaInteira(const string& mensagem) {
    string input;

    while (true) {
        cout << mensagem;
        getline(cin, input);

        if (input.find_first_not_of("1234567890") != string::npos || input.empty()) {
            cout << "Entrada inválida. Por favor, insira um valor numérico." << endl;
        } else {
            return stoi(input);
        }
    }
}

// Função para obter entrada de ponto flutuante
double obterEntradaDouble(const string& mensagem) {
    string input;

    while (true) {
        cout << mensagem;
        getline(cin, input);

        if (input.find_first_not_of("1234567890.") != string::npos || input.empty()) {
            cout << "Entrada inválida. Por favor, insira um valor numérico ou ponto decimal." << endl;
        } else {
            return stod(input);
        }
    }
}

// Função para solicitar informações do usuário para uma viagem
void solicitarInformacoes(Viagem& viagem) {
    // Solicitar a quantidade de quilômetros rodados
    while (true) {
        viagem.quilometrosRodados = obterEntradaDouble("Informe a quantidade de quilômetros rodados (entre 700 e 7000 km): ");
        if (viagem.quilometrosRodados >= 700 && viagem.quilometrosRodados <= 7000) {
            break;
        } else {
            cout << "Valor inválido! A quilometragem deve estar entre 700 e 7000 km." << endl;
        }
    }
    
    // Solicitar o número de horas de descanso
    while (true) {
        viagem.horasDescanso = obterEntradaDouble("Informe o número de horas de descanso: ");
        if (viagem.horasDescanso >= 0) {
            break;
        } else {
            cout << "Valor inválido! O número de horas de descanso deve ser maior ou igual a 0." << endl;
        }
    }
}

// Função para gerar um relatório com o resumo da viagem
void gerarRelatorio(const Viagem& viagem, double custoPorQuilometro, const string& nomeUsuario) {
    // Cálculo do custo total da viagem
    double custoTotal = custoPorQuilometro * viagem.quilometrosRodados;

    // Imprimir o relatório
    cout << "Relatório para " << nomeUsuario << ":" << endl;
    cout << "Quilômetros Rodados: " << ceil(viagem.quilometrosRodados) << " km" << endl;
    cout << "Horas de Descanso: " << fixed << setprecision(2) << viagem.horasDescanso << " horas" << endl;
    cout << "Custo por Quilômetro: R$ " << custoPorQuilometro << endl;
    cout << "Custo Total da Viagem: R$ " << custoTotal << "00" << "\n" << endl;
}

int main() {
    int quantidadeUsuarios;
    
    // Solicitar o número de usuários com um limite de 15
    while (true) {
        quantidadeUsuarios = obterEntradaInteira("Informe a quantidade de usuários: ");

        if (quantidadeUsuarios >= 1 && quantidadeUsuarios <= 15) {
            break; // Sai do loop se a entrada estiver dentro do limite
        } else {
            cout << "Quantidade de usuários fora do limite permitido (1 a 15)." << endl;
        }
    }

    // Criar um vetor para armazenar informações das viagens de cada usuário
    vector<vector<Viagem>> usuariosViagens;
    vector<string> nomesUsuarios;

    // Solicitar informações para cada usuário
    for (int i = 0; i < quantidadeUsuarios; i++) {
        cout << "\nUsuário " << i + 1 << ":" << endl;
        
        // Solicitar o nome do usuário
        string nomeUsuario;
        cout << "Informe o nome do usuário: ";
        getline(cin, nomeUsuario);
        nomesUsuarios.push_back(nomeUsuario);

        // Solicitar informações de viagem para o usuário atual
        int quantidadeViagens;
        quantidadeViagens = obterEntradaInteira("Informe a quantidade de viagens para " + nomeUsuario + ": ");

        vector<Viagem> viagensUsuario;
        
        for (int j = 0; j < quantidadeViagens; j++) {
            Viagem viagem;
            cout << "\nViagem " << j + 1 << "\n" << endl;
            
            // Solicitar informações do usuário para a viagem atual
            solicitarInformacoes(viagem);

            // Adicionar a viagem ao vetor de viagens do usuário
            viagensUsuario.push_back(viagem);
        }

        // Adicionar as viagens do usuário ao vetor de viagens de todos os usuários
        usuariosViagens.push_back(viagensUsuario);
    }

    // Gerar relatórios para todas as viagens de todos os usuários
    cout << "\nRelatórios de Todas as Viagens:\n" << endl;

    for (int i = 0; i < quantidadeUsuarios; i++) {
        cout << "Usuário: " << nomesUsuarios[i] << "\n" << endl;
        for (int j = 0; j < usuariosViagens[i].size(); j++) {
            cout << "Viagem #" << j + 1 << "\n" << endl;
            gerarRelatorio(usuariosViagens[i][j], calcularCustoPorQuilometro(), nomesUsuarios[i]);
        }
    }

    return 0;
}
