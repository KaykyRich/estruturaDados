#include <iostream>
using namespace std;

void shellSort(int lista[], int n) {
    int gap = n / 2;
    
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = lista[i];
            int j = i;

            while (j >= gap && lista[j - gap] > temp) {
                lista[j] = lista[j - gap];
                j -= gap;
            }
            
            lista[j] = temp;
        }
        gap /= 2;
    }
}

void mostraLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int main() {
    int lista[] = {10,20,98,34,43,12,56,87};
    int n = sizeof(lista) / sizeof(lista[0]);
    
    cout << "array original: ";
    mostraLista(lista, n);
    
    shellSort(lista, n);
    
    cout << "array ordenado: ";
    mostraLista(lista, n);
    
    return 0;
}





