
/*Questão 1) Construir um programa em que o usuário insira/digite 10 nomes completos de pessoas 
(validar se o nome lido tem duas palavras no mínimo). Esses nomes devem ser transformados para
 maiúsculo e armazenados em um vetor de tamanho 10 (ou TAM 10). Ao final, esses nomes devem ser 
 exibidos. Contudo, o programa deve ser composto por métodos (com ou sem retorno).*/

#include <iostream> // Inclui a biblioteca para entrada e saida de dados
#include <string> // Inclui a biblioteca para manipulacao de textos

using namespace std; // Permite o uso direto de recursos como cout, cin e string

#include"utils.h" // Inclui o arquivo de cabecalho com as funcoes criadas

int main() { // Funcao principal onde o programa comeca a ser executado
    const int TAM = 10; // Define uma constante com o tamanho do vetor (10)
    string nomes[TAM]; // Cria o vetor de strings para armazenar os 10 nomes

    system("cls"); // Limpa a tela da tela do terminal

    for (int i = 0; i < TAM; i++) { // Loop para pedir e ler os 10 nomes
        string nomeCompleto; // Declara uma variavel temporaria para armazenar o nome lido
        
        cout << "Digite o nome completo (" << i + 1 << " de " << TAM << "): "; // Pede para o usuario digitar o nome
        getline(cin, nomeCompleto); // Le a linha inteira digitada (com espacos)

        // Estrutura de repeticao que obriga o usuario a digitar um nome valido
        while (!validarNome(nomeCompleto)) { // Executa enquanto o nome for invalido
            cout << "Nome invalido! O nome precisa ter no minimo duas palavras.\n"; // Mostra mensagem de erro
            cout << "Digite o nome completo novamente (" << i + 1 << " de " << TAM << "): "; // Pede o nome novamente
            getline(cin, nomeCompleto); // Le a nova tentativa do usuario
        } // Fim do loop de repeticao while

        nomes[i] = converterMaiusculo(nomeCompleto); // Converte o nome para maiusculo e salva no vetor
    } // Fim do loop de leitura for

    exibirNomes(nomes, TAM); // Chama o procedimento do utils.h para exibir todos os nomes

    return 1; // Retorna 1 finalizando o programa com sucesso
} // Fim da funcao main