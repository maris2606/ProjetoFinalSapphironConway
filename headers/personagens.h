#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include <string>

class Personagem {
private: 
	int vidaMax;
    int forca;
    int poderCura;
	
public:
    // atributos
    std::string nome;
    std::string classe;
    std::string especie;
    int vida;
    bool estaDefendendo;
    
    // construtor padrao
    Personagem(); 
    // construtor para viloes
    Personagem(std::string nomeVilao, std::string classeVilao, std::string especieVilao, int vidaVilao, int forcaVilao, int curaVilao);
    
    // declarando funcoes
    void exibirFicha();

	void curar();
	void perderVida(int dano);
	
	// getters e setters
    int getForca();
    int getPoderCura();
    int getVidaMax();

    void setForca(int novaForca);
    void setPoderCura(int novaCura);
    void setVidaMax(int novaVidaMax);
};

#endif
