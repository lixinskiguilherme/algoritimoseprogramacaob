#include <iostream>
#include <string>
#include "meusmetodos.h" // Importa a sua biblioteca de métodos

using namespace std;

int main() {
    string nomeArquivo;
    cout << "Informe o nome do arquivo: ";
    cin >> nomeArquivo;

    string palavraBuscada;
    cout << "Informe a palavra que deseja contar: ";
    cin >> palavraBuscada;

    // O método executa, conta e RETORNA o número inteiro.
    // Nós guardamos esse retorno dentro da variável 'total'.
    int total = contarPalavrasNoArquivo(nomeArquivo, palavraBuscada);

    // Agora exibimos o valor que foi retornado
    cout << "A palavra \"" << palavraBuscada << "\" aparece " << total << " vezes no texto." << endl;

    return 0;
}
