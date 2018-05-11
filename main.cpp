/*  Aluno: Valfredo Santos Júnior
    Matrícula: 115040304  */

#include <fstream>
#include <iomanip>

#include "swapper.hpp"

/*  Função CriaLista recebe como parâmetro um nome de arquivo de entrada e uma
    referência para uma variável inteira, então ela atualiza a variável
    referenciada com o primeiro valor inteiro do arquivo, cria uma lista de
    referências à memória com base no resto do arquivo de entrada e retorna essa
    lista.  */
std::vector <int> CriaLista(const char* inputfile, int* qtdQuadros){

    std::ifstream file;
    file.open(inputfile, std::ios::in);

    std::vector <int> listaReferencias;

    if(file.good())
      file >> *qtdQuadros;

    while(file.good()){
        int aux;
        file >> aux;
        listaReferencias.push_back(aux);
    }

    file.close();

    return listaReferencias;

}

/*  O main faz a criação da lista de referências à memória com base na entrada,
    cria três objetos da classe Swapper e então chama uma função para cada
    algoritmo de substituição de paginas, passando a lista de referências e a
    quantidade de quadros na memória como parâmetros */
int main(){

    int qtdQuadros = 0;

    std::vector <int> listaReferencias = CriaLista("input.txt", &qtdQuadros);

    Swapper fifo;

    fifo.FIFO(listaReferencias, qtdQuadros);

    std::cout <<"FIFO " << fifo.faltaPagina << std::endl;

    return 0;
}
