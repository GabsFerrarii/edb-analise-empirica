# Algoritmos de Ordenação

## Bubble Sort

Compara pares de elementos adjacentes e troca os que estão fora de ordem. Repete até que nenhuma troca seja necessária.

### Funcionamento

1. Percorre o vetor comparando `arr[j]` com `arr[j+1]`.
2. Se `arr[j] > arr[j+1]`, troca os dois.
3. Ao final de cada passada, o maior elemento "borbulha" para o final.
4. Repete para os elementos restantes.
5. Se uma passada completa não fizer nenhuma troca, o vetor já está ordenado (otimização).

### Exemplo

Vetor: `[5, 3, 8, 1, 2]`

```
Passada 1: [3,5,8,1,2] → [3,5,8,1,2] → [3,5,1,8,2] → [3,5,1,2,8]
            ↑troca                       ↑troca        ↑troca
            O 8 borbulhou para o final.

Passada 2: [3,5,1,2,8] → [3,1,5,2,8] → [3,1,2,5,8]
                           ↑troca        ↑troca

Passada 3: [1,3,2,5,8] → [1,2,3,5,8]
            ↑troca        ↑troca

Passada 4: [1,2,3,5,8] → sem trocas → ordenado!
```

### Complexidade

- **Melhor caso:** $O(n)$ — vetor já ordenado (com a otimização de parada).
- **Pior caso:** $O(n^2)$ — vetor em ordem inversa.
- **Caso médio:** $O(n^2)$

### Código

```cpp
void bubbleSort(int vetor[], int tamanho) {
    bool trocou;
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}
```

Simples de implementar, mas ineficiente para grandes volumes de dados.

---

## Merge Sort

Algoritmo de divisão e conquista. Divide o vetor ao meio recursivamente até ter sub-vetores de 1 elemento, depois intercala (merge) os sub-vetores de volta em ordem.

### Funcionamento

1. **Dividir:** separa o vetor em duas metades.
2. **Conquistar:** aplica Merge Sort recursivamente em cada metade.
3. **Combinar:** intercala as duas metades ordenadas em um único vetor ordenado.

### Exemplo

Vetor: `[5, 3, 8, 1, 2, 7]`

```
Dividir:
  [5, 3, 8, 1, 2, 7]
  [5, 3, 8]     [1, 2, 7]
  [5] [3,8]     [1] [2,7]
  [5] [3] [8]   [1] [2] [7]

Combinar (merge):
  [5] [3] [8]   [1] [2] [7]
  [5] [3,8]     [1] [2,7]
  [3,5,8]       [1,2,7]
  [1, 2, 3, 5, 7, 8]
```

O merge compara os menores elementos de cada sub-vetor e coloca o menor no resultado:

```
Merge de [3,5,8] e [1,2,7]:
  3 vs 1 → pega 1  → [1]
  3 vs 2 → pega 2  → [1,2]
  3 vs 7 → pega 3  → [1,2,3]
  5 vs 7 → pega 5  → [1,2,3,5]
  8 vs 7 → pega 7  → [1,2,3,5,7]
  sobrou 8         → [1,2,3,5,7,8]
```

### Complexidade

- **Melhor caso:** $O(n \log n)$
- **Pior caso:** $O(n \log n)$
- **Caso médio:** $O(n \log n)$

A complexidade é sempre $O(n \log n)$ porque a divisão sempre gera $\log n$ níveis e cada nível processa $n$ elementos no merge.

### Código

```cpp
void merge(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int* esquerda = new int[n1];
    int* direita = new int[n2];

    for (int i = 0; i < n1; i++) esquerda[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++) direita[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) vetor[k++] = esquerda[i++];
        else vetor[k++] = direita[j++];
    }
    while (i < n1) vetor[k++] = esquerda[i++];
    while (j < n2) vetor[k++] = direita[j++];

    delete[] esquerda;
    delete[] direita;
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
```

---

## Comparação

| | Bubble Sort | Merge Sort |
|---|---|---|
| Complexidade (pior caso) | $O(n^2)$ | $O(n \log n)$ |
| Complexidade (melhor caso) | $O(n)$ | $O(n \log n)$ |
| Memória extra | $O(1)$ (in-place) | $O(n)$ (vetores auxiliares) |
| Estável? | Sim | Sim |
| Exemplo: n = 10.000 | ~100.000.000 operações | ~133.000 operações |
