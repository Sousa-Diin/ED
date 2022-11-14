/* Exercicos de Revisão
 * copyright (c) 2022 - Wildes Sousa
 * version: v1.22.0
 */
 #include <iostream>
 using namespace std;
 
 void ehPrimo (int vetor[], int tam);
 void exibe(int v[], int t);
 
 int main ()
 {
 
 	int tam;
 	cin >> tam;
 	int vetor [tam];
 	
 	
 	for(int e = 0; e < tam; e++){
 		cout << "Entre com o " << e << " numero: ";
 		cin >> vetor[e];
 	}
 	
	cout << endl;
	//exibe(vetor, tam);
	ehPrimo(vetor, tam);
 	
 	
 	return 0;
 }
 void ehPrimo (int vetor[], int tam)
 {
 	int indice = 0, cont = 0;
 	int verifica = 1;
 	int d = 2;
 		
	 	/*for(indice = 0; indice <= tam;indice++){
	 		if(vetor[indice] / 2 == 0){
	 			
	 			cout << vetor[indice] << endl;
	 		}
	 		
	 	}*/
	 	while(verifica == 1 && d <= vetor[indice] / 2) 
             {
                if (vetor[indice] % d  == 0)
                 verifica = 0;
                 d = d + 1;
             }
         if (verifica == 1)
        cout << vetor[indice] << " " << indice;
        exibe(vetor, tam);
 	
}


 void exibe(int v[], int t) {
  if (t == 1) {
    cout << v[t - 1] << endl;
   
  } else {
    exibe(v, t - 1);
    cout << v[t - 1] << endl;
    
  }
}
