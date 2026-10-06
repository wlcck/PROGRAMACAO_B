#include <iostream>
#include <string>

using namespace std;

#include "utils.h"

int main() {
    string NomeCompleto;

    system("cls");
    
    cout << "Digite o nome completo: ";
    getline(cin, nomeCompleto);
    string email = Geraremail(nomeCompleto);
    cout << "email gerado:" email \n";

    return 1;
} 