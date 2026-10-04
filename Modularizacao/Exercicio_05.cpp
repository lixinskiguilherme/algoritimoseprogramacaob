//fazer um programa que tenha um método que receba um vetor de números inteiros, o tamanho desse 
//vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado.

#include <iostream>

using namespace std;

#include "meusmetodos.h"

int main() {
    int tamanho;

    cout << "--- VERIFICADOR DE ORDENACAO ---" << endl;
    cout << "Quantos numeros tera o seu vetor? ";
    cin >> tamanho;

    // Criando o vetor com o tamanho definido pelo usuário
    int vetorUsuario[tamanho];

    // Laço para capturar cada número digitado
    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> vetorUsuario[i];
    }

    cout << "\n---------------------------------" << endl;
    cout << "Analisando o vetor..." << endl;

    // Chamando o método do 'meusmetodos.h' dentro do IF
    if (verificarOrdenado(vetorUsuario, tamanho)) {
        cout << "Resultado: O vetor ESTA ordenado de forma crescente!" << endl;
    } else {
        cout << "Resultado: O vetor NAO esta ordenado!" << endl;
    }
    cout << "---------------------------------" << endl;

    return 0;
}