#include <stdio.h>
#include <stdlib.h>

typedef short unsigned int Boolean;

#define TRUE 1
#define FALSE 0

void swap(int* Perm, int position, int next);
void swap(int* Perm, int position, int next)
{
    float tmp;
    tmp = Perm[position];
    Perm[position] = Perm[next];
    Perm[next] = tmp;
}

void bubble_sort(float* V, int* Perm, int size);
void bubble_sort(float* V, int* Perm, int size)
{
    int count;
    int k;
    Boolean swapdone;
    Boolean swapfound;

    for(count = 0; count < size; count++)
    {
        Perm[count] = count;
    }

    k = 0;
    swapdone = TRUE;

    do
    {
        swapfound = FALSE;

        for(count = 0; count < size - k - 1; count++)
        {
            if(V[Perm[count]] > V[Perm[count + 1]])
            {
                swap(Perm, count, count + 1);
                swapfound = TRUE;
            }
        }

        if(swapfound == FALSE)
        {
            swapdone = FALSE;
        }

        else
        {
            k++;
        }
    }
    while(swapdone == TRUE);
}


int main(int argc, char* argv[])
{
    float* A;
    int* Perm;
    int n;
    int count;
    int reply;
    int risp;
    Boolean back;
    Boolean exit;

    exit = FALSE;


    printf("\nBubble Sort\n");

    do
    {
        printf("\nCosa desideri fare?\n1)Creare un vettore\n2)Uscire\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                do
                {
                    printf("Inserire la dimensione del vettore\n>");
                    scanf("%d", &n);
                }
                while(n < 1);

                A = (float*)malloc(n * sizeof(float));
                Perm = (int*)malloc(n * sizeof(float));

                printf("\nInserire i valori...\n");

                for(count = 0; count < n; count++)
                {
                    printf("Valore in posizione %d >", count);
                    scanf("%f", &A[count]);
                }

                do
                {
                    printf("\nCosa desideri fare?\n1)stampare il vettore\n2)ordinare il vettore con l'algoritmo di Bubble Sort\n3)tornare al menu precedente\n>");
                    scanf("%d", &risp);

                    back = FALSE;

                    switch(risp)
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
                            bubble_sort(A, Perm, n);

                            printf("\nQuesto e' il vettore ordinato con Bubble Sort...\n");

                            for(count = 0; count < n; count++)
                            {
                                printf("|%f|\n", A[Perm[count]]);
                            }

                        }
                        break;

                        case 3:
                        {
                            back = TRUE;
                            free(Perm);
                            free(A);
                        }
                        break;

                        default:
                            printf("Selezione non valida\n");

                    }
                }
                while(back != TRUE);


            }
            break;

            case 2:
                exit = TRUE;
                break;

            default:
                printf("Selezione non valida\n");

        }
    }
    while(exit != TRUE);

    system("PAUSE");
    return 0;
}
