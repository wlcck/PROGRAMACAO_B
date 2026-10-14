/*Questão 2) Construir um programa que gere aleatoriamente n números inteiros e os armazene em um vetor de tamanho TAM.
 Contudo, é necessário criar um método que receba: a) o vetor com os números gerados automaticamente b) o tamanho
  desse vetor ou a quantidade de números inseridos no vetor c) um vetor de resultado que irá armazenar somente os pares*/
#include <iostream>        // Inclui a biblioteca para entrada e saida de dados

using namespace std;       // Permite o uso direto de cout, cin e endl

// Metodo para preencher o vetor com numeros aleatorios
void gerarNumerosAleatorios(int vet[], int tam) {        // Declara o metodo para gerar os numeros no vetor
    for (int i = 0; i < tam; i++) {                       // Loop que percorre todas as posicoes do vetor
        vet[i] = rand() % 100;                            // Gera um numero de 0 a 99 e armazena na posicao i
    }                                                     // Fim do loop for
}                                                         // Fim do metodo gerarNumerosAleatorios

// Metodo solicitado na questao:
// Recebe: a) vetor original, b) tamanho do vetor, c) vetor resultado para os pares
// Retorna: a quantidade de pares inseridos no vetor de pares
int extrairPares(int vetOriginal[], int tam, int vetPares[]) {    // Declara o metodo que retorna o total de pares
    int quantidadePares = 0;                                       // Contador para saber quantos pares foram encontrados
    for (int i = 0; i < tam; i++) {                               // Loop para percorrer o vetor original
        if (vetOriginal[i] % 2 == 0) {                            // Teste condicional para verificar se o numero e par
            vetPares[quantidadePares] = vetOriginal[i];           // Guarda o numero par no vetor de resultado
            quantidadePares++;                                     // Incrementa a quantidade de pares
        }                                                         // Fim do bloco if
    }                                                             // Fim do loop for
    return quantidadePares;                                       // Retorna a quantidade total de pares inseridos
}                                                                 // Fim do metodo extrairPares

// Metodo auxiliar para exibir o vetor na tela
void exibirVetor(int vet[], int tam) {                    // Declara o metodo para exibir o vetor
    for (int i = 0; i < tam; i++) {                       // Loop para percorrer as posicoes do vetor
        cout << vet[i] << " ";                             // Imprime o elemento seguido de um espaco
    }                                                     // Fim do loop for
    cout << endl;                                         // Salta uma linha ao finalizar a impressao
}                                                         // Fim do metodo exibirVetor