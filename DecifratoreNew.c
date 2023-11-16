#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // versione senza limiti e con terza modalità
    int input;
    int exit;
    int mod;
    int chiave;
    char hide;
    int out;

    exit = 0;

    do
    {
        printf("\n Scegliere quale modalita' di decifratura usare: 1, 2 o 3.\n >");
        scanf("%d", &mod);

        if(mod != 1 && mod != 2 && mod != 3)
        {
            printf("\07 \n Errore! \n");
        }
    }
    while(mod != 1 && mod != 2 && mod != 3);

    if(mod == 1)
    {

        do
        {
            printf("\n Hai scelto la modalita' 1. \n Adesso inserire la chiave di cifratura. \n Inserire un numero intero diverso da 0. \n >");
            scanf("%d", &chiave);

            if(chiave == 0)
            {
                printf("\07 \n Errore! \n");
            }
        }
        while(chiave == 0);

        if(chiave != 0)
        {

            scanf("%c", &hide);
            printf("\n \n Adesso inserire la sequenza di numeri che si desidera decrittografare. \n ATTENZIONE: tutti i numeri devono essere seprati da uno spazio \n l'uno dall'altro! \n \n");

            do
            {
                scanf("%d", &input);
                out = input / chiave;
                (char) out;
                printf("%c", out);
            }

            while(exit == 0);
        }
    }

    if(mod == 2)
    {
        printf("\n Hai scelto la modalita' 2. \n Adesso inserire la chiave di cifratura. \n Inserire un numero intero. \n >");

        scanf("%d", &chiave);

        scanf("%c", &hide);

        printf("\n \n Adesso inserire la sequenza di numeri che si desidera decrittografare. \n ATTENZIONE: tutti i numeri devono essere seprati da uno spazio \n l'uno dall'altro! \n \n");

        do
        {
            scanf("%d", &input);
            out = input - chiave;
            (char) out;
            printf("%c", out);
        }

        while(exit == 0);
    }


    if(mod == 3)
    {
        do
        {
            printf("\n Hai scelto la modalita' 3. \n Adesso inserire la chiave di cifratura. \n Inserire un numero intero diverso da 0. \n >");
            scanf("%d", &chiave);

            if(chiave == 0)
            {
                printf("\07 \n Errore! \n");
            }
        }
        while(chiave == 0);

        if(chiave != 0)
        {
            scanf("%c", &hide);

            printf("\n \n Adesso inserire la sequenza di numeri che si desidera decrittografare. \n ATTENZIONE: tutti i numeri devono essere seprati da uno spazio \n l'uno dall'altro! \n \n");

            do
            {
                scanf("%d", &input);
                out = ((input / chiave) - chiave);
                (char) out;
                printf("%c", out);
            }

            while(exit == 0);
        }
    }



    system("PAUSE");
    return 0;
}
