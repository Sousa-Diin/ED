// Questão 1: Pilha com armazenamento de dados em arranjos 
// Wildes Sousa

#include <iostream>
using namespace std;

typedef int Dado; 
 

class pilhav {
    private:
        int CAPACITY;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav();
        ~pilhav();
        void empilha(const Dado& valor);
        Dado desempilha();
        void espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav() 
{  
	CAPACITY = 20;
	dados = new Dado[CAPACITY];
	tamanho = 0;
	posTopo = dados[tamanho];
	
}
pilhav::~pilhav(){ delete[] dados; tamanho = 0; }

void pilhav::empilha(const Dado& valor) 
{
	if(posTopo < CAPACITY){
		dados[tamanho++] = valor;
	}
	posTopo = dados[tamanho];
}

Dado pilhav::desempilha() 
{
	if(posTopo > 0)
		return dados[tamanho];
	return -1;
}

void pilhav::espia() 
{ 
	cout << " Elemento: " << dados[tamanho] << endl; 
}

void pilhav::depura() {}
void pilhav::info() {}

int main ()
{
	
	pilhav pilha;
	
	pilha.empilha(21);
	pilha.empilha(01);
	pilha.empilha(14);
	
	pilha.espia();
	
	
	return 0;
}
