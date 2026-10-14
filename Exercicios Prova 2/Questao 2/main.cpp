/*Questão 2) Construir um programa que gere aleatoriamente n números inteiros e os armazene em um vetor de tamanho
 TAM. Contudo, é necessário criar um método que receba: a) o vetor com os números gerados automaticamente b) 
 o tamanho desse vetor ou a quantidade de números inseridos no vetor c) 
 um vetor de resultado que irá armazenar somente os pares*/
 #include <iostream>        // Inclui a biblioteca padrao de entrada e saida
#include <string>          // Inclui a biblioteca de manipulacao de textos

using namespace std;       // Usa o namespace padrao

#include "utils.h"         // Inclui o arquivo com os metodos criados

int main() {               // Funcao principal onde o programa inicia
    system("cls");         // Limpa a tela do terminal

    const int TAM = 10;    // Define a constante do tamanho do vetor
    int vetOriginal[TAM];  // Declara o vetor que guardara os numeros gerados
    int vetPares[TAM];     // Declara o vetor que guardara apenas os pares

    gerarNumerosAleatorios(vetOriginal, TAM);     // Preenche o vetor original com numeros aleatorios

    cout << "Vetor Original:" << endl;            // Imprime mensagem indicando o vetor original
    exibirVetor(vetOriginal, TAM);                 // Exibe os elementos do vetor original

    // Chama o metodo passando: a) vetor original, b) tamanho, c) vetor resultado dos pares
    int qtdPares = extrairPares(vetOriginal, TAM, vetPares);    // Armazena o retorno com a quantidade de pares

    cout << "\nVetor Apenas com Pares:" << endl;  // Imprime mensagem indicando o vetor de pares
    exibirVetor(vetPares, qtdPares);               // Exibe apenas os elementos pares armazenados

    cout << "\nQuantidade de pares inseridos: " << qtdPares << endl;    // Imprime o total de pares inseridos

    return 1;              // Finaliza o programa retornando 1
}                          // Fim da funcao main