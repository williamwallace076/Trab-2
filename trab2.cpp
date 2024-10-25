#include <ctime>
#include <cstdlib>
#include <algorithm> // Para usar sort
#include <vector>
#include "trab2.h"

// Função para gerar valores
void gerarValores(Lista &lista, int qtd, const string &tipo) {
    lista.tamanho = qtd;
    if (tipo == "aleatorio") {
        for (int i = 0; i < qtd; ++i) {
            lista.valores[i] = rand() % 1000 + 1;
        }
    } else if (tipo == "descendente") {
        for (int i = qtd; i > 0; --i) {
            lista.valores[qtd - i] = i;
        }
    }
}

// Algoritmos de ordenação

void bubbleSort(Lista &lista) {  // comparação de adjacentes
    lista.reset();
    int aux;
    for (int i = 0; i < lista.tamanho - 1; ++i) { // elemento subsequente
        for (int j = 0; j < lista.tamanho - 1 - i; ++j) {  // elemento anterior
            
            lista.comparacoes++; // adiciona uma comparação no marcador
            
            if (lista.valores[j] > lista.valores[j + 1]) {
                aux = lista.valores[j]; 
                lista.valores[j] = lista.valores[j + 1];  // fazendo swap {2,1} == {1,2}
                lista.valores[j + 1] = aux;
                
                lista.trocas++; // adiciona uma troca no marcador
            }
        }
    }
}

void merge(Lista &lista, int esq, int meio, int dir) {
    int AUX[MAX_SIZE]; // Vetor auxiliar para armazenar os elementos mesclados

    int i = esq;  // Índice inicial do primeiro sub-vetor
    int j = meio + 1;  // Índice inicial do segundo sub-vetor
    int k = 0;         // Índice para o vetor auxiliar

    // Mescla os dois sub-vetores
    while (i <= meio && j <= dir) {
        if (lista.valores[i] <= lista.valores[j]) {
            AUX[k] = lista.valores[i]; // Copia lista.valores[i] para o vetor auxiliar
            i++;
        } else {
            AUX[k] = lista.valores[j]; // Copia lista.valores[j] para o vetor auxiliar
            j++;
        }
        k++;
    }

    // Se ainda restarem elementos no primeiro sub-vetor
    while (i <= meio) {
        AUX[k] = lista.valores[i]; // Copia o restante do primeiro sub-vetor
        i++;
        k++;
    }

    // Se ainda restarem elementos no segundo sub-vetor
    while (j <= dir) {
        AUX[k] = lista.valores[j]; // Copia o restante do segundo sub-vetor
        j++;
        k++;
    }

    // Copia os elementos do vetor auxiliar de volta para o vetor original
    for (int m = 0; m < k; m++) {
        lista.valores[esq + m] = AUX[m]; // Copia de AUX para lista.valores
    }
}

// Função de Merge Sort
void mergeSort(Lista &lista, int esq, int dir) {
    if (esq < dir) { // Verifica se há mais de um elemento
        int meio = (esq + dir) / 2;
        mergeSort(lista, esq, meio); // Chamada recursiva para o sub-vetor da esquerda
        mergeSort(lista, meio + 1, dir); // Chamada recursiva para o sub-vetor da direita
        merge(lista, esq, meio, dir); // Mescla os sub-vetores
    }
}

// Função para o Bucket Sort
void bucketSort(Lista &lista) {
    lista.reset();

    // Passo 1: Criar buckets
    int max_value = *max_element(lista.valores, lista.valores + lista.tamanho);
    int num_buckets = max_value / 10 + 1;

    vector<vector<int>> buckets(num_buckets);

    // Passo 2: Distribuir os valores nos buckets
    for (int i = 0; i < lista.tamanho; i++) {
        int bucket_index = lista.valores[i] / 10;
        buckets[bucket_index].push_back(lista.valores[i]);
    }

    // Passo 3: Ordenar cada bucket individualmente
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        // Ordenação com contagem de comparações e trocas (se necessário)
        for (int j = 0; j < buckets[i].size(); j++) {
            for (int k = j + 1; k < buckets[i].size(); k++) {
                lista.comparacoes++;  // Contagem de comparações
                if (buckets[i][j] > buckets[i][k]) {
                    swap(buckets[i][j], buckets[i][k]);
                    lista.trocas++;  // Contagem de trocas
                }
            }
        }

        // Passar os valores ordenados de volta para a lista
        for (int j = 0; j < buckets[i].size(); j++) {
            lista.valores[index++] = buckets[i][j];
        }
    }
}

