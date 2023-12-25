#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // last version
    int input;
    int exit;
    int mod;
    int chiave;
    char hide;
    int out;

    exit = 0;

    do
    {
        printf("\n Scegliere quale modalita' di decifratura usare: 1 o 2 \n >");
        scanf("%d", &mod);

        if(mod != 1 && mod != 2)
        {
            printf("\07 \n Errore! \n");
        }
    }
    while(mod != 1 && mod != 2);

    if(mod == 1)
    {

        do
        {
            printf("\n Hai scelto la modalita' 1. \n Adesso inserire la chiave di cifratura. \n Inserire un intero compreso tra -10 e 10, escluso lo 0 \n >");
            scanf("%d", &chiave);

            if(chiave == 0 || chiave > 10 || chiave < -10)
            {
                printf("\07 \n Errore! \n");
            }
        }
        while(chiave == 0 || chiave > 10 || chiave < -10);

        if(chiave >= -10 && chiave != 0 && chiave <= 10)
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

        do
        {
            printf("\n Hai scelto la modalita' 2. \n Adesso inserire la chiave di cifratura. \n Inserire un intero compreso tra -100 e 100 \n >");
            scanf("%d", &chiave);

            if(chiave > 100 || chiave < -100)
            {
                printf("\07 \n Errore! \n");
            }
        }
        while(chiave > 100 || chiave < -100);

        if(chiave >= -100 && chiave <= 100)
        {

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
    }
    
    system("PAUSE");
    return 0;
}
