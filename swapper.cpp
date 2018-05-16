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
        /* Caso a referência não estava na memória, coloque a referência no
           primeiro quadro vazio ou o mais antigo da memória e incremente a
           falta de paginas */
        if(!memCheque){
            memoriaRAM[primeiro] = listaReferencias[i];
            primeiro = (primeiro + 1) % qtdQuadros;
            this->faltaPagina++;
        }
    }
}

/* Método do algoritmo de substituição de paginas OTM (Algoritmo Ótimo) */
void Swapper::OTM(std::vector <int> listaReferencias, int qtdQuadros){
    int memoriaRAM[qtdQuadros];
    int distancia[qtdQuadros];

    /* Inicializa a memória RAM com -1 */
    for(int i = 0; i < qtdQuadros; i++)
        memoriaRAM[i] = -1;

    /* Inicializa o array de distâncias com um valor máximo */
    for(int u = 0; u < qtdQuadros; u++)
        distancia[u] = INT_MAX;

    /* Percorre a lista de referências */
    for(unsigned int i = 0; i < listaReferencias.size(); i++){
        int memCheque = -1;

        /* Percorre a memória RAM */
        for(int k = 0; k < qtdQuadros; k++){
            /* Checa se a referência se encontra na memória */
            if(memoriaRAM[k] == listaReferencias[i])
                memCheque = k;
        }

        /* Se a referência for encontrada na memória */
        if(memCheque != -1){
            /* Decrementa a distância de todos as paginas */
            for(int u = 0; u < qtdQuadros; u++)
                distancia[u]--;

            int aux = 1;

            /* Percorre a lista de referências a partir da pagina sendo avaliada */
            for(unsigned int k = i+1; k < listaReferencias.size(); k++){
                /* Se a pagina atual aparecer novamente na lista de referências,
                   ataualizar sua distância, caso não apareça novamente, coloque
                   sua distância igual ao número de referências que faltam */
                if(listaReferencias[k] == listaReferencias[i] || k == (listaReferencias.size() -1)){
                    distancia[memCheque] = aux;
                    break;
                }
                aux++;
            }
            continue;
        }
        /* Caso a referência não seja encontrada na memória */
        else{

            int maiorDistancia = 0;
            int maiorDistanciaID;

            /* Procura a pagina com maior distância e salva seu indice */
            for(int k = 0; k < qtdQuadros; k++){
                if(maiorDistancia < distancia[k]){
                    maiorDistancia = distancia[k];
                    maiorDistanciaID = k;
                }
            }

            /* Faz a nova referência tomar o lugar na memória da pagina com a
               maior distância */
            memoriaRAM[maiorDistanciaID] = listaReferencias[i];

            /* Decrementa a idade de todas as paginas na memória e atualiza a
               distância da que acabou de ser inserida */
            for(int u = 0; u < qtdQuadros; u++)
                distancia[u]--;
                
            this->faltaPagina++;
                
            int aux = 1;
            for(unsigned int k = i+1; k < listaReferencias.size(); k++){
                if(listaReferencias[k] == listaReferencias[i] || k == (listaReferencias.size() -1)){
                    distancia[maiorDistanciaID] = aux;
                    break;
                }
                aux++;
            }
        }
    }
}

/* Método do algoritmo de substituição de paginas LRU (Least Recently Used) */
void Swapper::LRU(std::vector <int> listaReferencias, int qtdQuadros){
    int memoriaRAM[qtdQuadros];
    int idade[qtdQuadros];

    /* Inicializa a memória RAM com -1 */
    for(int i = 0; i < qtdQuadros; i++)
        memoriaRAM[i] = -1;

    /* Inicializa o array de idade com um valor máximo menos o número de quadros */
    for(int u = 0; u < qtdQuadros; u++){
        idade[u] = INT_MAX / 2;
    }

    /* Percorre a lista de referências */
    for(unsigned int i = 0; i < listaReferencias.size(); i++){
        int memCheque = -1;

        /* Percorre a memória RAM */
        for(int k = 0; k < qtdQuadros; k++){
            /* Checa se a referência se encontra na memória */
            if(memoriaRAM[k] == listaReferencias[i])
                memCheque = k;
        }

        /* Se a referência for encontrada, incremente a idade de todos as paginas
           e faz com que a idade da pagina que foi referenciada seja 0 */
        if(memCheque != -1){
            for(int u = 0; u < qtdQuadros; u++)
                idade[u]++;

            idade[memCheque] = 0;
            continue;
        }
        
        /* Caso a referência não seja encontrada */
        else{
            int maisVelho = 0;
            int maisVelhoID;

            /* Procura a pagina mais velha e salva seu indice */
            for(int k = 0; k < qtdQuadros; k++){
                if(maisVelho < idade[k]){
                    maisVelho = idade[k];
                    maisVelhoID = k;
                }
            }

            /* Faz a nova referência tomar o lugar na memória da pagina mais 
               velha */
            memoriaRAM[maisVelhoID] = listaReferencias[i];

            this->faltaPagina++;

            /* Incrementa a idade de todas as paginas na memória e faz com que
               a idade da que acabou de ser inserida seja 0 */
            for(int u = 0; u < qtdQuadros; u++)
                idade[u]++;
                
            idade[maisVelhoID] = 0;
        }
    }
}
