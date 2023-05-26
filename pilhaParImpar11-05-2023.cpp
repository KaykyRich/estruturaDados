#include <iostream>
using namespace std;

#define MAXIMO 30

struct Pilha
{
    int qtde;
    float elements[MAXIMO];
};

Pilha *init()
{
    Pilha *p = new Pilha();
    p->qtde = 0;
    return p;
}

int isEmpty(Pilha *p)
{
    return (p->qtde == 0);
}

int count(Pilha *p)
{
    return (p->qtde);
}

void freePilha(Pilha *p)
{
    free(p);
}

int push(Pilha *p, float v)
{
    int podeEmpilhar = (p->qtde < MAXIMO);
    if (podeEmpilhar)
    {
        p->elements[p->qtde++] = v;
    }
    return podeEmpilhar;
}

float pop(Pilha *p)
{
    float v;
    int podeDesempilhar = (!isEmpty(p));
    if (podeDesempilhar)
    {
        v = p->elements[p->qtde - 1];
        p->qtde--;
    }
    else
    {
        v = -1;
    }
    return v;
}

void print(Pilha *p)
{
    cout << "Quantidade de elementos: " << count(p) << endl;
    cout << "-----------------------" << endl;
    for (int i = p->qtde - 1; i >= 0; --i)
    {
        cout << p->elements[i] << endl;
    }
    cout << "-----------------------\n"
         << endl;
}

int main(int argc, char **argv)
{
    Pilha *pilhaPar = init();
    Pilha *pilhaImpar = init();
    Pilha *pilha = init();
    int numero;
    cout << "Digite, em ordem crescente, 30 números inteiros:" << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << "Digite o " << i + 1 << "º número: ";
        cin >> numero;

        while (numero <= pilha->elements[pilha->qtde - 1])
        {
            cout << "Inválido. A lista deve ser sempre crescente." << endl;
            cout << "Digite o " << i + 1 << "º número: ";
            cin >> numero;
        }
        push(pilha, numero);
        if (numero % 2 == 0)
        {
            push(pilhaPar, numero);
        }
        else
        {
            push(pilhaImpar, numero);
        }
    }
    cout << "\nPilha de números pares:" << endl;
    print(pilhaPar);
    cout << "\nPilha de números ímpares:" << endl;
    print(pilhaImpar);
    cout << "\nDesempilhando a pilha dos pares" << endl;
    while (!isEmpty(pilhaPar))
    {
        pop(pilhaPar);
    }
    cout << "Desempilhando a pilha dos ímpares\n"
         << endl;
    while (!isEmpty(pilhaImpar))
    {
        pop(pilhaImpar);
    }
    freePilha(pilhaPar);
    freePilha(pilhaImpar);
    while (!isEmpty(pilha))
    {
        cout << pop(pilha) << endl;
    }
    freePilha(pilha);

    return 0;
}
