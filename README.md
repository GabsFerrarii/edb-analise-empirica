# Análise Empírica de Complexidade de Algoritmos

Programa em C++ que avalia empiricamente o tempo de execução de algoritmos de busca e ordenação, comparando os dados coletados com funções assintóticas conhecidas para identificar automaticamente a complexidade de cada algoritmo.

## Algoritmos Implementados

### Busca
- **Busca Sequencial** — $O(n)$
- **Busca Binária** — $O(\log n)$

### Ordenação
- **Bubble Sort** — $O(n^2)$
- **Merge Sort** — $O(n \log n)$

## Funções Assintóticas Avaliadas

- $O(\log n)$
- $O(n)$
- $O(n \log n)$
- $O(n^2)$
- $O(n^3)$

## Estrutura do Projeto

| Arquivo | Descrição |
|---|---|
| `main.cpp` | Ponto de entrada, configuração dos tamanhos e chamadas de benchmark |
| `SearchAlgorithms.hpp/cpp` | Algoritmos de busca (namespace `Search`) |
| `SortAlgorithms.h/cpp` | Algoritmos de ordenação (namespace `Sort`) |
| `Benchmark.hpp/cpp` | Motor de benchmark — coleta de tempos com `chrono` |
| `Analysis.hpp/cpp` | Ajuste de funções assintóticas via variância residual log |

## Como Compilar e Executar

Requer `g++` com suporte a C++17.

```bash
g++ -Wall -O2 -std=c++17 main.cpp SearchAlgorithms.cpp SortAlgorithms.cpp Benchmark.cpp Analysis.cpp -o programa
./programa
```

## Adicionando Novos Algoritmos

Basta implementar a função seguindo a assinatura padrão e registrar na `main()`:

```cpp
// Busca: int func(const std::vector<int>& arr, int target)
benchmarkSearch("Minha Busca", minhaFuncaoDeBusca);

// Ordenação: void func(std::vector<int>& arr)
benchmarkSort("Minha Ordenacao", minhaFuncaoDeOrdenacao, TAMANHOS);
```
