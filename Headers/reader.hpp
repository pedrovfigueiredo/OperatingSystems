//
//  reader.hpp
//  Projeto1-SO
//
//  Created by Pedro Figueirêdo on 26/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef reader_hpp
#define reader_hpp
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "processo.hpp"

class Reader
{
public:
    Reader();
    ~Reader();
    
    static const void parseProcessesFromFile(const std::string& fileName, std::vector<Processo*>& processos);
    
};

#endif /* reader_hpp */
