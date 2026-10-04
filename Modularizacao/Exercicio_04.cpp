//fazer um programa que tenha um método que receba uma frase e retorne essa frase totalmente em maiúscula.

#include <iostream>
#include <string>

using namespace std;

#include "meusmetodos.h"

int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    // CORREÇÃO: Chamando a função da forma certa e ajustando o texto
    cout << "Frase em maiusculas: " << transformarMaiuscula(frase) << endl;
    
    return 0; // Boa prática: return 0 para indicar sucesso
}