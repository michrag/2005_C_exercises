#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int reply;
    int* V;

    do
    {
        int n;

        printf("\n Immettere il numero di quanti addendi consecutivi devono avere \n somma uguale ad un certo valore \n >");

        scanf("%d", &n);

        if(n <= 0)
        {
            printf("\n Devi immettere un numero di addendi >=1 !");
        }
        else
        {
            int key;
            int next2read;
            int count;
            int sum;

            printf("\n Immettere il valore per cui quando la somma degli ultimi %d numeri \n immessi risulta uguale a tale valore, il programma termina \n >", n);

            scanf("%d", &key);

            V = (int*)malloc(n * sizeof(int));

            printf("\n Adesso immettere i numeri... \n");

            for(count = 0; count < n - 1; count = count + 1)
            {
                scanf("%d", &V[count]);
            }

            next2read = n - 1;

            do
            {
                scanf("%d", &V[next2read]);
                next2read = (next2read + 1) % n;
                sum = 0;

                for(count = 0; count < n; count = count + 1)
                {
                    sum = sum + V[count];
                }
            }

            while(sum != key);

            printf("\n La somma degli ultimi %d numeri immessi risulta uguale a %d \n", n, key);
            printf("\n Vuoi ripetere il programma? \n No: invia 0 \n Si': invia un qualunque altro valore \n >");
            scanf("%d", &reply);
        }
    }
    while(reply != 0);

    system("PAUSE");
    free(V);
    return 0;
}
