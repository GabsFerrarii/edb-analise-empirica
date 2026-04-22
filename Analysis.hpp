#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <vector>
#include <string>
#include <utility>

namespace Analysis {

    struct FitResult {
        std::string name;    // Ex: "O(n)", "O(n log n)"
        double rSquared;     // R² da regressao log-log
        double slope;        // Slope da regressao (deve ser ~1 para bom ajuste)
        bool bestFit;        // Indica se é o melhor ajuste
    };

    // Analisa os dados de timing e retorna os resultados de ajuste
    std::vector<FitResult> analyze(const std::vector<std::pair<int, double>>& data);

    // Exibe os resultados formatados no terminal
    void printResults(const std::string& algorithmName,
                      const std::vector<std::pair<int, double>>& data,
                      const std::vector<FitResult>& fits);
}

#endif
