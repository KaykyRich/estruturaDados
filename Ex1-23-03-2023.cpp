#include <iostream>
#include <string>
#include <unistd.h> //biblioteca para usar a função sleep()

using namespace std;

int main() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    int tamanho = mensagem.size();
    
    //Centraliza a mensagem na linha 5
    int espacos = (80 - tamanho) / 2;
    for(int i = 0; i < espacos; i++) {
        cout << " ";
    }
    cout << mensagem << endl;
    
    //Simula a "cascata"
    for(int linha = 6; linha <= 20; linha++) {
        for(int i = 0; i < espacos; i++) {
            cout << " ";
        }
        for(int i = 0; i < tamanho; i++) {
            if(rand() % 2 == 0) { //50% de chance de imprimir o caractere
                cout << mensagem[i];
            } else {
                cout << " ";
            }
        }
        cout << endl;
        sleep(1); //pausa por 1 segundo para simular o efeito de "cascata"
    }
    
    //Imprime a mensagem completa na linha 20
    for(int i = 0; i < espacos; i++) {
        cout << " ";
    }
    cout << mensagem << endl;
    
    return 0;
}
