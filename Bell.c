#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("\n Questo programma emette un numero di suoni consecutivi pari al valore immesso.\n\n");

    int key;
    int count;
    int reply;

    do
    {
        printf("\n Inserire il numero di suoni desiderato \n>");
        scanf("%d", &key);

        for(count = 0; count < key; count++)
        {
            printf("\07");
        }

        printf("\n Continuare? \n No: inserisci 0 \n Si': inserisci un qualunque altro valore \n>");
        scanf("%d", &reply);
    }
    while(reply != 0);

    system("PAUSE");
    return 0;
}
