#include <iostream>
using namespace std;

class Noh {
	private:
		int dados;
		Noh* proximo;
	public:
	
		Noh();
		void criarNoh(int value);
		void setNoh(Noh* ptrProximo);
		int getDado();
		//~Noh();
};

Noh::Noh(){
	dados = 0;
	proximo = NULL;
}

void Noh::criarNoh(int value){
	dados = value;
	proximo = NULL;
}

void Noh::setNoh(Noh* ptrProximo){
	proximo = ptrProximo;

}

int Noh::getDado(){
	return dados;
}

class Pilha {
	private:
		int tamanho;
		Noh* topo;
	
	public:
		Pilha(){
		    tamanho = 0;
		    topo = NULL;
		}
		int getTam();
		Noh* getTopo();
		void setPilha();
		void push( int &valor);
		int element();


};

int Pilha::getTam(){
	return tamanho;
}

Noh* Pilha::getTopo(){
	return topo;
}

void Pilha::setPilha(){
	topo = NULL;
	tamanho = 0;
}

void Pilha::push(int &valor){
	Noh *novo;
	novo->criarNoh(valor);
	novo->setNoh(topo);
	topo = novo;
	
	tamanho++;
}

int Pilha::element(){
	return topo->getDado();
}

int main(){

	int elemento = 89;
	int elem2 = 100;
	
	Pilha pilha,p2;
	cout << pilha.getTopo() << endl << endl;
	pilha.push(elemento);
	cout << "Valor do Pilha: " << pilha.element() << endl;
	cout << pilha.getTam() << endl;
	cout << pilha.getTopo() << endl << endl;
	
	p2.push(elem2);
	cout << "Valor do P2: " << p2.element() << endl;
	cout << p2.getTam() << endl;
	cout << p2.getTopo() << endl << endl;
	cout << &elemento << "\t" << elemento << endl;
	
	
	
	/*p2.setPilha(num2);
	
	cout << p2.getTam() << endl;
	cout << *p2.getTopo() << endl;
    */
    return 0;
}
