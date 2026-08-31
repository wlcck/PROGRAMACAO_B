**Exercícios de fixação combinando funções com uso de arquivo texto**
 **1) Criar um programa que tenha uma função que receba uma frase e retorne a quantidade de vogais;**
 #include <iostream>
#include <string>

using namespace std;

// Função que conta as vogais sem usar comandos avançados
int contarVogais(string frase) {
    int contador = 0;

    // Passa por cada caractere da frase, um por um
    for (int i = 0; i < frase.length(); i++) {
        char letra = frase[i];

        // Testa cada possibilidade individualmente em linhas separadas
        if (letra == 'a') {
            contador = contador + 1;
        }
        if (letra == 'e') {
            contador = contador + 1;
        }
        if (letra == 'i') {
            contador = contador + 1;
        }
        if (letra == 'o') {
            contador = contador + 1;
        }
        if (letra == 'u') {
            contador = contador + 1;
        }
        if (letra == 'A') {
            contador = contador + 1;
        }
        if (letra == 'E') {
            contador = contador + 1;
        }
        if (letra == 'I') {
            contador = contador + 1;
        }
        if (letra == 'O') {
            contador = contador + 1;
        }
        if (letra == 'U') {
            contador = contador + 1;
        }
    }

    return contador;
}

int main() {
    string fraseDigitada;

    cout << "Digite a frase: ";
    getline(cin, fraseDigitada);

    int resultado = contarVogais(fraseDigitada);

    cout << "A frase contem " << resultado << " vogais." << endl;

    return 0;
}
**2) Criar um programa que tenha uma função que receba uma frase e um caracter de pesquisa. A função deve retornar a frase substituindo o caracter de pesquisa pelo símbolo @.
            Por exemplo, Frase: "Turma de Algoritmos"**

            #include <iostream>
#include <string>

using namespace std;

// Função que substitui o caractere desejado por '@'
string substituirCaractere(string frase, char letraProcurada) {
    // Passa por cada letra da frase, uma por uma
    for (int i = 0; i < frase.length(); i = i + 1) {
        
        // Se a letra atual for igual à letra procurada, troca por '@'
        if (frase[i] == letraProcurada) {
            frase[i] = '@';
        }
    }
    
    // Retorna a frase modificada
    return frase;
}

int main() {
    string texto;
    char letra;

    cout << "Digite uma frase: ";
    getline(cin, texto);

    cout << "Digite o caractere que deseja substituir: ";
    cin >> letra;

    // Chama a função e guarda o texto alterado
    string resultado = substituirCaractere(texto, letra);

    cout << "Resultado: " << resultado << endl;

    return 0;
}

  **3) Criar um programa que tenha duas funções:
            - função que receba uma frase e a retorne em maiúsculo
            - função que receba uma frase e retorne a quantidade de palavras**

  #include <iostream>
#include <string>

using namespace std;

// Função 1: Converte para maiúsculo sem usar toupper (usando a tabela ASCII)
string converterParaMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i = i + 1) {
        // Verifica se a letra é minúscula (entre 'a' e 'z')
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i] - 32; // Subtrai 32 do código ASCII da letra
        }
    }
    return frase;
}

// Função 2: Conta a quantidade de palavras
int contarPalavras(string frase) {
    if (frase.length() == 0) {
        return 0;
    }

    int palavras = 1;

    for (int i = 0; i < frase.length(); i = i + 1) {
        if (frase[i] == ' ') {
            palavras = palavras + 1;
        }
    }

    return palavras;
}

int main() {
    string texto;

    cout << "Digite uma frase: ";
    getline(cin, texto);

    string textoMaiusculo = converterParaMaiusculo(texto);
    int totalPalavras = contarPalavras(texto);

    cout << "Frase em maiusculo: " << textoMaiusculo << endl;
    cout << "Quantidade de palavras: " << totalPalavras << endl;

    return 0;
}


**4) Criar um programa que tenha duas funções:**
**- função que receba o nome de um arquivo texto (.csv, .txt, .json, .dat) e retorne True caso o arquivo exista; ou False, caso contrário;
            - função que receba o arquivo e retorne em uma string o conteúdo desse arquivo texto.**

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função 1: Verifica se o arquivo existe
bool arquivoExiste(string nome) {
    ifstream arquivo(nome);
    
    // Se o arquivo abriu com sucesso
    if (arquivo) {
        return true;
    } else {
        return false;
    }
}

// Função 2: Lê o conteúdo do arquivo
string lerArquivo(string nome) {
    ifstream arquivo(nome);
    string textoCompleto = "";
    string linha;

    // Lê linha por linha até o fim do arquivo
    while (getline(arquivo, linha)) {
        textoCompleto = textoCompleto + linha + "\n";
    }

    return textoCompleto;
}

int main() {
    string nomeDoArquivo;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;

    if (arquivoExiste(nomeDoArquivo)) {
        cout << "O arquivo existe!" << endl;
        cout << "Conteudo do arquivo:" << endl;
        cout << lerArquivo(nomeDoArquivo);
    } else {
        cout << "O arquivo NAO existe!" << endl;
    }

    return 0;
}


**5) Criar um programa que tenha uma função que receba um nome de arquivo texto e retorne a quantidade de vogais;**

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função que recebe o nome do arquivo e conta a quantidade de vogais
int contarVogaisArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;
    int contador = 0;

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha)) {
        
        // Passa por cada letra da linha atual
        for (int i = 0; i < linha.length(); i = i + 1) {
            char letra = linha[i];

            // Verifica cada vogal individualmente
            if (letra == 'a') { contador = contador + 1; }
            if (letra == 'e') { contador = contador + 1; }
            if (letra == 'i') { contador = contador + 1; }
            if (letra == 'o') { contador = contador + 1; }
            if (letra == 'u') { contador = contador + 1; }
            if (letra == 'A') { contador = contador + 1; }
            if (letra == 'E') { contador = contador + 1; }
            if (letra == 'I') { contador = contador + 1; }
            if (letra == 'O') { contador = contador + 1; }
            if (letra == 'U') { contador = contador + 1; }
        }
    }

    return contador;
}

int main() {
    string nomeDoArquivo;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;

    int totalVogais = contarVogaisArquivo(nomeDoArquivo);

    cout << "O arquivo possui " << totalVogais << " vogais." << endl;

    return 0;
}

**6) Criar um programa que tenha uma função que receba um nome de arquivo texto e um caracter de pesquisa. A função deve retornar uma string contendo o conteúdo do arquivo, contudo substituindo o caracter de pesquisa pelo símbolo @.
            Por exemplo, Frase: "Turma de Algoritmos"
                         Letra de pesquisa: 'a' 
                         Resultado: "Turm@ de @lgoritmos"**
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função que lee o arquivo e substitui o caractere por '@'
string substituirNoArquivo(string nomeArquivo, char letraProcurada) {
    ifstream arquivo(nomeArquivo);
    string textoResultado = "";
    string linha;

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha)) {
        
        // Passa por cada letra da linha atual
        for (int i = 0; i < linha.length(); i = i + 1) {
            
            // Se a letra for igual à procurada, troca por '@'
            if (linha[i] == letraProcurada) {
                linha[i] = '@';
            }
        }

        // Adiciona a linha modificada no resultado final com a quebra de linha (\n)
        textoResultado = textoResultado + linha + "\n";
    }

    return textoResultado;
}

int main() {
    string nomeDoArquivo;
    char letra;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;

    cout << "Digite o caractere que deseja substituir: ";
    cin >> letra;

    // Chama a função e exibe o resultado
    string resultado = substituirNoArquivo(nomeDoArquivo, letra);

    cout << "\nConteudo do arquivo modificado:" << endl;
    cout << resultado;

    return 0;
}

 **7) Criar um programa que tenha duas funções:
            - função que receba um nome de arquivo texto e a retorne uma string com todas as palavras em maiusculo;
            - função que receba um nome de arquivo texto e retorne a quantidade de palavras neste arquivo**

  #include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função 1: Lê o arquivo e retorna o conteúdo todo em maiúsculo
string converterArquivoMaiusculo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string textoMaiusculo = "";
    string linha;

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha)) {
        
        // Converte cada letra minúscula da linha para maiúscula (usando a tabela ASCII)
        for (int i = 0; i < linha.length(); i = i + 1) {
            if (linha[i] >= 'a' && linha[i] <= 'z') {
                linha[i] = linha[i] - 32;
            }
        }
        
        // Acumula a linha modificada no texto final
        textoMaiusculo = textoMaiusculo + linha + "\n";
    }

    return textoMaiusculo;
}

// Função 2: Conta a quantidade total de palavras no arquivo
int contarPalavrasArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string palavra;
    int contador = 0;

    // O operador '>>' lê o arquivo palavra por palavra (separadas por espaço ou Enter)
    while (arquivo >> palavra) {
        contador = contador + 1;
    }

    return contador;
}

int main() {
    string nomeDoArquivo;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;

    // Chama a primeira função
    string textoMaiusculo = converterArquivoMaiusculo(nomeDoArquivo);
    
    // Chama a segunda função
    int totalPalavras = contarPalavrasArquivo(nomeDoArquivo);

    // Exibe os resultados
    cout << "\nConteudo em maiusculo:" << endl;
    cout << textoMaiusculo << endl;

    cout << "Quantidade de palavras no arquivo: " << totalPalavras << endl;

    return 0;
}
