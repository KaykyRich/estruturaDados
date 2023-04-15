#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

// Função para transformar um nome no formato de agenda telefônica
std::string transformaNome(std::string nome) {
    std::vector<std::string> partes;
    std::istringstream iss(nome);
    std::string parte;

    while (iss >> parte) {
        partes.push_back(parte);
    }
    std::string sobrenome = partes.back();
    partes.pop_back();
    std::ostringstream oss;
    oss << sobrenome << ", ";
    for (size_t i = 0; i < partes.size(); i++) {
        oss << partes[i];
        if (i < partes.size() - 1) {
            oss << " ";
        }
    }
    return oss.str();
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::string nome;
    while (std::getline(arquivo, nome)) {
        std::string nomeTransformado = transformaNome(nome);
        std::cout << nomeTransformado << std::endl;
    }
    return 0;
}
