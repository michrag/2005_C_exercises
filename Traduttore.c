#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("\n Questo programma traduce ogni carattere inserito tramite tastiera nel \n corrispondente valore numerico della tabella caratteri.\n NOTA: il carattere 32 e' lo spazio e il 10 e' l'invio. \n\n Digitare una sequenza di caratteri... \n \n ");

    char lettera;
    int exit;

    exit = 0;

    do
    {

        scanf("%c", &lettera); /*legge la lettera come variabile di tipo char */

        (int)lettera; /*in teoria questo CAST è superfluo perchè char<int e quindi
                  il printf viene eseguito secondo la semantica del tipo int*/

        printf("%d\n", lettera); /*scrive la lettera come variabile di tipo int.
                         Attenzione: \n è importante! */
    }
    while(exit == 0);

    system("PAUSE");
    return 0;
}
