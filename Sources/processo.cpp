//
//  processo.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/processo.hpp"

Processo::Processo(int tempoDeChegada, int duracao):
tempoDeChegada_(tempoDeChegada),
duracao_(duracao){}

int Processo::getDuracao(){return duracao_;}

int Processo::getTempoDeChegada(){return tempoDeChegada_;}

void Processo::resetarTempos(){
    tempoDeRetorno_ = 0;
    tempoDeResposta_ = -1;
    tempoDeEspera_ = 0;
    tempoExecutando = 0;
    estadoAtual = Criado;
}
