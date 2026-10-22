#include <iostream>
#include <vector>
#include <limits>
#include "meusUtilitarios.h" // Importa as tuas funções criadas

using namespace std;

int main() {
    vector<string> nomes;
    int opcao;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir nome\n";
        cout << "2 - Listar nomes\n";
        cout << "3 - Pesquisar nome\n";
        cout << "4 - Remover nome\n";
        cout << "5 - Carregar de arquivo (.txt)\n";
        cout << "6 - Salvar em arquivo (.txt)\n";
        cout << "7 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                inserir(nomes);
                break;
            case 2:
                listar(nomes);
                break;
            case 3:
                pesquisar(nomes);
                break;
            case 4:
                remover(nomes);
                break;
            case 5:
                carregarArquivo(nomes);
                break;
            case 6:
                salvarArquivo(nomes);
                break;
            case 7:
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 7);

    return 0;
}
