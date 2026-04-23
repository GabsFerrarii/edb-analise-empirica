#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>

// Funções originais com arrays C
void bubbleSort(int vetor[], int tamanho);
void mergeSort(int vetor[], int inicio, int fim);

// Wrappers com std::vector para uso no benchmark
namespace Sort {
    void bubbleSort(std::vector<int>& arr);
    void mergeSort(std::vector<int>& arr);
}

#endif
