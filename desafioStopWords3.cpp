/*
Desafio em Arquivos txt

A ideia geral e principal é:
i) carregar os stop words do arquivo stopWords.txt em um lista de stopWords
ii) ler o arquivo do texto original e suas palavras
iii) comparar a palavra lida com as palavras na lista de stopWords
iv) descarregar em arquivo de saida as palavras do texto que não forem stop words

cultura in [a, as, o, os, um, uns, uma, umas]
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "util.h"

int main() {
    //rotina que carrega os stop words do arquivo para listaStopWords
    ifstream arquivoStopWords;
    vector<string> listaStopWords;
    arquivoStopWords.open("stopWords.txt");
    if (!arquivoStopWords) {
        cout << "Arquivo de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    } 

    //le o arquivo capturando as frases
	string linha;
	while (!arquivoStopWords.eof()) {
		getline(arquivoStopWords,linha); //lendo a linha inteira
        //colocar a linha para maiusculo
        linha = paraMaiusculoStringComRetorno(linha);

        listaStopWords.push_back(linha);
		
	}
	arquivoStopWords.close();
    //fim rotina que carrega os stop words do arquivo para listaStopWords


    //rotina que exiba os stop words inseridos na listaStopWords
    for (int i = 0; i < listaStopWords.size(); i++) {
        cout << listaStopWords[i] << ", ";
    }
    cout << "\n\n\n";
    //fim rotina que exiba os stop words inseridos na listaStopWords
    

    //rotina que abre e le arquivo original palavra por palavra
    ifstream arquivoTextoOriginal;
    string nomeArquivo;
    cout << "Digite caminho e nome do arquivo: ";
    cin >> nomeArquivo;
    arquivoTextoOriginal.open(nomeArquivo);

    if (!arquivoTextoOriginal) {
        cout << "Arquivo original para tratamento de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    } 

    ofstream arquivoTextoSemStopWords;
    arquivoTextoSemStopWords.open("arquivoTextoSemStopWords.txt");
    
    //para cada palavra lida, comparar na listaStopWords
    bool encontrou;
    string palavra;
    // O próprio '>>' faz a leitura e já serve como condição de parada segura
    while (arquivoTextoOriginal >> palavra) {
        // Aqui você analisa a palavra desejada
        palavra = paraMaiusculoStringComRetorno(palavra);
        
        //caso a palavra lida nao esteja na lista, adiciona-la no arquivo de saida
        encontrou = false;
        for (int i = 0; i < listaStopWords.size(); i++) {
            if (palavra == listaStopWords[i]) {
                encontrou = true;
                break;
            }
        }

        if (!encontrou) {
            arquivoTextoSemStopWords << palavra << " ";
        }
    }

    arquivoTextoOriginal.close();
    arquivoTextoSemStopWords.close();

    return 1;
}