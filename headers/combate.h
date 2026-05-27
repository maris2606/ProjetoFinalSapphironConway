#ifndef COMBATE_H
#define COMBATE_H

#include "personagens.h"

bool iniciarCombate(Personagem &protagonista, Personagem &vilao);

void turnoJogador(Personagem &protagonista, Personagem &vilao);
void turnoInimigo(Personagem &protagonista, Personagem &vilao);
void narrativaCombate(Personagem &protagonista);

#endif
