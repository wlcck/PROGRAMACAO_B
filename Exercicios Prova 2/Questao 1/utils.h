/*Questão 1) Construir um programa em que o usuário insira/digite 10 nomes completos de pessoas
 (validar se o nome lido tem duas palavras no mínimo). Esses nomes devem ser transformados para maiúsculo
  e armazenados em um vetor de tamanho 10 (ou TAM 10). Ao final, esses nomes devem ser exibidos. Contudo,
   o programa deve ser composto por métodos (com ou sem retorno).*/

#include <iostream> // Inclui a biblioteca para entrada e saida de dados (cout/cin)
#include <string> // Inclui a biblioteca para manipulacao de textos (string)

using namespace std; // Permite usar cout, cin e string sem o prefixo std::

// Funcao que recebe um nome e retorna verdadeiro se for valido e falso se nao for
bool validarNome(string nome) { // Declara a funcao validarNome que recebe uma string
    int espacos = 0; // Cria a variavel para contar a quantidade de espacos na string
    for (int i = 0; i < nome.length(); i++) { // Percorre a string da primeira ate a ultima letra
        if (nome[i] == ' ') { // Verifica se o caractere atual e um espaco em branco
            espacos++; // Aumenta o contador de espacos em 1
        } // Fim do bloco if do espaco
    } // Fim do loop for
    if (espacos >= 1) { // Verifica se encontrou pelo menos 1 espaco (2 palavras ou mais)
        return true; // Retorna verdadeiro indicando que o nome e valido
    } // Fim do bloco if de validacao
    return false; // Retorna falso se tiver menos de 1 espaco
} // Fim da funcao validarNome

// Funcao para converter todo o texto digitado para letras maiusculas
string converterMaiusculo(string texto) { // Declara a funcao que recebe e retorna uma string
    for (int i = 0; i < texto.length(); i++) { // Loop que percorre cada caractere do texto
        texto[i] = toupper(texto[i]); // Transforma o caractere da posicao 'i' em maiusculo
    } // Fim do loop for
    return texto; // Retorna o texto completo transformado em maiusculo
} // Fim da funcao converterMaiusculo

// Procedimento para imprimir a lista de nomes que estao no vetor
void exibirNomes(string nomes[], int tam) { // Declara a funcao void que recebe o vetor e o tamanho
    cout << "\n--- LISTA DE NOMES REGISTRADOS ---\n"; // Imprime o cabeçalho da lista na tela
    for (int i = 0; i < tam; i++) { // Loop para percorrer todas as posicoes do vetor
        cout << i + 1 << ". " << nomes[i] << endl; // Imprime a posicao (1 a 10) e o nome correspondente
    } // Fim do loop for
} // Fim do procedimento exibirNomes