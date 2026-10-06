#include <fstream>

bool existeArquivo(string nomeArquivo) {
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    if (!arquivo) {
        return false;
    }
    arquivo.close();   
    return true;
}


void exibirQuantasPalavrasArquivo(string palavra, string nomeArquivo) {
    ifstream arquivo;
    int contador = 0;
    string palavraAtual;
    arquivo.open(nomeArquivo);

    while (arquivo >> palavraAtual) {
        if (palavraAtual == palavra) {
            contador++;            
        }
    }
    cout << "Quantidade de " << palavra << " localizadas no arquivo: " << contador << endl;

    arquivo.close();
}

int contarQuantasPalavrasArquivo(string palavra, string nomeArquivo) {
    ifstream arquivo;
    int contador = 0;
    string palavraAtual;
    arquivo.open(nomeArquivo);

    while (arquivo >> palavraAtual) {
        if (palavraAtual == palavra) {
            contador++;            
        }
    }
    
    arquivo.close();
    return contador;
}
    bool validarCPF (string cpf){
        if ((cpf.length()==10)){
            return true;
        }
        return false;
 }

bool ValidarData (string data){
        if ((data.length()==10)){
            return true;
        }
        return false;
    }