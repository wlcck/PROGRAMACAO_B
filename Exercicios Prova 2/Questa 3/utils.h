/*Questão 3) Dado um arquivo texto chamado de nomes.txt, criar um programa que leia o arquivo
 e armazene esses nomes numa lista de nomes do tipo string. Ao final, exibir a lista populada 
 com a quantidade de nomes lidos do arquivo. Exemplo de arquivo nomes.txt
  Anderson Dick Guilherme Londero João Messias Alexandre Zamberlan Anderson Dick Guilherme Londero*/
  #include <iostream>        // Inclui a biblioteca para entrada e saida de dados
#include <fstream>         // Inclui a biblioteca para leitura e escrita de arquivos
#include <string>          // Inclui a biblioteca para manipulacao de texto

using namespace std;       // Permite usar cout, cin e string sem o prefixo std::

// Metodo do modelo para verificar se o arquivo existe na pasta
bool existeArquivo(string nomeArquivo) {                  // Recebe o nome do arquivo e retorna verdadeiro ou falso
    ifstream arquivo;                                     // Cria a variavel de fluxo para ler o arquivo
    arquivo.open(nomeArquivo);                            // Tenta abrir o arquivo informado
    if (!arquivo) {                                       // Se nao conseguir abrir o arquivo
        return false;                                     // Retorna falso indicando que o arquivo nao foi encontrado
    }                                                     // Fim do bloco if
    arquivo.close();                                      // Fecha o arquivo
    return true;                                          // Retorna verdadeiro indicando que o arquivo existe
}                                                         // Fim do metodo existeArquivo

// Metodo para ler as linhas do arquivo e armazenar no vetor
int lerNomesArquivo(string nomeArquivo, string nomes[], int tamMax) {    // Recebe o nome do arquivo, vetor e o tamanho maximo
    ifstream arquivo;                                     // Cria a variavel de leitura do arquivo
    arquivo.open(nomeArquivo);                            // Abre o arquivo de texto
    
    int quantidade = 0;                                   // Contador de nomes lidos do arquivo
    string nomeLido;                                      // Variavel temporaria para guardar cada nome lido

    while (getline(arquivo, nomeLido) && quantidade < tamMax) {   // Le linha por linha ate o final do arquivo
        if (nomeLido != "") {                             // Verifica se a linha lida nao esta vazia
            nomes[quantidade] = nomeLido;                 // Guarda o nome lido na posicao atual do vetor
            quantidade++;                                 // Incrementa a quantidade de nomes armazenados
        }                                                 // Fim do bloco if
    }                                                     // Fim do loop while

    arquivo.close();                                      // Fecha o arquivo de texto apos finalizar a leitura
    return quantidade;                                    // Retorna o total de nomes armazenados na lista
}                                                         // Fim do metodo lerNomesArquivo

// Metodo para exibir a lista de nomes e a quantidade final
void exibirListaNomes(string nomes[], int quantidade) {   // Recebe o vetor de nomes e a quantidade total lida
    cout << "LISTA DE NOMES POPULADA DO ARQUIVO:" << endl; // Imprime o cabeçalho
    for (int i = 0; i < quantidade; i++) {                // Loop para percorrer as posicoes preenchidas do vetor
        cout << i + 1 << ". " << nomes[i] << endl;        // Imprime o numero da linha e o nome correspondente
    }                                                     // Fim do loop for
    cout << "\nQuantidade de nomes lidos do arquivo: " << quantidade << endl;  // Imprime a quantidade final de nomes
}                                                         // Fim do procedimento exibirListaNomes