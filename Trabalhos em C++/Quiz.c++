#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Estrutura para armazenar uma pergunta e suas opções
struct Pergunta {
    string textoPergunta;
    string opcoes[4];
    int opcaoCorreta;
};

// Função para fazer uma pergunta ao usuário e obter sua escolha
int fazerPergunta(const Pergunta& pergunta) {
    // Exibe a pergunta e suas opções para o usuário
    cout << pergunta.textoPergunta << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << pergunta.opcoes[i] << endl;
    }

    int escolhaUsuario;
    while (true) {
        // Solicita a escolha do usuário
        cout << "\nEscolha a opção correta (1-4): ";
        cin >> escolhaUsuario;

        // Verifica se a entrada é válida (apenas um caractere)
        if (cin.fail() || cin.peek() != '\n' || escolhaUsuario < 1 || escolhaUsuario > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opção inválida. Digite um número entre 1 e 4." << endl;
        } else {
            break;
        }
    }

    return escolhaUsuario;
}

int main() {
    // Inicialização do gerador de números aleatórios baseado no tempo atual
    srand(time(0));

    cout << "Seja Bem-Vindo ao Quizz C/C++ Guru Quest! \n" << endl;
    
    // Número total de perguntas no quizz
    const int numPerguntas = 12;
      Pergunta perguntas[numPerguntas] = {
        {
            "Qual utilidade da sigla &?",
            {"Mostrar o array", "Obter o endereço de uma variável", "Armazenar dados do arquivo", "Determinar que uma variável seja string"},
            1
        },
        {
            "Qual é a sintaxe correta para imprimir 'Hello, World!' em C++?",
            {"print >> ('Hello, World!');", "cout << 'Hello, World!';", "cin << 'Hello, World!';", "printf('Hello, World!');"},
            1
        },
        {
            "Qual é o resultado da expressão em C++ 5 + 3 * 2?",
            {"10", "16", "11", "13"},
            2
        },
        {
            "Qual é o tipo de variável que armazena múltiplos dados?",
            {"include <string>", "include <algorithm>", "array", "bool"},
            2
        },
        {
            "Qual tipo de loop em C++ é mais adequado para executar um bloco de código quando a condição de parada não é conhecida antes da execução do loop?",
            {"Loop for", "Todos os loops são igualmente adequados para esse cenário", "Loop while", "Loop do-while"},
            2
        },
        {
            "Em C++, o operador != é utilizado para:",
            {"Comparar dois vetores e verificar se eles têm o mesmo tamanho.", "Comparar se dois vetores ocupam a mesma quantidade de memória.", "Comparar se dois vetores têm elementos iguais.", "Comparar o valor de dois elementos individuais em um vetor."},
            3
        },
        {
            "Qual é a melhor maneira de encontrar o tamanho (número de elementos) de um vetor chamado numbers?",
            {"size(numbers)", "length(numbers)", "numbers.size()", "lengthof(numbers)"},
            1
        },
        {
            "Qual é o propósito principal do tipo void em C++?",
            {"Representar um tipo de dado indefinido.",
             "Indicar que uma função não retorna um valor.",
             "Definir uma variável que pode conter qualquer tipo de dado.",
             "Permitir a conversão de tipos de dados incompatíveis."},
            1
        },
        {
            "Qual é a definição correta de um vetor em C++?",
            {"Um tipo de dado usado para armazenar informações sobre matrizes", "Uma estrutura de dados que contém chaves e valores associados", "Um conjunto ordenado de elementos do mesmo tipo", "Uma coleção heterogênea de objetos"},
            2
        },
        {
            "Qual é a diferença entre bibliotecas de C e C++?",
            {"Bibliotecas de C são projetadas apenas para programas em C++, enquanto as de C++ são para ambos", "As bibliotecas de C não incluem funções matemáticas, enquanto as de C++ incluem", "Bibliotecas de C++ frequentemente fornecem recursos adicionais usando classes e recursos de programação orientada a objetos", "As bibliotecas de C são mais eficientes em termos de desempenho em comparação com as de C++"},
            3
        },
        {
            "Qual é uma diferença fundamental entre o uso de vetores com e sem a biblioteca vector em C++?",
            {"A biblioteca vector é menos eficiente em termos de uso de memória.",
             "Vetores com a biblioteca vector são mais rápidos.",
             "A biblioteca vector gerencia automaticamente o tamanho do vetor.",
             "Vetores sem a biblioteca vector não podem armazenar tipos de dados complexos, enquanto vetores com a biblioteca podem."},
            2
        },
        {
            "Qual é a diferença entre os operadores ++i e i++?",
            {"Não há diferença entre eles, ambos incrementam a variável i da mesma maneira.", "O operador ++i incrementa i e, em seguida, retorna o valor incrementado.", "O operador i++ retorna o valor de i e, em seguida, incrementa i.", "O operador ++i é usado em loops for e o operador i++ é usado em loops while."},
            2
        }
    };

    // Número de equipes participantes
    const int numEquipes = 3;
    // Número máximo de perguntas que cada equipe deve responder
    const int maxPerguntasPorEquipe = 4;
    // Pontuações iniciais de cada equipe
    int pontuacoes[numEquipes] = {0};

    int opcao;
    
    do {
        cout << "===== Qual equipe irá responder? =====" << endl;
        cout << "Digite 1 para encerrar o programa" << endl;
        // Exibe as opções de escolha de equipe para o usuário
        for (int i = 0; i < numEquipes; i++) {
            cout << "Digite " << i + 2 << " para Equipe " << i + 2 << endl;
        }
        cout << "======================================\n" << endl;

        cout << "Digite sua opção: ";
    
        // Verifica se a entrada é válida (apenas um caractere)
        while (!(cin >> opcao) || cin.peek() != '\n' || opcao < 1 || opcao > numEquipes + 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opção inválida. Digite novamente: ";
        }

        switch (opcao) {
            case 1:
                cout << "Programa encerrado!\n" << endl;
                cout << "Obrigado por jogar!\n" << endl;
                break;
            case 2:
            case 3:
            case 4: {
                // Calcula o índice da equipe selecionada
                int equipe = opcao - 2;
                int numPerguntasRespondidas = 0;
                vector<int> indicesPerguntasUsadas;

                // Loop para fazer perguntas para a equipe atual
                while (numPerguntasRespondidas < maxPerguntasPorEquipe) {
                    cout << "Equipe " << equipe + 2 << " está respondendo!\n" << endl;

                    int indicePergunta;
                    do {
                        // Seleciona um índice aleatório que não foi usado antes
                        indicePergunta = rand() % numPerguntas;
                    } while (find(indicesPerguntasUsadas.begin(), indicesPerguntasUsadas.end(), indicePergunta) != indicesPerguntasUsadas.end());

                    indicesPerguntasUsadas.push_back(indicePergunta);

                    // Chama a função para fazer a pergunta e obter a escolha do usuário
                    int escolhaUsuario = fazerPergunta(perguntas[indicePergunta]);
                    if (escolhaUsuario - 1 == perguntas[indicePergunta].opcaoCorreta) {
                        cout << "Resposta correta!\n" << endl;
                        pontuacoes[equipe]++;
                    } else {
                        cout << "Resposta incorreta!\n";
                        cout << "A resposta correta era: " << perguntas[indicePergunta].opcoes[perguntas[indicePergunta].opcaoCorreta] << "\n" << endl;
                    }
                    numPerguntasRespondidas++;
                }

                // Exibe a pontuação da equipe atual
                cout << "Equipe " << equipe + 2 << " respondeu a " << numPerguntasRespondidas << " perguntas e acertou " << pontuacoes[equipe] << " questões." << endl;
                cout << "Pontuação total da Equipe " << equipe + 2 << ": " << pontuacoes[equipe] << " pontos\n" << endl;
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente!\n" << endl;
                break;
        }
    } while (opcao != 1);

     cout << "\nPontuações Finais:" << endl;
    for (int equipe = 0; equipe < numEquipes; equipe++) {
        cout << "Equipe " << equipe + 2 << ": " << pontuacoes[equipe] << " pontos" << endl;
    }

    int pontuacaoMaxima = *max_element(pontuacoes, pontuacoes + numEquipes);
    vector<int> equipesVencedoras;
    for (int equipe = 0; equipe < numEquipes; equipe++) {
        if (pontuacoes[equipe] == pontuacaoMaxima) {
            equipesVencedoras.push_back(equipe + 2);
        }
    }

    cout << "\nEquipes vencedoras:" << endl;
    for (int vencedora : equipesVencedoras) {
        cout << "Equipe " << vencedora << endl;
    }


    return 0;
}
