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

    x = -1;

    do
    {
        printf("Inserisci un numero naturale, perfavore\n>");
        scanf("%d", &x);
    }
    while(x < 0);

    if(pari(x) == TRUE)
    {
        printf("\nil numero e' pari!\n");
    }
    else
    {
        printf("\nil numero e' dispari!\n");
    }

    system("PAUSE");
    return 0;
}
