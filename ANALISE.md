# Como Funciona o Benchmark e a Análise

## Coleta de Dados (Benchmark)

Para cada algoritmo, o programa:

1. Gera vetores de tamanhos crescentes (n).
2. Executa o algoritmo 20 vezes para cada tamanho e calcula o tempo médio usando `std::chrono::high_resolution_clock`.
3. Armazena os pares (n, tempo_médio).

### Particularidades por tipo de algoritmo

**Busca:** o vetor é ordenado (1, 2, 3, ..., n) e o alvo é `n + 1` (elemento inexistente), forçando o pior caso.

**Ordenação:** a cada repetição, um vetor aleatório novo é gerado usando `std::mt19937` com seed fixa (`42 + repetição`), garantindo reprodutibilidade sem reutilizar vetores já ordenados.

### Tamanhos de entrada

| Algoritmo | Tamanhos de n |
|---|---|
| Busca Sequencial / Binária | 100 a 100.000 |
| Bubble Sort | 100 a 10.000 |
| Merge Sort | 1.000 a 5.000.000 |

O Merge Sort usa tamanhos maiores porque a diferença entre $O(n)$ e $O(n \log n)$ só se manifesta de forma clara com faixas amplas de n.

## Análise Assintótica

### Método: Variância Residual em Escala Logarítmica

Se um algoritmo tem complexidade $O(f(n))$, então:

$$tempo = c \cdot f(n)$$

Aplicando logaritmo:

$$\log(tempo) - \log(f(n)) = \log(c)$$

Se $f(n)$ for a função correta, $\log(c)$ deve ser constante para todo n. O programa calcula a **variância** desses valores para cada função candidata. A candidata com **menor variância** é a que melhor descreve o algoritmo.

### Por que logaritmo?

Sem log, tempos grandes (ex: 648ms para n=5M) dominam o cálculo e tempos pequenos (0.07ms para n=1000) são ignorados. O logaritmo normaliza as escalas, fazendo todos os pontos contribuírem igualmente.

### Exemplo com Merge Sort

Testando $f(n) = n \log n$:
```
log(0.070) - log(1000 × 10.0)   = -13.87
log(9.527) - log(100000 × 16.6) = -12.07
log(648.3) - log(5000000 × 22.3) = -12.06
→ valores próximos → variância baixa ✓
```

Testando $f(n) = n$:
```
log(0.070) - log(1000)    = -11.57
log(9.527) - log(100000)  = -9.26
log(648.3) - log(5000000) = -8.95
→ valores mais espalhados → variância maior ✗
```

### Resultado por algoritmo

| Algoritmo | Complexidade Identificada |
|---|---|
| Busca Sequencial | $O(n)$ |
| Busca Binária | $O(\log n)$ |
| Bubble Sort | $O(n^2)$ |
| Merge Sort | $O(n \log n)$ |
