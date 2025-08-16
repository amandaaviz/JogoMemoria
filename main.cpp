#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Lista.hpp"
#include "Ordenacao.hpp"
using namespace std;

int main() {
    srand(time(0));

    // Pares de conceitos científicos
    vector<string> pares = {
        "Einstein", "Relatividade",
        "Darwin", "Evolução",
        "Mendel", "Genética",
        "Curie", "Radioatividade"
    };

    // Embaralhar
    random_shuffle(pares.begin(), pares.end());

    // Criar lista de cartas
    Lista lista;
    for (int i = 0; i < pares.size(); i++) {
        lista.inserir(new Carta(i, pares[i]));
    }

    int jogadas = 0;
    int acertos = 0;

    cout << "=== JOGO DA MEMÓRIA: CIENTISTAS E SUAS DESCOBERTAS ===" << endl;

    while (acertos < pares.size() / 2) {
        lista.mostrar();

        int p1, p2;
        cout << "Escolha a primeira carta: ";
        cin >> p1;
        cout << "Escolha a segunda carta: ";
        cin >> p2;

        Carta *c1 = lista.acessar(p1);
        Carta *c2 = lista.acessar(p2);

        if (c1 == nullptr || c2 == nullptr || p1 == p2) {
            cout << "Jogada inválida!" << endl;
            continue;
        }

        // Revela temporariamente
        c1->revelada = true;
        c2->revelada = true;
        lista.mostrar();

        if ((c1->conteudo == "Einstein" && c2->conteudo == "Relatividade") ||
            (c1->conteudo == "Relatividade" && c2->conteudo == "Einstein") ||
            (c1->conteudo == "Darwin" && c2->conteudo == "Evolução") ||
            (c1->conteudo == "Evolução" && c2->conteudo == "Darwin") ||
            (c1->conteudo == "Mendel" && c2->conteudo == "Genética") ||
            (c1->conteudo == "Genética" && c2->conteudo == "Mendel") ||
            (c1->conteudo == "Curie" && c2->conteudo == "Radioatividade") ||
            (c1->conteudo == "Radioatividade" && c2->conteudo == "Curie")) {
            
            cout << "Par encontrado! ✅" << endl;
            acertos++;
        } else {
            cout << "Não formou par. ❌" << endl;
            c1->revelada = false;
            c2->revelada = false;
        }

        jogadas++;
    }

    cout << "Parabéns! Você encontrou todos os pares em " << jogadas << " jogadas." << endl;

	// Coleta todas as cartas reveladas para ordenar
	vector<string> descobertas;
	for (int i = 0; i < lista.tamanho(); i++) {
	    Carta *c = lista.acessar(i);
	    if (c != nullptr) descobertas.push_back(c->conteudo);
	}
	
	cout << "\n=== Ordenando os conceitos revelados (Insertion Sort) ===" << endl;
	Ordenacao::insertionSort(descobertas);
	
	cout << "\nCartas em ordem final: ";
	for (string s : descobertas) {
	    cout << "[" << s << "] ";
	}
	cout << endl;
}

//Define os pares de cientistas e descobertas.

//Embaralha os pares.

//Insere cada carta em uma lista encadeada.

//Loop principal do jogo:

//Mostra cartas (escondidas ou reveladas).

//Jogador escolhe duas posições.

//Se formarem par → ficam reveladas.

//Se não → voltam a ser escondidas.

//Quando todos os pares forem encontrados:

//Mostra a quantidade de jogadas.

//Recolhe todos os conteúdos revelados.

//Aplica o Insertion Sort, mostrando cada passo.

//Exibe a lista final ordenada.
