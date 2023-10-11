#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

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
            cout << "Entrada invalida. Por favor, insira um valor numérico." << endl;
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
            cout << "Entrada invalida. Por favor, insira um valor numérico ou ponto decimal." << endl;
        } else {
            return stod(input);
        }
    }
}

// Função para solicitar informações do usuário
void solicitarInformacoes(int& diaInicio, int& mesInicio, int& diaFim, int& mesFim, double& quilometrosRodados) {
    diaInicio = obterEntradaInteira("Informe o dia de inicio da viagem: ");
    mesInicio = obterEntradaInteira("Informe o mes de inicio da viagem: ");
    diaFim = obterEntradaInteira("Informe o dia de fim da viagem: ");
    mesFim = obterEntradaInteira("Informe o mes de fim da viagem: ");
    
    // Solicitar a quantidade de quilômetros rodados
    quilometrosRodados = obterEntradaDouble("Informe a quantidade de quilometros rodados (entre 700 e 7000 km): ");
    
    // Verificar se a quilometragem está dentro do intervalo permitido
    while (quilometrosRodados < 700 || quilometrosRodados > 7000) {
        cout << "Valor invalido! A quilometragem deve estar entre 700 e 7000 km." << endl;
        quilometrosRodados = obterEntradaDouble("Informe a quantidade de quilometros rodados (entre 700 e 7000 km): ");
    }
}

// Função para gerar um relatório com o resumo da viagem
void gerarRelatorio(double custoPorQuilometro, double quilometrosRodados, int diaInicio, int mesInicio, int diaFim, int mesFim) {
    // Cálculo do custo total da viagem
    double custoTotal = custoPorQuilometro * quilometrosRodados;

    // Imprimir o relatório
    cout << "Relatorio da Viagem do caminhao Scania R500" << endl;
    cout << "-------------------" << endl;
    cout << "Data de Inicio: " << setfill('0') << setw(2) << diaInicio << "/" << setfill('0') << setw(2) << mesInicio << endl;
    cout << "Data de Fim: " << setfill('0') << setw(2) << diaFim << "/" << setfill('0') << setw(2) << mesFim << endl;
    cout << "Quilometros Rodados: " << ceil(quilometrosRodados) << " km" << endl;
    cout << fixed << setprecision(2);
    cout << "Custo por Quilometro: R$ " << custoPorQuilometro << endl;
    cout << "Custo Total da Viagem: R$ " << custoTotal << endl;
}

int main() {
    int diaInicio, mesInicio, diaFim, mesFim;
    double quilometrosRodados;

    // Solicitar informações do usuário
    solicitarInformacoes(diaInicio, mesInicio, diaFim, mesFim, quilometrosRodados);

    // Chamando a função para gerar o relatório
    gerarRelatorio(calcularCustoPorQuilometro(), quilometrosRodados, diaInicio, mesInicio, diaFim, mesFim);

    return 0;
}
