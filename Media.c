#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int key;
    int count;

    float sum;
    float media;
    float last;
    int reply;

    do
    {
        printf("\n Inserire il numero di quanti valori si vuole calcolare la media \n >");
        scanf("%d", &key);

        if(key <= 0)
        {
            printf("\n \07 Devi immettere un numero naturale >=1 ! \n");
        }
        else
        {

            printf("\n Adesso inserisci %d numeri... \n", key);

            for(sum = 0, count = 0; count < key; count++)
            {
                printf(">");
                scanf("%f", &last);
                sum = sum + last;
            }

            media = sum / key;

            printf("\n La media dei %d valori immessi e' %f \n", key, media);
            printf("\n Vuoi calcolare un'altra media? \n No: immetti 0 \n Si': immetti un qualunque altro valore \n >");
            scanf("%d", &reply);
        }
    }
    while(reply != 0);

    system("PAUSE");
    return 0;
}
