#include "combate.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std::chrono_literals;

bool iniciarCombate(Personagem &protagonista, Personagem &vilao) {
	int caixaDialogo = (rand() % 3) + 1;
	
    std::cout << "\n==========================================\n";
    
    switch(caixaDialogo) {
    	case 1:
    		std::cout << "!!! CUIDADO !!!\n";
    		std::cout << protagonista.nome << " deu de cara com " << vilao.nome << "\n";
    		break;
    	case 2:
    		std::cout << "Voce sente o perigo se aproximando...\n";
    		std::this_thread::sleep_for(1000ms);
    		std::cout << "!!! ATENCAO !!!\n";
    		std::cout << protagonista.nome << " caiu no terreno de " << vilao.nome << "\n";
    		break;
    	default: 
    		std::cout << "Algo nao esta certo...\n";
    		std::this_thread::sleep_for(1000ms);
    		std::cout << "!!! CUIDADO !!!\n";
    		std::cout << vilao.nome << " achou " << protagonista.nome << "\n";
    		break;
	}
    
    std::cout << "==========================================\n";
    std::this_thread::sleep_for(2000ms);

    // O combate dura enquanto estiverem vivos
    while (protagonista.vida > 0 && vilao.vida > 0) {
        
        turnoJogador(protagonista, vilao);
        if (vilao.vida <= 0) {
            std::cout << "\n" << vilao.nome << " foi derrotado!\n";
            std::this_thread::sleep_for(1500ms);
            return true; // Vitória neste combate
            
            narrativaCombate(protagonista);
        }

        turnoInimigo(protagonista, vilao);
        if (protagonista.vida <= 0) {
            return false; // Derrota do jogador
        }

    }
    return protagonista.vida > 0;
}

void turnoJogador(Personagem &protagonista, Personagem &vilao) {
    protagonista.estaDefendendo = false; // Reseta a defesa do turno anterior
    int acaoHeroi = 0;

    do {
        std::cout << "\n--- SEU TURNO (Vida: " << protagonista.vida << ") (" << vilao.nome << ": "<< vilao.vida <<")---\n";
        std::cout << "[1] Atacar " << vilao.nome << "\n";
        std::cout << "[2] Defender\n";
        std::cout << "[3] Curar\n";
        std::cout << "Escolha sua acao: ";
        std::cin >> acaoHeroi;

        if (std::cin.fail() || acaoHeroi < 1 || acaoHeroi > 3) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Acao invalida! Escolha entre 1 e 3!!!\n";
        } else {
            break;
        }
    } while (true);

    if (acaoHeroi == 1) {
        int danoFinal = protagonista.forca;
        if (vilao.estaDefendendo) {
            danoFinal /= 2;
            vilao.estaDefendendo = false;
            std::cout << vilao.nome << " estava defendendo! Dano reduzido.\n";
        }
        vilao.perderVida(danoFinal);
    } 
    else if (acaoHeroi == 2) {
        std::cout << protagonista.nome << " entra em postura defensiva.\n";
        protagonista.estaDefendendo = true;
    } 
    else if (acaoHeroi == 3) {
        protagonista.curar();
    }
    std::this_thread::sleep_for(1500ms);
}

void turnoInimigo(Personagem &protagonista, Personagem &vilao) {
    std::cout << "\n--- TURNO DE " << vilao.nome << " ---\n";
    std::this_thread::sleep_for(1000ms);

    int acaoVilao = (rand() % 3) + 1;

    if (acaoVilao == 1) {
        std::cout << vilao.nome << " avanca para atacar!\n";
        std::this_thread::sleep_for(1000ms);

        int danoDoVilao = vilao.forca;
        if (protagonista.estaDefendendo) {
            danoDoVilao /= 2;
            std::cout << "Voce reduziu o impacto com sua defesa!\n";
        }
        protagonista.perderVida(danoDoVilao);
    } 
    else if (acaoVilao == 2) {
        std::cout << vilao.nome << " assume uma postura de guarda.\n";
        vilao.estaDefendendo = true;
    } 
    else if (acaoVilao == 3) {
        vilao.curar();
    }
    std::this_thread::sleep_for(1500ms);
}

void narrativaCombate(Personagem &protagonista) {
	// coloca um valor aleatorio para recuperar vida entre as rodadas de vilao
	// entre 10 e 20
	int vidaRecuperavel = (rand() % (20 - 10 + 1)) + 10;
	
    std::cout << "\n------------------------------------------\n";
    std::cout << "O vento sopra forte pelas arvores da floresta...\n";
    std::this_thread::sleep_for(1500ms);
    std::cout << "A energia do ambiente revigora suas asas.\n";
    std::this_thread::sleep_for(1500ms);
    
    std::cout << "Voce recuperou "<< vidaRecuperavel <<" pontos de vida.\n";
    protagonista.vida += vidaRecuperavel;
    if (protagonista.vida > 1000) protagonista.vida = 1000;

	std::cout << "Agora voce está com "<< protagonista.vida <<" pontos de vida.\n";
    std::cout << "------------------------------------------\n";
    std::this_thread::sleep_for(1500ms);
}
