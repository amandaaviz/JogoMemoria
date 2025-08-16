#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP
#include <vector>
#include <string>
using namespace std;

class Ordenacao {
public:
    static void insertionSort(vector<string> &dados);
};

#endif

//Criamos uma classe Ordenacao.

//Ela contém apenas métodos estáticos (não precisa criar objeto).

//Aqui temos a declaração do insertionSort(), que vai ordenar um vetor de strings.