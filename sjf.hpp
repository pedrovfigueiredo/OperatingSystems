//
//  sjf.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef sjf_hpp
#define sjf_hpp
#include "algoritmo.hpp"

class SJF : public AlgoritmoDeEscalonamento{
public:
    
    SJF(std::vector<Processo*> processos);
    ~SJF();
    
    void escalonaProcessos();
    
};

#endif /* sjf_hpp */
