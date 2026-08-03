#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int main() {
    int opcao;
    int vetor[TAMANHO];
    int qtd_elementos = 0;
    srand(time(NULL));

    do {
        system("cls");
        printf("MENU PRINCIPAL\n");
        printf("1 - Popular vetor com numeros aleatorios\n");
        printf("2 - Listar vetor populado\n");
        printf("3 - Ordenar vetor\n");
        printf("4 - Calcular media aritmetica\n");
        printf("5 - Calcular e exibir a mediana\n");
        printf("6 - Exibir menor e maior valor\n"); 
        printf("7 - Sair do sistema\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Populando o vetor com numeros aleatorios\n");
                qtd_elementos = 0; // <-- zera qui para não acumular
                for (int i = 0; i < TAMANHO; i++) {
                    vetor[i] = rand() % 100;
                    qtd_elementos++;
                }
                break;
            case 2:
                printf("Listando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0){
                    for (int i = 0; i < TAMANHO; i++) {
                        printf("%d\t", vetor[i]);
                    }
                    printf("\n");
                } else {
                    printf("Vetor vazio. Nada a exibir\n");
                }
                break;
            case 3:
                printf("Ordenando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0){
                    // Implementação do Bubble Sort em C
                    int i, j, aux;
                    for (i = 0; i < TAMANHO - 1; i++) {
                        for (j = 0; j < TAMANHO - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                aux = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = aux;
                            }
                        }
                    }
                    printf("Vetor ordenado com sucesso! Use a opcao 2 para visualizar.\n");
                } else {
                    printf("Vetor vazio. Nada a ordenacao\n");
                }
                break;
            case 4: // <-- NOVO BLOCO: CÁLCULO DA MÉDIA
                printf("Calculando a media aritmetica\n");
                if (qtd_elementos > 0) {
                    float soma = 0;
                    for (int i = 0; i < TAMANHO; i++) {
                        soma += vetor[i];
                    }
                    float media = soma / TAMANHO; // <-- Divide direto por 10 (TAMANHO)
                    printf("A soma total dos elementos e: %.0f\n", soma);
                    printf("A media aritmetica dos elementos e: %.2f\n", media);
                } else {
                    printf("Vetor vazio. Impossivel calcular a media.\n");
                }
                break;

            case 5: // <-- NOVO BLOCO: CÁLCULO DA MEDIANA
                printf("Calculando a mediana dos valores\n");
                if (qtd_elementos > 0) {
                    // 1. Primeiro ordena o vetor (Bubble Sort)
                    int i, j, aux;
                    for (i = 0; i < TAMANHO - 1; i++) {
                        for (j = 0; j < TAMANHO - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                aux = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = aux;
                            }
                        }
                    }

                    // 2. Calcula a mediana (para TAMANHO = 10, pega os elementos nos índices 4 e 5)
                    float mediana;
                    if (TAMANHO % 2 == 0) {
                        mediana = (vetor[TAMANHO / 2 - 1] + vetor[TAMANHO / 2]) / 2.0;
                    } else {
                        mediana = vetor[TAMANHO / 2];
                    }

                    printf("Vetor ordenado para calculo da mediana:\n");
                    for (int k = 0; k < TAMANHO; k++) {
                        printf("%d\t", vetor[k]);
                    }
                    printf("\n");
                    printf("A mediana dos valores e: %.2f\n", mediana);
                } else {
                    printf("Vetor vazio. Impossivel calcular a mediana.\n");
                }
                break;

            case 6: // <-- NOVO BLOCO: MENOR E MAIOR VALOR
                printf("Localizando o menor e o maior valor\n");
                if (qtd_elementos > 0) {
                    int menor = vetor[0];
                    int maior = vetor[0];

                    for (int i = 1; i < TAMANHO; i++) {
                        if (vetor[i] < menor) {
                            menor = vetor[i];
                        }
                        if (vetor[i] > maior) {
                            maior = vetor[i];
                        }
                    }

                    printf("Menor valor do vetor: %d\n", menor);
                    printf("Maior valor do vetor: %d\n", maior);
                } else {
                    printf("Vetor vazio. Impossivel verificar os valores.\n");
                }
                break;

            case 7:
                printf("Sistema encerrado\n");
                break;
            default:
                printf("Opcao invalida. Redigite\n");
                break;
        }
        system("pause");
    } while (opcao != 7);
    return 0;
}

