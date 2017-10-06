//
//  algoritmo.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "algoritmo.hpp"
#include <algorithm>

bool tempoDeChegada(Processo* a, Processo* b){
    return a->getTempoDeChegada() < b->getTempoDeChegada();
}

AlgoritmoDeEscalonamento::AlgoritmoDeEscalonamento(std::vector<Processo*> processos){
    
    //Ordena-se o vetor de processos de forma crescente em relação ao tempo de chegada dos elementos
    std::sort(processos.begin(), processos.end(), tempoDeChegada);
    
    this->processos_ = processos;
}

AlgoritmoDeEscalonamento::~AlgoritmoDeEscalonamento(){}

void AlgoritmoDeEscalonamento::computarTemposMedios(){
    double tempoDeRetorno = 0, tempoDeEspera = 0, tempoDeResposta = 0;
    unsigned long processos_size = processos_.size();
    
    for(auto processo : processos_){
        tempoDeRetorno += processo->tempoDeRetorno_;
        tempoDeResposta += processo->tempoDeResposta_;
        tempoDeEspera += processo->tempoDeEspera_;
    }
    
    tempoDeRetornoMedio_ = tempoDeRetorno / processos_size;
    tempoDeRespostaMedio_ = tempoDeResposta / processos_size;
    tempoDeEsperaMedio_ = tempoDeEspera / processos_size;
}

double AlgoritmoDeEscalonamento::getTempoDeRetornoMedio(){return tempoDeRetornoMedio_;}

double AlgoritmoDeEscalonamento::getTempoDeRespostaMedio(){return tempoDeRespostaMedio_;}

double AlgoritmoDeEscalonamento::getTempoDeEsperaMedio(){return tempoDeEsperaMedio_;}
