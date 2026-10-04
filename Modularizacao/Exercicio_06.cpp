#include <iostream>
#include <string>
#include "meusmetodos.h" 

using namespace std;

int main() {
        
    string nomeCompleto;
    
    cout << "Digite o seu nome completo: ";
    getline(cin, nomeCompleto); // Lê o nome inteiro com espaços
    
    // Chama o método que está guardado no seu arquivo .h
    string primeiroNome = obterPrimeiroNome(nomeCompleto);
    
    cout << "O primeiro nome é: " << primeiroNome << endl;
    
    return 0;
}