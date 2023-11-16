#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char lettera;


    scanf("%c", &lettera);
    (int) lettera;

    if(lettera == 97) /* 97 è il numero del carattere a */
    {
        printf("\07");
    }

    if(lettera == 98) /* 98 è il num di b */
    {
        printf("\07\07");
    }

    //potrei farlo per tutto l'alfabeto e metterci un do-while

    system("PAUSE");
    return 0;
}
