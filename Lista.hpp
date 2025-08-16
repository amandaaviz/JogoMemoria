#ifndef LISTA_HPP
#define LISTA_HPP
#include "Carta.hpp"

struct No {
    Carta *carta;
    No *prox;
};

class Lista {
private:
    No *inicio;
public:
    Lista();
    void inserir(Carta *c);
    Carta* acessar(int pos);
    void mostrar();
    int tamanho();
};

#endif

//O que acontece aqui:

//Definimos a estrutura de dados: lista encadeada.

//Cada No armazena uma carta (Carta* carta) e um ponteiro para o próximo (prox).

//A classe Lista controla a lista:

//inicio: aponta para o primeiro nó.

//inserir(): insere uma carta.

//acessar(): acessa carta pela posição.

//mostrar(): imprime no console as cartas (se reveladas ou escondidas).

//tamanho(): retorna o número de cartas.