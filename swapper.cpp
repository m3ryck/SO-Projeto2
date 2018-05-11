#include "swapper.hpp"

/* Inicializa o atributo faltaPagina do objeto com 0 */
Swapper::Swapper(){
    this->faltaPagina = 0;
}

Swapper::~Swapper(){;}

/* Método do algoritmo de substituição de paginas FIFO (First In First Out) */
void Swapper::FIFO(std::vector <int> listaReferencias, int qtdQuadros){
    int memoriaRAM[qtdQuadros];

    /* Inicializa a memória RAM com -1 */
    for(int i = 0; i < qtdQuadros; i++)
        memoriaRAM[i] = -1;

    int primeiro = 0;

    /* Percorre a lista de referências */
    for(unsigned int i = 0; i < listaReferencias.size(); i++){
        bool memCheque = false;

        /* Percorre a memória RAM */
        for(int k = 0; k < qtdQuadros; k++){
            /* Checa se a referência se encontra na memória */
            if(memoriaRAM[k] == listaReferencias[i])
                memCheque = true;
        }

        /* Caso a referência estava na memória, volte para o inicio do loop e
           avalie a próxima entrada da lista de referências */
        if(memCheque){
            continue;
        }
        /* Caso a referência não estava na memória, coloque a referência no
           primeiro quadro vazio ou o mais antigo da memória */
        else{
            memoriaRAM[primeiro] = listaReferencias[i];
            primeiro = (primeiro + 1) % qtdQuadros;
            this->faltaPagina++;
        }
    }
}
