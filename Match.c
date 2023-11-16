#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0


void stampa(float* V, int n);
void stampa(float* V, int n)
{
    unsigned int count;

    for(count = 0; count < n; count++)
    {
        printf("|%f|\n", V[count]);
    }
}

Boolean match(float* V1, int n1, float* V2, int n2);
Boolean match(float* V1, int n1, float* V2, int n2)
{
    int base;
    int offset;
    Boolean found;
    Boolean mismatch;
    base = 0;
    found = FALSE;

    while((base <= (n1 - n2)) && (found == FALSE))
    {
        offset = 0;
        mismatch = FALSE;

        while((offset < n2) && (mismatch == FALSE))
        {
            if(V2[offset] != V1[base + offset])
            {
                mismatch = TRUE;
            }

            offset++;
        }

        if(mismatch == FALSE)
        {
            found = TRUE;
        }

        else
        {
            base++;
        }
    }

    return found;
}

int main(int argc, char* argv[])
{
    float* A;
    float* B;
    int sizeA;
    int sizeB;
    int count;
    int reply;
    int risp;
    Boolean exit;
    Boolean back;
    Boolean result;

    exit = FALSE;

    do
    {

        printf("\nCosa desideri fare?\n1)creare due vettori\n2)uscire\n>");
        scanf("%d", &risp);

        switch(risp)
        {
            case 1:
            {

                back = FALSE;
                result = FALSE;

                do
                {
                    printf("Inserire la dimensione del primo vettore\n>");
                    scanf("%d", &sizeA);
                }
                while(sizeA < 1);

                A = (float*)malloc(sizeA * sizeof(float));
                printf("\nImmettere i valori del primo vettore...\n");

                for(count = 0; count < sizeA; count++)
                {
                    printf("valore in posizione %d >", count);
                    scanf("%f", &A[count]);
                }

                do
                {
                    printf("\nInserire la dimensione del secondo vettore\nATTENZIONE: non deve essere maggiore di quella del primo!\n>");
                    scanf("%d", &sizeB);
                }
                while((sizeB > sizeA) || (sizeB < 1));

                B = (float*)malloc(sizeB * sizeof(float));
                printf("\nImmettere i valori del secondo vettore..\n");

                for(count = 0; count < sizeB; count++)
                {
                    printf("valore in posizione %d >", count);
                    scanf("%f", &B[count]);
                }

                do
                {
                    printf("\nCosa si desidera fare?\n1)stampare il primo vettore\n2)stampare il secondo vettore\n3)verificare se il secondo vettore e' contenuto nel primo\n4)tornare al menu precedente\n>");
                    scanf("%d", &reply);

                    switch(reply)
                    {
                        case 1:
                        {
                            printf("Questo e' il primo vettore...\n");
                            stampa(A, sizeA);
                        }
                        break;

                        case 2:
                        {
                            printf("Questo e' il secondo vettore...\n");
                            stampa(B, sizeB);
                        }
                        break;

                        case 3:
                        {
                            result = match(A, sizeA, B, sizeB);

                            if(result == TRUE)
                            {
                                printf("\nIl secondo vettore e' contenuto nel primo.");
                            }
                            else
                            {
                                printf("\nIl secondo vettore NON e' contenuto nel primo.");
                            }
                        }
                        break;

                        case 4:
                        {
                            back = TRUE;
                            free(A);
                            free(B);
                        }
                        break;

                        default:
                            printf("Selezione non valida!\n");

                    }
                }
                while(back != TRUE);
            }
            break;

            case 2:
                exit = TRUE;
                break;

            default:
                printf("Selezione non valida!\n");
        }
    }
    while(exit != TRUE);

    system("PAUSE");
    return 0;
}
