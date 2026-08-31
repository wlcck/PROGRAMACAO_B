7. Conta Bancária Simplificada (Alteração de Dados)
    Contexto: Um banco precisa atualizar saldos.
    * Struct: Conta (Número da Conta, Saldo).
    * Menu:
    1. Cadastrar conta (saldo inicial).
    2. Depositar: O usuário escolhe uma posição do vetor (índice) e soma um valor ao saldo existente.
    3. Mostrar todas as contas.
    4. Sair.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_CONTAS = 100;

struct Conta {
    int numeroConta;
    float saldo;
};

int main() {
    Conta banco[MAX_CONTAS];
    int totalContas = 0;
    int opcao = 0;

    do {
        cout << "\n--- BANCO ---\n";
        cout << "1. Cadastrar conta\n";
        cout << "2. Depositar\n";
        cout << "3. Mostrar todas as contas\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            if (totalContas < MAX_CONTAS) {
                cout << "\nDigite o numero da conta: ";
                cin >> banco[totalContas].numeroConta;

                cout << "Digite o saldo inicial (R$): ";
                cin >> banco[totalContas].saldo;

                totalContas = totalContas + 1;
                cout << "Conta cadastrada com sucesso!\n";
            } else {
                cout << "Limite de contas atingido!\n";
            }
        } 
        else if (opcao == 2) {
            if (totalContas == 0) {
                cout << "\nNenhuma conta cadastrada ate o momento.\n";
            } else {
                int indice;
                cout << "\nDigite o indice da conta (0 a " << (totalContas - 1) << "): ";
                cin >> indice;

                if (indice >= 0 && indice < totalContas) {
                    float valorDeposito;
                    cout << "Digite o valor para deposito (R$): ";
                    cin >> valorDeposito;

                    if (valorDeposito > 0) {
                        banco[indice].saldo = banco[indice].saldo + valorDeposito;
                        cout << "Deposito realizado com sucesso!\n";
                        cout << "Novo saldo da conta " << banco[indice].numeroConta 
                             << ": R$ " << banco[indice].saldo << endl;
                    } else {
                        cout << "Valor de deposito invalido!\n";
                    }
                } else {
                    cout << "Indice invalido!\n";
                }
            }
        } 
        else if (opcao == 3) {
            if (totalContas == 0) {
                cout << "\nNenhuma conta cadastrada ate o momento.\n";
            } else {
                cout << "\n--- LISTA DE CONTAS ---\n";
                for (int i = 0; i < totalContas; i = i + 1) {
                    cout << "Indice [" << i << "] | Conta: " << banco[i].numeroConta 
                         << " | Saldo: R$ " << banco[i].saldo << endl;
                }
            }
        } 
        else if (opcao == 4) {
            cout << "\nEncerrando o programa...\n";
        } 
        else {
            cout << "\nOpcao invalida. Tente novamente.\n";
        }

    } while (opcao != 4);

    return 0;
}
