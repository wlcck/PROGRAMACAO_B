/*Questão 3) Dado um arquivo texto chamado de nomes.txt, criar um programa que leia o arquivo e armazene esses nomes numa
 lista de nomes do tipo string. Ao final, exibir a lista populada com a quantidade de nomes lidos do arquivo. Exemplo 
 de arquivo nomes.txt Anderson Dick Guilherme Londero João Messias Alexandre Zamberlan Anderson Dick Guilherme Londero*/
#include <iostream>        // Inclui a biblioteca padrao de entrada e saida
#include <string>          // Inclui a biblioteca de manipulacao de textos

using namespace std;       // Usa o namespace padrao

#include "utils.h"         // Inclui o arquivo de cabecalho com os metodos criados

int main() {               // Funcao principal onde inicia o programa
    system("cls");         // Limpa a tela do terminal

    string nomeArquivo = "nomes.txt";    // Nome do arquivo texto exigido na questao
    const int TAM = 100;                 // Define o tamanho maximo suportado pelo vetor
    string nomes[TAM];                   // Vetor de strings para armazenar a lista de nomes

    // Teste condicional que valida a existencia do arquivo antes de tentar ler
    if (!existeArquivo(nomeArquivo)) {   // Chama a funcao existeArquivo do utils.h
        cout << "Erro: O arquivo " << nomeArquivo << " nao foi encontrado!" << endl;  // Exibe mensagem de erro
        return 1;                        // Encerra a execucao caso o arquivo nao exista
    }                                    // Fim do bloco if

    // Le os nomes contidos no arquivo nomes.txt e popula o vetor de strings
    int quantidadeLida = lerNomesArquivo(nomeArquivo, nomes, TAM);  // Guarda a quantidade total de nomes lidos

    // Exibe a lista de nomes populada junto da quantidade final
    exibirListaNomes(nomes, quantidadeLida);  // Chama o metodo de exibicao

    return 1;              // Finaliza o programa retornando 1
}                          // Fim da funcao main