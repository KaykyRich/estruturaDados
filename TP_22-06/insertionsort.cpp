#include <iostream>
using namespace std;

void insertionSort(int* lista, int n) {
    for (int i = 1; i < n; i++) {
        int aux = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > aux) {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = aux;
    }
}


int main(int argc, char **argv)
{
    int numeros[8] = {10,20,98,34,43,12,56,87};
    cout << "Lista desorganizada: ";
    for (int i = 0; i < 8; i++) {
        cout << numeros[i] << " ";
    }
    insertionSort(numeros, 8);
    cout << "\nLista organizada: ";
    for (int i = 0; i < 8; i++) {
        cout << numeros[i] << " ";
    }
    
    return 0;
}
