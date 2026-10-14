#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void inicializarVetor(vector<int> &v, int qtd, int valor) {
    for (int i = 0; i < qtd; i++) {
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
    for (int i = 0; i < qtd; i++) {
        numero = inicio + (rand() % (fim - inicio + 1));
        v.push_back(numero);
    }
}

void exercicio2(vector<int> vetorA, vector<int> vetorB, vector<int> &vetorResultado) {
    for (int i = 0; i < vetorA.size(); i++) {
        for (int j = 0; j < vetorB.size(); j++) {
            if (vetorA[i] == vetorB[j]) {
                
                // Evita adicionar números duplicados no vetor de resultados
                bool jaExiste = false;
                for (int k = 0; k < vetorResultado.size(); k++) {
                    if (vetorResultado[k] == vetorA[i]) {
                        jaExiste = true;
                        break;
                    }
                }
                
                // Se o número ainda não estiver no resultado, adiciona ele
                if (!jaExiste) {
                    vetorResultado.push_back(vetorA[i]);
                }
                break; 
            }
        }
    }
}

int main() {
    srand(time(NULL)); 

    vector<int> vetorA;
    vector<int> vetorB;
    vector<int> vetorResultado; // Criação do vetor que guardará as intersecções

    // Sorteando 10 números entre 1 e 15 para testar
    popularVetor(vetorA, 10, 1, 15);
    popularVetor(vetorB, 10, 1, 15);

    cout << "Vetor A:" << endl;
    exibirVetor(vetorA);

    cout << "Vetor B:" << endl;
    exibirVetor(vetorB);
    
    cout << endl;

    // Chamada da função passando os três vetores
    exercicio2(vetorA, vetorB, vetorResultado);

    // Exibindo o vetor resultado preenchido por referência
    cout << "Vetor Resultado (Elementos comuns):" << endl;
    if (vetorResultado.empty()) {
        cout << "Nenhum numero em comum foi encontrado." << endl;
    } else {
        exibirVetor(vetorResultado);
    }

    return 0;
}
