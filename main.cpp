#include <iostream>
#include <vector>
#include "SearchAlgorithms.hpp"
#include "SortAlgorithms.hpp"
#include "Benchmark.hpp"
#include "Analysis.hpp"
#include "Plotter.hpp"

// Tamanhos de entrada para os benchmarks
static const std::vector<int> SEARCH_SIZES = {100, 500, 1000, 5000, 10000, 50000, 100000};
static const std::vector<int> BUBBLE_SIZES = {100, 500, 1000, 2000, 5000, 10000};
static const std::vector<int> MERGE_SIZES  = {1000, 10000, 50000, 100000, 500000, 1000000, 5000000};
static const int REPETITIONS = 20;

// Executa benchmark, analise para um algoritmo de busca
void benchmarkSearch(const std::string& name, Benchmark::SearchFunc func) {
    auto data = Benchmark::runSearch(name, func, SEARCH_SIZES, REPETITIONS);
    auto fits = Analysis::analyze(data);
    Analysis::printResults(name, data, fits);

    // Integração com o Plotter
    Plotter plotter(name);
    for (const auto& [n, tempo] : data) {
        plotter.addData(n, tempo);
    }
    plotter.plot();
}

// Executa benchmark, analise para um algoritmo de ordenacao
void benchmarkSort(const std::string& name, Benchmark::SortFunc func,
                   const std::vector<int>& sizes) {
    auto data = Benchmark::runSort(name, func, sizes, REPETITIONS);
    auto fits = Analysis::analyze(data);
    Analysis::printResults(name, data, fits);

    Plotter plotter(name);
    for (const auto& [n, tempo] : data) {
        plotter.addData(n, tempo);
    }
    plotter.plot();
}


int main() {
    std::cout << "============================================" << std::endl;
    std::cout << "  Analise Empirica de Complexidade" << std::endl;
    std::cout << "  Algoritmos de Busca e Ordenacao" << std::endl;
    std::cout << "============================================" << std::endl;

    std::cout << "\n>>> ALGORITMOS DE BUSCA <<<\n" << std::endl;
    benchmarkSearch("Busca Sequencial", Search::sequentialSearch);
    benchmarkSearch("Busca Binaria", Search::binarySearch);

    std::cout << "\n>>> ALGORITMOS DE ORDENACAO <<<\n" << std::endl;
    benchmarkSort("Bubble Sort", Sort::bubbleSort, BUBBLE_SIZES);
    benchmarkSort("Merge Sort", Sort::mergeSort, MERGE_SIZES);

    std::cout << "\n============================================" << std::endl;
    std::cout << "  Analise e Plotagem concluidas com sucesso." << std::endl;
    std::cout << "============================================" << std::endl;

    return 0;
}