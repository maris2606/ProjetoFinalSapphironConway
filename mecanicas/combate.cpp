#include "../headers/combate.h"
#include "../headers/rolarDados.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std::chrono_literals;

bool iniciarCombate(Personagem &protagonista, Personagem &vilao) {
	int caixaDialogo = rolarDados (1,3);
	
    std::cout << "\n==========================================\n";
    
    switch(caixaDialogo) {
    	case 1:
    		std::cout << "!!! CUIDADO !!!\n";
    		std::cout << protagonista.nome << " deu de cara com " << vilao.nome << "\n";
    		break;
    	case 2:
    		std::cout << "Você sente o perigo se aproximando...\n";
    		std::this_thread::sleep_for(1000ms);
    		std::cout << "!!! ATENCAO !!!\n";
    		std::cout << protagonista.nome << " caiu no terreno de " << vilao.nome << "\n";
    		break;
    	default: 
    		std::cout << "Algo não está certo...\n";
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
            
            narrativaCombate(protagonista);
            return true; // Vitória neste combate
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
            std::cout << "Ação inválida! Escolha entre 1 e 3!!!\n";
        } else {
            break;
        }
    } while (true);

    if (acaoHeroi == 1) {
    	// tem chance de acertar o ataque ou não
    	if (rolarDados (1, 20) > 6) { // tem mais chance de acertar
	    	int danoFinal = static_cast<int>(protagonista.getForca() * gerarMultiplicador());
	        
	        if (vilao.estaDefendendo) {
	            danoFinal /= 2;
	            vilao.estaDefendendo = false;
	            std::cout << vilao.nome << " estava defendendo! Dano reduzido.\n";
	        }
	        
	        vilao.perderVida(danoFinal);	
		} else {
			std::cout << protagonista.nome << " errou o ataque!\n";
			std::cout << vilao.nome << " não perdeu nenhum ponto de vida :(\n\n";
	        
		}
        
        
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

    int acaoVilao = rolarDados(1,10);

	
    if (acaoVilao <=8) {
    	
    	if (rolarDados (1, 20) > 3) {
	        std::cout << vilao.nome << " avanca para atacar!\n";
	        std::this_thread::sleep_for(1000ms);
	
	        int danoDoVilao = static_cast<int>(vilao.getForca() * gerarMultiplicador());
	        if (protagonista.estaDefendendo) {
	            danoDoVilao /= 2;
	            std::cout << "Você reduziu o impacto com sua defesa!\n";
	        }
	        protagonista.perderVida(danoDoVilao);
	    } else {
	    	std::cout << vilao.nome << " errou o ataque!\n";
			std::cout << "Você não perdeu nenhum ponto de vida!!\n\n";
		}
    } 
    else if (acaoVilao == 9) {
        std::cout << vilao.nome << " assume uma postura de guarda.\n";
        vilao.estaDefendendo = true;
    } 
    else if (acaoVilao == 10) {
        vilao.curar();
    }
    std::this_thread::sleep_for(1500ms);
}

void narrativaCombate(Personagem &protagonista) {
	// coloca um valor aleatorio para recuperar vida entre as rodadas de vilao
	// entre 10 e 30
	int vidaRecuperavel = rolarDados (10,30);
	int bonusForca = rolarDados(5, 15);
	int bonusCura = rolarDados(3, 10);
	
    std::cout << "\n------------------------------------------\n"
    	 		 "O vento sopra forte pelas árvores da floresta...\n";
    	 		 
    std::this_thread::sleep_for(1500ms);
    
    std::cout << "A energia do ambiente revigora suas asas.\n\n";
    std::this_thread::sleep_for(1500ms);
    
    std::cout << "Sua vida Máxima aumentou 50 pontos!!!\n";
    protagonista.setVidaMax( protagonista.getVidaMax() + 50);
    
    std::cout << "Você recuperou "<< vidaRecuperavel <<" pontos de vida!!!\n";
    
    protagonista.vida += vidaRecuperavel;
    
    if (protagonista.vida > protagonista.getVidaMax()) { protagonista.vida = protagonista.getVidaMax(); }

    protagonista.setForca(protagonista.getForca() + bonusForca);

    protagonista.setPoderCura(protagonista.getPoderCura() + bonusCura);
    
	std::this_thread::sleep_for(1500ms);
	
    std::cout << "Sua força aumentou em " << bonusForca << "!\n"
                 "Seu poder de cura aumentou em " << bonusCura << "!\n"
                 "Agora você está com "<< protagonista.vida <<" pontos de vida.\n\n";
                 
	std::this_thread::sleep_for(2500ms); 
	std::cout << "E preparado para um novo desafio! \n";

    std::cout << "------------------------------------------\n";
    std::this_thread::sleep_for(1500ms);
}
