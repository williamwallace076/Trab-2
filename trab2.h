// Definindo a constante máxima de elementos
const int MAX_SIZE = 10000;

#include <iostream>
using namespace std;

// Estrutura para armazenar a lista e os contadores
struct Lista {
    int valores[MAX_SIZE];
    int tamanho;
    int comparacoes;
    int trocas;

    Lista() {
    tamanho = 0;
    comparacoes = 0;
    trocas = 0;
    }


    void reset() {
        comparacoes = 0;
        trocas = 0;
    }

    void exibir() {
        for (int i = 0; i < tamanho; i++) {
            cout << valores[i] << " ";
        }
        cout << endl;
    }
};

void bubbleSort(Lista &lista);
void mergeSort(Lista &lista, int esq, int dir);
void bucketSort(Lista &lista);
void gerarValores(Lista &lista, int qtd, const string &tipo);
