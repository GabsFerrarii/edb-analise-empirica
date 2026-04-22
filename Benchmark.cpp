#include "Benchmark.hpp"
#include <chrono>
#include <random>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace Benchmark {

    // Gera vetor aleatorio de tamanho n
    static std::vector<int> generateRandomVector(int n, unsigned int seed) {
        std::mt19937 gen(seed);
        std::uniform_int_distribution<int> dist(1, n * 10);
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = dist(gen);
        }
        return vec;
    }

    // Gera vetor ordenado de 1 a n
    static std::vector<int> generateSortedVector(int n) {
        std::vector<int> vec(n);
        std::iota(vec.begin(), vec.end(), 1);
        return vec;
    }

    TimingData runSearch(const std::string& name,
                         SearchFunc func,
                         const std::vector<int>& sizes,
                         int repetitions) {
        TimingData results;
        std::cout << "Executando benchmark: " << name << std::endl;

        for (int n : sizes) {
            std::vector<int> arr = generateSortedVector(n);
            int target = n + 1; // Pior caso: elemento nao presente

            double totalTime = 0.0;
            for (int r = 0; r < repetitions; ++r) {
                auto start = std::chrono::high_resolution_clock::now();
                func(arr, target);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> elapsed = end - start;
                totalTime += elapsed.count();
            }

            double avgTime = totalTime / repetitions;
            results.push_back({n, avgTime});
        }

        return results;
    }

    TimingData runSort(const std::string& name,
                       SortFunc func,
                       const std::vector<int>& sizes,
                       int repetitions) {
        TimingData results;
        std::cout << "Executando benchmark: " << name << std::endl;

        for (int n : sizes) {
            double totalTime = 0.0;
            for (int r = 0; r < repetitions; ++r) {
                // Gera vetor aleatorio novo a cada repeticao
                std::vector<int> arr = generateRandomVector(n, 42 + r);

                auto start = std::chrono::high_resolution_clock::now();
                func(arr);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> elapsed = end - start;
                totalTime += elapsed.count();
            }

            double avgTime = totalTime / repetitions;
            results.push_back({n, avgTime});
        }

        return results;
    }
}
