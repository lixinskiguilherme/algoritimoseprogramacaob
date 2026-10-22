#ifndef MEUS_UTILITARIOS_H
#define MEUS_UTILITARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void inserir(vector<string>& nomes) {
    string nome;
    cout << "Digite o nome: ";
    getline(cin, nome);

    bool existe = false;
    for (size_t j = 0; j < nomes.size(); j++) {
        if (nome == nomes[j]) {
            existe = true;
            break;
        }
    }

    if (!existe) {
        nomes.push_back(nome);
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
}

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
}

void remover(vector<string>& nomes) {
    if (nomes.empty()) {
        cout << "Nenhum nome para remover.\n";
        return;
    }

    string nome;
    cout << "Digite o nome que deseja remover: ";
    getline(cin, nome);

    vector<string>::iterator it = remove(nomes.begin(), nomes.end(), nome);

    if (it != nomes.end()) {
        nomes.erase(it, nomes.end());
        cout << "Nome removido com sucesso!\n";
    } else {
        cout << "Nome não encontrado no vetor.\n";
    }
}

void carregarArquivo(vector<string>& nomes) {
    string nomeArquivo;
    cout << "Digite o nome do arquivo para importar (ex: dados.txt): ";
    getline(cin, nomeArquivo);

    ifstream arquivo(nomeArquivo.c_str());
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo ou o arquivo não existe.\n";
        return;
    }

    nomes.clear();
    string linha;
    while (getline(arquivo, linha)) {
        if (!linha.empty()) {
            nomes.push_back(linha);
        }
    }
    arquivo.close();
    cout << "Dados carregados com sucesso do arquivo!\n";
}

void salvarArquivo(const vector<string>& nomes) {
    if (nomes.empty()) {
        cout << "Não há dados para salvar.\n";
        return;
    }

    string nomeArquivo;
    cout << "Digite o nome do arquivo para salvar (ex: dados.txt): ";
    getline(cin, nomeArquivo);

    ofstream arquivo(nomeArquivo.c_str());
    if (!arquivo.is_open()) {
        cout << "Erro ao criar/abrir o arquivo para gravação.\n";
        return;
    }

    for (size_t i = 0; i < nomes.size(); i++) {
        arquivo << nomes[i] << endl;
    }
    arquivo.close();
    cout << "Dados salvos com sucesso no arquivo!\n";
}

#endif
