#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int n;
    long int count;
    long int fact;

    int reply;

    printf("\n Questo programma calcola il fattoriale (n!) di un mumero naturale n minore \n di 17\n \n NOTA: il fattoriale e' definito solo e su tutti i  numeri naturali ma questo \n programma non e' capace di calcolarlo per numeri naturali maggiori di 16 \n \n");

    do
    {
        printf("\n Inserire il numero naturale, minore di 17, di cui si vuole calcolare \n il fattoriale \n>");
        scanf("\%d", &n);

        if((n < 0) || (n > 16))

        {
            printf("\07 \n Il numero inserito non e' un numero compreso tra 0 e 16 ! \n");
        }
        else
        {
            fact = 1;

            for(count = 2; count <= n; count = count + 1)
            {
                fact = fact * count;
            }

            printf("Il fattoriale (\%d!) di \%d e' \%d \n", n, n, fact);
            printf("\n Calcolare il fattoriale di un altro numero naturale? \n No: invia 0 \n Si': invia un qualunque altro valore \n >");
            scanf("%d", &reply);
        }
    }
    while(reply != 0);

    system("PAUSE");
    return 0;
}
