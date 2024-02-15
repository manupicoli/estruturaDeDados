#include <iostream>
#include <stack>

bool EncontrarValor(std::stack<std::string>&pilha, const std::string &placa){ //bool para retornar true ou false
    std::stack<std::string> temporaria;

    while(!pilha.empty()){
        if(pilha.top() == placa){ //string encontrada
            while (!temporaria.empty()) { //então já reorganiza a pilha principal
                pilha.push(temporaria.top());
                temporaria.pop();
            }
            return true; //retorna true e para a execução
        } else {
            temporaria.push(pilha.top());
            pilha.pop();
        }
    }

    //se não encontrar, sai do while, e organiza a pilha antes do return false
    while (!temporaria.empty()) {
        pilha.push(temporaria.top());
        temporaria.pop();
    }

    return false;
}