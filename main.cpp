#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime> 
#include <clocale>

#include "./headers/personagens.h"
#include "./headers/rolarDados.h"
#include "./headers/combate.h"

using namespace std::chrono_literals;

/*
"Para compilar o projeto, 
utilize o compilador g++ com suporte ao padrão C++11 ou superior, 
incluindo todos os arquivos .cpp do diretório: g++ main.cpp mecanicas/*.cpp -Iheaders -std=c++17 -o jogo"

*/

// declarar funcoes
void montarFicha(Personagem &p);
void definirAtributos(Personagem &p, int classe, std::string especie);

bool estaDefendendo = false;
int jogarNovamente = 0;

int main (){
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));
	
	do {
		
		// variaveis e objetos
		Personagem protagonista;
		// viloes com classe, vida, forca e cura
		Personagem gato ("Gato Cat-astrofe", "vilão", "gato", 100, 10, 5);
		Personagem loboMau ("Lobo Mau", "vilão", "lobo", 200, 15, 10);
		Personagem gaviaoDeFogo ("Gavião de Fogo", "vilão", "gavião", 400, 20, 15);
		
		//introdução	
		std::cout << "================== birbRPG ===============\n\n";
		std::this_thread::sleep_for(1000ms);
		
		std::cout << "Seja Bem Vindo(a) ao BirbRPG!\n"
		             "um mundo fantástico onde voce será um passarinho aventureiro\n"
		             "numa jornada mástica\n\n"
					 "\t  __\n"
		             "\t /  \\\n"
					 "\t< u |\n"
					 "\t|   ----\n"
					 "\t|   \\  |\n"
					 "\tL-------\n"
					 "\t  J  J\n";
		std::cout << "------------------------------------------\n\n";
		std::this_thread::sleep_for(1000ms);
		
		std::cout << "Está na hora de saber quem você será";
		std::this_thread::sleep_for(1000ms);
		std::cout << ".";
		std::this_thread::sleep_for(500ms);
		std::cout << ".";
		std::this_thread::sleep_for(500ms);
		std::cout << ".\n";
		
		std::this_thread::sleep_for(1000ms);
		//dados
		montarFicha(protagonista);
		
		// jogatina
	    bool estaVivo = true;
	
		std::this_thread::sleep_for(2000ms);
		std::cout << "\nHouve um tempo onde os pássaros viviam em paz em sua\n"
					 "bela floresta, coletando alimento e praticando voos livres\n\n";
		std::this_thread::sleep_for(2000ms);			 
		std::cout << "Mas como nem tudo dura para sempre, há 100 anos,\n"
					 "após a chegada de três animais sedentos por poder\n"
					 "nenhuma ave soube o que era voar sem medo\n\n";
	
		std::this_thread::sleep_for(1500ms);
		std::cout << "Porém, você, " << protagonista.nome << ", ainda tem esperança...\nde dias mais belos...\nde manhãs tranquilas";
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
		std::cout << "Ele é rapido, e fica vigiando as noites, procurando\n"
					 "por vítimas descuidadas que ousam sair a luz da Lua.\n\n"
					 "Ele só nao espera ter alguem vindo atrás dele.\n";
		
		std::this_thread::sleep_for(2000ms);
	
	    estaVivo = iniciarCombate(protagonista, gato);
	
	    // Luta 2: O Lobo Mau 
	    if (estaVivo) {
	    	std::this_thread::sleep_for(1000ms);
	    	std::cout << "------------------------------------------\n\n";
			
	        std::cout << "\nA jornada continua mais a fundo na floresta...\n";
	        std::this_thread::sleep_for(3000ms);
	        std::cout << "\nDepois de uma planície, ao amanhecer, você avista o covil\n"
						 "do terrível Lobo Mau, que impede que qualquer um deixe a floresta\n"
						 "(e tem como hobbie atacar velhinhas)\n";	
			std::this_thread::sleep_for(2000ms);
			
	        estaVivo = iniciarCombate(protagonista, loboMau);
	    }
	
	    // Luta 3: O Gavião de Fogo
	    if (estaVivo) {
	    	std::this_thread::sleep_for(1000ms);
	    	std::cout << "------------------------------------------\n\n";
	    	
	        std::cout << "\nVoce alcanca o topo da montanha para o desafio final...\n";
	        std::this_thread::sleep_for(3000ms);
	        std::cout << "\nO pôr do Sol marca a paisagem atrás do ninho do pior de todos os vilões";
						 
			std::this_thread::sleep_for(500ms);
			std::cout << ".";
			std::this_thread::sleep_for(500ms);
			std::cout << ".";
			std::this_thread::sleep_for(500ms);
			std::cout << ".\n";
			std::this_thread::sleep_for(1500ms);
			
			std::cout << "\nE você se sente tomado por determinação";	
			std::this_thread::sleep_for(2000ms);
			
	
	        estaVivo = iniciarCombate(protagonista, gaviaoDeFogo);
	    }
	
	    std::cout << "\n==========================================\n";
	    if (estaVivo) {
	        std::cout << "VITÓRIA! O Lendário Birb "<< protagonista.nome <<" derrotou todas as ameaças e salvou a todos!\n";
	        
	    } else {
	        std::cout << "GAME OVER! Suas asas fraquejaram e o mundo caiu em trevas.\n";
			
	    }
	    
	    std::cout << "------------------------------------------\n";
	    
		std::cout << "\n\nDeseja tentar novamente??\n"
                  << "[1] Sim\n"
                  << "[2] Não\n";         
        std::cin >> jogarNovamente;
        
        while (std::cin.fail() || (jogarNovamente != 1 && jogarNovamente != 2)) {
            std::cin.clear();              
            std::cin.ignore(9999, '\n');    
            
            std::cout << "Valor inválido!\n";
            std::cout << "\nDeseja tentar novamente??\n"
                      << "[1] Sim\n"
                      << "[2] Não\n";         
            std::cin >> jogarNovamente;
        }
        
        std::cout << "==========================================\n";
        
    } while (jogarNovamente == 1); // O jogo só repete se a opção for 1
    
    return 0;
}


void montarFicha (Personagem &p)
{
	int classe = 0;
	int opt = 0;
	std::string especieEscolhida = "";

	std::cout << "Para começar, vamos precisar definir alguns dados:\n\n";
	std::this_thread::sleep_for(1000ms);
	std::cout << "digite o nome do seu personagem (até 20 caracteres):\n";
	std::getline(std::cin >> std::ws, p.nome);
	
	if (p.nome.length() >= 20) {
	    std::cout << "\n[Aviso]: O nome era muito longo e foi encurtado para caber na ficha.\n\n";
	    
		// Corta a string
	    p.nome = p.nome.substr(0, 20); 
	}
	
	std::cout << "escolha a espécie do "<< p.nome <<":\n"
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
		
		if (opt != 1 && opt != 2 && opt!= 3) std::cout << "\nOpção inválida, digite de novo...\n\n";
		
	} while (opt != 1 && opt != 2 && opt!= 3);
	
	std::this_thread::sleep_for(1000ms);
	std::cout << "escolha a classe do seu personagem:\ncom muita atenção...\n"
				 "[1] mago\t[ataque e cura]\n"
				 "[2] curador\t[+cura e -ataque]\n"
				 "[3] guerreiro\t[+ataque e -cura]\n";
	std::cin >> classe;
	
	definirAtributos(p, classe, especieEscolhida);
	
	std::this_thread::sleep_for(1000ms);
	p.exibirFicha();
}

void definirAtributos(Personagem &p, int classe, std::string especie)
{
	p.especie = especie;
	
	switch (classe) {
	    case 1: // Força média, Cura baixa
	        p.classe = "mago";
	        p.setForca(rolarDados (10, 20));     
	        p.setPoderCura(rolarDados (4, 8));   
	        break;
	
	    case 2: // Força baixa, Cura alta
	        p.classe = "curador";
	        p.setForca(rolarDados (10, 15));     
	        p.setPoderCura(rolarDados (8, 15));  
	        break;
	
	    case 3: // Força alta, Cura quase nula
	        p.classe = "guerreiro";
	        p.setForca(rolarDados (15, 25));    
	        p.setPoderCura(rolarDados (3, 7));    
	        break;
	
	    default:
	    	std::this_thread::sleep_for(1000ms);
	        std::cout << "Classe inválida...\nO universo escolherá por você...\n";
	        std::this_thread::sleep_for(200ms);
			std::cout << ".";
			std::this_thread::sleep_for(200ms);
			std::cout << ".";
			std::this_thread::sleep_for(200ms);
			std::cout << ".\n\n";
	        // Sorteia uma classe de 1 a 3 para o jogador inválido
	        int classeSorteada = rolarDados (1, 3);
	        
	        if (classeSorteada == 1) {
	            p.classe = "mago";
	            p.setForca(rolarDados (10, 20));     
	        	p.setPoderCura(rolarDados (4, 8));   
	        } else if (classeSorteada == 2) {
	            p.classe = "curador";
		        p.setForca(rolarDados (10, 15));     
		        p.setPoderCura(rolarDados (8, 15));  
	        } else {
	            p.classe = "guerreiro";
		        p.setForca(rolarDados (15, 25));   
		        p.setPoderCura(rolarDados (3, 7));   
	        }
	        break;
	}
}





