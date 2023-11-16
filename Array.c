#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    float* A;
    int n;
    int count;
    int reply;
    int exit;

    do
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
            printf(">");
            scanf("%f", &A[count]);
        }

        printf("\n\nStampare? Si'=1\n>");
        scanf("%d", &reply);

        if(reply == 1)
        {
            for(count = 0; count < n; count++)
            {
                printf("|%f|\n", A[count]);
            }
        }

        free(A);

        printf("\nUscire? Si'=1\n>");
        scanf("%d", &exit);
    }
    while(exit != 1);

    system("PAUSE");
    return 0;
}
