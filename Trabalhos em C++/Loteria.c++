#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    int num_escolhas = 6;
    int numero_min = 1;
    int numero_max = 60;

    srand(time(0));
    cout << "Bem vindo ao Jogo de Loteria!" << endl;
    cout << "Escolha os numeros que deseja jogar" << endl;

    while (true) {
        int escolhas_usuario[num_escolhas];

        // Coleta as escolhas do usuario.
        for (int i = 0; i < num_escolhas; i++) {
            do {
                cout << "Numero " << i + 1 << "): ";
                cin >> escolhas_usuario[i];

                // Verifica se a escolha está dentro dos limites e se não é repetida.
                if (escolhas_usuario[i] < numero_min || escolhas_usuario[i] > numero_max) {
                    cout << "Numero acima de 60. Tente novamente." << endl; // Exibe mensagem caso for acima de 60
                } else if (count(escolhas_usuario, escolhas_usuario + i, escolhas_usuario[i])) {
                    cout << "Numero repetido. Tente novamente." << endl; // Exibe mensagem caso for repetido
                }
            } while (escolhas_usuario[i] < numero_min || escolhas_usuario[i] > numero_max ||
                     count(escolhas_usuario, escolhas_usuario + i, escolhas_usuario[i]));
        }

        int numeros_sorteados[num_escolhas];
        for (int i = 0; i < num_escolhas; i++) {
            int numero;
            bool repetido;
            do {
                numero = rand() % numero_max + 1;
                repetido = false;
                for (int j = 0; j < i; j++) {
                    if (numero == numeros_sorteados[j]) {
                        repetido = true;
                        break;
                    }
                }
            } while (repetido);
            numeros_sorteados[i] = numero;
        }

        int num_acertos = 0;
        for (int i = 0; i < num_escolhas; i++) {
            for (int j = 0; j < num_escolhas; j++) {
                if (escolhas_usuario[i] == numeros_sorteados[j]) {
                    num_acertos++;
                    break;
                }
            }
        }

        // Exibe os números escolhidos, sorteados e a quantidade de acertos.
        cout << "\nNumeros escolhidos: ";
        for (int i = 0; i < num_escolhas; i++) {
            cout << escolhas_usuario[i] << " ";
        }
        cout << "\nNumeros sorteados : ";
        for (int i = 0; i < num_escolhas; i++) {
            cout << numeros_sorteados[i] << " ";
        }
        cout << "\nAcertos: " << num_acertos << endl;

        char jogar_novamente;
        cout << "Deseja tentar novamente? (S/N): ";
        cin >> jogar_novamente;

        // Converte a entrada para letras para minúsculas
        jogar_novamente = tolower(jogar_novamente);

        // Verifica se o usuario deseja jogar novamente.
        if (jogar_novamente == 's' || jogar_novamente == 'sim') {
            continue;  // Reinicia o loop para jogar novamente.
        } else if (jogar_novamente == 'n' || jogar_novamente == 'não' || jogar_novamente == 'nao') {
            cout << "Obrigado por jogar!" << endl;
            break;  // Encerra o loop do jogo.
        } else {
            cout << "Entrada invalida. Por favor, responda com 'S' ou 'N'." << endl;
        
        }
    }

    return 0;
}
