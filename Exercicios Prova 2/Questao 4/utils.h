/*Questão 4) Complemento da questão 3. Agora, construir um método que localize e exiba os nomes replicados.*/

#include <iostream>        // Inclui a biblioteca para entrada e saida de dados
#include <fstream>         // Inclui a biblioteca para leitura de arquivos
#include <string>          // Inclui a biblioteca para manipulacao de texto

using namespace std;       // Permite o uso direto de cout, cin e string

// Metodo do modelo para verificar se o arquivo existe na pasta
bool existeArquivo(string nomeArquivo) {                  // Recebe o nome do arquivo e retorna verdadeiro ou falso
    ifstream arquivo;                                     // Cria a variavel para ler o arquivo
    arquivo.open(nomeArquivo);                            // Tenta abrir o arquivo informado
    if (!arquivo) {                                       // Se nao conseguir abrir o arquivo
        return false;                                     // Retorna falso indicando que nao existe
    }                                                     // Fim do bloco if
    arquivo.close();                                      // Fecha o arquivo
    return true;                                          // Retorna verdadeiro indicando que existe
}                                                         // Fim do metodo existeArquivo

// Metodo da Questao 3 para ler os nomes do arquivo
int lerNomesArquivo(string nomeArquivo, string nomes[], int tamMax) {    // Recebe o arquivo, vetor e tamanho maximo
    ifstream arquivo;                                     // Cria a variavel de leitura de arquivo
    arquivo.open(nomeArquivo);                            // Abre o arquivo de texto
    
    int quantidade = 0;                                   // Contador de nomes lidos
    string nomeLido;                                      // Variavel temporaria para armazenar cada nome

    while (getline(arquivo, nomeLido) && quantidade < tamMax) {   // Le linha por linha ate o fim do arquivo
        if (nomeLido != "") {                             // Verifica se a linha lida nao esta vazia
            nomes[quantidade] = nomeLido;                 // Armazena o nome na posicao atual do vetor
            quantidade++;                                 // Incrementa a quantidade de nomes lidos
        }                                                 // Fim do bloco if
    }                                                     // Fim do loop while

    arquivo.close();                                      // Fecha o arquivo apos a leitura
    return quantidade;                                    // Retorna o total de nomes lidos
}                                                         // Fim do metodo lerNomesArquivo

// Metodo auxiliar para exibir a lista completa de nomes
void exibirListaNomes(string nomes[], int quantidade) {   // Recebe o vetor de nomes e a quantidade lida
    cout << "LISTA DE NOMES POPULADA DO ARQUIVO:" << endl; // Imprime o titulo da lista
    for (int i = 0; i < quantidade; i++) {                // Loop para percorrer as posicoes preenchidas
        cout << i + 1 << ". " << nomes[i] << endl;        // Imprime a posicao e o nome
    }                                                     // Fim do loop for
    cout << "\nQuantidade de nomes lidos: " << quantidade << endl;  // Imprime o total lido
}                                                         // Fim do metodo exibirListaNomes

// Metodo SOLICITADO NA QUESTAO 4: Localiza e exibe apenas os nomes replicados
void exibirNomesReplicados(string nomes[], int quantidade) {  // Recebe a lista de nomes e a quantidade de elementos
    cout << "\nNOMES REPLICADOS ENCONTRADOS:" << endl;    // Imprime o titulo da busca
    bool encontrouReplicado = false;                      // Variavel para saber se achou algum nome repetido

    for (int i = 0; i < quantidade; i++) {                // Loop para testar cada nome da lista
        bool jaApareceuAntes = false;                      // Marca se o nome ja foi verificado em posicoes anteriores

        // Verifica se este nome ja apareceu em algum indice anterior
        for (int k = 0; k < i; k++) {                     // Loop que percorre do inicio ate a posicao atual
            if (nomes[i] == nomes[k]) {                   // Compara o nome atual com os anteriores
                jaApareceuAntes = true;                   // Se ja apareceu antes, altera a marca para verdadeiro
            }                                             // Fim do bloco if
        }                                                 // Fim do loop for secundario

        // Se o nome nao apareceu antes, conta quantas vezes ele aparece na lista inteira
        if (!jaApareceuAntes) {                           // Executa apenas se for a primeira vez que vê o nome
            int contagem = 0;                             // Contador de repeticoes do nome atual
            for (int j = 0; j < quantidade; j++) {        // Loop para percorrer a lista inteira novamente
                if (nomes[i] == nomes[j]) {               // Se encontrar um nome igual
                    contagem++;                           // Incrementa o contador de repeticoes
                }                                         // Fim do bloco if
            }                                             // Fim do loop for

            // Se o nome apareceu mais de 1 vez, significa que esta replicado
            if (contagem > 1) {                           // Teste condicional de replicacao
                cout << "- " << nomes[i] << " (Aparece " << contagem << " vezes)" << endl;  // Imprime o nome e total
                encontrouReplicado = true;               // Marca que pelo menos um replicado foi exibido
            }                                             // Fim do bloco if
        }                                                 // Fim do bloco if principal
    }                                                     // Fim do loop for principal

    if (!encontrouReplicado) {                            // Se a variavel continuar falsa
        cout << "Nenhum nome replicado foi encontrado." << endl;  // Informa que nao ha repeticoes
    }                                                     // Fim do bloco if
}                                                         // Fim do metodo exibirNomesReplicados