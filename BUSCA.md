# Algoritmos de Busca

## Busca Sequencial

Percorre o vetor elemento por elemento, do início ao fim, comparando cada um com o alvo.

### Funcionamento

1. Começa no primeiro elemento (índice 0).
2. Compara o elemento atual com o alvo.
3. Se for igual, retorna o índice.
4. Se não, avança para o próximo.
5. Se chegar ao fim sem encontrar, retorna -1.

### Exemplo

Vetor: `[10, 20, 30, 40, 50]`, alvo: `30`

```
Passo 1: 10 == 30? Não → avança
Passo 2: 20 == 30? Não → avança
Passo 3: 30 == 30? Sim → retorna índice 2
```

### Complexidade

- **Melhor caso:** $O(1)$ — elemento está na primeira posição.
- **Pior caso:** $O(n)$ — elemento está na última posição ou não existe.
- **Caso médio:** $O(n)$

### Código

```cpp
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

Não exige que o vetor esteja ordenado.

---

## Busca Binária

Divide o vetor ordenado ao meio repetidamente, descartando a metade onde o alvo não pode estar.

### Funcionamento

1. Define os limites: `left = 0`, `right = n - 1`.
2. Calcula o meio: `mid = left + (right - left) / 2`.
3. Se `arr[mid] == alvo`, retorna `mid`.
4. Se `arr[mid] < alvo`, o alvo está na metade direita → `left = mid + 1`.
5. Se `arr[mid] > alvo`, o alvo está na metade esquerda → `right = mid - 1`.
6. Repete até encontrar ou `left > right`.

### Exemplo

Vetor: `[10, 20, 30, 40, 50, 60, 70]`, alvo: `50`

```
Passo 1: left=0, right=6, mid=3 → arr[3]=40 < 50 → left=4
Passo 2: left=4, right=6, mid=5 → arr[5]=60 > 50 → right=4
Passo 3: left=4, right=4, mid=4 → arr[4]=50 == 50 → retorna 4
```

A cada passo, metade dos elementos é descartada.

### Complexidade

- **Melhor caso:** $O(1)$ — elemento está exatamente no meio.
- **Pior caso:** $O(\log n)$ — divide até restar 1 elemento.
- **Caso médio:** $O(\log n)$

### Código

```cpp
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

**Pré-requisito:** o vetor deve estar ordenado.

---

## Comparação

| | Busca Sequencial | Busca Binária |
|---|---|---|
| Complexidade | $O(n)$ | $O(\log n)$ |
| Vetor ordenado? | Não precisa | Obrigatório |
| Exemplo: n = 1.000.000 | Até 1.000.000 comparações | Até 20 comparações |
