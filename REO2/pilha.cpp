// Questão 1: Pilha com armazenamento de dados em arranjos 
// Wildes Augusto de Sousa
#include <iostream>
using namespace std;

using Dado = int;


class Pilha {
	private:
		enum { MAX = 20};
		Dado itens[MAX];
		int tamanho;
		int topo;
	
	public:
		Pilha();
		void push(const Dado& item);
		Dado pop(Dado& item);
		Dado espia();
		void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info(); 
        int getTamanho();
};

///////////////////// METHOD DA CLASS///////////////////////
Pilha::Pilha() { 
	topo = 0;
	tamanho = 0;
}

void Pilha::push(const Dado& item) {
	if(topo < MAX){
		itens[topo++] = item;
		tamanho++;
	}
}

Dado Pilha::pop(Dado& item){
	if(topo > 0){
		item = itens[--topo];
		tamanho--;
		return item;
	}
	return -1;
}
Dado Pilha::espia() 
{ 
	return itens[topo - 1]; 
}

void Pilha::depura()
{
	int i = 0;
	while (i < topo ){
		cout << itens[i++] << " " ;
	}
}

void Pilha::info() 
{
	cout << endl << tamanho << " " << topo - 1 << endl ;
}

int Pilha::getTamanho()
{
	return tamanho;
}

////////////////// FUNCOES AUXILIARES ////////////////////

Pilha saidaDeDados ( Pilha pilha, int qtd)
{
	int ini = 0;
	Dado i;
	while( ini < qtd  ){
		ini++;
		pilha.pop(i);
		cout << i << " ";
	}
	cout << endl;
	return pilha;
	
}

Pilha entradaDeDados ( Pilha pilha, int qtd)
{
	int ini = 0, e;
	while( ini < qtd){
		cin >> e ;
		pilha.push(e);
		ini++;
	}
	
	return saidaDeDados(pilha, 3);
	
}

//////////////FUNCAO PRINCIPAL////////////////////
int main(){
	//cout << "EXEMPLO DE PILHA C/ VETOR" << endl << endl;
	Pilha pilha;
	
	pilha = entradaDeDados(pilha, 5);
	//cout << pilha.getTamanho() << endl;
	pilha = entradaDeDados(pilha, 4);
	//cout << pilha.getTamanho() << endl;
	cout << pilha.espia() << endl;
	
	pilha.depura();
	pilha.info();
	

	return 0;
}
