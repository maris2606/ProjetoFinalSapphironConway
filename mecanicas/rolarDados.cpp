#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime> 

#include "../headers/rolarDados.h"

int rolarDados (int min, int max) {
	
	return (rand() % (max - min + 1)) + min;
}

float gerarMultiplicador (){
	
	int numero = rolarDados (50, 150); 

	return numero/100.0f + 1.0f; 
}
