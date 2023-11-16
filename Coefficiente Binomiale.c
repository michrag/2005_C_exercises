#include <stdio.h>
#include <stdlib.h>

int fattoriale(int num);
int fattoriale(int num)
{
    int fact;
    int count;

    fact = 1;

    if(num != 0 && num != 1)
    {
        for(count = 2; count < num + 1; count++)
        {
            fact = fact * count;
        }
    }

    return fact;
}

int main(int argc, char* argv[])
{
    int n;
    int factn;
    int k;
    int factk;
    int factnsubk;
    int coebin;
    int exit;

    printf("\nCalcolo del coefficiente binomiale (n k)=n!/k!(n-k)!");

    do
    {
        exit = 0;

        do
        {
            printf("\nInserire n...\n>");
            scanf("%d", &n);
            printf("\nInserire k...\n>");
            scanf("%d", &k);
        }
        while(n < 0 || k < 0);

        factn = fattoriale(n);
        factk = fattoriale(k);
        factnsubk = fattoriale(n - k);

        coebin = (factn) / (factk * factnsubk);

        printf("\nIl fattoriale di n=%d e' %d", n, factn);
        printf("\nIl fattoriale di k=%d e' %d", k, factk);
        printf("\nIl fattoriale di (n-k)=%d e' %d", n - k, factnsubk);
        printf("\nIl coefficiente binomiale di n=%d e k=%d e' %d\n", n, k, coebin);


        printf("\nUscire? SI'=1, NO=any digit but 1\n>");
        scanf("%d", &exit);
    }
    while(exit != 1);

    printf("\nCiao e grazie!\n");
    system("PAUSE");
    return 0;
}
