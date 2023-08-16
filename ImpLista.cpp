#include "biblioPonte.h"
#include <iostream>
using namespace std;


bool estaVaziaLA(TListaA l){
    return l.primeiro == l.ultimo;
}

void inicializarlistaA(TListaA &la)
{

    la.primeiro = 0;
    la.ultimo = la.primeiro;
    la.contItens = 0;
}

void mostrarItensLA(TListaA la)
{
    setlocale(LC_ALL,"");
    if(estaVaziaLA(la)){

        cout << "A lista está vazia!!" << endl;
    }
    else
    {
    for(int i = la.primeiro; i < la.ultimo; i++)
    {
       cout << "Nome do paciente: " << la.vetPessoas[i].Nome << endl;
       cout << "Idade do paciente: " << la.vetPessoas[i].idade << endl;
       cout <<"Identidade do paciente: " << la.vetPessoas[i].identidade << endl;
       cout << "Rua onde o paciente mora: " << la.vetPessoas[i].rua << endl;
       cout << "Bairro onde o paciente reside: " <<  la.vetPessoas[i].bairro << endl;

       cout << "================ // =================" << endl;

    }
    }
}

void inserirListaA(TListaA &l, TPessoa x)
{
        cout << "======== Paciente atendido!! ========" << endl;
        cout << "Nome: " << x.Nome << "." << endl;
        cout << "Idade: " << x.idade << "." << endl;
        cout << "Identidade: " << x.identidade << "." << endl;
        cout << "Rua: " << x.rua << "." << endl;
        cout << "Bairro: " << x.bairro << "." << endl;
        l.vetPessoas[l.ultimo] = x;
        l.ultimo++;
}


void retirarDaListaPosicao(TListaA &l,int p){
    setlocale(LC_ALL,"");
    if (estaVaziaLA(l) || p < 0 || p >= l.ultimo){
        cout << "Lista vazia ou posição fora do intervalo." << endl;
    }
    else{
        l.ultimo--;
        for(int aux=p; aux<l.ultimo; aux++){
            l.vetPessoas[aux] = l.vetPessoas[aux+1];
        }
    }

}


int pegaMaiorIdade(TListaA l){


    if(estaVaziaLA(l)){
        return -1;
    }
    else{

        int maioridade = -1;
        int posMaior = -1;

        for (int i=l.primeiro;i<l.ultimo;i++){
            if (l.vetPessoas[i].idade > maioridade){

                maioridade = l.vetPessoas[i].idade;
                posMaior = i;
            }
        }
        return posMaior;
    }
    cout << "-------------------------------" << endl;
}

