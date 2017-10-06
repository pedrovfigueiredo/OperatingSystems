//
//  fcfs.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef fcfs_hpp
#define fcfs_hpp
#include "algoritmo.hpp"

class FCFS : public AlgoritmoDeEscalonamento{
public:
    
    FCFS(std::vector<Processo*> processos);
    ~FCFS();
    
    void escalonaProcessos();
    
};

#endif /* fcfs_hpp */
