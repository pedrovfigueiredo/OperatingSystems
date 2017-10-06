//
//  fcfs.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "fcfs.hpp"

FCFS::FCFS(std::vector<Processo*> processos):
AlgoritmoDeEscalonamento(processos){}

FCFS::~FCFS(){}

void FCFS::escalonaProcessos(){
    int tempoDecorrido = 0;
    
    for(auto processo : processos_)
        processo->resetarTempos();
    
    for (auto processo : processos_) {
        processo->tempoDeResposta_ = tempoDecorrido - processo->getTempoDeChegada();
        processo->tempoDeEspera_ = tempoDecorrido - processo->getTempoDeChegada();
        processo->tempoDeRetorno_ = tempoDecorrido + processo->getDuracao();
        processo->estadoAtual = Processo::Estado::Finalizado;
        tempoDecorrido += processo->getDuracao();
    }
    
    computarTemposMedios();
}
