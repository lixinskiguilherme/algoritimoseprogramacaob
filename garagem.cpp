#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef struct {
    string marcaVeiculo;
    string placa;
    string cor;
    string horaEntrada;
    string horaSaida; //é necessário para informar o horário da saída.
    bool naGaragem;
} Veiculo;

// Esta função é necessário para fazer a transformação do tempo em horas para minutos
int converterParaMinutos(string horario) {
    int horas, minutos;
    char doisPontos;
    stringstream ss(horario);
    ss >> horas >> doisPontos >> minutos;
    return (horas * 60) + minutos;
}

int main() {
    vector<Veiculo> garagem;
    int opcao;
    
    do {
        cout << "Menu de opcoes:\n";
        cout << "1 - Adicionar veiculo\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Registrar horario de saida por placa\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

        switch (opcao) {
            case 1: {
                string marcaVeiculo, placa, cor, horaEntrada;
                Veiculo novoVeiculo; // cria um objeto temporário no struct para controlar
                cout << "Digite a marca e nome do veiculo: ";
                getline(cin, marcaVeiculo);
                cout << "Digite a placa do veiculo: ";
                getline(cin, placa);
                cout << "Digite a cor do veiculo: ";
                getline(cin, cor);
                cout << "Digite a hora de entrada do veiculo: [hh:mm] ";
                getline(cin, horaEntrada);
                
                novoVeiculo.marcaVeiculo = marcaVeiculo;
                novoVeiculo.placa = placa;
                novoVeiculo.cor = cor;
                novoVeiculo.horaEntrada = horaEntrada;
                novoVeiculo.horaSaida = "";
                novoVeiculo.naGaragem = true; //garante que ele está na garagem

                garagem.push_back(novoVeiculo);
                break;
            }

            case 2:
                cout << "Veiculos na garagem:\n";
                for (int i = 0; i < garagem.size(); i++) {
                    cout << "Marca veiculo: " << garagem[i].marcaVeiculo << "Placa: " << garagem[i].placa << ", Cor: " << garagem[i].cor << ", Hora de Entrada: " << garagem[i].horaEntrada;
                    if (!garagem[i].naGaragem) {
                            cout << " | Saida: " << garagem[i].horaSaida;
                        } else {
                            cout << " | Status: (Na garagem)";
                        }
                        cout << endl;
                    }
                break;

            case 3: {
                string placaBusca, horaSaida;
                cout << "Digite a placa do veiculo para registrar a saida: ";
                getline(cin, placaBusca);

                bool encontrado = false;
                for (size_t i = 0; i < garagem.size(); i++) {
                    if (garagem[i].placa == placaBusca) {
                        encontrado = true;
                        if (!garagem[i].naGaragem) {
                            cout << "Este veiculo ja registrou saida anteriormente.\n";
                            break;
                        }

                        cout << "Digite a hora de saida [hh:mm]: ";
                        getline(cin, horaSaida);
                        garagem[i].horaSaida = horaSaida;
                        garagem[i].naGaragem = false;

                        // Cálculo do tempo em minutos
                        int entradaMinutos = converterParaMinutos(garagem[i].horaEntrada);
                        int saidaMinutos = converterParaMinutos(horaSaida);
                        int tempoPermanencia = saidaMinutos - entradaMinutos;

                        if (tempoPermanencia < 0) {
                            tempoPermanencia += 24 * 60; // Caso passe da meia-noite
                        }

                        cout << "\n--- Saida Registrada ---\n";
                        cout << "Veiculo: " << garagem[i].marcaVeiculo << endl;
                        cout << "Tempo permanecido na garagem: " << tempoPermanencia << " minutos.\n";
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Veiculo com a placa " << placaBusca << " nao encontrado.\n";
                }
                break;
            }

            case 0:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);
    return 0;
}
