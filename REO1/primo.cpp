#include <stdio.h>

 #define VET 10

//Convenção verifica = 1 --> O numero é primo

//          verifica = 0 --> O numero não é primo
main()
{
    int n[VET],i;
    int d; // divisor
    int verifica; // verifica se o numero é primo.

    d=2;
    verifica=1;

    for(i=0; i<10 ;i++)
    {
        printf("\nDigite um numero:");
        scanf("%d",&n[i]);
        printf("O numero digitado foi: %d\n",n[i]);

        if (n[i] <= 1)
        verifica = 0;

            while(verifica == 1 && d <= n[i] / 2) 
             {
                if (n[i] % d  == 0)
                verifica = 0;
                d = d + 1;
             }

        if (verifica == 1)
        printf("%d eh primo.Sua posicao eh %d.\n", n[i],i);

    }

    return 0;   
    system("pause");
}
