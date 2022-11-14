#include <iostream>
#include <cstdlib>
using namespace std;

class Vetorx {
	private:
		int tamanho;
		int* dados;
	
	public:
		void inicializa(int _tamanho);
		void finaliza();
		void preencher();
		void imprimir();
		int getElemento(int posicao);

};

void Vetorx::inicializa(int _tamanho){
	dados = new int [_tamanho];
	tamanho = _tamanho;
}

void Vetorx::finaliza(){
	delete [] dados;
	tamanho = 0;
	cout << "Vetor destruido" << endl;
}

void Vetorx::preencher(){
	for(int i =0; i < tamanho;i++)
		dados[i] = random() % 100;
}

void Vetorx::imprimir(){
	for(int i =0; i < tamanho;i++)
		cout << dados[i] << " " ;
}

int Vetorx::getElemento(int posicao){
	if((posicao >= 0) and (posicao < tamanho))
		return dados[posicao];
	return -1;
}

int main() {
	srand(time(NULL));
	
	Vetorx vet;
	vet.inicializa(7);
	vet.preencher();
	vet.imprimir();
	cout << endl;
	cout << vet.getElemento(0) << endl;
	cout << vet.getElemento(5) << endl;
	vet.finaliza();
	cout << endl;
	cout << vet.getElemento(5) << endl;

	return 0;
}
