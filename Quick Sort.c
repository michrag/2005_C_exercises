#include <stdio.h>
#include <stdlib.h>

typedef short unsigned int Boolean;

#define TRUE 1
#define FALSE 0

void swap(float* V, int position, int next);
void swap(float* V, int position, int next)
{
    float tmp;
    tmp = V[position];
    V[position] = V[next];
    V[next] = tmp;
}

int partition(float* V, int size);
int partition(float* V, int size)
{
    float pivot;
    int l;
    int r;

    pivot = V[0];
    l = 0;
    r = size;

    while(l < r)
    {
        do
        {
            r--;
        }
        while(V[r] > pivot);

        if(l < r)
        {
            do
            {
                l++;
            }
            while(V[l] <= pivot && l < r);

            swap(V, l, r);
        }
    }

    swap(V, 0, l);
    return l;
}

void quick_sort(float* V, int size);
void quick_sort(float* V, int size)
{
    int q;

    if(size > 1)
    {
        q = partition(V, size);
        quick_sort(V, q);
        quick_sort(&V[q + 1], size - (q + 1));
    }
}

int main(int argc, char* argv[])
{
    float* A;

    int n;
    int count;
    int reply;
    int risp;
    int answer;
    Boolean back;
    Boolean exit;

    exit = FALSE;


    printf("\nQuick Sort\n");

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

                printf("\nInserire i valori...\n");

                for(count = 0; count < n; count++)
                {
                    printf("Valore in posizione %d >", count);
                    scanf("%f", &A[count]);
                }

                do
                {
                    printf("\nCosa desideri fare?\n1)stampare il vettore\n2)ordinare il vettore con l'algoritmo Quick Sort\n   (attenzione: il vettore sara' modificato!)\n3)tornare al menu precedente\n>");
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

                        case 2: //ordinamento
                        {
                            quick_sort(A, n);
                            printf("\nIl vettore e' stato ordinato\n");

                            do
                            {
                                printf("\nCosa desideri fare?\n1)stampare il vettore ordinato\n2)tornare al menu principale\n>");
                                scanf("%d", &answer);

                                switch(answer)
                                {
                                    case 1:
                                    {
                                        printf("\nQuesto e' il vettore ordinato con Quick Sort...\n");

                                        for(count = 0; count < n; count++)
                                        {
                                            printf("|%f|\n", A[count]);
                                        }
                                    }
                                    break;

                                    case 2:
                                        back = TRUE;
                                        break;

                                    default:
                                        printf("Selezione non valida\n");

                                }
                            }
                            while(back != TRUE);
                        }
                        break;

                        case 3:
                        {
                            back = TRUE;
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
