//
//  main.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include <iostream>
#include "reader.hpp"
#include "processo.hpp"
#include "fcfs.hpp"
#include "sjf.hpp"
#include "rr.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<Processo*> processos;
    
    Reader::parseProcessesFromFile("/Users/PedroFigueiredo/Google Drive/5 Período/Sistemas Operacionais I/Projetos/Projeto 1/Projeto1-SO/Projeto1-SO/input_so.txt", processos);
    
    FCFS* fcfs = new FCFS(processos);
    SJF* sjf = new SJF(processos);
    RoundRobin* rr = new RoundRobin(processos, 4);
    
    fcfs->escalonaProcessos();
    sjf->escalonaProcessos();
    rr->escalonaProcessos();
    
    std::cout << "FCFS " << fcfs->getTempoDeRetornoMedio() << " " << fcfs->getTempoDeRespostaMedio() << " " << fcfs->getTempoDeEsperaMedio() << std::endl;
    std::cout << "SJF " << sjf->getTempoDeRetornoMedio() << " " << sjf->getTempoDeRespostaMedio() << " " << sjf->getTempoDeEsperaMedio() << std::endl;
    std::cout << "RR " << rr->getTempoDeRetornoMedio() << " " << rr->getTempoDeRespostaMedio() << " " << rr->getTempoDeEsperaMedio() << std::endl;
    
    return 0;
}
