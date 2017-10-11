//
//  rr.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/rr.hpp"

RoundRobin::RoundRobin(std::vector<Processo*> processos, const int quantum):
AlgoritmoDeEscalonamento(processos),
quantum_(quantum){}

RoundRobin::~RoundRobin(){}

// Ordena processos de forma decrescente de acordo com o tempo de resposta
bool compareRR(Processo* p1, Processo* p2){
    return p1->tempoDeResposta_ < p2->tempoDeResposta_;
}

void RoundRobin::escalonaProcessos(){
    int tempoDecorrido = 0;
    std::vector<Processo*> filaDeProntos;
    
    for(auto processo : processos_)
        processo->resetarTempos();
    
    while(true){
        int recemInseridosFilaDeProntos = 0;
        for (auto processo : processos_){
            if(filaDeProntos.empty() && processo->getTempoDeChegada() > tempoDecorrido)
                tempoDecorrido = processo->getTempoDeChegada();
            
            if (processo->getTempoDeChegada() <= tempoDecorrido && (std::find(filaDeProntos.begin(), filaDeProntos.end(), processo) == filaDeProntos.end()) && processo->estadoAtual != Processo::Estado::Finalizado){
                filaDeProntos.push_back(processo);
                processo->estadoAtual = Processo::Estado::Executando;
                recemInseridosFilaDeProntos++;
            }
        }
        // Se não há processos na fila de prontos, não há mais o que se fazer
        if(filaDeProntos.empty())
            break;
        
        // Faz-se sort apenas nos elementos recém-colocados na fila de prontos para priorizar novos processos
        std::sort(filaDeProntos.begin() + filaDeProntos.size() - recemInseridosFilaDeProntos, filaDeProntos.end(), compareRR);
        
        Processo* processoAtual = filaDeProntos.front();
        filaDeProntos.erase(filaDeProntos.begin());
        
        processoAtual->tempoDeEspera_ = tempoDecorrido - processoAtual->tempoExecutando - processoAtual->getTempoDeChegada();
        processoAtual->tempoExecutando += this->quantum_;
        
        // Se é a primeira vez que o processo executa
        if (processoAtual->tempoDeResposta_ == -1)
            processoAtual->tempoDeResposta_ = tempoDecorrido - processoAtual->getTempoDeChegada();
        
        // If para caso em que a diferença entre duração e tempoExecutando é 0
        if(processoAtual->getDuracao() != processoAtual->tempoExecutando)
            tempoDecorrido += std::min(this->quantum_, std::abs((processoAtual->getDuracao() - processoAtual->tempoExecutando)));
        else
            tempoDecorrido += this->quantum_;
        
        if (processoAtual->tempoExecutando >= processoAtual->getDuracao()){
            processoAtual->tempoDeRetorno_ = tempoDecorrido - processoAtual->getTempoDeChegada();
            processoAtual->estadoAtual = Processo::Estado::Finalizado;
        }
    }
    
    computarTemposMedios();
}
