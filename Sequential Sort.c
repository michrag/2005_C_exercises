#include <stdio.h>
#include <stdlib.h>

typedef short unsigned int Boolean;

#define TRUE 1
#define FALSE 0

void swap(int* Perm, int max_index, int position);
void swap(int* Perm, int max_index, int position)
{
    float tmp;
    tmp = Perm[max_index];
    Perm[max_index] = Perm[position];
    Perm[position] = tmp;
}


void sequential_sort(float* V, int size, int* Perm);
void sequential_sort(float* V, int size, int* Perm)
{

    int count;
    int max_index;
    int k;

    for(count = 0; count < size; count++)
    {
        Perm[count] = count;
    }

    for(k = 0; k < size - 1; k++)
    {
        max_index = 0;

        for(count = 1; count < size - k; count++)
            if(V[Perm[count]] > V[Perm[max_index]])
            {
                max_index = count;
            }

        swap(Perm, max_index, size - k - 1);
    }
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


    printf("\nSequential Sort\n");

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
                    printf("\nCosa desideri fare?\n1)stampare il vettore\n2)ordinare il vettore con l'algoritmo di Sequential Sort\n3)tornare al menu precedente\n>");
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
                            sequential_sort(A, n, Perm);

                            printf("\nQuesto e' il vettore ordinato con Sequential Sort...\n");

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
