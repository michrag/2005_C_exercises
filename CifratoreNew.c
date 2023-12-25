#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    //versione senza limiti sulla dimensione di chiave e con terza modalità
    char lettera;
    int exit;
    int mod;
    int chiave;
    char hide;
    int out;


    exit = 0;

    do
    {
        printf("\n Scegliere quale modalita' di cifratura usare: 1, 2 o 3. \n >");
        scanf("%d", &mod);

        if(mod != 1 && mod != 2 && mod != 3)
        {
            printf("\07 \n Errore! \n");
        }
    }
    while(mod != 1 && mod != 2 && mod != 3);

    if(mod == 1) // moltiplicazione
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
            printf("\n \n Adesso inserire la sequenza di caratteri che si desidera crittografare... \n \n");

            do
            {

                scanf("%c", &lettera);
                (int)lettera;
                out = lettera * chiave;
                printf("%d\n", out);
            }
            while(exit == 0);
        }
    }

    if(mod == 2) // addizione
    {
        printf("\n Hai scelto la modalita' 2. \n Adesso inserire la chiave di cifratura. \n Inserire un numero intero. \n >");
        scanf("%d", &chiave);
        scanf("%c", &hide);
        printf("\n \n Adesso inserire la sequenza di caratteri che si desidera crittografare... \n \n");

        do
        {

            scanf("%c", &lettera);
            (int)lettera;
            out = lettera + chiave;
            printf("%d\n", out);
        }
        while(exit == 0);
    }

    if(mod == 3) //addizione e moltiplicazione
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
            printf("\n \n Adesso inserire la sequenza di caratteri che si desidera crittografare... \n \n");

            do
            {
                scanf("%c", &lettera);
                (int)lettera;
                out = ((lettera + chiave) * chiave);
                printf("%d\n", out);
            }
            while(exit == 0);
        }
    }

    system("PAUSE");
    return 0;
}
