#ifndef BIBLIOPONTE_H_INCLUDED
#define BIBLIOPONTE_H_INCLUDED
#include "global.h"


using namespace std;

struct TPessoa{

    string Nome;
    int idade;
    int identidade;
    int rua;
    string bairro;

};

struct TListaA{

    TPessoa vetPessoas[maxTam];
    int primeiro;
    int ultimo;
    int contItens;
};

struct TCelula{

    TPessoa Pessoa;
    TCelula *proximo;

};
struct TFilaP{

    TCelula *frente;
    TCelula *tras;

};
struct TNo{
    TPessoa Pessoa;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{
    int contItens;
    TNo *raiz;
};

bool estaVaziaLA(TListaA l);

bool estaVaziaFilaP(TFilaP f);

void criarArvoreVazia(TArvoreBin &a);

void inicializarlistaA(TListaA &la);

void inicializarFilaP(TFilaP &fa);


void inserirArvore(TNo *&no, TPessoa p);

void MostrarEmOrdem(TNo *&no, int k);

void mostrarItensLA(TListaA la);

void mostraritensFila(TFilaP f);

void enfileirar(TFilaP &f, TPessoa x);

void inserirListaA(TListaA &l, TPessoa x);

void cadastrar(TListaA &l, TArvoreBin &arvorezinha);


void retirarDaListaPosicao(TListaA &l,int p);

int pegaMaiorIdade(TListaA l);

void TransferirLparaF(TListaA &l, TFilaP &p);

int numeropararaiz(TFilaP p);

void colocarRaizNAarvore(TArvoreBin &arvorao, TFilaP &f);

void colocarNAarvore(TArvoreBin &arvorao, TFilaP &f);

void menu(TListaA l, TFilaP f, TArvoreBin a);

#endif // BIBLIOPONTE_H_INCLUDED

