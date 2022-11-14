#include <iostream>
#include <string>
using namespace std;

void menu();
void inserir(int *dado);

int main() {
	int op;
	int capacidade;
	cout << "Entre com a capacidade: " << endl;
	cin >> capacidade;
	int *vetor = int [capacidade]; 

	do{
		menu();
		cin >> op;
	
	}while(op != 3);

	return 0;
}

void menu(){
	cout << "1 - inserir \n" 
		 << "2 - mostrar \n" 
		 << "3 - sair" << endl;
}

void inserir(int *dado){
	
}
