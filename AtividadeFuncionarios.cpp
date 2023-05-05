#include <iostream>
using namespace std;

struct Funcionario
{
    int prontuario;
    string nome;
    double salario;
};

struct Lista
{
    Funcionario *funcionario;
    struct Lista *prox;
};

Lista *init()
{
    return NULL;
}

int isEmpty(Lista *lista)
{
    return (lista == NULL);
}

Lista *insert(Lista *lista, Funcionario *funcionario)
{
    Lista *novo = new Lista();
    novo->funcionario = funcionario;
    novo->prox = lista;
    return novo;
}

void print(Lista *lista)
{
    Lista *aux = lista;
    int somaSalario = 0;
    while (aux != NULL)
    {
        cout << "Prontuário: " << aux->funcionario->prontuario << endl;
        cout << "Nome: " << aux->funcionario->nome << endl;
        cout << "Salário: " << aux->funcionario->salario << endl;
        cout << endl;
        somaSalario += aux->funcionario->salario;
        aux = aux->prox;
    }
    cout << "Soma dos salarios: " << somaSalario << endl;
}

Lista *find(Lista *lista, int prontuario)
{
    Lista *aux = lista;

    while (aux != NULL && aux->funcionario->prontuario != prontuario)
    {
        aux = aux->prox;
    }
    return aux;
}

Lista *remove(Lista *lista, int prontuario)
{
    Lista *ant = NULL;
    Lista *aux = lista;

    while (aux != NULL && aux->funcionario->prontuario != prontuario)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return lista;
    }
    if (ant == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }
    free(aux);

    cout << "Funcionário excluído com SUCESSO.";
    cout << endl;

    return lista;
}

Lista *insertOpcao(Lista *lista)
{
    Funcionario *funcionario = new Funcionario();
    cout << "Digite o prontuário: ";
    int prontuario;
    cin >> prontuario;
    bool prontRepetido = find(lista, prontuario) != NULL;
    while (prontRepetido)
    {
        cout << endl;
        cout << "Funcionário já cadastrado! Não são permitidos prontuários iguais." << endl;
        cout << "Digite outro prontuário: ";
        cin >> prontuario;
        prontRepetido = find(lista, prontuario) != NULL;
    }
    funcionario->prontuario = prontuario;
    cout << "Digite o nome do funcionário: ";
    cin >> funcionario->nome;
    cout << "Digite o salário do funcionário: ";
    cin >> funcionario->salario;
    cout << endl;
    lista = insert(lista, funcionario);
    cout << "Funcionário adicionado com SUCESSO!";
    cout << endl;
    return lista;
}

int Menu()
{
    cout << "Menu de opções: " << endl;
    cout << endl;
    cout << "0. Sair" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Pesquisar" << endl;
    cout << "4. Listar" << endl;
    cout << endl;
    cout << "Digite o número da ação desejada: ";
    cout << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

Lista *opcoes(int opcao, Lista *lista)
{
    Lista *funcionario = nullptr;
    switch (opcao)
    {
    case 0:
        cout << "Sistema encerrado!" << endl;
        break;
    case 1:
        cout << endl;
        cout << "Okay, vamos incluir!" << endl;
        lista = insertOpcao(lista);
        cout << endl;
        break;
    case 2:
        cout << endl;
        cout << "Entendido, vamos excluir." << endl;
        cout << "Digite o prontuário do funcionário a ser excluído: ";
        int prontuario;
        cin >> prontuario;
        cout << endl;
        lista = remove(lista, prontuario);
        cout << endl;
        break;
    case 3:
        cout << endl;
        cout << "Certo, vamos lá!" << endl;
        cout << "Digite o prontuário do funcionário a ser pesquisado: ";
        int prontPesquisado;
        cin >> prontPesquisado;
        cout << endl;
        funcionario = find(lista, prontPesquisado);
        if (funcionario != NULL)
        {
            cout << "Funcionário encontrado:" << endl;
            cout << endl;
            cout << "Prontuário: " << funcionario->funcionario->prontuario << endl;
            cout << "Nome: " << funcionario->funcionario->nome << endl;
            cout << "Salário: " << funcionario->funcionario->salario << endl;
            cout << endl;
        }
        else
        {
            cout << "Funcionário NÃO encontrado!" << endl;
            cout << endl;
        }
        break;
    case 4:
        cout << endl;
        cout << "Perfeito! Segue a lista de funcionários: " << endl;
        cout << endl;
        print(lista);
        cout << endl;
        break;
    default:
        cout << endl;
        cout << "Essa opção não existe." << endl;
        cout << endl;
        break;
    }

    return lista;
}

int main(int argc, char **argv)
{
    Lista *minhaLista;
    int opcao = -1;
    minhaLista = init();

    do
    {
        opcao = Menu();
        minhaLista = opcoes(opcao, minhaLista);
    } while (opcao != 0);

    return 0;
}
