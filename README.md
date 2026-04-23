# Análise Empírica de Complexidade de Algoritmos

Programa em C++ que avalia empiricamente o tempo de execução de algoritmos de busca e ordenação, comparando os dados com funções assintóticas conhecidas e gerando gráficos automaticamente via integração direta com Python.

## Requisitos

- Compilador com suporte a **C++17** (ex: `g++`)
- **Python 3** com a biblioteca `matplotlib` instalada.

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
| `SortAlgorithms.hpp/cpp` | Algoritmos de ordenação (namespace `Sort`) |
| `Benchmark.hpp/cpp` | Motor de benchmark — coleta de tempos com `chrono` |
| `Analysis.hpp/cpp` | Ajuste de funções assintóticas via variância residual log |
| `Plotter.hpp` | Motor de plotagem em tempo real via Pipe na memória (C++ → Python) |

## Como Compilar e Executar

No terminal, compile os arquivos usando o `g++` e execute o programa gerado:

```bash
g++ -Wall -O2 -std=c++17 main.cpp SearchAlgorithms.cpp SortAlgorithms.cpp Benchmark.cpp Analysis.cpp -o programa
./programa