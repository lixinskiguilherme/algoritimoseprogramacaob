
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Método que recebe a string e o char, conta as ocorrências e exibe o resultado
void contarLetra(string palavra, char letra) {
    int contador = 0;

    // Percorre cada caractere da palavra
    for (int i = 0; i < palavra.length(); i++) {
        if (palavra[i] == letra) { // Correção: usando == correto aqui
            contador++;
        }
    }

    // Exibe a quantidade encontrada (Correção: aspas e barras invertidas ajustadas)
    cout << "A letra '" << letra << "' aparece " << contador << " vez(es) na palavra \"" << palavra << "\"." << endl;
}

// Método para analisar a data
    void verificarData(string diaStr, string mesStr, string anoStr) {
    // Converte as strings recebidas para números inteiros
    int dia = atoi(diaStr.c_str());
	int mes = atoi(mesStr.c_str());
	int ano = atoi(anoStr.c_str());

    // Validação básica de limites para mês e ano
    if (mes < 1 || mes > 12 || ano < 1 || dia < 1) {
        cout << "DATA INVALIDA" << endl;
        return;
    }

    // Define a quantidade padrão máxima de dias para o mês atual
    int diasNoMes = 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        // Meses com exatamente 30 dias: abr, jun, set, nov
        diasNoMes = 30;
    } 
    else if (mes == 2) {
        // Regra para Fevereiro (Ano Bissexto)
        // Um ano é bissexto se for divisível por 4 e não por 100, OU se for divisível por 400
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    }

    // Verifica se o dia informado não estoura o limite permitido para o respectivo mês
    if (dia <= diasNoMes) {
        cout << "DATA VALIDA" << endl;
    } else {
        cout << "DATA INVALIDA" << endl;
    }
}

// Método que recebe uma frase e exibe a quantidade de vogais
int contarVogais(string frase) {
    int contador = 0;

    for (int i = 0; i < frase.length(); i++) {
        char letraAtual = tolower(frase[i]);

        if (letraAtual == 'a' || letraAtual == 'e' || letraAtual == 'i' || letraAtual == 'o' || letraAtual == 'u') {
            contador++;
        }
    }

    return contador; // IMPORTANTE: Devolve o número inteiro
}


//Metodo que converte as letras para maíusculas
string transformarMaiuscula(string frase) {
    // Percorre cada letra da frase
    for (int i = 0; i < frase.length(); i++) {
        // toupper() transforma a letra atual em maiúscula
        frase[i] = toupper(frase[i]);
    }
    
    return frase; // Retorna a frase toda em maiúsculas
}


// Método que recebe o vetor e seu tamanho, retornando true (ordenado) ou false (desordenado)
bool verificarOrdenado(int vetor[], int tamanho) {
    // Um vetor com 0 ou 1 elemento sempre é considerado ordenado
    if (tamanho <= 1) {
        return true;
    }

    // Percorre até o penúltimo elemento (tamanho - 1)
    for (int i = 0; i < tamanho - 1; i++) {
        // Se o elemento atual for maior que o próximo, o vetor NÃO está ordenado
        if (vetor[i] > vetor[i + 1]) {
            return false; 
        }
    }

    // Se passou por todo o laço sem quebrar a regra, está ordenado
    return true; 
}

// Método para extrair o primeiro nome
	string obterPrimeiroNome(string nomeCompleto) {
    // Encontra a posição do primeiro espaço em branco
    size_t posicaoEspaco = nomeCompleto.find(' ');
    
    // Se não encontrar nenhum espaço, retorna o nome inteiro digitado
    if (posicaoEspaco == string::npos) {
        return nomeCompleto;
    }
    
    // Retorna o recorte do texto da posição 0 até o espaço
    return nomeCompleto.substr(0, posicaoEspaco);
}