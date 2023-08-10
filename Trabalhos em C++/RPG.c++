#include <iostream> 
#include <string> //Biblioteca que permite manipular strings de caracteres 
#include <vector> //Biblioteca que permite criar e manipular vetores 
#include <algorithm> //Biblioteca quem contém componentes que executam operações algorítmicas em contêineres e outras sequências.


std::string toUpperCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);/*// std::transform é um algoritmo da biblioteca
    padrão que transforma os elementos de um intervalo usando uma função.*/
    return result;
// A função ::toupper é uma função da biblioteca padrão que converte um caractere para maiúsculo

}
using namespace std;
// serve para que você não precise ficar usando o "std"


// Classe para representar os equipamentos do personagem
class Equipamento {//cria um conjunto de classes e variaveis dentro de uma só classe de forma organizada
public: //significa que pode ser usado por qualquer parte do progama, é publico
    string nome;
    string tipo;
    string atributo;
    string valor;

//Criar váriaveis do tipo string e int
    Equipamento(string nome, string tipo, string atributo, string valor) {
        this->nome = nome;
        this->tipo = tipo;
        this->atributo = atributo;
        this->valor = valor;
//O uso do "this->" no construtor é uma forma de acessar os membros de dados da classe usando o ponteiro "this", que aponta para o objeto atual.        
    }
};
// Classe para representar a ficha de personagem
class FichaPersonagem {
public:
    string Nome;
    string Classe;
    string Nivel;
    string Raca;
    string Vida;
    string Ataque;
    string Velocidade;
    string Mana;
    vector<string> habilidades;
    vector<Equipamento> equipamentos;
// O "vector" é uma classe que fornece métodos para adicionar, remover e acessar elementos da sequência
    FichaPersonagem() {}
// Construtor vazio para permitir que o usuário crie seu próprio personagem.

    FichaPersonagem(string Nome, string Classe, string Nivel, string Raca, string Vida, string Ataque, string Velocidade, string Mana) {
        this->Nome = Nome;
        this->Classe = Classe;
        this->Nivel = Nivel;
        this->Raca = Raca;
        this->Vida = Vida;
        this->Ataque = Ataque;
        this->Velocidade = Velocidade;
        this->Mana = Mana;
    }

    void adicionarHabilidade(string habilidade) {/*Esta função recebe uma string habilidade como argumento e a
    adiciona essa habilidade ao vetor habilidades da classe à qual essa função pertence */
        habilidades.push_back(habilidade);
    }

    void adicionarEquipamento(string nome, string tipo, string atributo, string valor) {
        Equipamento equip(nome, tipo, atributo, valor); //cria um objeto de classe "equipamento" chamado "equip"
        equipamentos.push_back(equip); //O objeto equip é adicionado ao vetor Equipamentos
    }

    void removerEquipamento(string nome) {
        for (auto i = 0u; i < equipamentos.size(); i++) {
            if (equipamentos[i].nome == nome) {
                equipamentos.erase(equipamentos.begin() + i);
                break;
    /*percorre o vetor usando um loop for, verificando cada elemento para determinar
    se o nome corresponde ao nome de um equipamento. Se encontrar um equipamento com o mesmo nome, o método erase() é usado
    para remover o equipamento do vetor equipamentos*/
            }
        }
    }
    //Exibir a ficha
    void exibirFicha() {
        cout << "-------------------------- Ficha do Personagem --------------------------" << endl;
        cout << "Nome: " << Nome << endl;
        cout << "Classe: " << Classe << endl;
        cout << "Nivel: " << Nivel << endl;
        cout << "Raca: " << Raca << endl;
        cout << "Vida: " << Vida << endl;
        cout << "Ataque: " << Ataque << endl;
        cout << "Velocidade: " << Velocidade << endl;
        cout << "Mana: " << Mana << endl;
        cout << "Habilidades:" << endl;

        for (const auto& habilidade : habilidades) {
            cout << "- " << habilidade << endl;/* Para cada habilidade presente no vetor, o código exibe o
        nome da habilidade com um hífen antes, seguido de uma quebra de linha*/
        }

        cout << "Equipamentos:" << endl;/*. Para cada equipamento presente no vetor, o código exibe o
        nome, tipo, atributo e valor do equipamento, separados por vírgulas, com cada atributo em uma nova linha*/
        for (const auto& equip : equipamentos) {
            cout << "Nome: " << equip.nome << " - Tipo: " << equip.tipo << " - Atributo: " << equip.atributo << " - Valor: " << equip.valor << endl;
        }
        cout << "-------------------------------------------------------------------------" << endl;
    }
};

int main() {
    string resposta;
    cout << "Deseja criar uma ficha de personagem? (s/n): ";
    
    while (true) {
    cin >> resposta;

    // Converter a resposta para letras maiúsculas
    resposta = toUpperCase(resposta);

// Verificação da resposta do usuário para criar uma ficha personalizada
     if (resposta == "S" || resposta == "SIM") {
        // Criar um personagem personalizado
        string nome, classe, raca;
        string nivel, vida, ataque, velocidade, mana;

        cout << "Digite o nome do personagem: ";
        cin.ignore(); // Ignorar o caractere de nova linha pendente
        getline(cin, nome);

        cout << "Digite a classe do personagem: ";
        getline(cin, classe);

        cout << "Digite o nível do personagem: ";
        getline(cin, nivel);

        cout << "Digite a raça do personagem: ";
        getline(cin, raca);

        cout << "Digite a vida do personagem: ";
        getline(cin, vida);

        cout << "Digite o ataque do personagem: ";
        getline(cin, ataque);

        cout << "Digite a velocidade do personagem: ";
        getline(cin, velocidade);

        cout << "Digite a mana do personagem: ";
        getline(cin, mana);
//Usar as informações inseridas pelo usuário para criar a ficha do personagem na instância 'ficha' da classe FichaPersonagem

//Exibir ficha de acordo com as informações fornecidas pelo usuário
 cout << "-------------------------- Ficha do Personagem --------------------------" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Classe: " << classe << endl;
        cout << "Nivel: " << nivel << endl;
        cout << "Raca: " << raca << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Velocidade: " << velocidade << endl;
        cout << "Mana: " << mana << endl;
 
// Verificação da resposta do usuário para criar uma ficha pré definida
    } else if (resposta == "N" || resposta == "NÃO" || resposta == "NAO") {  
        // Usar as informações predefinidas
        FichaPersonagem ficha("Marney", "Assassino", "1", "Nephilim", "150", "200", "170", "100");
        ficha.adicionarHabilidade("Cura Instantanea");
        ficha.adicionarHabilidade("Teleporte");
        ficha.adicionarHabilidade("Superforca");
        ficha.adicionarHabilidade("Reflexos Sobrenaturais");
        ficha.adicionarEquipamento("Espada Simples", "Arma Branca", "Ataque", "50");
        ficha.adicionarEquipamento("Armadura de Pano", "Armadura", "Defesa", "0");

        //Exibindo a ficha
        ficha.exibirFicha();

// Exibir mensagem de resposta inválida caso o usuário tenha inserido uma resposta * inválida * 
    } else {
        cout << "Opção inválida, digite 's' para criar uma ficha ou 'n' para usar uma pré-definida: " << endl;
    }
    }
    return 0;
}