#include "biblioPonte.h"
#include <iostream>
using namespace std;



bool estaVaziaFilaP(TFilaP f){
    return f.frente == f.tras;
}

void inicializarFilaP(TFilaP &fa)
{
     fa.frente = new TCelula;
     fa.tras = fa.frente;
     fa.frente->proximo = NULL;


}

void mostraritensFila(TFilaP f){
    TCelula *celAux;
    celAux = f.frente->proximo;
    setlocale(LC_ALL,"");

    cout << "=== MOSTRANDO A FILA === "<< endl;
    if (estaVaziaFilaP(f)){
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else{
        while (celAux != NULL){

            cout << "   Nome:   " << celAux->Pessoa.Nome << endl;
            cout << "   Idade:   " << celAux->Pessoa.idade << endl;
            cout << "   Identidade: " << celAux->Pessoa.identidade << endl;
            cout << "   Rua: " << celAux->Pessoa.rua<< endl;
            cout << "   Bairro: " << celAux->Pessoa.bairro << endl;
            celAux = celAux->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

void enfileirar(TFilaP &f, TPessoa x){
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->Pessoa = x;
    f.tras->proximo = NULL;
}


int numeropararaiz(TFilaP p)
{
    int media;
   media = (p.frente->proximo->Pessoa.idade + p.tras->Pessoa.idade) / 2;

return media;

}

