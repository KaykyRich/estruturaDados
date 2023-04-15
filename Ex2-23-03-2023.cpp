#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    //Remove espaços em branco da mensagem
    mensagem.erase(remove_if(mensagem.begin(), mensagem.end(), ::isspace), mensagem.end());
    
    //Verifica se a mensagem é um palíndromo
    string reverso = mensagem;
    reverse(reverso.begin(), reverso.end());
    if(mensagem == reverso) {
        cout << "A mensagem digitada É um palíndromo!" << endl;
    } else {
        cout << "A mensagem digitada NÃO é um palíndromo." << endl;
    }
    
    return 0;
}
