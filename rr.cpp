//
//  rr.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "rr.hpp"

RoundRobin::RoundRobin(std::vector<Processo*> processos, const int quantum):
AlgoritmoDeEscalonamento(processos),
quantum_(quantum){}

RoundRobin::~RoundRobin(){}

void RoundRobin::escalonaProcessos(){
    int tempoDecorrido = 0;
    std::vector<Processo*> filaDeProntos;
    
    for(auto processo : processos_)
        processo->resetarTempos();
    
    while(true){
        for (auto processo : processos_){
            if (processo->getTempoDeChegada() <= tempoDecorrido && (std::find(filaDeProntos.begin(), filaDeProntos.end(), processo) == filaDeProntos.end()) && processo->estadoAtual != Processo::Estado::Finalizado){
                filaDeProntos.push_back(processo);
                processo->estadoAtual = Processo::Estado::Executando;
            }
        }
        
        if(filaDeProntos.empty())
            break;
        
        Processo* processoAtual = filaDeProntos.front();
        filaDeProntos.erase(filaDeProntos.begin());
        
        processoAtual->tempoDeEspera_ = tempoDecorrido - processoAtual->getTempoDeChegada();
        processoAtual->tempoDeRetorno_ = tempoDecorrido + processoAtual->getDuracao();
        processoAtual->tempoExecutando += this->quantum_;
        
        if (processoAtual->tempoDeResposta_ == -1)
            processoAtual->tempoDeResposta_ = tempoDecorrido - processoAtual->getTempoDeChegada();
        
        if (processoAtual->tempoExecutando >= processoAtual->getDuracao())
            processoAtual->estadoAtual = Processo::Estado::Finalizado;
        
        tempoDecorrido += std::min(this->quantum_, std::abs((processoAtual->getDuracao() - processoAtual->tempoExecutando)));
    }
    
    computarTemposMedios();
}
