#include <iostream>
#include <stack>
#include "auxiliar.cpp"

using namespace std;

int main(){
    stack <string> estacionamento;
    stack <string> manobra;
    string menu; //vou inicializar como string para evitar erros de digitação do usuário
    string placa;
    
    while (true){
        cout << endl << "Menu de opções: " << endl 
        << endl
        << "    1 - Registrar entrada" << endl
        << "    2 - Registrar saída" << endl
        << "    3 - Consultar vaga" << endl
        << "    4 - Sair" << endl
        << endl
        << "Digite a sua escolha: ";

        cin >> menu;

        try{
            int num_menu = stoi(menu); //se a conversão for bem sucedida, significa que o usuário digitou mesmo um nº
            //pode dar sequência

            if(num_menu == 1){
                if (estacionamento.size() < 8){ //se o tamanho da pilha for menor que 8, significa que ainda há vagas
                    cout << endl <<  "Informe a placa do seu carro: ";
                    cin >> placa;
                    estacionamento.push(placa); //adiciona o valor digitado na pilha
                    cout << endl <<  "Carro " << estacionamento.top() << " adicionado com sucesso." << endl;
                } else{
                    cout << endl << "Não há vagas." << endl;
                };
                    
            } else if (num_menu == 2){
                if (estacionamento.empty()){
                    cout << endl << "Estacionamento vazio." << endl; //não há carros para registrar saída
                } else {
                    cout << endl << "Informe a placa do seu carro: ";
                    cin >> placa; //guarda o valor da placa para achá-lo na pilha

                    bool encontrar = EncontrarValor(estacionamento, placa); //usa a função criada na funcoes.cpp para ver se o valor existe na pilha

                    if(encontrar){
                        while (true){
                            if (placa == estacionamento.top()){ //quando o carro estiver no topo, nao precisa retirar nenhum outro
                                cout << endl << "Carro " << placa << " retirado com sucesso" << endl;
                                estacionamento.pop(); //removemos ele, break no while
                                break;
                            } else{ //se não estiver no topo, cai no else e vai rodando a pilha ate que o valor esteja no topo
                                cout << "Manobrando... "<< estacionamento.top() << endl; //mostra o carro que vai ser retirado
                                manobra.push(estacionamento.top()); //coloca ele na area de manobra
                                estacionamento.pop(); //depois tira do estacionamento para seguir procurando
                                //volta para o inicio do while até que o carro procurado esteja no topo
                            }
                        }

                        while (!manobra.empty()){ //depois que ele ja retirou o carro do estacionamento, é hora de recolocar os carros que estão na área manobra
                            estacionamento.push(manobra.top()); //adiciona novamente no estacionamento o carro que esta no topo (dessa forma, mantem a ordem que os carros estavam anteriormente)
                            manobra.pop(); //então retira da manobra e repete o processo ate a pilha ficar vazia
                        }

                    } else { //se a função EncontrarValor retornar false, significa que não está na pilha, então cai no else
                        cout << endl << "Carro não encontrado. Por favor, tente novamente." << endl;
                    }
                }

            } else if (num_menu == 3){ //para exibir a quantidade de vagas e de veículos estacionados
                int vagas = 8 - estacionamento.size(); //diminui a capacidade total pelo tamanho da pilha
                cout << endl << "Quantidade de carros estacionados: " << estacionamento.size() << endl; 
                cout << "Quantidade de vagas restantes: " << vagas << endl;

            } else if (num_menu == 4) {
                break;

            } else { //se o usuário digitar errado, ele pede para digitar novamente
                cout << endl << "Por favor, digite novamente." << endl;
            }

        } catch(const std::invalid_argument& e){ //se não for um nº, fica como argumento inválido e printa a mensagem de erro para o usuário
            std::cerr << endl << "Erro: Entrada inválida. Certifique-se de digitar um número inteiro.\n";
        }
    }

    cout << endl << "Programa encerrado." << endl;
        
    // cout << endl << "Estacionamento: " << endl;
    // while(!estacionamento.empty()){
    //     cout << estacionamento.top() << endl;
    //     estacionamento.pop();
    // } 
    // para conferir quais carros ficaram estacionados
    
    return 0;
}