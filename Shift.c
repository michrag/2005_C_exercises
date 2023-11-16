#include <stdio.h>
#include <stdlib.h>

void shift(int* V, int size);
void shift(int* V, int size)
{
    int count;
    int tmp;
    tmp = V[size - 1];

    for(count = size - 2; count > -1; count--)
    {
        V[count + 1] = V[count];
    }

    V[0] = tmp;

    for(count = 0; count < size; count++)
    {
        printf("|%d|\n", V[count]);
    }
}

int main(int argc, char* argv[])
{
    int* A;
    int n;
    int count;
    int reply;
    int risp;
    int exit;


    do
    {
        exit = 0;
        printf("inserire n\n");
        scanf("%d", &n);

        A = (int*)malloc(n * sizeof(int));

        for(count = 0; count < n; count++)
        {
            printf(">");
            scanf("%d", &A[count]);
        }

        printf("\n\nStampare?\n>");
        scanf("%d", &reply);

        if(reply == 1)
        {
            for(count = 0; count < n; count++)
            {
                printf("|%d|\n", A[count]);
            }
        }

        printf("\nEseguire uno shift circolare?\n>");
        scanf("%d", &risp);

        if(risp == 1)
        {
            shift(A, n);
        }


        free(A);
        printf("\nUscire?\n>");
        scanf("%d", &exit);
    }
    while(exit != 1);

    system("PAUSE");
    return 0;
}
