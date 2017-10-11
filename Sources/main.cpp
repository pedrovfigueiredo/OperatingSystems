//
//  main.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include <iostream>
#include "../Headers/reader.hpp"
#include "../Headers/processo.hpp"
#include "../Headers/fcfs.hpp"
#include "../Headers/sjf.hpp"
#include "../Headers/rr.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<Processo*> processos;
    
    Reader::parseProcessesFromFile(argv[1], processos);
    
    FCFS* fcfs = new FCFS(processos);
    SJF* sjf = new SJF(processos);
    RoundRobin* rr = new RoundRobin(processos, 2);
    
    fcfs->escalonaProcessos();
    sjf->escalonaProcessos();
    rr->escalonaProcessos();
    
    std::cout.precision(1);
    std::cout << "FCFS " << std::fixed << fcfs->getTempoDeRetornoMedio() << " " << std::fixed << fcfs->getTempoDeRespostaMedio() << " " << std::fixed << fcfs->getTempoDeEsperaMedio() << std::endl;
    std::cout << "SJF " << std::fixed << sjf->getTempoDeRetornoMedio() << " " << std::fixed << sjf->getTempoDeRespostaMedio() << " " << std::fixed << sjf->getTempoDeEsperaMedio() << std::endl;
    std::cout << "RR " << std::fixed << rr->getTempoDeRetornoMedio() << " " << std::fixed << rr->getTempoDeRespostaMedio() << " " << std::fixed << rr->getTempoDeEsperaMedio() << std::endl;
    
    return 0;
}
