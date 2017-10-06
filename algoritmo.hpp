//
//  algoritmo.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef algoritmo_hpp
#define algoritmo_hpp
#include <vector>
#include <list>
#include <algorithm>
#include "processo.hpp"

class AlgoritmoDeEscalonamento
{
public:
    
    AlgoritmoDeEscalonamento(std::vector<Processo*> processos);
    ~AlgoritmoDeEscalonamento();
    
    virtual void escalonaProcessos() = 0;
    
    double getTempoDeRetornoMedio();
    double getTempoDeRespostaMedio();
    double getTempoDeEsperaMedio();
    
protected:
    void computarTemposMedios();
    
    std::vector<Processo*> processos_;

private:
    double tempoDeRetornoMedio_ = 0;
    double tempoDeRespostaMedio_ = 0;
    double tempoDeEsperaMedio_ = 0;
    
};

#endif /* algoritmo_hpp */
