#include "Analysis.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <numeric>

namespace Analysis {

    // Calcula a variancia residual de log(tempo) - log(f(n))
    // Se tempo = c * f(n), entao log(tempo) - log(f(n)) = log(c) = constante
    // Quanto menor a variancia, melhor o ajuste
    static double residualVariance(const std::vector<std::pair<int, double>>& data,
                                   double (*func)(int)) {
        std::vector<double> residuals;
        for (const auto& [n, time] : data) {
            double fn = func(n);
            if (fn > 0 && time > 0) {
                residuals.push_back(std::log(time) - std::log(fn));
            }
        }
        if (residuals.empty()) return 1e9;

        double mean = std::accumulate(residuals.begin(), residuals.end(), 0.0)
                       / residuals.size();
        double var = 0.0;
        for (double r : residuals) {
            var += (r - mean) * (r - mean);
        }
        return var / residuals.size();
    }

    static double fLogN(int n) { return std::log2(static_cast<double>(n)); }
    static double fN(int n) { return static_cast<double>(n); }
    static double fNLogN(int n) { return n * std::log2(static_cast<double>(n)); }
    static double fN2(int n) { return static_cast<double>(n) * n; }
    static double fN3(int n) { return static_cast<double>(n) * n * n; }

    std::vector<FitResult> analyze(const std::vector<std::pair<int, double>>& data) {
        struct Candidate {
            std::string name;
            double (*func)(int);
        };

        std::vector<Candidate> candidates = {
            {"O(log n)",    fLogN},
            {"O(n)",        fN},
            {"O(n log n)",  fNLogN},
            {"O(n^2)",      fN2},
            {"O(n^3)",      fN3}
        };

        std::vector<FitResult> results;
        double bestVar = 1e9;
        int bestIdx = -1;

        for (size_t i = 0; i < candidates.size(); ++i) {
            double var = residualVariance(data, candidates[i].func);
            results.push_back({candidates[i].name, var, 0.0, false});

            if (var < bestVar) {
                bestVar = var;
                bestIdx = static_cast<int>(i);
            }
        }

        if (bestIdx >= 0) {
            results[bestIdx].bestFit = true;
        }

        return results;
    }

    void printResults(const std::string& algorithmName,
                      const std::vector<std::pair<int, double>>& data,
                      const std::vector<FitResult>& fits) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "  " << algorithmName << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << std::left << std::setw(12) << "n"
                  << "| Tempo (ms)" << std::endl;
        std::cout << "------------|------------" << std::endl;
        for (const auto& [n, time] : data) {
            std::cout << std::left << std::setw(12) << n
                      << "| " << std::fixed << std::setprecision(6) << time << std::endl;
        }

        std::cout << "\nAjuste Assintotico (menor variancia = melhor):" << std::endl;
        for (const auto& fit : fits) {
            std::cout << "  " << std::left << std::setw(14) << fit.name
                      << "-> var = " << std::scientific << std::setprecision(4)
                      << fit.rSquared;
            if (fit.bestFit) {
                std::cout << "  <-- Melhor ajuste";
            }
            std::cout << std::endl;
        }
    }
}
