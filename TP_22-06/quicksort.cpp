#include <iostream>
using namespace std;

int partition(int* lista, int menor, int maior) {
    int pivot = lista[maior];
    int i = menor - 1;

    for (int j = menor; j < maior; j++) {
        if (lista[j] < pivot) {
            i++;
            int temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
        }
    }
    int temp = lista[i + 1];
    lista[i + 1] = lista[maior];
    lista[maior] = temp;

    return i + 1;
}

void quickSort(int* lista, int menor, int maior) {
    if (menor < maior) {
        int pi = partition(lista, menor, maior);
        quickSort(lista, menor, pi - 1);
        quickSort(lista, pi + 1, maior);
    }
}

int main(int argc, char **argv)
{
    int numeros[8] = {10,20,98,34,43,12,56,87};
    cout << "Lista desorganizada: ";
    for (int i = 0; i < 8; i++)
    {
        cout << numeros[i] << " ";
    }
    quickSort(numeros, 0, 7);
    cout << "\nLista organizada: ";
    for (int i = 0; i < 8; i++)
    {
        cout << numeros[i] << " ";
    }
    

    return 0;
}
