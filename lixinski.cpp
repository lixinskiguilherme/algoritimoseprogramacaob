#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

void inserir(vector<string>& nomes) {
    string nome;
    int quantidadeInseridos = 0;

    cout << "Digite o nome: ";
    getline(cin, nome);
    fflush(stdin);
    //rotina que verifica se o nome ja esta no vetor de nomes
    bool existe = false;
    for (int j = 0; j < quantidadeInseridos; j++) {
    	if (nome == nomes[j]) {
    	existe = true;
    	break; //forçar a saida do for com o j
    	}
    }
        if (!existe) {
        nomes[quantidadeInseridos] = nome;
        quantidadeInseridos++;
        } 
			else {
            cout << "Nome ja cadastrado..." << endl;
            }
    }
    

void listar(const vector<string>& nomes) {
    if (nomes.empty()) {
        cout << "Nenhum nome cadastrado.\n";
        return;
    }

    cout << "\nNomes cadastrados:\n";
    for (int i = 0; i < nomes.size(); i++) {
        cout << i + 1 << " - " << nomes[i] << "\n";
    }
    
void pesquisar(const vector<string>& nomes) {
    string nome;
	
	//complete o código abaixo
    cout << "Digite o nome que deseja pesquisar: ";
    getline(cin, nome);
    int quantidadeLocalizados = 0;
    for (int i = 0; i < quantidadeInseridos; i++) {
    if (nomes[i].find(nome) != std::string::npos) {
    cout << nomes[i] << endl;
    quantidadeLocalizados++;
        }
    }
    cout << "-----------------" << endl;
    cout << "Total de registros: " << quantidadeLocalizados << endl;
    }
    break;

//Criar método remover nomes;

void remover(vector<string>& nomes) { // 1. Removido o 'const' para permitir alterações
    // 2. Limpa o buffer do teclado para evitar que o getline seja pulado
    cin.ignore(); 

    string nome;
    cout << "Digite o nome que deseja remover: ";
    getline(cin, nome);

    // 3. Lógica para encontrar e remover o nome do vetor
    auto it = remove(nomes.begin(), nomes.end(), nome);

    if (it != nomes.end()) {
        nomes.erase(it, nomes.end()); // Apaga efetivamente do vetor
        cout << "Nome removido com sucesso!\n";
    } else {
        cout << "Nome não encontrado no vetor.\n";
    }
}

 
int main() {
    vector<string> nomes;
    int opcao;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir nome\n";
        cout << "2 - Listar nomes\n";
        cout << "3 - Pesquisar nome\n";
        cout << "4 - Remover nome\n";
        cout << "5 - Sair\n";#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

void inserir(vector<string>& nomes) {
    string nome;
    cout << "Digite o nome: ";
    getline(cin, nome);

    // Verifica se o nome já existe no vetor
    bool existe = false;
    for (size_t j = 0; j < nomes.size(); j++) {
        if (nome == nomes[j]) {
            existe = true;
            break;
        }
    }

    if (!existe) {
        nomes.push_back(nome); // Adiciona dinamicamente ao final do vetor
        cout << "Nome cadastrado com sucesso!\n";
    } else {
        cout << "Nome ja cadastrado...\n";
    }
}

void listar(const vector<string>& nomes) {
    if (nomes.empty()) {
        cout << "Nenhum nome cadastrado.\n";
        return;
    }

    cout << "\nNomes cadastrados:\n";
    for (size_t i = 0; i < nomes.size(); i++) {
        cout << i + 1 << " - " << nomes[i] << "\n";
    }
} // <--- Chave que faltava para fechar a função listar

void pesquisar(const vector<string>& nomes) {
    string nome;
    cout << "Digite o nome que deseja pesquisar: ";
    getline(cin, nome);
    
    int quantidadeLocalizados = 0;
    for (size_t i = 0; i < nomes.size(); i++) {
        if (nomes[i].find(nome) != string::npos) {
            cout << nomes[i] << endl;
            quantidadeLocalizados++;
        }
    }
    cout << "-----------------" << endl;
    cout << "Total de registros: " << quantidadeLocalizados << endl;
} // <--- Removido o 'break' solto que estava aqui

void remover(vector<string>& nomes) {
    if (nomes.empty()) {
        cout << "Nenhum nome para remover.\n";
        return;
    }

    string nome;
    cout << "Digite o nome que deseja remover: ";
    getline(cin, nome);

    // Lógica para encontrar e remover o nome do vetor
    auto it = remove(nomes.begin(), nomes.end(), nome);

    if (it != nomes.end()) {
        nomes.erase(it, nomes.end()); // Apaga efetivamente do vetor
        cout << "Nome removido com sucesso!\n";
    } else {
        cout << "Nome não encontrado no vetor.\n";
    }
}

int main() {
    vector<string> nomes;
    int opcao;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir nome\n";
        cout << "2 - Listar nomes\n";
        cout << "3 - Pesquisar nome\n";
        cout << "4 - Remover nome\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        // Limpa o buffer para evitar problemas com o getline
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
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 5);

    return 0;
}
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
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 5);

