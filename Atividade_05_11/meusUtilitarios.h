#ifndef MEUSUTILITARIOS_H
#define MEUSUTILITARIOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void contarLetra(string palavra, char letra) {
    int contador = 0;
    for (int i = 0; i < palavra.length(); i++) {
        if (palavra[i] == letra) {
            contador++;
        }
    }
    cout << "A letra '" << letra << "' aparece " << contador << " vez(es) na palavra \"" << palavra << "\"." << endl;
}

void verificarData(string diaStr, string mesStr, string anoStr) {
    int dia = atoi(diaStr.c_str());
    int mes = atoi(mesStr.c_str());
    int ano = atoi(anoStr.c_str());

    if (mes < 1 || mes > 12 || ano < 1 || dia < 1) {
        cout << "DATA INVALIDA" << endl;
        return;
    }

    int diasNoMes = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } 
    else if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    }

    if (dia <= diasNoMes) {
        cout << "DATA VALIDA" << endl;
    } else {
        cout << "DATA INVALIDA" << endl;
    }
}

int contarVogais(string frase) {
    int contador = 0;
    for (int i = 0; i < frase.length(); i++) {
        char letraAtual = tolower(frase[i]);
        if (letraAtual == 'a' || letraAtual == 'e' || letraAtual == 'i' || letraAtual == 'o' || letraAtual == 'u') {
            contador++;
        }
    }
    return contador;
}

string transformarMaiuscula(string frase) {
    for (int i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool verificarOrdenado(int vetor[], int tamanho) {
    if (tamanho <= 1) {
        return true;
    }
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false; 
        }
    }
    return true; 
}

string obtenerPrimeiroNome(string nomeCompleto) {
    size_t posicaoEspaco = nomeCompleto.find(' ');
    if (posicaoEspaco == string::npos) {
        return nomeCompleto;
    }
    return nomeCompleto.substr(0, posicaoEspaco);
}

int contarPalavrasNoArquivo(string nomeArquivo, string palavraBuscada) {
    ifstream procuradorArquivo; 
    procuradorArquivo.open(nomeArquivo.c_str());

    if (!procuradorArquivo) {
        cout << "Arquivo nao localizado. Programa encerrado." << endl;
        exit(0);
    } 
 
    string palavraLida;
    int contador = 0; 
    while (procuradorArquivo >> palavraLida) {
        if (palavraLida == palavraBuscada) {
            contador++; 
        }
    }
    procuradorArquivo.close();
    return contador;
}

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

    vector<string>::iterator it = std::remove(nomes.begin(), nomes.end(), nome);

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
    cout << "Dados salvos com sucesso nel arquivo!\n";
}

#endif

