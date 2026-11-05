/*Atividade da Aula 05/11

A partir da base de telefonia https://github.com/alexandrezamberlan/pesquisa_ordenacao/blob/master/05-hash/problemaSessaoTelefonia/telephony_sessions.txt, criar um programa em C ou C++ para:*/

/*1) ler a base de telefonia e armazenar em um vector do tipo Telefone
    - o struct será:
        typedef struct {
            string numeroCelular;
            string dadosSessao;
        } Telefone;*/

       // vector<Telefone> listaSessoes;

 /*2) oferecer um menu para o usuário do tipo:
    - Menu
        1) Listar telefones e mostrar a quantidade
        2) Pesquisar por telefone (o usuario digita um numero de telefone e o sistema retorna seus dados de sessão)
        3) Finalizar ou encerrar programa 

3) reutilizar os métodos:*/
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao;
} Telefone;


void carregarDados(vector<Telefone> &listaSessoes, int &total) {
    ifstream arquivo("telephony_sessions.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo telephony_sessions.txt!" << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        if (linha != "") {
            int posicaoEspaco = linha.find(" ");
            
            Telefone t;
            t.numeroCelular = linha.substr(0, posicaoEspaco);
            t.dadosSessao = linha.substr(posicaoEspaco + 1);
            
            listaSessoes.push_back(t);
            total = total + 1;
        }
    }
    arquivo.close();
}


void listarTelefones(vector<Telefone> listaSessoes, int total) {
    cout << "\n--- LISTA DE TELEFONES ---\n";
    for (int i = 0; i < total; i = i + 1) {
        cout << listaSessoes[i].numeroCelular << endl;
    }
    cout << "Total de telefones listados: " << total << endl;
}

void pesquisarTelefone(vector<Telefone> listaSessoes, int total) {
    string telefoneProcurado;
    cout << "Digite o numero de celular: ";
    cin >> telefoneProcurado;

    int achou = 0;

    for (int i = 0; i < total; i = i + 1) {
        if (listaSessoes[i].numeroCelular == telefoneProcurado) {
            cout << "Dados de sessao: " << listaSessoes[i].dadosSessao << endl;
            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        cout << "Telefone nao encontrado!\n";
    }
}

int main() {
    vector<Telefone> listaSessoes;
    int total = 0;

    
    carregarDados(listaSessoes, total);

    int opcao = 0;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone e dados de sessao\n";
        cout << "3 - Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                listarTelefones(listaSessoes, total);
                break;

            case 2:
                pesquisarTelefone(listaSessoes, total);
                break;

            case 3:
                cout << "Obrigado por usar o sistema\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }

        if (opcao == 3) {
            break;
        }
    }

    return 0;
}