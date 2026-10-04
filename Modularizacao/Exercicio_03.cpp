//fazer um programa que tenha um método que receba uma frase e retorne a quantidade de vogais presentes na frase.

#include <iostream>
#include <string>

using namespace std;

#include "meusmetodos.h"


int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Quantidade de vogais na frase: " << contarVogais(frase) << endl;
    
    return 1;
}