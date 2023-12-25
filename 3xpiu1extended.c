#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean pari(int x);
Boolean pari(int x)
{
    float dummyx;
    dummyx = x;
    int resi;
    float resf;
    resi = x / 2;
    resf = dummyx / 2;

    if(resi < resf)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int main(int argc, char* argv[])
{
    int count;
    int min;
    int max;
    int x;
    int exit;


    printf("Ciao, questo e' l'algoritmo 3x+1.\n\nFunziona cosi':\ndato x numero naturale positivo, se x e' pari allora x=x/2,\nse x e' dispari allora x=3x+1.\n\nSi suppone che termini con x=1 per ogni x, ma non e' mai stato dimostrato!\n");

    do
    {
        exit = 0;

        do
        {
            printf("\nInserisci i valori di min e max:\nil programma eseguira' l'algoritmo per tutti gli x tali che min<=x<=max\n");
            printf("min=");
            scanf("%d", &min);
            printf("max=");
            scanf("%d", &max);
        }
        while((min < 1) || (max < 1));

        for(count = min; count <= max; count++)
        {
            x = count;

            do
            {
                if(pari(x) == TRUE)
                {
                    x = x / 2;
                }
                else
                {
                    x = 3 * x + 1;
                }
            }
            while(x != 1);

            printf("L'algoritmo e' terminato per x=%d\n", count);
        }

        printf("\nImmetti 1 per uscire, qualunque altro valore per continuare\n>");
        scanf("%d", &exit);
    }
    while(exit != 1);

    system("PAUSE");
    return 0;
}
