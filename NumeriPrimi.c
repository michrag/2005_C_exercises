#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean test(unsigned long int numero);
Boolean test(unsigned long int numero)
{
    Boolean NONprimo;
    NONprimo = FALSE;


    long int result;
    result = 1;
    long int count;
    count = 2;

    if(numero == 1)
    {
        NONprimo = TRUE;
    }


    while((count < numero) && (NONprimo == FALSE))
    {
        result = (numero) % (count);

        if(result == 0)
        {
            NONprimo = TRUE;
        }

        count++;
    };

    return NONprimo;
}


int main(int argc, char* argv[])
{
    unsigned long int min;
    unsigned long int max;
    unsigned long int count;

    printf("Programma che estrae i numeri primi presenti in un intervallo di numeri naturali");

    do
    {
        printf("\nInserire il minimo dell'intervallo...\n>");
        scanf("%d", &min);

        printf("\nInserire il massimo dell'intervallo...\n>");
        scanf("%d", &max);

    }
    while((min < 1) || (max < min));

    printf("\nI numeri primi presenti nell'intervallo considerato sono...\n");

    for(count = min; count < max + 1; count++)
    {
        if(test(count) == FALSE)
        {
            printf("%d\n", count);
        }
    }





    system("PAUSE");
    return 0;
}
