#include<iostream>
#include<string>
using namespace std;

class Pessoa {
	private:
		string nome;
		int idade;
	public:
		Pessoa(const string nome, int idade);
		void exibir();	

};

Pessoa::Pessoa(const string _nome, int _idade){
	nome = _nome;
	idade = _idade;

}

void Pessoa::exibir(){
	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
}

class Vetor {
	private:
		int *vetor;
		int t;
		
	public:
		Vetor();
		Vetor(int t);
		void setVetor();
		int getElemento(int posicion);
		int getTam();
		~Vetor();
		
};

Vetor::Vetor(int t){
	vetor = new int[t];
	this -> t = t;
}

int Vetor::getTam(){
	return t;
}

void Vetor::setVetor(){

	int elemento;
	for(int i = 0; i < this->t;i++){
		if(i != t)
			cout << i << " ";
		cin >> elemento;
	}
	
	cout << "Fim." << endl << endl;
}

int Vetor::getElemento(int posicion){
	return vetor[posicion];

}

Vetor::~Vetor(){

	cout << "vetor destruido" << endl;
	delete [] vetor;
	this -> t = 0;
}



int main()
{
	cout << "Hello, world!!" << endl << endl;
	
	Pessoa *pessoa = new Pessoa("Wildes Sousa" , 27);
	pessoa->exibir();
	
	Vetor *vet = new Vetor(5);
	vet->setVetor();
	cout << "Tamando do vetor: " << vet->getTam() << endl;
	cout << "Elemento: " << vet->getElemento(6) << endl;
	vet -> ~Vetor();
	
	return 0;
}
