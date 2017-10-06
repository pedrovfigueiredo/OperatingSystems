//
//  processo.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 20/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef processo_hpp
#define processo_hpp

class Processo{
public:
    enum Estado{Criado,Executando,Finalizado};
    
    Processo(int tempoDeChegada, int duracao);
    ~Processo();
    
    int getTempoDeChegada();
    int getDuracao();
    void resetarTempos();
    
    double tempoDeRetorno_ = 0;
    double tempoDeResposta_ = -1;
    double tempoDeEspera_ = 0;
    Estado estadoAtual = Criado;
    
    // Round Robin
    int tempoExecutando = 0;
    
private:
    int tempoDeChegada_;
    int duracao_;
};

#endif /* processo_hpp */
