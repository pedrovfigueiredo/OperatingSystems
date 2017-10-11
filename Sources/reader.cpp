//
//  reader.cpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 26/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/reader.hpp"

Reader::Reader(){}
Reader::~Reader(){}

const void Reader::parseProcessesFromFile(const std::string& fileName, std::vector<Processo*>& processos){
    int i, j;
    std::ifstream file(fileName);
    processos.reserve(10);
    
    while (file >> i >> j)
        processos.push_back(new Processo(i,j));
    
    file.close();
}
