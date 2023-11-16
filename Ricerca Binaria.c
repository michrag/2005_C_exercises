#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;

#define TRUE 1
#define FALSE 0

Boolean Bsearch(float* V, int size, float target);
Boolean Bsearch(float* V, int size, float target)
{
    if(size > 0)
    {
        if(V[size / 2] == target)
        {
            return TRUE;
        }

        else
        {
            if(target > V[size / 2])
            {
                return(Bsearch(&(V[size / 2 + 1]), size - size / 2 - 1, target));
            }

            else
            {
                return(Bsearch(V, size / 2, target));
            }
        }
    }

    else
    {
        return FALSE;
    }
}



int main(int argc, char* argv[])
{
    float* A;
    int n;
    int count;
    int reply;
    int exit;
    float target;
    Boolean result;

    do
    {
        printf("Inserire la dimensione del vettore\n>");
        scanf("%d", &n);
    }
    while(n < 1);

    A = (float*)malloc(n * sizeof(float));

    printf("\nInserire i valori in ordine crescente...\n");


    printf("\nImmettere il valore in posizione 0\n>");
    scanf("%f", &A[0]);

    for(count = 1; count < n; count++)
    {
        do
        {
            printf("\nImmettere il valore in posizione %d\n>", count);
            scanf("%f", &A[count]);
        }
        while(A[count - 1] > A[count]);
    }

    do
    {
        printf("\nCosa si desidera fare?\n1)Stampare il vettore\n2)Eseguire una ricerca binaria\n3)Uscire\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                printf("\nQuesto e' il vettore...\n");

                for(count = 0; count < n; count++)
                {
                    printf("|%f|\n", A[count]);
                }
            }
            break;


            case 2:
            {
                printf("\nInserire il valore cercato\n>");
                scanf("%f", &target);
                result = Bsearch(A, n, target);

                if(result == TRUE)
                {
                    printf("\n%f e' presente nel vettore", target);
                }
                else
                {
                    printf("\n%f NON e' presente nel vettore", target);
                }
            }
            break;

            case 3:
                exit = 1;
                break;

            default:
                printf("\nSelezione non valida!");
        }
    }
    while(exit != 1);

    free(A);
    system("PAUSE");
    return 0;
}
