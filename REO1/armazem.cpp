/* 
    armazem.cpp - aplicação para desenvolvimento de atividade
    de Tipo Abstrado de Dados

    Atividade de  GCC216 - Estruturas de Dados, 2020

    Solução de: INSIRA AQUI SEU NOME
*/

#include <iostream>

using namespace std;

struct item {
    string nomeDoProduto;
    int validadeEmDias;
    int quantidadeEmQuilos;
    item();
};

item::item() {
    nomeDoProduto.clear();
    validadeEmDias = 0;
    quantidadeEmQuilos = 0;
}

class armazem {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        item* listaDeItens;
        int quantidadeDeItens;
        int capacidadeMaxima;
    public:
        armazem(int capacidade);
        ~armazem();
        void inserirNovoItem(const item& umItem);
        bool buscarItem(const string& nome, item& umItem);
        void redimensionarCapacidade();
        friend void verificarItensPertoDoVencimento(armazem umArmazem, int dias);
};

armazem::armazem(int capacidade) {
    quantidadeDeItens = 0;
    capacidadeMaxima = capacidade;
    listaDeItens = new item[capacidadeMaxima];
}

armazem::~armazem() {
    delete [] listaDeItens;
}

void armazem::inserirNovoItem(const item& umItem) {
    if (quantidadeDeItens == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeItens[quantidadeDeItens] = umItem;
    quantidadeDeItens++;
}

bool armazem::buscarItem(const string& nome, item& umItem) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeItens and 
           listaDeItens[posicaoAtual].nomeDoProduto != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeItens) {
        umItem = listaDeItens[posicaoAtual];
        return true;
    }

    return false;
}

void armazem::redimensionarCapacidade() {
#warning implemente este metodo!
}

void verificarItensPertoDoVencimento(armazem umArmazem, int dias) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umArmazem.quantidadeDeItens; i++) {
        if (umArmazem.listaDeItens[i].validadeEmDias <= dias) 
            cout << umArmazem.listaDeItens[i].nomeDoProduto << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Armazem - Aplicativo para Controlar Vencimento de Produtos\n" 
         << "Entre com capacidade máxima inicial: ";
    cin >> capacidadeInicial;

    armazem meuArmazem(capacidadeInicial);

    cout << "Armazem - Escolha a Opção:\n"
         << "i - inserir novo item\n"
         << "b - buscar por um dado item a partir do nome\n"
         << "v - verificar itens próximo do vencimento\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    item umItem;
    string nome;
    int dias;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do item (nome, validade em dias, quantidade em Kg):" << endl;
                cin >> umItem.nomeDoProduto
                    >> umItem.validadeEmDias
                    >> umItem.quantidadeEmQuilos;
                meuArmazem.inserirNovoItem(umItem);
                break;

            case 'b' :
                cout << "Entre com nome do item para busca: ";
                cin >> nome;
                
                if (meuArmazem.buscarItem(nome, umItem)) 
                    cout << umItem.nomeDoProduto << " "
                         << umItem.validadeEmDias << " "
                         << umItem.quantidadeEmQuilos << endl << endl;
                else 
                    cout << "Item não encontrado!" << endl << endl;
                break;

            case 'v' : 
                cout << "Entre com quantidade de dias para verificação: ";
                cin >> dias;
                verificarItensPertoDoVencimento(meuArmazem,dias);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Armazem - Escolha a Opção:\n"
            << "i - inserir novo item\n"
            << "b - buscar por um dado item a partir do nome\n"
            << "v - verificar itens próximo do vencimento\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
