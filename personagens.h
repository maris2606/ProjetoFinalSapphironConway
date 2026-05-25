#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include <string>

class Personagem {
public:
    // atributos
    std::string nome;
    std::string classe;
    std::string especie;
    int vida;
    int pontos;
    int forca;
    int poderCura;
    bool estaDefendendo;
    
    // construtor padrao
    Personagem(); 
    // construtor para viloes
    Personagem(std::string nomeVilao, std::string classeVilao, std::string especieVilao, int vidaVilao, int forcaVilao, int curaVilao);
    
    // declarando funcoes
    void exibirFicha();

	void curar();
	void perderVida(int dano);
};

#endif
