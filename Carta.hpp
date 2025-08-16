#ifndef CARTA_HPP
#define CARTA_HPP
#include <string>
using namespace std;

struct Carta {
    int id;
    string conteudo;
    bool revelada;

    Carta(int i, string c) {
        id = i;
        conteudo = c;
        revelada = false;
    }
};

#endif

//Esse é o TAD Carta, que representa cada carta do jogo.

//Cada carta tem:

//id: identificador único da carta (posição).

//conteudo: o que está escrito na carta (ex: "Einstein", "Relatividade").

//revelada: indica se a carta está virada para cima (true) ou para baixo (false).

//Construtor inicializa a carta com conteúdo e id, e já deixa como não revelada.