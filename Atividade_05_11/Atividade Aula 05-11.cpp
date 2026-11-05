#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

#include "meusUtilitarios.h" // Importa as funções criadas

using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao;
} Telefone;

string *split(string frase, string delimitador = " ")
{
    string *vetor = (string *)malloc(sizeof(string) * 3); 
    int inicio = 0;
    int fim = frase.find(delimitador);
    int i = 0;
    while (fim != -1) {
        vetor[i] = frase.substr(inicio, fim - inicio);
        inicio = fim + delimitador.size();
        fim = frase.find(delimitador, inicio);
        i++;
    }
    vetor[i] = frase.substr(inicio, fim - inicio);

    return vetor;
}

void carregarBaseTelefonia(vector<Telefone>& listaSessoes) {
    ifstream arquivo("telephony_sessions.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo telephony_sessions.txt ou arquivo nao existe.\n\n";
        return;
    }

    listaSessoes.clear();
    string linha;

    while (getline(arquivo, linha)) {
        if (!linha.empty()) {
            // Supondo que o arquivo separa o telefone do resto por um delimitador (ex: espaço ou ponto-e-vírgula)
            // Se o split que você fez usa " ", ele quebrará a linha nas primeiras ocorrências.
            string* partes = split(linha, " "); 
            
            Telefone t;
            t.numeroCelular = partes[0]; // Primeira parte: número do celular
            
            // O restante da linha vira os dados da sessão (reconstruindo ou pegando as partes)
            t.dadosSessao = partes[1] + " " + partes[2]; 
            
            listaSessoes.push_back(t);
            free(partes); // Liberando o ponteiro alocado com malloc no split
        }
    }
    arquivo.close();
    cout << "Base de telefonia carregada com sucesso! Registros: " << listaSessoes.size() << "\n\n";
}

int main() {
    vector<Telefone> listaSessoes;
    string opcao;

    //método que carrega a base de telefonia e armazena numero de celular e dados de sessao no vector listaSessoes
    carregarBaseTelefonia(listaSessoes);

    do {
        cout << "MENU\n"
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone\n";
        cout << "3 - Finalizar ou encerrar o programa\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            "1": {
                if (listaSessoes.empty()) {
                cout << "Nenhum telefone cadastrado na base.\n\n";
                break;
                }
                
                cout << "\n--- LISTA DE CELULARES ---\n";
                for (size_t i = 0; i < listaSessoes.size(); i++) {
                    cout << listaSessoes[i].numeroCelular << "\n";
                }
                cout << "--------------------------\n";
                cout << "Total de celulares exibidos: " << listaSessoes.size() << "\n\n";
                break;
            }
                break;
            "2":
                if (listaSessoes.empty()) {
                    cout << "Nenhum dado carregado para pesquisa.\n\n";
                    break;
                }

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
                break;
            }
                break;
            "3":
                cout << "Obrigado por usar o sistema\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != "3");

    return 0;
}