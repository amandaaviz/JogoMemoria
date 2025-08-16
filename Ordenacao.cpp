#include <iostream>
#include "Ordenacao.hpp"
using namespace std;

void Ordenacao::insertionSort(vector<string> &dados) {
    int n = dados.size();
    for (int i = 1; i < n; i++) {
        string chave = dados[i];
        int j = i - 1;

        // Move os elementos maiores que "chave" para frente
        while (j >= 0 && dados[j] > chave) {
            dados[j + 1] = dados[j];
            j--;
        }
        dados[j + 1] = chave;

        // Mostra passo a passo
        cout << "Passo " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << "[" << dados[k] << "] ";
        }
        cout << endl;
    }
}

//Implementamos o Insertion Sort:

//Começa no índice 1.

//Pega a carta atual (chave).

//Compara com todas as anteriores, movendo as maiores para frente.

//Insere a chave no lugar certo.

//Imprime cada passo no console.