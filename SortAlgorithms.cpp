#include "SortAlgorithms.h"

// Bubble Sort
void bubbleSort(int vetor[], int tamanho) {

    bool trocou;

    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 0; j < tamanho - i - 1; j++) { //irá pecorrer o vetor comparando pares
            if (vetor[j] > vetor[j + 1]) { // irá verificar se os dois elemnetos estão fora de ordem
                int temp = vetor[j]; // se estiver fora de ordem, irá guardar em uma variavel auxiliar para trocar 
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = true;
            }
        }

        if (!trocou) break; // otimizacao, se não ocorrer trocas irá parar
    }
}

// Merge Sort
void merge(int vetor[], int inicio, int meio, int fim) {

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* esquerda = new int[n1]; // vetores auxiliares para armazenar as duas partes
    int* direita = new int[n2];

    for (int i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i]; // irá copiar a metade esquerda

    for (int j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j]; // irá copiar a metade direita

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]){ //enquanto tiver elemento nas duas listas irá comparar os menores elementos e colocar o menor no vetor final 
            vetor[k] = esquerda[i];
            i++
        }
        else{
            vetor[k] = direita[j];
            j++
        }
        k++
    }

    while (i < n1) { // caso sobre elementos irá copiar na esquerda
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    
    while (j < n2) { // e na direita
        vetor[k] = direita[j];
        j++;
        k++;
    }

    delete[] esquerda;
    delete[] direita;
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) { // caso base, quando tiver apenas um elemento irá parar
        int meio = inicio + (fim - inicio) / 2; // divide no meio

        mergeSort(vetor, inicio, meio); //recursao para ficar dividindo o vetor na parte esquerda
        mergeSort(vetor, meio + 1, fim); // recursao para ficar dividindo o vetor na parte direita

        merge(vetor, inicio, meio, fim); //chama o merge para juntar 
    }
}