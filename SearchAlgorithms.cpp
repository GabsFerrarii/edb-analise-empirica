#include "SearchAlgorithms.hpp"

namespace Search {
    int sequentialSearch(const std::vector<int>& arr, int target) {
        for (size_t i = 0; i < arr.size(); ++i) { // percorre sequencialmente todo elemento do vetor
            if (arr[i] == target) return i; // se encontra o alvo, retorna a posicao
        }
        return -1;
    }

    int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) { // se essa condicao for verdadeira, a chave nao esta no vetor (tudo ja foi percorrido)
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid; // checa se o meio atual é a chave
            if (arr[mid] < target) left = mid + 1; // prossegue se a chave estiver na menor parte
            else right = mid - 1; // prossegue se a chave estiver na maior parte
        }
        return -1;
    }
}