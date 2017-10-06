//
//  rr.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef rr_hpp
#define rr_hpp
#include "algoritmo.hpp"
#include <cstdlib>

class RoundRobin : public AlgoritmoDeEscalonamento{
public:
    
    RoundRobin(std::vector<Processo*> processos, const int quantum);
    ~RoundRobin();
    
    void escalonaProcessos();
    
private:
    int quantum_;
    
};

#endif /* rr_hpp */
