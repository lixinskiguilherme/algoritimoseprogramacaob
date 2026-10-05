#include <iostream>
#include <string>
#include "meus_metodos.h" // Importa o seu arquivo de métodos

using namespace std; 

int main() {
    string nomeArquivo;
    cout << "Informe nome do arquivo: ";
    cin >> nomeArquivo;
    
    string palavraBuscada;
    cout << "Informe a palavra que deseja contar: ";
    cin >> palavraBuscada;
    
    // Chama o método que está isolado no outro arquivo
    int total = contarPalavrasNoArquivo(nomeArquivo, palavraBuscada);

    cout << "A palavra \"" << palavraBuscada << "\" aparece " << total << " vezes no texto." << endl;

    return 0;
}