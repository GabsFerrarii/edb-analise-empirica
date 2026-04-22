#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <vector>
#include <string>
#include <functional>
#include <utility>

namespace Benchmark {

    // Par (n, tempo_medio_ms)
    using TimingData = std::vector<std::pair<int, double>>;

    using SearchFunc = std::function<int(const std::vector<int>&, int)>;
    using SortFunc = std::function<void(std::vector<int>&)>;

    // Executa benchmark de um algoritmo de busca
    TimingData runSearch(const std::string& name,
                         SearchFunc func,
                         const std::vector<int>& sizes,
                         int repetitions);

    // Executa benchmark de um algoritmo de ordenação
    TimingData runSort(const std::string& name,
                       SortFunc func,
                       const std::vector<int>& sizes,
                       int repetitions);
}

#endif
