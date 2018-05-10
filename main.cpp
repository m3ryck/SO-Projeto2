/*  Aluno: Valfredo Santos Júnior
    Matrícula: 115040304  */

#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>

int qtdQuadros = 0;

/*  Função CriaLista recebe como parâmetro um nome de arquivo de entrada,
    cria uma lista de inteiros com base na entrada, e retorna essa lista.  */
std::vector <int> CriaLista(const char* inputfile){

    std::ifstream file;
    file.open(inputfile, std::ios::in);

    std::vector <int> listaReferencias;

    if(file.good())
      file >> qtdQuadros;

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
    algoritmo de substituição de paginas, passando a lista de referências
    como parâmetro */
int main(){

    std::vector <int> listaReferencias = CriaLista("input.txt");

    return 0;
}
