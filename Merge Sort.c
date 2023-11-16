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

void merge(float* V, float* TMP, int n1, int n2);
void merge(float* V, float* TMP, int n1, int n2)
{
    int count;
    int l;
    int r;

    l = 0;
    r = 0;

    for(count = 0; count < n1; count ++)
    {
        TMP[count] = V[count];
    }

    while(l < n1 && r < n2)
    {
        if(TMP[l] <= V[n1 + r])
        {
            V[l + r] = TMP[l];
            l++;
        }
        else
        {
            V[l + r] = V[n1 + r];
            r++;
        }
    }

    while(l < n1)
    {
        V[l + r] = TMP[l];
        l++;
    }
}


void merge_sort(float* V, float* tmp, int size);
void merge_sort(float* V, float* tmp, int size)
{
    if(size > 2)
    {
        merge_sort(V, tmp, size / 2);
        merge_sort(&V[size / 2], &tmp[size / 2], size - (size / 2));
        merge(V, tmp, size / 2, size - (size / 2));
    }

    else
    {
        if(V[0] > V[1])
        {
            swap(V, 0, 1);
        }
    }
}

void alloc_and_call_mergesort(float* V, int size);
void alloc_and_call_mergesort(float* V, int size)
{
    float* tmp;

    tmp = (float*)malloc((size / 2) * sizeof(float));

    merge_sort(V, tmp, size);
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


    printf("\nMerge Sort\n");

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
                    printf("\nCosa desideri fare?\n1)stampare il vettore\n2)ordinare il vettore con l'algoritmo Merge Sort\n   (attenzione: il vettore sara' modificato!)\n3)tornare al menu precedente\n>");
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
                            alloc_and_call_mergesort(A, n);
                            printf("\nIl vettore e' stato ordinato\n");

                            do
                            {
                                printf("\nCosa desideri fare?\n1)stampare il vettore ordinato\n2)tornare al menu principale\n>");
                                scanf("%d", &answer);

                                switch(answer)
                                {
                                    case 1:
                                    {
                                        printf("\nQuesto e' il vettore ordinato con Merge Sort...\n");

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
