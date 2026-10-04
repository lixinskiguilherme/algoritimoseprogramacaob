//fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). 
//O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade;

#include <iostream>
#include <string>

#include "meusmetodos.h"

using namespace std;

int main() {
    // Definindo as variáveis de teste
    string minhaPalavra = "programacao";
    char minhaLetra = 'a';

    // Chamando o método criado acima
    contarLetra(minhaPalavra, minhaLetra);

    return 0; 
}