//  sjf.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "sjf.hpp"

SJF::SJF(std::vector<Processo*> processos):
AlgoritmoDeEscalonamento(processos){}

SJF::~SJF(){}

bool duracao(Processo* a, Processo* b){
    return a->getDuracao() < b->getDuracao();
}

void SJF::escalonaProcessos(){
    int tempoDecorrido = 0;
    std::vector<Processo*> filaDeProntos;
    
    for(auto processo : processos_)
        processo->resetarTempos();
    
    do{
        for (auto processo : processos_){
            if (processo->getTempoDeChegada() <= tempoDecorrido && (std::find(filaDeProntos.begin(), filaDeProntos.end(), processo) == filaDeProntos.end()) && processo->estadoAtual != Processo::Estado::Finalizado){
                filaDeProntos.push_back(processo);
                processo->estadoAtual = Processo::Estado::Executando;
            }
        }
        
        // Sort para colocar os processos de menor duração no começo
        std::sort(filaDeProntos.begin(), filaDeProntos.end(), duracao);
        
        Processo* processoAtual = filaDeProntos.front();
        filaDeProntos.erase(filaDeProntos.begin());
        
        processoAtual->tempoDeEspera_ = tempoDecorrido - processoAtual->getTempoDeChegada();
        processoAtual->tempoDeResposta_ = tempoDecorrido - processoAtual->getTempoDeChegada();
        processoAtual->tempoDeRetorno_ = tempoDecorrido + processoAtual->getDuracao();
        processoAtual->estadoAtual = Processo::Estado::Finalizado;
        
        tempoDecorrido += processoAtual->getDuracao();
    }while(!filaDeProntos.empty());
    
    computarTemposMedios();
}
