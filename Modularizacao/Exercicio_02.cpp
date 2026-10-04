//Fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). 
//O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas.

#include <iostream>
#include <string>

using namespace std;

#include "meusmetodos.h"

int main() {
    // 1. Criando as variáveis vazias que vão receber os dados do usuário
    string userDia, userMes, userAno;

    cout << "--- VALIDADOR DE DATAS ---" << endl;

    // 2. Capturando os dados que o usuário digitar no terminal
    cout << "Digite o dia (ex: 01 a 31): ";
    cin >> userDia;

    cout << "Digite o mes (ex: 01 a 12): ";
    cin >> userMes;

    cout << "Digite o ano (ex: 2024): ";
    cin >> userAno;

    cout << "\nResultado da analise: ";
    
    // 3. Enviando o que o usuário digitou para o método que está no 'meusmetodos.h'
    verificarData(userDia, userMes, userAno);

    cout << "--------------------------" << endl;

    return 0; 
}