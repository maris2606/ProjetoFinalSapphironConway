#include <iostream>
#include "../headers/personagens.h"
#include "../headers/rolarDados.h"

// Implementação do Construtor
Personagem::Personagem() {
    vidaMax=200;
    vida=200;
    estaDefendendo = false;
}

Personagem::Personagem(std::string nomeVilao, std::string classeVilao, std::string especieVilao, int vidaVilao, int forcaVilao, int curaVilao){
    nome = nomeVilao;
    classe = classeVilao;
    especie = especieVilao;
    vida = vidaVilao;
    vidaMax= vidaVilao;
    forca = forcaVilao;
    poderCura = curaVilao;
    estaDefendendo = false;
}

// getters e setters
int Personagem::getForca() { return forca; }
int Personagem::getPoderCura() { return poderCura; }
int Personagem::getVidaMax() { return vidaMax; }

void Personagem::setForca(int novaForca) { forca = novaForca; }
void Personagem::setPoderCura(int novaCura) { poderCura = novaCura; }
void Personagem::setVidaMax(int novaVidaMax) { vidaMax = novaVidaMax; }


// função de exibir a ficha
void Personagem::exibirFicha() {
    std::cout << "===== ficha =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Espécie: " << especie << "\n";
    std::cout << "Vida: " << vida << "\n";
    std::cout << "Força: " << forca << "\n";
    std::cout << "Poder de cura: " << poderCura << "\n\n";
    std::cout << "=================\n\n";
}

void Personagem::curar() {
	std::cout << nome << " se curou e recebeu " << poderCura <<" pontos de vida\n";
	
	// como multiplicador é float, é bom converter
	vida += static_cast<int>(poderCura * gerarMultiplicador()); 
	
	if (vida > vidaMax) vida = vidaMax;
}

void Personagem::perderVida(int dano) {
	std::cout << nome << " perdeu " << dano <<" pontos de vida\n";
	vida -= dano;
}



