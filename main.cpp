#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime> 

#include "personagens.h"
#include "combate.h"

using namespace std::chrono_literals;

/*
"Para compilar o projeto, 
utilize o compilador g++ com suporte ao padrão C++11 ou superior, 
incluindo todos os arquivos .cpp do diretório: g++ *.cpp -std=c++17 -o jogo"
*/

// declarar funcoes
void montarFicha();
void definirAtributos(Personagem &p, int classe, std::string especie);

// variaveis e objetos
Personagem protagonista;
// viloes com classe, vida, forca e cura
Personagem gato ("Gato Cat-astrofe", "vilao", "gato", 100, 10, 5);
Personagem loboMau ("Lobo Mau", "vilao", "lobo", 200, 15, 10);
Personagem gaviaoDeFogo ("Gaviao de Fogo", "vilao", "gaviao", 400, 20, 15);

bool estaDefendendo = false;

int main (){
	srand(time(0));
	
	//introdução
	std::cout << "================== birbRPG ===============\n\n";
	std::this_thread::sleep_for(1000ms);
	
	std::cout << "Seja Bem Vindo(a) ao BirbRPG!\n"
	             "um mundo fantastico onde voce sera um passarinho aventureiro\n"
	             "numa jornada mistica\n\n"
				 "\t  __\n"
	             "\t /  \\\n"
				 "\t< u |\n"
				 "\t|   ----\n"
				 "\t|   \\  |\n"
				 "\tL-------\n"
				 "\t  J  J\n";
	std::cout << "------------------------------------------\n\n";
	std::this_thread::sleep_for(1000ms);
	
	std::cout << "Esta na hora de saber quem voce sera";
	std::this_thread::sleep_for(1000ms);
	std::cout << ".";
	std::this_thread::sleep_for(500ms);
	std::cout << ".";
	std::this_thread::sleep_for(500ms);
	std::cout << ".\n";
	
	//dados
	montarFicha();
	
	// jogatina
    bool estaVivo = true;

	std::this_thread::sleep_for(2000ms);
	std::cout << "\nHouve um tempo onde os passaros viviam em paz em sua\n"
				 "bela floresta, coletando alimento e praticando voos livres\n\n";
	std::this_thread::sleep_for(2000ms);			 
	std::cout << "Mas como nem tudo dura para sempre, ha 100 anos,\n"
				 "apos a chegada de tres animais sedentos por poder\n"
				 "nenhuma ave soube o que era voar sem medo\n\n";

	std::this_thread::sleep_for(1500ms);
	std::cout << "Porem, voce, " << protagonista.nome << ", ainda tem esperanca...\nde dias mais belos...\nde manhas tranquilas";
	std::this_thread::sleep_for(500ms);
	std::cout << ".";
	std::this_thread::sleep_for(500ms);
	std::cout << ".";
	std::this_thread::sleep_for(500ms);
	std::cout << ".\n";
	std::this_thread::sleep_for(1500ms);
	std::cout << "E por isso decidiu lutar.\n\n";

    // Luta 1: O Gato
    std::this_thread::sleep_for(2000ms);
    std::cout << "O primeiro na linha de frente era o Gato Cat-astrofe,\n"
				 "que recebeu esse apelido pelo que ele espalhava em seu caminho...\n";
	std::this_thread::sleep_for(3000ms);			 
	std::cout << "Ele e rapido, e fica vigiando as noites, procurando\n"
				 "por vitimas descuidadas que ousam sair a luz da Lua.\n\n"
				 "Ele so nao espera ter alguem vindo atras dele.\n";
	
	std::this_thread::sleep_for(2000ms);

    estaVivo = iniciarCombate(protagonista, gato);

    // Luta 2: O Lobo Mau 
    if (estaVivo) {
        std::cout << "\nA jornada continua mais a fundo na floresta...\n";
        	
		std::this_thread::sleep_for(2000ms);
		
        estaVivo = iniciarCombate(protagonista, loboMau);
    }

    // Luta 3: O Gavião de Fogo
    if (estaVivo) {
        std::cout << "\nVoce alcanca o topo da montanha para o desafio final...\n";
        
        std::this_thread::sleep_for(2000ms);

        estaVivo = iniciarCombate(protagonista, gaviaoDeFogo);
    }

    std::cout << "\n==========================================\n";
    if (estaVivo) {
        std::cout << "VITORIA! O Lendario Birb "<< protagonista.nome <<" derrotou todas as ameacas e salvou a todos!\n";
        
    } else {
        std::cout << "GAME OVER! Suas asas fraquejaram e o mundo caiu em trevas.\n";
    }
    std::cout << "==========================================\n";
    
    std::this_thread::sleep_for(60000ms);
	return 0;
}


void montarFicha ()
{
	int classe = 0;
	int opt = 0;
	std::string especieEscolhida = "";

	std::cout << "Para comecar, vamos precisar definir alguns dados:\n\n";
	std::cout << "digite o nome do seu personagem:\n";
	std::cin >> protagonista.nome;
	
	std::cout << "escolha a especie do "<< protagonista.nome <<":\n"
				 "[1] periquito\n"
				 "[2] calopsita\n"
				 "[3] papagaio\n";
	do {
		std::cin >> opt;
		switch (opt) {
		    case 1: 
		        especieEscolhida = "periquito";
		        break;
		
		    case 2: 
		        especieEscolhida = "calopsita";
		        break;
		
		    case 3: 
		        especieEscolhida = "papagaio";
		        break;
		}
		
		if (opt != 1 && opt != 2 && opt!= 3) std::cout << "\nOpcao invalida, digite de novo...\n\n";
		
	} while (opt != 1 && opt != 2 && opt!= 3);
	
	std::this_thread::sleep_for(1000ms);
	std::cout << "escolha a classe do seu personagem:\ncom muita atencao...\n"
				 "[1] mago\n"
				 "[2] curador\n"
				 "[3] guerreiro\n";
	std::cin >> classe;
	
	definirAtributos(protagonista, classe, especieEscolhida);
	
	std::this_thread::sleep_for(1000ms);
	protagonista.exibirFicha();
}

void definirAtributos(Personagem &p, int classe, std::string especie)
{
	p.especie = especie;
	
	switch (classe) {
	    case 1: // Força média, Cura baixa
	        p.classe = "mago";
	        p.forca = (rand() % (15 - 5 + 1)) + 5;       // Força de 5 a 15
	        p.poderCura = (rand() % (5 - 1 + 1)) + 1;    // Cura de 1 a 5
	        break;
	
	    case 2: // Força baixa, Cura alta
	        p.classe = "curador";
	        p.forca = (rand() % (10 - 3 + 1)) + 3;       // Força de 3 a 10
	        p.poderCura = (rand() % (12 - 6 + 1)) + 6;   // Cura de 6 a 12
	        break;
	
	    case 3: // Força alta, Cura quase nula
	        p.classe = "guerreiro";
	        p.forca = (rand() % (25 - 12 + 1)) + 12;     // Força de 12 a 25
	        p.poderCura = (rand() % (2 - 0 + 1)) + 0;    // Cura de 0 a 2
	        break;
	
	    default:
	    	std::this_thread::sleep_for(1000ms);
	        std::cout << "Classe invalida...\nO universo escolhera por voce...\n";
	        std::this_thread::sleep_for(200ms);
			std::cout << ".";
			std::this_thread::sleep_for(200ms);
			std::cout << ".";
			std::this_thread::sleep_for(200ms);
			std::cout << ".\n\n";
	        // Sorteia uma classe de 1 a 3 para o jogador inválido
	        int classeSorteada = (rand() % 3) + 1;
	        
	        if (classeSorteada == 1) {
	            p.classe = "mago";
	            p.forca = (rand() % (15 - 5 + 1)) + 5;
	            p.poderCura = (rand() % (5 - 1 + 1)) + 1;
	        } else if (classeSorteada == 2) {
	            p.classe = "curador";
	            p.forca = (rand() % (10 - 3 + 1)) + 3;
	            p.poderCura = (rand() % (12 - 6 + 1)) + 6;
	        } else {
	            p.classe = "guerreiro";
	            p.forca = (rand() % (25 - 12 + 1)) + 12;
	            p.poderCura = (rand() % (2 - 0 + 1)) + 0;
	        }
	        break;
	}
}













