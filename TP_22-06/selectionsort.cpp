#include <iostream>
using namespace std;

void selectionSort(int* lista, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min]) min = j;
        }

        int temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
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

    selectionSort(numeros, 8);
    cout << "\nLista organizada: ";
    for (int i = 0; i < 8; i++)
    {
        cout << numeros[i] << " ";
    }
    

    return 0;
}
