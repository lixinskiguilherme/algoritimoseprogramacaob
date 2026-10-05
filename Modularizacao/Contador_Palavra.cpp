#include <iostream>
#include <string>

using namespace std;

#include "utils.h"

int main() {
    string nomeArquivo;
    string palavra; 

    system("cls");
    
    cout << "Digite caminho e nome do arquivo: ";
    cin >> nomeArquivo;
    cin.ignore();

    //metodo que verifique se o arquivo existe sim ou não
    if (existeArquivo(nomeArquivo)) {
        cout << "Arquivo localizado com sucesso\n"; 
        cout << "Digite uma palavra ou frase de pesquisa: ";
        getline(cin, palavra);
        //exibirQuantasPalavrasArquivo(palavra, nomeArquivo);
        cout << "Total de palavras localizadas: " << contarQuantasPalavrasArquivo(palavra, nomeArquivo) << endl;
    } else {
        cout << "Problemas em localizar ou abrir o arquivo\n";
    }

    return 1;
}