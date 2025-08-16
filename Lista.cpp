#include <iostream>
#include "Lista.hpp"
using namespace std;

Lista::Lista() {
    inicio = nullptr;
}

void Lista::inserir(Carta *c) {
    No *novo = new No;
    novo->carta = c;
    novo->prox = inicio;
    inicio = novo;
}

Carta* Lista::acessar(int pos) {
    No *atual = inicio;
    int count = 0;
    while (atual != nullptr) {
        if (count == pos) return atual->carta;
        atual = atual->prox;
        count++;
    }
    return nullptr;
}

void Lista::mostrar() {
    No *atual = inicio;
    int pos = 0;
    while (atual != nullptr) {
        if (atual->carta->revelada) {
            cout << "[" << atual->carta->conteudo << "] ";
        } else {
            cout << "[" << pos << "] ";
        }
        atual = atual->prox;
        pos++;
    }
    cout << endl;
}

int Lista::tamanho() {
    int count = 0;
    No *atual = inicio;
    while (atual != nullptr) {
        count++;
        atual = atual->prox;
    }
    return count;
}

//Implementação das funções da lista:

//Construtor: começa com lista vazia (inicio = nullptr).

//inserir(): coloca uma nova carta no início da lista.

//acessar(pos): percorre a lista até achar a posição pos.

//mostrar(): se a carta está revelada → mostra o conteúdo; senão → mostra apenas o índice da carta.

//tamanho(): conta quantas cartas existem.