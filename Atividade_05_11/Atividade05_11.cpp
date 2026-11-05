#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream> 

#include "meusUtilitarios.h" // Importa as funções criadas

using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao;
} Telefone;

int main() {
    vector<Telefone> listaSessoes;
    char opcao; 

    // Abre o arquivo 
    ifstream arquivo("telephony_sessions"); 
    if (!arquivo.is_open()) {
        arquivo.open("telephony_sessions.txt"); 
    }

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            if (!linha.empty()) {
                stringstream ss(linha);
                string primeiroNumero;
                
                
                if (ss >> primeiroNumero) { 
                    Telefone t;
                    t.numeroCelular = primeiroNumero;
                    t.dadosSessao = linha; 
                    listaSessoes.push_back(t);
                }
            }
        }
        arquivo.close();
        cout << "Base de dados carregada com sucesso! " << listaSessoes.size() << " registros encontrados.\n\n";
    } else {
        cout << "Aviso: Arquivo telephony_sessions nao localizado na pasta.\n\n";
    }

    do {
        cout << "MENU\n";
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone\n";
        cout << "3 - Finalizar ou encerrar o programa\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case '1': { 
                if (listaSessoes.empty()) {
                    cout << "Nenhum telefone cadastrado na base.\n\n";
                } else {
                    cout << "\n--- LISTA DE CELULARES ---\n";
                    for (size_t i = 0; i < listaSessoes.size(); i++) {
                        cout << listaSessoes[i].numeroCelular << "\n";
                    }
                    cout << "--------------------------\n";
                    cout << "Total de celulares exibidos: " << listaSessoes.size() << "\n\n";
                }
                break;
            }

            case '2': { 
                if (listaSessoes.empty()) {
                    cout << "Nenhum dado carregado para pesquisa.\n\n";
                } else {
                    string celularBuscado;
                    cout << "Digite o numero de celular que deseja pesquisar: ";
                    getline(cin, celularBuscado);

                    bool localizado = false;
                    cout << "\n--- RESULTADO DA BUSCA ---\n";
                    for (size_t i = 0; i < listaSessoes.size(); i++) {
                        if (listaSessoes[i].numeroCelular.find(celularBuscado) != string::npos) {
                            cout << "Celular: " << listaSessoes[i].numeroCelular << "\n";
                            cout << "Dados da Sessao: " << listaSessoes[i].dadosSessao << "\n";
                            cout << "--------------------------\n";
                            localizado = true;
                        }
                    }

                    if (!localizado) {
                        cout << "Nenhum registro localizado para o numero digitado.\n--------------------------\n\n";
                    }
                }
                break;
            }

            case '3': { 
                cout << "Obrigado por usar o sistema\n";
                break;
            }

            default: {
                cout << "Opcao invalida!\n\n";
                break;
            }
        }
    } while (opcao != '3');

    return 0;
}
