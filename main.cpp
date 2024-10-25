/*
Alunos : William wallace da costa pereira // washington smith pinho macmabira 
•	uma opção de escolher a quantidade de valores inteiros de entrada dentre as opções: 10, 100, 1.000 e 10.000 elementos.
•	uma opção de escolher como os valores de entrada estão dispostos antes da ordenação, ou seja, ordenados descendentes e/ou aleatórios.
•	uma opção para apresentar os valores do vetor de entrada, ou seja, o vetor antes da ordenação.
•	O programa deverá ter uma opção para a escolha do algoritmo de ordenação entre três  algoritmos de ordenação, escolhendo conforme a regra:
o	Escolher um dos algoritmos: Bubblesort, Selectionsort, Insertionsort
o	Escolher um dos algoritmos: Mergesort, Quicksort, Heapsort 
o	Escolher um dos algoritmos: radixsort, bucket sort e counting sort
•	Durante a ordenação, o programa deverá contabilizar o número de comparações, número de trocas que realizam na ordenação de sequências, e o tempo de execução.
•	Após a execução do algoritmo de ordenação, o programa deverá apresentar o vetor ordenado, bem como o tempo de execução, número de comparações, e número de trocas.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "trab2.h"

using namespace std;

int main() {
    srand(time(0)); // inicializadno gerador de numeros aleatorios 
    int qtd;
    string tipo;

    cout << "Escolha a quantidade de valores: (10, 100, 1000, 10000)" << endl;
    cin >> qtd;

    while (qtd != 10 && qtd != 100 && qtd != 1000 && qtd != 10000) {
        cout << "Opção inválida, tente novamente." << endl;
        cin >> qtd;
    }

    cout << "Escolha a disposição dos valores: (aleatorio, descendente)" << endl;
    cin >> tipo;

    while (tipo != "aleatorio" && tipo != "descendente") {
        cout << "Opção inválida, tente novamente." << endl;
        cin >> tipo;
    }

    Lista lista;
    gerarValores(lista, qtd, tipo);
    string exibirAntes;
    cout << "Deseja ver a lista antes da ordenação ? (sim/não) :" << endl;
    cin >> exibirAntes;
    
    if (exibirAntes == "sim"){
        lista.exibir();
    }

    int algoritmo;
    cout << "Escolha o algoritmo de ordenação:" << endl;
    cout << "1. Bubblesort" << endl;
    cout << "2. Mergesort" << endl;
    cout << "3. Bucketsort" << endl;
    cin >> algoritmo;

    clock_t start = clock();

    switch (algoritmo) {
        case 1:
            bubbleSort(lista);
            break;
        case 2:
            mergeSort(lista, 0, lista.tamanho - 1);
            break;
        case 3:
            bucketSort(lista);
            break;
            
        default:
            cout << "Algoritmo inválido." << endl;
            return 1;
    }

    clock_t end = clock();
    double tempoExecucao = double(end - start) / CLOCKS_PER_SEC;

    cout << "Valores após a ordenação:" << endl;
    lista.exibir();
    cout << "Tempo de execução: " << tempoExecucao << " segundos" << endl;
    cout << "Número de comparações: " << lista.comparacoes << endl;
    cout << "Número de trocas: " << lista.trocas << endl;

    return 0;
}
