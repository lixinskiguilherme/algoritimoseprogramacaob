#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void inicializarVetor(vector<int> &v, int qtd, int valor) {
    for (int i = 0; i < qtd; i++) { // Corrigido o espaço aqui
        v.push_back(valor);
    }
}

void exibirVetor(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    int numero;
    for (int i = 0; i < qtd; i++) { // Corrigido o espaço aqui
        numero = inicio + (rand() % (fim - inicio + 1));
        v.push_back(numero);
    }
}

void estatistica(vector<int> v, int *min, int *max) { // Corrigido de 'vctor' para 'vector'
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < *min) {
            *min = v[i];
        }
        if (v[i] > *max) {
            *max = v[i];
        }
    }
}

void exercicio1(vector<int> vetorA, vector<int> vetorB) {
    cout << "Numeros que aparecem nos dois vetores: " << endl;
    for (int i = 0; i < vetorA.size(); i++) {
        for (int j = 0; j < vetorB.size(); j++) {
            if (vetorA[i] == vetorB[j]) {
                cout << vetorA[i] << "\t";
                break; 
            }
        }
    }
    cout << endl;
}

int main() {
    srand(time(NULL)); 

    vector<int> vetorA;
    vector<int> vetorB;

    // Sorteando 10 números de 1 a 20 para aumentar as chances de repetição
    popularVetor(vetorA, 10, 1, 20);
    popularVetor(vetorB, 10, 1, 20);

    cout << "Vetor A:" << endl;
    exibirVetor(vetorA);

    cout << "Vetor B:" << endl;
    exibirVetor(vetorB);
    
    cout << endl;

    exercicio1(vetorA, vetorB);

    return 0;
}
