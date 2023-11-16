#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{



    int lettera;
    int exit;

    exit = 0;

    printf("\n Questo programma converte ogni numero nel corrispondente carattere della \n tabella caratteri. \n \n Inserire una sequenza di numeri. \n \n ATTENZIONE: tutti i numeri devono essere separati da uno spazio l'uno \n dall'altro! \n\n");

    do
    {
        scanf("%d", &lettera);
        (char) lettera;
        printf("%c", lettera);
    }

    while(exit == 0);

    system("PAUSE");
    return 0;

}


