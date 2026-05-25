#include <iostream>
#include "personagens.h"

// Implementação do Construtor
Personagem::Personagem() {
    vida = 300;
    pontos = 0;
    estaDefendendo = false;
}

Personagem::Personagem(std::string nomeVilao, std::string classeVilao, std::string especieVilao, int vidaVilao, int forcaVilao, int curaVilao){
    nome = nomeVilao;
    classe = classeVilao;
    especie = especieVilao;
    vida = vidaVilao;
    forca = forcaVilao;
    poderCura = curaVilao;
    estaDefendendo = false;
    pontos = 0; // Vilão sempre nasce com 0 pontos
}

// função de exibir a ficha
void Personagem::exibirFicha() {
    std::cout << "===== ficha =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Especie: " << especie << "\n";
    std::cout << "Vida: " << vida << "\n";
    std::cout << "Pontos: " << pontos << "\n";
    std::cout << "Forca: " << forca << "\n";
    std::cout << "Poder de cura: " << poderCura << "\n\n";
    std::cout << "=================\n\n";
}

void Personagem::curar() {
	std::cout << nome << " se curou e recebeu " << poderCura <<" pontos de vida\n";
	vida += poderCura;
	if (vida > 1000) vida = 1000;
}

void Personagem::perderVida(int dano) {
	std::cout << nome << " perdeu " << dano <<" pontos de vida\n";
	vida -= dano;
}



