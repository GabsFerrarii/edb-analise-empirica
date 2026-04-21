#include <iostream>
#include <vector>
#include <algorithm>
#include "SearchAlgorithms.hpp"

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 70;

    std::cout << "--- Teste de Algoritmos de Busca ---" << std::endl;

    int resSeq = Search::sequentialSearch(data, target);
    std::cout << "Busca Sequencial: " << (resSeq != -1 ? "Encontrado" : "Nao encontrado") << std::endl;

    std::sort(data.begin(), data.end());
    int resBin = Search::binarySearch(data, target);
    std::cout << "Busca Binaria: " << (resBin != -1 ? "Encontrado" : "Nao encontrado") << std::endl;

    return 0;
}