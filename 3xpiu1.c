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


    int x;
    int exit;
    int copiax;
    exit = 0;

    x = -1;
    printf("Ciao, questo e' l'algoritmo 3x+1.\n\nFunziona cosi':\ndato x numero naturale positivo, se x e' pari allora x=x/2,\nse x e' dispari allora x=3x+1.\n\nSi suppone che termini con x=1 per ogni x, ma non e' mai stato dimostrato!\n");

    do
    {
        do
        {
            printf("\nAdesso inserisci un numero naturale positivo, perfavore\n>");
            scanf("%d", &x);
        }
        while(x < 1);

        copiax = x;
        printf("Ecco la successione!\n\n");

        do
        {
            if(pari(x) == TRUE)
            {
                x = x / 2;
                printf("%d\n", x);
            }
            else
            {
                x = 3 * x + 1;
                printf("%d\n", x);
            }

        }
        while(x != 1);

        printf("\nVisto?! Hai immesso %d e l'algoritmo e' terminato!\n", copiax);
        printf("\nImmetti 1 per uscire, qualunque altro valore per continuare\n>");
        scanf("%d", &exit);
    }
    while(exit != 1);

    system("PAUSE");
    return 0;
}
