#ifndef SWAPPER_HPP
#define PROCESSO_HPP

#include <vector>
#include <limits.h>
#include <iostream>

class Swapper{

  public:

      Swapper();
      ~Swapper();

      void FIFO(std::vector <int> listaReferencias, int qtdQuadros);
      void OTM(std::vector <int> listaReferencias, int qtdQuadros);
      void LRU(std::vector <int> listaReferencias, int qtdQuadros);

      int faltaPagina;

};

#endif
