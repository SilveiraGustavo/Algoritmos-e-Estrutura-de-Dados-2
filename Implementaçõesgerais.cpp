#include "biblioPonte.h"
using namespace std;

void criarArvoreVazia(TArvoreBin &a){

    a.raiz = NULL;
}

void inserirArvore(TNo *&no, TPessoa p){

    if (no == NULL){
        no = new TNo;
        no->Pessoa = p;
        no->esquerda = NULL;
        no->direita = NULL;
    }
    else{
        if (p.idade < no->Pessoa.idade){
            inserirArvore(no->esquerda,p);
        }
        else{
            if (p.idade > no->Pessoa.idade){
                inserirArvore(no->direita,p);
            }
            else{
                if (p.idade == no->Pessoa.idade){
                    cout << "Não posso inserir. Item já existe!" << endl;
                 }
            }
        }

    }
}


void MostrarEmOrdem(TNo *&no, int k){

    if(no!=NULL){
        MostrarEmOrdem(no->esquerda, k);
        if(no->Pessoa.idade > k)
        {
        cout << no ->Pessoa.Nome << " que tem " << no->Pessoa.idade << " anos." << endl ;
        }
        MostrarEmOrdem(no->direita, k);
    }

}

void cadastrar(TListaA &l, TArvoreBin &arvorezinha)
{
    setlocale(LC_ALL,"");
    TPessoa auxpessoa;

    auxpessoa.Nome = "João Vitor";
    auxpessoa.idade = 14;
    auxpessoa.identidade = 2335345-5;
    auxpessoa.bairro = "Santa Maria";
    auxpessoa.rua = 77;

    inserirListaA(l, auxpessoa);


    auxpessoa.Nome = "André";

    auxpessoa.idade = 19;
    auxpessoa.identidade = 3248827-3;
    auxpessoa.bairro = "São Judas";
    auxpessoa.rua = 34;

    inserirListaA(l, auxpessoa);


    auxpessoa.Nome = "Julia Pedrosa";
    auxpessoa.idade = 25;
    auxpessoa.identidade = 5529865-8;
    auxpessoa.bairro = "Centro";
    auxpessoa.rua = 89;

    inserirListaA(l, auxpessoa);

     auxpessoa.Nome = "Paulo Cesar";
    auxpessoa.idade = 17;
    auxpessoa.identidade = 5555565-8;
    auxpessoa.bairro = "Cerrado";
    auxpessoa.rua = 23;

    inserirListaA(l, auxpessoa);

     auxpessoa.Nome = "Márcio Costa";
    auxpessoa.idade = 15;
    auxpessoa.identidade = 5524356-8;
    auxpessoa.bairro = "Centro";
    auxpessoa.rua = 80;

    inserirListaA(l, auxpessoa);

     auxpessoa.Nome = "Jorge Henrique";
    auxpessoa.idade = 16;
    auxpessoa.identidade = 2223865-8;
    auxpessoa.bairro = "Explanada";
    auxpessoa.rua = 4;

    inserirListaA(l, auxpessoa);

    auxpessoa.Nome = "Maria Laura";
    auxpessoa.idade = 40;
    auxpessoa.identidade = 9765865-8;
    auxpessoa.bairro = "Cerrado";
    auxpessoa.rua = 55;

    inserirListaA(l, auxpessoa);

    auxpessoa.Nome = "Bruna Rodrigues";
    auxpessoa.idade = 46;
    auxpessoa.identidade = 5526639-8;
    auxpessoa.bairro = "Explanada";
    auxpessoa.rua = 6;

    inserirListaA(l, auxpessoa);

    auxpessoa.Nome = "Paula Fernandes";
    auxpessoa.idade = 30;
    auxpessoa.identidade = 7865784-8;
    auxpessoa.bairro = "São Judas";
    auxpessoa.rua = 30;

    inserirListaA(l, auxpessoa);

    auxpessoa.Nome = "Lucas Silva";
    auxpessoa.idade = 32;
    auxpessoa.identidade = 5529865-8;
    auxpessoa.bairro = "São josé";
    auxpessoa.rua = 99;

    inserirListaA(l, auxpessoa);


}

void TransferirLparaF(TListaA &l, TFilaP &p)
{
    setlocale(LC_ALL,"");
    for(int i = l.ultimo; i > l.primeiro; i--){
    int posicao;
    posicao = pegaMaiorIdade(l);
    if (estaVaziaLA(l)){
        cout << "Não posso transferir!" << endl;
    }
    else{
        enfileirar(p, l.vetPessoas[posicao]);
        retirarDaListaPosicao(l, posicao);
    }

    }

    cout << "Pacientes transferidos!!" << endl;
}


void colocarRaizNAarvore(TArvoreBin &arvorao, TFilaP &f)
{
    int numerocentral;
    numerocentral = numeropararaiz(f);
    TCelula *Celaux;
    Celaux = f.frente->proximo;
    while(Celaux != NULL)
    {
        if(Celaux->Pessoa.idade == numerocentral)
        {
            inserirArvore(arvorao.raiz, Celaux->Pessoa);
        }

        Celaux = Celaux->proximo;
    }

}

void colocarNAarvore(TArvoreBin &arvorao, TFilaP &f)
{
    int numerocentral;
    numerocentral = numeropararaiz(f);
    TCelula *Celaux;
    Celaux = f.frente->proximo;
     while(Celaux != NULL)
    {
    if(Celaux->Pessoa.idade != numerocentral)
    {
    inserirArvore(arvorao.raiz, Celaux->Pessoa);
    }
    Celaux = Celaux->proximo;
}
}

void pesquisar(TArvoreBin a, int idade, TNo *&n){
    if (n == NULL){
        cout << "Paciente não encontrado na fila, verifique se a mesma se encontra vazia!!" << endl;
    }
    else {
        if (idade < n->Pessoa.idade){
            pesquisar(a, idade, n->esquerda);
        }
        else {
            if (idade > n->Pessoa.idade){
                pesquisar(a, idade, n->direita);
            }
            else{

                cout << "Paciente com " <<  n->Pessoa.idade << " anos é : " << n->Pessoa.Nome << "." << endl;
            }
        }
    }

}


void menu(TListaA l, TFilaP f, TArvoreBin a)
{   setlocale(LC_ALL, "");
    cout << " ---------- Bem-Vindo ao sistema de consulta do posto de saúde Santa Maria ---------------- " << endl;
    inicializarlistaA(l);
    cadastrar(l, a);
    inicializarFilaP(f);
    criarArvoreVazia(a);
 int opcao, valorIdade;
 char voltar;

 cout << "###############################################" << endl;

 cout << "Deseja acessar o menu (s/n)?: ";
 cin >> voltar;


 while (voltar == 's')
 {
 cout << " ============= MENU ============= " << endl;
 cout << "[1] ->  Mostrar a lista de pacientes atendidos." << endl;
 cout << "[2] ->  Transferir a lista de pacientes para uma fila com prioridade de idade." << endl;
 cout << "[3] ->  Mostrar itens da fila de prioridade por idade." << endl;
 cout << "[4] ->  Consultar paciente pela sua idade." << endl;
 cout << "[5] ->  Pessoas que receberam cirurgia." << endl;


 cout << "Digite uma opção: ";
 cin >> opcao;

 if (opcao == 1)
 {
     mostrarItensLA(l);
 }
 else if (opcao == 2)
 {
    TransferirLparaF(l, f);
    colocarRaizNAarvore(a, f);
    colocarNAarvore(a, f);
 }
 else if (opcao == 3)
 {

     mostraritensFila(f);
 }
 else if (opcao == 4)
 {
    cout << " Digite idade da pessoa que deseja encontrar: ";
    cin >> valorIdade;

    pesquisar(a, valorIdade, a.raiz);

 }
 else if (opcao == 5)
 {
     if(estaVaziaFilaP(f))
     {
      cout << "A fila de pacientes por prioridade não está preenchida, por favor ative a opção 2 do menu!!" << endl;
     }
     else
     {


     int num;
     cout << "Digite a idade mínima para ser contemplado com a cirurgia: ";
     cin >> num;

    cout << "As pessoas que foram contempladas com a cirurgia são: " << endl;


     MostrarEmOrdem(a.raiz, num);
     }


 }

 cout << "Deseja voltar ao menu?: ";
 cin >> voltar;
 }


}
