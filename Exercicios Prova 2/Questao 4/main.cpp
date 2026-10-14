/*Questão 4) Complemento da questão 3. Agora, construir um método que localize e exiba os nomes replicados.*/

#include <iostream>        // Inclui a biblioteca padrao de entrada e saida
#include <string>          // Inclui a biblioteca de manipulacao de textos

using namespace std;       // Usa o namespace padrao

#include "utils.h"         // Inclui o arquivo de cabecalho com os metodos criados

int main() {               // Funcao principal onde o programa inicia
    system("cls");         // Limpa a tela do terminal

    string nomeArquivo = "nomes.txt";    // Nome do arquivo texto exigido na questao
    const int TAM = 100;                 // Define a capacidade maxima do vetor
    string nomes[TAM];                   // Vetor de strings para armazenar os nomes

    // Valida a existencia do arquivo usando a funcao do modelo
    if (!existeArquivo(nomeArquivo)) {   // Verifica se o arquivo nomes.txt existe
        cout << "Erro: O arquivo " << nomeArquivo << " nao foi encontrado!" << endl;  // Exibe mensagem de erro
        return 1;                        // Encerra caso o arquivo nao exista
    }                                    // Fim do bloco if

    // Le os nomes do arquivo e popula o vetor
    int quantidadeLida = lerNomesArquivo(nomeArquivo, nomes, TAM);  // Armazena a quantidade de nomes lidos

    // Exibe a lista completa populada (da Questao 3)
    exibirListaNomes(nomes, quantidadeLida);  // Chama o procedimento de exibicao

    // Chama o novo metodo da Questao 4 para exibir os nomes replicados
    exibirNomesReplicados(nomes, quantidadeLida);  // Exibe somente os nomes repetidos

    return 1;              // Finaliza o programa retornando 1
}                          // Fim da funcao main