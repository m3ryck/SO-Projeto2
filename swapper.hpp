#ifndef SWAPPER_HPP
#define PROCESSO_HPP

#include <vector>
#include <iostream>

class Swapper{

  public:

      Swapper();
      ~Swapper();

      void FIFO(std::vector <int> listaReferencias, int qtdQuadros);

      int faltaPagina;

};

#endif
